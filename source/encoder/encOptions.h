/* Copyright (c) 2026, InterDigital
 * All rights reserved.
 * See LICENSE under the root folder.
 */

#pragma once
#include "../commonlib/commondef.h"
#include "../commonlib/utility.h"

int readOptions(int argc, char *argv[], char *filein, char *fileout, int *rows,
                int *cols, int *frameNum, int *skip, int *type);
