// Copyright (c) 2026, InterDigital
// All rights reserved.
// See LICENSE under the root folder.

#include "acodec.h"
#include <stdlib.h>
#include <cmath>
#include <utility>
using std::swap;

// - - Constants - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

const unsigned AC__MinLength = 0x01000000U;   // threshold for renormalization
const unsigned AC__MaxLength = 0xFFFFFFFFU;      // maximum AC interval length

                                           // Maximum values for binary models
const unsigned BM__LengthShift = 13;     // length bits discarded before mult.
const unsigned BM__MaxCount    = 1 << BM__LengthShift;  // for adaptive models

                                          // Maximum values for general models
const unsigned DM__LengthShift = 15;     // length bits discarded before mult.
const unsigned DM__MaxCount    = 1 << DM__LengthShift;  // for adaptive models

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - Static functions  - - - - - - - - - - - - - - - - - - - - - - - - - - -


static void abort_msg(const char *func, const char *msg)
{
  fprintf(stderr, "\n\n -> Arithmetic coding error: ");
  if (func && *func) {
    fprintf(stderr, "[%s] ", func);
  }
  fputs(msg, stderr);
  fputs("\n Execution terminated!\n", stderr);
  exit(1);
}

#define AC_ABORT_MSG(msg) abort_msg(__func__, (msg))


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - Static Data Model implementation with modification - - - - - - - - - - -
// - - by referencing Static data model in the thrid party codes - - - - - - - 

StaticDataModel::StaticDataModel(unsigned number_of_symbols)
{
    set_alphabet(number_of_symbols);
}

void StaticDataModel::set_alphabet(unsigned number_of_symbols, const double probability[])
{
    if ((number_of_symbols < 2) || (number_of_symbols > (1 << 11)))
        AC_ABORT_MSG("invalid number of data symbols");

    if (data_symbols != number_of_symbols) {     // assign memory for data model
        data_symbols = number_of_symbols;
        last_symbol = data_symbols - 1;
        delete [] distribution;
        
        decoder_table = 0;
        table_size = table_shift = 0;
        distribution = new unsigned[data_symbols];
        if (distribution == 0) 
            AC_ABORT_MSG("cannot assign model memory");
    }
                             // compute cumulative distribution, decoder table
    unsigned s = 0;
    double sum = 0.0, p = 1.0 / double(data_symbols);

    for (unsigned k = 0; k < data_symbols; k++) {
        if (probability) p = probability[k];
        if ((p < 0.0001) || (p > 0.9999)) AC_ABORT_MSG("invalid symbol probability");
        distribution[k] = unsigned(sum * (1 << DM__LengthShift));
        sum += p;
        if (table_size == 0) continue;
        unsigned w = distribution[k] >> table_shift;
        while (s < w) decoder_table[++s] = k - 1;
    }

    if ((sum < 0.9999) || (sum > 1.0001)) AC_ABORT_MSG("invalid probabilities");
}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - Adaptive Data Model implementation with modification - - - - - - - - - - -
// - - by referencing Adaptive data model in the thrid party codes - - - - - - - 

AdaptiveDataModel::AdaptiveDataModel(void)
{
    distribution_forbidden = 0;
}

AdaptiveDataModel::AdaptiveDataModel(unsigned number_of_symbols)
{
    distribution_forbidden = 0;
}

AdaptiveDataModel::~AdaptiveDataModel(void)
{
    delete [] distribution_forbidden;
}

void AdaptiveDataModel::reset(void)
{
    if (data_symbols <= 1)
        return;

    // restore probability estimates to uniform distribution
    total_count = 0;
    update_cycle = data_symbols;
    for (unsigned k = 0; k < data_symbols; k++) symbol_count[k] = 1;
    update();
    symbols_until_update = update_cycle = 1;
}

void AdaptiveDataModel::set_alphabet(unsigned number_of_symbols)
{
    if ((number_of_symbols < 1) || (number_of_symbols > (1 << 11)))
        AC_ABORT_MSG("invalid number of data symbols");

    if (data_symbols != number_of_symbols) {     // assign memory for data model
        data_symbols = number_of_symbols;
        last_symbol = data_symbols - 1;
        delete [] distribution;
        delete[] distribution_forbidden;
        // define size of table for fast decoding
        // small alphabet: no table needed
        decoder_table = 0;
        table_size = table_shift = 0;
        distribution = new unsigned[2 * data_symbols];
        distribution_forbidden = new unsigned[data_symbols];
        symbol_count = distribution + data_symbols;
        if (distribution == 0)
            AC_ABORT_MSG("cannot assign model memory");
    }
    reset();                                                 // initialize model
}

void AdaptiveDataModel::printProbability(void)
{
    for (int i = 0; i < data_symbols - 1; i++) {
        printf("%f ",   float(int(distribution[i + 1]) - int(distribution[i])) / 32767);
    }
    printf("%f ", float(32767 - int(distribution[data_symbols - 1])) / 32767);
    printf("\n");
}

void AdaptiveDataModel::setProbability(float prob[])
{
    total_count = 9;
    for (unsigned k = 0; k < data_symbols; k++)
        symbol_count[k] = int(10 * prob[k]);

    update();
}

void AdaptiveDataModel::copy(int *count_list)
{
    total_count = 0;
    for (unsigned k = 0; k < data_symbols; k++) {
        symbol_count[k] = count_list[k];
        total_count += count_list[k];
    }
    
    total_count--;
    update();
}

void AdaptiveDataModel::copy(AdaptiveDataModel &M, int *forbidden)
{
    total_count = M.total_count;
    for (int i = 0; i < forbidden[0]; i++)
        total_count -= M.symbol_count[forbidden[i + 1]];

    unsigned j = 1;
    for (unsigned k = 0; k < M.data_symbols; k++) {
        if (k == forbidden[j]) {
            if (j <= forbidden[0])
                j++;
            continue;
        }
        symbol_count[k - (j - 1)] = M.symbol_count[k];
    }
    
    total_count--;
    update();
}

float AdaptiveDataModel::get_bits(unsigned data)
{
    return -log2(symbol_count[data] / float(total_count));
}

float AdaptiveDataModel::get_bits(unsigned data, int forbidden)
{
    if (forbidden >= 0 && forbidden < data_symbols) {
        return -log2(float(symbol_count[data]) /
                    (total_count - symbol_count[forbidden]));
    } else {
        return -log2(float(symbol_count[data]) / total_count);
    }
}

void AdaptiveDataModel::update()
{
    // halve counts when a threshold is reached
    if ((total_count += update_cycle) > DM__MaxCount) {
        total_count = 0;
        for (unsigned n = 0; n < data_symbols; n++)
            total_count += (symbol_count[n] = (symbol_count[n] + 1) >> 1);
    }
    
    // compute cumulative distribution, decoder table
    unsigned k, sum = 0, s = 0;
    unsigned scale = 0x80000000U / total_count;

    for (k = 0; k < data_symbols; k++) {
        distribution[k] = (scale * sum) >> (31 - DM__LengthShift);
        sum += symbol_count[k];
    }
    //  set frequency of model updates
    update_cycle = (5 * update_cycle) >> 2;
    unsigned max_cycle = (data_symbols + 6) << 3;
    if (update_cycle > max_cycle) update_cycle = max_cycle;
    symbols_until_update = update_cycle;
}

void AdaptiveBitModel::reset(void)
{
    // initialization to equiprobable model
    bit_0_count = 1;
    bit_count   = 2;
    bit_0_prob  = 1U << (BM__LengthShift - 1);
    update_cycle = bits_until_update = 1; // start with frequent updates
}

void AdaptiveBitModel::printProbability(void)
{
    printf("%f ", float(bit_0_prob) / 8191);
    printf("%f \n", 1 - float(bit_0_prob) / 8191);
}

void AdaptiveBitModel::setProbability(float prob0)
{
    bit_count = 10;
    bit_0_count = int(bit_count * prob0);
    unsigned scale = 0x80000000U / bit_count;
    bit_0_prob = (bit_0_count * scale) >> (31 - BM__LengthShift);
}

void AdaptiveBitModel::copy(int *count_list)
{
    bit_count = count_list[0] + count_list[1];
    bit_0_count = count_list[0];
    unsigned scale = 0x80000000U / bit_count;
    bit_0_prob = (bit_0_count * scale) >> (31 - BM__LengthShift);
}

float AdaptiveBitModel::get_bits(unsigned data)
{
    if (data == 0)
        return -log2(bit_0_count / float(bit_count));
    return -log2(1 - bit_0_count / float(bit_count));
}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - ArithmeticCodec implementation with modification - - - - - - - - - - -
// - - by referencing Arithmetic codec in the thrid party codes - - - - - - - 


void ArithmeticCodec::noencode(unsigned data, AdaptiveDataModel &M)
{
    // was ++M.symbol_count[data];
    M.get_arr_symbol_count()[data]++;

    // was if (--M.symbols_until_update == 0)
    M.get_ref_symbols_until_update()--;
    if (M.get_symbols_until_update() == 0)
        M.update(); // periodic model update
}

void ArithmeticCodec::nodecode(AdaptiveDataModel &M, int s)
{
    // was ++M.symbol_count[s];
    M.get_arr_symbol_count()[s]++;

    // was if (--M.symbols_until_update == 0)
    M.get_ref_symbols_until_update()--;
    if (M.get_symbols_until_update() == 0)
        M.update(); // periodic model update
}

void ArithmeticCodec::encode(unsigned bit, AdaptiveBitModel &M)
{

}

void ArithmeticCodec::encode(unsigned data, AdaptiveDataModel &M, int forbidden1, int forbidden2)
{
#ifdef _DEBUG
    if (mode != 1)
        AC_ABORT_MSG("encoder not initialized");
    if (data >= M.data_symbols)
        AC_ABORT_MSG("invalid data symbol");
#endif
    if (forbidden2 < forbidden1)
        swap(forbidden1, forbidden2);

    unsigned j, k, sum = 0;
    unsigned scale = 0x80000000U / (M.get_total_count() - M.get_symbol_count(forbidden1) -
                                    M.get_symbol_count(forbidden2));
    for (k = 0; k < M.model_symbols(); k++) {
        if (k == forbidden1 || k == forbidden2)
            continue;
        j = k;
        if (j > forbidden2)
            j -= 2;
        else if (j > forbidden1)
            j -= 1;
        M.get_arr_distribution_forbidden()[j] = (scale * sum) >> (31 - DM__LengthShift);
        sum += M.get_symbol_count(k);
    }
  
    unsigned data_code = data;
    if (data_code > forbidden2)
        data_code -= 2;
    else if (data_code > forbidden1)
        data_code -= 1;

    unsigned x, init_base = base;

    if (data_code == M.get_last_symbol() - 2) {
        x = M.get_distribution_forbidden(data_code) * (length >> DM__LengthShift);
        base += x;   // update interval
        length -= x; // no product needed
    } else {
        x = M.get_distribution_forbidden(data_code) * (length >>= DM__LengthShift);
        base += x; // update interval
        length = M.get_distribution_forbidden(data_code + 1) * length - x;
    }

    if (init_base > base)
        propagate_carry(); // overflow = carry

    if (length < AC__MinLength)
        renorm_enc_interval(); // renormalization

    M.get_arr_symbol_count()[data]++;
    M.get_ref_symbols_until_update()--;
    
    if (M.get_symbols_until_update() == 0)
        M.update(); // periodic model update
}

void ArithmeticCodec::encode(unsigned data, AdaptiveDataModel &M, int *forbidden)
{
    if (M.model_symbols() == 1)
        return;
    if (forbidden[0] == 0) {
        unsigned x, init_base = base;
        // compute products
        if (data == M.get_last_symbol()) {
            x = M.get_distribution(data) * (length >> DM__LengthShift);
            base += x;   // update interval
            length -= x; // no product needed
        } else {
            x = M.get_distribution(data) * (length >>= DM__LengthShift);
            base += x; // update interval
            length = M.get_distribution(data + 1) * length - x;
        }

    if (init_base > base)
        propagate_carry(); // overflow = carry

    if (length < AC__MinLength)
        renorm_enc_interval(); // renormalization

    M.get_arr_symbol_count()[data]++;
    M.get_ref_symbols_until_update()--;
    if (M.get_symbols_until_update() == 0)
        M.update(); // periodic model update
    } else {
        if (M.model_symbols() - forbidden[0] == 1)
            return;

        forbidden[forbidden[0] + 1] = 0;
        unsigned j = 1, k, sum = 0;
        unsigned data_code = data;
        unsigned count_rest = M.get_total_count();
        for (int i = 0; i < forbidden[0]; i++)
            count_rest -= M.get_symbol_count(forbidden[i + 1]);

        unsigned scale = 0x80000000U / count_rest;

        for (k = 0; k < M.model_symbols(); k++) {
            if (k == forbidden[j]) {
                if (j <= forbidden[0])
                    j++;
                continue;
            }
            if (k == data)
            data_code = k - (j - 1);
            M.get_arr_distribution_forbidden()[k - (j - 1)] = (scale * sum) >> (31 - DM__LengthShift);
            sum += M.get_symbol_count(k);
        }

        unsigned x, init_base = base;

        if (data_code == M.get_last_symbol() - forbidden[0]) {
            x = M.get_distribution_forbidden(data_code) * (length >> DM__LengthShift);
            base += x;   // update interval
            length -= x; // no product needed
        } else {
            x = M.get_distribution_forbidden(data_code) * (length >>= DM__LengthShift);
            base += x; // update interval
            length = M.get_distribution_forbidden(data_code + 1) * length - x;
        }

        if (init_base > base)
            propagate_carry(); // overflow = carry

        if (length < AC__MinLength)
            renorm_enc_interval(); // renormalization

        M.get_arr_symbol_count()[data]++;
        M.get_ref_symbols_until_update()--;
        if (M.get_symbols_until_update() == 0)
            M.update(); // periodic model update
    }
}

unsigned ArithmeticCodec::decode(StaticDataModel &M)
{
#ifdef _DEBUG
    if (mode != 2) AC_ABORT_MSG("decoder not initialized");
#endif

    unsigned n, s, x, y = length;

    x = s = 0;
    length >>= DM__LengthShift;
    unsigned m = (n = M.model_symbols()) >> 1;
    // decode via bisection search
    do {
        unsigned z = length * M.get_distribution(m);
        if (z > value) {
            n = m;
            y = z; // value is smaller
        } 
        else {
            s = m;
            x = z; // value is larger or equal
        }
    } while ((m = (s + n) >> 1) != s);
    value -= x;                                               // update interval
    length = y - x;

    if (length < AC__MinLength) renorm_dec_interval();        // renormalization

    return s;
}

unsigned ArithmeticCodec::decode(AdaptiveDataModel &M)
{
#ifdef _DEBUG
    if (mode != 2) AC_ABORT_MSG("decoder not initialized");
#endif

    unsigned n, s, x, y = length;

    x = s = 0;
    length >>= DM__LengthShift;
    unsigned m = (n = M.model_symbols()) >> 1;
      // decode via bisection search
    do {
        unsigned z = length * M.get_distribution(m);
        if (z > value) {
            n = m;
            y = z; // value is smaller
        } else {
            s = m;
            x = z; // value is larger or equal
        }
    } while ((m = (s + n) >> 1) != s);

    value -= x; // update interval
    length = y - x;

    if (length < AC__MinLength)
        renorm_dec_interval(); // renormalization

    M.get_arr_symbol_count()[s]++;
    M.get_ref_symbols_until_update()--;
    if (M.get_symbols_until_update() == 0)
        M.update(); // periodic model update

  return s;
}

unsigned ArithmeticCodec::decode(AdaptiveDataModel &M, int forbidden1, int forbidden2)
{
#ifdef _DEBUG
    if (mode != 2)
        AC_ABORT_MSG("decoder not initialized");
#endif
    if (forbidden2 < forbidden1)
        swap(forbidden1, forbidden2);

    unsigned j, k, sum = 0;
    unsigned scale = 0x80000000U / (M.get_total_count() - M.get_symbol_count(forbidden1) -
                                    M.get_symbol_count(forbidden2));
    
    for (k = 0; k < M.model_symbols(); k++) {
        if (k == forbidden1 || k == forbidden2)
        continue;
        j = k;
        if (j > forbidden2)
            j -= 2;
        else if (j > forbidden1)
            j -= 1;
        M.get_arr_distribution_forbidden()[j] = (scale * sum) >> (31 - DM__LengthShift);
        sum += M.get_symbol_count(k);
    }

    unsigned n, s, x, y = length;

    x = s = 0;
    length >>= DM__LengthShift;
    unsigned m = (n = (M.model_symbols() - 2)) >> 1;
    do {
        unsigned z = length * M.get_distribution_forbidden(m);
        if (z > value) {
            n = m;
            y = z; // value is smaller
        } else {
            s = m;
            x = z; // value is larger or equal
        }
    } while ((m = (s + n) >> 1) != s);

    value -= x; // update interval
    length = y - x;

    if (length < AC__MinLength)
        renorm_dec_interval(); // renormalization
    if (s >= forbidden1)
        s++;
    if (s >= forbidden2)
        s++;

    M.get_arr_symbol_count()[s]++;
    M.get_ref_symbols_until_update()--;

    if (M.get_symbols_until_update() == 0)
        M.update(); // periodic model update

    return s;
}

unsigned ArithmeticCodec::decode(AdaptiveDataModel &M, int *forbidden)
{
    if (M.model_symbols() == 1)
        return 0;

    if (forbidden[0] == 0) {
        unsigned n, s, x, y = length;

        x = s = 0;
        length >>= DM__LengthShift;
        unsigned m = (n = M.model_symbols()) >> 1;
        
        // decode via bisection search
        do {
            unsigned z = length * M.get_distribution(m);
            if (z > value) {
                n = m;
                y = z; // value is smaller
            } else {
                s = m;
                x = z; // value is larger or equal
            }
        } while ((m = (s + n) >> 1) != s);

        value -= x; // update interval
        length = y - x;

        if (length < AC__MinLength)
            renorm_dec_interval(); // renormalization

        M.get_arr_symbol_count()[s]++;
        M.get_ref_symbols_until_update()--;
        if (M.get_symbols_until_update() == 0)
            M.update(); // periodic model update

        return s;
    } else {
        if (M.model_symbols() - forbidden[0] == 1) {
            for (int i = 0; i < M.model_symbols() - 1; i++) {
                if (forbidden[i + 1] != i)
                    return i;
            }
            return M.model_symbols() - 1;
        }

    forbidden[forbidden[0] + 1] = 0;
    unsigned j = 1, k, sum = 0;
    unsigned count_rest = M.get_total_count();
    for (int i = 0; i < forbidden[0]; i++)
        count_rest -= M.get_symbol_count(forbidden[i + 1]);

    unsigned scale = 0x80000000U / count_rest;
    for (k = 0; k < M.model_symbols(); k++) {
        if (k == forbidden[j]) {
            if (j <= forbidden[0])
                j++;
            continue;
        }
        M.get_arr_distribution_forbidden()[k - (j - 1)] = (scale * sum) >> (31 - DM__LengthShift);
        sum += M.get_symbol_count(k);
    }

    unsigned n, s, x, y = length;

    x = s = 0;
    length >>= DM__LengthShift;
    unsigned m = (n = (M.model_symbols() - forbidden[0])) >> 1;
    do {
        unsigned z = length * M.get_distribution_forbidden(m);
        if (z > value) {
            n = m;
            y = z; // value is smaller
        } else {
            s = m;
            x = z; // value is larger or equal
        }
    } while ((m = (s + n) >> 1) != s);

    value -= x; // update interval
    length = y - x;

    if (length < AC__MinLength)
        renorm_dec_interval(); // renormalization

    for (int i = 0; i < forbidden[0]; i++) {
        if (s >= forbidden[i + 1])
            s++;
        else
            break;
    }

    M.get_arr_symbol_count()[s]++;
    M.get_ref_symbols_until_update()--;
    if (M.get_symbols_until_update() == 0)
      M.update(); // periodic model update

    return s;
  }
}

float ArithmeticCodec::getBits(unsigned data, AdaptiveDataModel &M, int *forbidden)
{
    if (M.model_symbols() == 1 || M.model_symbols() - forbidden[0] == 1)
        return 0;

    unsigned count_rest = M.get_total_count();
  
    for (int i = 0; i < forbidden[0]; i++)
        count_rest -= M.get_symbol_count(forbidden[i + 1]);
    
    float p = float(M.get_symbol_count(data)) / count_rest;

    M.get_arr_symbol_count()[data]++;
    M.get_ref_total_count()++;

    return -log2(p);
}
