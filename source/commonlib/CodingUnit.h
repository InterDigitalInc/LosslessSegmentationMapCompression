#pragma once
#include "global_arithmetic.h"
#include <iostream> 
using namespace std;

class CodingUnit
{
public:
	CodingUnit();
	~CodingUnit();
	void create_object_MSC(unsigned char* pImg, int h, int w, int loc_row, int loc_col, int index, bool paint = true);
	void create_object_3OT(unsigned char* pImg, int h, int w, int loc_row, int loc_col, int index);
	void destroyObject();

	void enObjectEdge(int loc_row, int loc_col);
	void selectChainMode();
	void setFlag();

	int pic_width;
	int pic_height;

	int location_row;
	int location_col;
	CodingUnit* next;

	int chainType; //0: MSE 1: 3OT

	int colorValue;
	int object_index;
	int* Edge_MSC;   
	int* Overlap_MSC;
	int* Edge_3OT;
	int* Overlap_3OT;
};


