// Copyright (c) 2026, InterDigital
// All rights reserved.
// See LICENSE under the root folder.

#pragma once

#include "third_party/arithmetic_codec.h"

class StaticDataModel : public Static_Data_Model
{
public:
    StaticDataModel(unsigned number_of_symbols);
    void set_alphabet(unsigned number_of_symbols,
                    const double probability[] = 0);    //  0 means uniform distribution

    unsigned get_distribution(int m) {  return distribution[m];    }
};


class AdaptiveBitModel : public Adaptive_Bit_Model
{
public:
    void reset(void); // reset to equiprobable model
    void printProbability(void);
    void setProbability(float prob0);
    void copy(int *count_list);
    float get_bits(unsigned data);
    int get_count()                    { return bit_count; }
};


class AdaptiveDataModel : public Adaptive_Data_Model
{
public:
    AdaptiveDataModel(void);
    AdaptiveDataModel(unsigned number_of_symbols);
    ~AdaptiveDataModel();
    
    void        reset(void);                             // reset to equiprobable model
    void        set_alphabet(unsigned number_of_symbols);
    void        printProbability(void);
    void        setProbability(float prob[]);
    void        copy(int* count_list);
    void        copy(AdaptiveDataModel &M, int* forbidden);
    float       get_bits(unsigned data);
    float       get_bits(unsigned data, int forbidden);

    unsigned&   get_ref_total_count()                       { return total_count; }
    unsigned*   get_arr_symbol_count()                      { return symbol_count;  }
    unsigned    get_symbol_count(int idx)                   { return symbol_count[idx]; }
    unsigned&   get_ref_symbols_until_update()              { return symbols_until_update;  }
    unsigned    get_symbols_until_update()                  { return symbols_until_update;  }
    unsigned    get_distribution(int m)                     { return distribution[m];    }
    unsigned    get_total_count()                           { return total_count;   }
    void        set_total_count(unsigned v)                 { total_count = v;   }
    unsigned*   get_arr_distribution_forbidden()            { return distribution_forbidden;    }
    unsigned    get_distribution_forbidden(int idx)         { return distribution_forbidden[idx];   }
    unsigned    get_last_symbol()                           { return last_symbol;   }
    void        update();

    unsigned* distribution_forbidden;
    unsigned pre_count;
private:
};

class ArithmeticCodec : public Arithmetic_Codec
{
public:
    using Arithmetic_Codec::encode;
    using Arithmetic_Codec::decode;

    void encode(unsigned bit, AdaptiveBitModel &M);
    void noencode(unsigned data, AdaptiveDataModel &);
    void nodecode(AdaptiveDataModel &, int s);

    void encode(unsigned data, AdaptiveDataModel &M, int forbidden1, int forbidden2);
    void encode(unsigned data, AdaptiveDataModel &M, int *forbidden);
    
    unsigned decode(StaticDataModel &M);
    unsigned decode(AdaptiveDataModel &M);
    unsigned decode(AdaptiveDataModel &M, int forbidden1, int forbidden2);
    unsigned decode(AdaptiveDataModel &M, int *forbidden);
    
    float getBits(unsigned data, AdaptiveDataModel &M, int *forbidden);

    int getByteNum()        {   return writeBytes;  }
};
