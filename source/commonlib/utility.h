#pragma once
#include "CodingUnit.h"
#include "global_arithmetic.h"

void advancedExpand(unsigned char *img, int height, int width, int color1,
                    int color2_y, int color2_x);
void objectExpand(unsigned char *img, int height, int width, int color2_y,
                  int color2_x, int color);
void decObjectExpand(unsigned char *img, int height, int width, int color2_y,
                     int color2_x, int color);
void encObjectExpand(unsigned char *img, int height, int width, int color2_y,
                     int color2_x, int color);
int getBitSize(int num);
void encGolomb(int absV, int mode, int k);
float GolombBits(int absV, int mode, int k);
int decGolomb(int mode, int k);
void writeByArithmetic(Arithmetic_Codec *ace, Adaptive_Bit_Model *bit,
                       int output, int num);
int readByArithmetic(Arithmetic_Codec *acd, Adaptive_Bit_Model *bit, int num);
void write2bin(unsigned char *p, int size, char *file_name);
int getFSize(FILE *pFile);
int get_MSC(int direction1, int direction2, int direction3, int *num);
int get_3OT(int direction1, int direction2, int *direction_list, int *num,
            int *start_x, int *start_y, int end_x, int end_y, int pic_width,
            int pic_height, bool boundary);
void encodeEdgeLength_MSC(CodingUnit *CU, bool encode);
void encodeEdgeLength_3OT(CodingUnit *CU);
int get_direction1(int direction, int *index);
int get_RMSC(int index, int direction);
int get_position_index(int x, int y, int pic_w, int pic_h);
int get_position_3OT(int x, int y, int pic_w, int pic_h);
void adapt_position(int *x, int *y, int direction);
void get_forbidden1(int x, int y, int pic_w, int pic_h, int *forbidden,
                    int start_index);
void get_forbidden2(int x, int y, int pic_w, int pic_h, int direction_index,
                    int direction1, int *forbidden, int start_index,
                    int high_point, int left_point);
void get_forbidden3(int x, int y, int pic_w, int pic_h, int direction_index,
                    int direction1, int direction2, int *forbidden,
                    int start_index, int high_point, int left_point);
void get_forbidden_3OT(int x, int y, int pic_w, int pic_h, int pre_direction,
                       int turn, int *forbidden, bool boundary, int start_index,
                       int high_point, int left_point);
int get_dec_MSC(int index, int direction);
float getBits_MSC(CodingUnit *CU);
float getBits_3OT(CodingUnit *CU);
