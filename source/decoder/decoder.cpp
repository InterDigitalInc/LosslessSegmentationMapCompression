#include "../../source/commonlib/CodingUnit.h"
#include "../../source/commonlib/utility.h"
#include "decOptions.h"
#include <assert.h>
#include <fstream>
#include <iostream>
#include <time.h>
using namespace std;

void dec_edge_position(int *loc_row, int *loc_col, int h, int w, int val) {
  if (val < h) {
    *loc_row = val;
    *loc_col = 0;
  } else if (val < h + w - 1) {
    *loc_row = h - 1;
    *loc_col = val - (h - 1);
  } else if (val < 2 * h + w - 2) {
    *loc_row = 2 * h + w - 3 - val;
    *loc_col = w - 1;
  } else {
    *loc_row = 0;
    *loc_col = 2 * h + 2 * w - 4 - val;
  }
}

int get_overlap(unsigned char *img, int pic_height, int pic_width, int y_run,
                int x_run, int direction, int *Available_val) {
  int F8[3] = {-1, -1, -1};
  int x, y;

  for (int k = 0; k < 3; k++) {
    x = x_run;
    y = y_run;
    direction = (direction + 5) % 8;
    int end_direction = direction;
    bool find = false;
    while (x_run >= 0 && x_run < pic_width && y_run >= 0 &&
           y_run < pic_height) {
      direction = (direction + 1) % 8;
      switch (direction) {
      case 0:
        x_run = x + 1;
        y_run = y;
        if (!(x_run >= 0 && x_run < pic_width && y_run >= 0 &&
              y_run < pic_height)) {
          F8[k] = 0;
          break;
        }
        if (Available_val[img[y_run * pic_width + x_run]]) {
          F8[k] = 0;
          find = true;
        }
        break;
      case 1:
        x_run = x + 1;
        y_run = y - 1;
        if (!(x_run >= 0 && x_run < pic_width && y_run >= 0 &&
              y_run < pic_height)) {
          F8[k] = 1;
          break;
        }
        if (Available_val[img[y_run * pic_width + x_run]]) {
          F8[k] = 1;
          find = true;
        }
        break;
      case 2:
        x_run = x;
        y_run = y - 1;
        if (!(x_run >= 0 && x_run < pic_width && y_run >= 0 &&
              y_run < pic_height)) {
          F8[k] = 2;
          break;
        }
        if (Available_val[img[y_run * pic_width + x_run]]) {
          F8[k] = 2;
          find = true;
        }
        break;
      case 3:
        x_run = x - 1;
        y_run = y - 1;
        if (!(x_run >= 0 && x_run < pic_width && y_run >= 0 &&
              y_run < pic_height)) {
          F8[k] = 3;
          break;
        }
        if (Available_val[img[y_run * pic_width + x_run]]) {
          F8[k] = 3;
          find = true;
        }
        break;
      case 4:
        x_run = x - 1;
        y_run = y;
        if (!(x_run >= 0 && x_run < pic_width && y_run >= 0 &&
              y_run < pic_height)) {
          F8[k] = 4;
          break;
        }
        if (Available_val[img[y_run * pic_width + x_run]]) {
          F8[k] = 4;
          find = true;
        }
        break;
      case 5:
        x_run = x - 1;
        y_run = y + 1;
        if (!(x_run >= 0 && x_run < pic_width && y_run >= 0 &&
              y_run < pic_height)) {
          F8[k] = 5;
          break;
        }
        if (Available_val[img[y_run * pic_width + x_run]]) {
          F8[k] = 5;
          find = true;
        }
        break;
      case 6:
        x_run = x;
        y_run = y + 1;
        if (!(x_run >= 0 && x_run < pic_width && y_run >= 0 &&
              y_run < pic_height)) {
          F8[k] = 6;
          break;
        }
        if (Available_val[img[y_run * pic_width + x_run]]) {
          F8[k] = 6;
          find = true;
        }
        break;
      case 7:
        x_run = x + 1;
        y_run = y + 1;
        if (!(x_run >= 0 && x_run < pic_width && y_run >= 0 &&
              y_run < pic_height)) {
          F8[k] = 7;
          break;
        }
        if (Available_val[img[y_run * pic_width + x_run]]) {
          F8[k] = 7;
          find = true;
        }
        break;
      }
      if (direction == end_direction)
        break;
      if (find)
        break;
    }
  }
  return get_MSC(F8[0], F8[1], F8[2], &x);
}

void deObjectEdge_MSC(unsigned char *img, int pic_height, int pic_width,
                      int initial_loc_y, int initial_loc_x, int color) {
  int loc_y, loc_x, first_y, first_x;
  int direction, dir_last, dir_index, direction1, direction2, direction_index,
      direction1_candi1, direction1_candi2;
  int start_index;
  int Available_val[256];
  int runLength;
  bool end;
  bool newzero = false;

  loc_y = initial_loc_y;
  loc_x = initial_loc_x;

  // printf("%d %d\n", initial_loc_y, initial_loc_x);

  if (loc_x == 0) {
    loc_y -= 1;
    dir_last = 0;
  } else if (loc_y == pic_height - 1) {
    loc_x -= 1;
    dir_last = 2;
  } else if (loc_x == pic_width - 1) {
    loc_y += 1;
    dir_last = 4;
  } else if (loc_y == 0) {
    loc_x += 1;
    dir_last = 6;
  } else {
    loc_x -= 1;
    dir_last = 2;
  }

  first_y = loc_y;
  first_x = loc_x;

  bool boundary = false;
  if (initial_loc_x == 0 || initial_loc_x == pic_width - 1 ||
      initial_loc_y == 0 || initial_loc_y == pic_height - 1)
    boundary = true;
  int high_point = initial_loc_y - 1;
  if (boundary)
    high_point = -1;
  int left_point = initial_loc_x;
  if (boundary)
    left_point = -1;

  start_index =
      get_position_index(initial_loc_x, initial_loc_y, pic_width, pic_height);

  for (int j = 0; j < pic_height * pic_width; j++)
    codedMap[j] = 255;
  codedMap[loc_y * pic_width + loc_x] = -1;

  int forbidden[38] = {0};
  dir_index = 0;

  for (int i = 0; i < 256; i++)
    Available_val[i] = 1;
  Available_val[255] = 0;
  Available_val[img[initial_loc_y * pic_width + initial_loc_x]] = 0;
  runLength = 0;
  newzero = false;
  do {
    if (dir_index == 0) {
      if (Available_val[img[loc_y * pic_width + loc_x]]) {
        end = acodec.decode(aEndFlag);
        if (end)
          runLength = 10000000;
        else
          runLength = decGolomb(0, 3);
      }

      if (!runLength) {
        newzero = false;
        if (boundary) {
          get_forbidden1(loc_x, loc_y, pic_width, pic_height, forbidden,
                         start_index);
          if (initial_loc_x == 0)
            direction = acodec.decode(aMSC_L, forbidden);
          else if (initial_loc_y == pic_height - 1)
            direction = acodec.decode(aMSC_B, forbidden);
          else if (initial_loc_x == pic_width - 1)
            direction = acodec.decode(aMSC_R, forbidden);
          else if (initial_loc_y == 0)
            direction = acodec.decode(aMSC_A, forbidden);
        } else {
          int MSC_index = acodec.decode(aMSC_I);
          if (MSC_index == 0)
            direction = 1;
          else if (MSC_index == 1)
            direction = 9;
          else if (MSC_index == 2)
            direction = 25;
        }
      } else {
        direction = get_overlap(img, pic_height, pic_width, loc_y, loc_x,
                                dir_last, Available_val);
        runLength--;
        if (!runLength)
          newzero = true;
      }

      direction1 = get_direction1(direction, &direction_index);
    } else if (dir_index == 1) {
      if (Available_val[img[loc_y * pic_width + loc_x]] && runLength == 0 &&
          !newzero) {
        end = acodec.decode(aEndFlag);
        if (end)
          runLength = 10000000;
        else
          runLength = decGolomb(0, 3);
      }

      if (!runLength) {
        newzero = false;
        get_forbidden2(loc_x, loc_y, pic_width, pic_height, direction_index,
                       direction1, forbidden, start_index, high_point,
                       left_point);
        switch (direction1) {
        case 0:
          direction2 = dec_arr1[0][acodec.decode(aMSC_0, forbidden)];
          break;
        case 1:
          direction2 = dec_arr1[1][acodec.decode(aMSC_1, forbidden)];
          break;
        case 2:
          direction2 = dec_arr1[2][acodec.decode(aMSC_2, forbidden)];
          break;
        case 3:
          direction2 = dec_arr1[3][acodec.decode(aMSC_3, forbidden)];
          break;
        case 4:
          direction2 = dec_arr1[4][acodec.decode(aMSC_4, forbidden)];
          break;
        case 5:
          direction2 = dec_arr1[5][acodec.decode(aMSC_5, forbidden)];
          break;
        case 6:
          direction2 = dec_arr1[6][acodec.decode(aMSC_6, forbidden)];
          break;
        case 7:
          direction2 = dec_arr1[7][acodec.decode(aMSC_7, forbidden)];
          break;
        case 8:
          direction2 = dec_arr1[8][acodec.decode(aMSC_8, forbidden)];
          break;
        }
        direction = get_dec_MSC(direction_index, direction2);
      } else {
        direction = get_overlap(img, pic_height, pic_width, loc_y, loc_x,
                                dir_last, Available_val);
        direction2 = get_RMSC(direction_index, direction);
        runLength--;
        if (!runLength)
          newzero = true;
      }

      direction1_candi1 = get_direction1(direction, &direction_index);
    } else {
      if (Available_val[img[loc_y * pic_width + loc_x]] && runLength == 0 &&
          !newzero) {
        end = acodec.decode(aEndFlag);
        if (end)
          runLength = 10000000;
        else
          runLength = decGolomb(0, 3);
      }

      if (!runLength) {
        newzero = false;
        get_forbidden3(loc_x, loc_y, pic_width, pic_height, direction_index,
                       direction1, direction2, forbidden, start_index,
                       high_point, left_point);
        switch (direction1 * 100 + direction2) {
        case 0:
          direction2 = dec_arr[0][0][acodec.decode(aMSC_00, forbidden)];
          break;
        case 1:
          direction2 = dec_arr[0][1][acodec.decode(aMSC_01, forbidden)];
          break;
        case 2:
          direction2 = dec_arr[0][2][acodec.decode(aMSC_02, forbidden)];
          break;
        case 3:
          direction2 = dec_arr[0][3][acodec.decode(aMSC_03, forbidden)];
          break;
        case 4:
          direction2 = dec_arr[0][4][acodec.decode(aMSC_04, forbidden)];
          break;
        case 5:
          direction2 = dec_arr[0][5][acodec.decode(aMSC_05, forbidden)];
          break;
        case 6:
          direction2 = dec_arr[0][6][acodec.decode(aMSC_06, forbidden)];
          break;
        case 7:
          direction2 = dec_arr[0][7][acodec.decode(aMSC_07, forbidden)];
          break;
        case 8:
          direction2 = dec_arr[0][8][acodec.decode(aMSC_08, forbidden)];
          break;
        case 9:
          direction2 = dec_arr[0][9][acodec.decode(aMSC_09, forbidden)];
          break;
        case 10:
          direction2 = dec_arr[0][10][acodec.decode(aMSC_010, forbidden)];
          break;
        case 11:
          direction2 = dec_arr[0][11][acodec.decode(aMSC_011, forbidden)];
          break;
        case 12:
          direction2 = dec_arr[0][12][acodec.decode(aMSC_012, forbidden)];
          break;
        case 13:
          direction2 = dec_arr[0][13][acodec.decode(aMSC_013, forbidden)];
          break;
        case 14:
          direction2 = dec_arr[0][14][acodec.decode(aMSC_014, forbidden)];
          break;
        case 15:
          direction2 = dec_arr[0][15][acodec.decode(aMSC_015, forbidden)];
          break;
        case 16:
          direction2 = dec_arr[0][16][acodec.decode(aMSC_016, forbidden)];
          break;
        case 17:
          direction2 = dec_arr[0][17][acodec.decode(aMSC_017, forbidden)];
          break;
        case 18:
          direction2 = dec_arr[0][18][acodec.decode(aMSC_018, forbidden)];
          break;
        case 19:
          direction2 = dec_arr[0][19][acodec.decode(aMSC_019, forbidden)];
          break;
        case 20:
          direction2 = dec_arr[0][20][acodec.decode(aMSC_020, forbidden)];
          break;
        case 21:
          direction2 = dec_arr[0][21][acodec.decode(aMSC_021, forbidden)];
          break;
        case 22:
          direction2 = dec_arr[0][22][acodec.decode(aMSC_022, forbidden)];
          break;
        case 23:
          direction2 = dec_arr[0][23][acodec.decode(aMSC_023, forbidden)];
          break;
        case 24:
          direction2 = dec_arr[0][24][acodec.decode(aMSC_024, forbidden)];
          break;
        case 25:
          direction2 = dec_arr[0][25][acodec.decode(aMSC_025, forbidden)];
          break;
        case 26:
          direction2 = dec_arr[0][26][acodec.decode(aMSC_026, forbidden)];
          break;
        case 100:
          direction2 = dec_arr[1][0][acodec.decode(aMSC_10, forbidden)];
          break;
        case 101:
          direction2 = dec_arr[1][1][acodec.decode(aMSC_11, forbidden)];
          break;
        case 102:
          direction2 = dec_arr[1][2][acodec.decode(aMSC_12, forbidden)];
          break;
        case 103:
          direction2 = dec_arr[1][3][acodec.decode(aMSC_13, forbidden)];
          break;
        case 104:
          direction2 = dec_arr[1][4][acodec.decode(aMSC_14, forbidden)];
          break;
        case 105:
          direction2 = dec_arr[1][5][acodec.decode(aMSC_15, forbidden)];
          break;
        case 106:
          direction2 = dec_arr[1][6][acodec.decode(aMSC_16, forbidden)];
          break;
        case 107:
          direction2 = dec_arr[1][7][acodec.decode(aMSC_17, forbidden)];
          break;
        case 108:
          direction2 = dec_arr[1][8][acodec.decode(aMSC_18, forbidden)];
          break;
        case 109:
          direction2 = dec_arr[1][9][acodec.decode(aMSC_19, forbidden)];
          break;
        case 110:
          direction2 = dec_arr[1][10][acodec.decode(aMSC_110, forbidden)];
          break;
        case 111:
          direction2 = dec_arr[1][11][acodec.decode(aMSC_111, forbidden)];
          break;
        case 112:
          direction2 = dec_arr[1][12][acodec.decode(aMSC_112, forbidden)];
          break;
        case 113:
          direction2 = dec_arr[1][13][acodec.decode(aMSC_113, forbidden)];
          break;
        case 114:
          direction2 = dec_arr[1][14][acodec.decode(aMSC_114, forbidden)];
          break;
        case 115:
          direction2 = dec_arr[1][15][acodec.decode(aMSC_115, forbidden)];
          break;
        case 116:
          direction2 = dec_arr[1][16][acodec.decode(aMSC_116, forbidden)];
          break;
        case 117:
          direction2 = dec_arr[1][17][acodec.decode(aMSC_117, forbidden)];
          break;
        case 118:
          direction2 = dec_arr[1][18][acodec.decode(aMSC_118, forbidden)];
          break;
        case 119:
          direction2 = dec_arr[1][19][acodec.decode(aMSC_119, forbidden)];
          break;
        case 120:
          direction2 = dec_arr[1][20][acodec.decode(aMSC_120, forbidden)];
          break;
        case 121:
          direction2 = dec_arr[1][21][acodec.decode(aMSC_121, forbidden)];
          break;
        case 122:
          direction2 = dec_arr[1][22][acodec.decode(aMSC_122, forbidden)];
          break;
        case 123:
          direction2 = dec_arr[1][23][acodec.decode(aMSC_123, forbidden)];
          break;
        case 124:
          direction2 = dec_arr[1][24][acodec.decode(aMSC_124, forbidden)];
          break;
        case 125:
          direction2 = dec_arr[1][25][acodec.decode(aMSC_125, forbidden)];
          break;
        case 126:
          direction2 = dec_arr[1][26][acodec.decode(aMSC_126, forbidden)];
          break;
        case 200:
          direction2 = dec_arr[2][0][acodec.decode(aMSC_20, forbidden)];
          break;
        case 201:
          direction2 = dec_arr[2][1][acodec.decode(aMSC_21, forbidden)];
          break;
        case 202:
          direction2 = dec_arr[2][2][acodec.decode(aMSC_22, forbidden)];
          break;
        case 203:
          direction2 = dec_arr[2][3][acodec.decode(aMSC_23, forbidden)];
          break;
        case 204:
          direction2 = dec_arr[2][4][acodec.decode(aMSC_24, forbidden)];
          break;
        case 205:
          direction2 = dec_arr[2][5][acodec.decode(aMSC_25, forbidden)];
          break;
        case 206:
          direction2 = dec_arr[2][6][acodec.decode(aMSC_26, forbidden)];
          break;
        case 207:
          direction2 = dec_arr[2][7][acodec.decode(aMSC_27, forbidden)];
          break;
        case 208:
          direction2 = dec_arr[2][8][acodec.decode(aMSC_28, forbidden)];
          break;
        case 209:
          direction2 = dec_arr[2][9][acodec.decode(aMSC_29, forbidden)];
          break;
        case 210:
          direction2 = dec_arr[2][10][acodec.decode(aMSC_210, forbidden)];
          break;
        case 211:
          direction2 = dec_arr[2][11][acodec.decode(aMSC_211, forbidden)];
          break;
        case 212:
          direction2 = dec_arr[2][12][acodec.decode(aMSC_212, forbidden)];
          break;
        case 213:
          direction2 = dec_arr[2][13][acodec.decode(aMSC_213, forbidden)];
          break;
        case 214:
          direction2 = dec_arr[2][14][acodec.decode(aMSC_214, forbidden)];
          break;
        case 215:
          direction2 = dec_arr[2][15][acodec.decode(aMSC_215, forbidden)];
          break;
        case 216:
          direction2 = dec_arr[2][16][acodec.decode(aMSC_216, forbidden)];
          break;
        case 217:
          direction2 = dec_arr[2][17][acodec.decode(aMSC_217, forbidden)];
          break;
        case 218:
          direction2 = dec_arr[2][18][acodec.decode(aMSC_218, forbidden)];
          break;
        case 219:
          direction2 = dec_arr[2][19][acodec.decode(aMSC_219, forbidden)];
          break;
        case 220:
          direction2 = dec_arr[2][20][acodec.decode(aMSC_220, forbidden)];
          break;
        case 221:
          direction2 = dec_arr[2][21][acodec.decode(aMSC_221, forbidden)];
          break;
        case 222:
          direction2 = dec_arr[2][22][acodec.decode(aMSC_222, forbidden)];
          break;
        case 223:
          direction2 = dec_arr[2][23][acodec.decode(aMSC_223, forbidden)];
          break;
        case 224:
          direction2 = dec_arr[2][24][acodec.decode(aMSC_224, forbidden)];
          break;
        case 225:
          direction2 = dec_arr[2][25][acodec.decode(aMSC_225, forbidden)];
          break;
        case 226:
          direction2 = dec_arr[2][26][acodec.decode(aMSC_226, forbidden)];
          break;
        case 300:
          direction2 = dec_arr[3][0][acodec.decode(aMSC_30, forbidden)];
          break;
        case 301:
          direction2 = dec_arr[3][1][acodec.decode(aMSC_31, forbidden)];
          break;
        case 302:
          direction2 = dec_arr[3][2][acodec.decode(aMSC_32, forbidden)];
          break;
        case 303:
          direction2 = dec_arr[3][3][acodec.decode(aMSC_33, forbidden)];
          break;
        case 304:
          direction2 = dec_arr[3][4][acodec.decode(aMSC_34, forbidden)];
          break;
        case 305:
          direction2 = dec_arr[3][5][acodec.decode(aMSC_35, forbidden)];
          break;
        case 306:
          direction2 = dec_arr[3][6][acodec.decode(aMSC_36, forbidden)];
          break;
        case 307:
          direction2 = dec_arr[3][7][acodec.decode(aMSC_37, forbidden)];
          break;
        case 308:
          direction2 = dec_arr[3][8][acodec.decode(aMSC_38, forbidden)];
          break;
        case 309:
          direction2 = dec_arr[3][9][acodec.decode(aMSC_39, forbidden)];
          break;
        case 310:
          direction2 = dec_arr[3][10][acodec.decode(aMSC_310, forbidden)];
          break;
        case 311:
          direction2 = dec_arr[3][11][acodec.decode(aMSC_311, forbidden)];
          break;
        case 312:
          direction2 = dec_arr[3][12][acodec.decode(aMSC_312, forbidden)];
          break;
        case 313:
          direction2 = dec_arr[3][13][acodec.decode(aMSC_313, forbidden)];
          break;
        case 314:
          direction2 = dec_arr[3][14][acodec.decode(aMSC_314, forbidden)];
          break;
        case 315:
          direction2 = dec_arr[3][15][acodec.decode(aMSC_315, forbidden)];
          break;
        case 316:
          direction2 = dec_arr[3][16][acodec.decode(aMSC_316, forbidden)];
          break;
        case 317:
          direction2 = dec_arr[3][17][acodec.decode(aMSC_317, forbidden)];
          break;
        case 318:
          direction2 = dec_arr[3][18][acodec.decode(aMSC_318, forbidden)];
          break;
        case 319:
          direction2 = dec_arr[3][19][acodec.decode(aMSC_319, forbidden)];
          break;
        case 320:
          direction2 = dec_arr[3][20][acodec.decode(aMSC_320, forbidden)];
          break;
        case 321:
          direction2 = dec_arr[3][21][acodec.decode(aMSC_321, forbidden)];
          break;
        case 322:
          direction2 = dec_arr[3][22][acodec.decode(aMSC_322, forbidden)];
          break;
        case 323:
          direction2 = dec_arr[3][23][acodec.decode(aMSC_323, forbidden)];
          break;
        case 324:
          direction2 = dec_arr[3][24][acodec.decode(aMSC_324, forbidden)];
          break;
        case 325:
          direction2 = dec_arr[3][25][acodec.decode(aMSC_325, forbidden)];
          break;
        case 326:
          direction2 = dec_arr[3][26][acodec.decode(aMSC_326, forbidden)];
          break;
        case 400:
          direction2 = dec_arr[4][0][acodec.decode(aMSC_40, forbidden)];
          break;
        case 401:
          direction2 = dec_arr[4][1][acodec.decode(aMSC_41, forbidden)];
          break;
        case 402:
          direction2 = dec_arr[4][2][acodec.decode(aMSC_42, forbidden)];
          break;
        case 403:
          direction2 = dec_arr[4][3][acodec.decode(aMSC_43, forbidden)];
          break;
        case 404:
          direction2 = dec_arr[4][4][acodec.decode(aMSC_44, forbidden)];
          break;
        case 405:
          direction2 = dec_arr[4][5][acodec.decode(aMSC_45, forbidden)];
          break;
        case 406:
          direction2 = dec_arr[4][6][acodec.decode(aMSC_46, forbidden)];
          break;
        case 407:
          direction2 = dec_arr[4][7][acodec.decode(aMSC_47, forbidden)];
          break;
        case 408:
          direction2 = dec_arr[4][8][acodec.decode(aMSC_48, forbidden)];
          break;
        case 409:
          direction2 = dec_arr[4][9][acodec.decode(aMSC_49, forbidden)];
          break;
        case 410:
          direction2 = dec_arr[4][10][acodec.decode(aMSC_410, forbidden)];
          break;
        case 411:
          direction2 = dec_arr[4][11][acodec.decode(aMSC_411, forbidden)];
          break;
        case 412:
          direction2 = dec_arr[4][12][acodec.decode(aMSC_412, forbidden)];
          break;
        case 413:
          direction2 = dec_arr[4][13][acodec.decode(aMSC_413, forbidden)];
          break;
        case 414:
          direction2 = dec_arr[4][14][acodec.decode(aMSC_414, forbidden)];
          break;
        case 415:
          direction2 = dec_arr[4][15][acodec.decode(aMSC_415, forbidden)];
          break;
        case 416:
          direction2 = dec_arr[4][16][acodec.decode(aMSC_416, forbidden)];
          break;
        case 417:
          direction2 = dec_arr[4][17][acodec.decode(aMSC_417, forbidden)];
          break;
        case 418:
          direction2 = dec_arr[4][18][acodec.decode(aMSC_418, forbidden)];
          break;
        case 419:
          direction2 = dec_arr[4][19][acodec.decode(aMSC_419, forbidden)];
          break;
        case 420:
          direction2 = dec_arr[4][20][acodec.decode(aMSC_420, forbidden)];
          break;
        case 421:
          direction2 = dec_arr[4][21][acodec.decode(aMSC_421, forbidden)];
          break;
        case 422:
          direction2 = dec_arr[4][22][acodec.decode(aMSC_422, forbidden)];
          break;
        case 423:
          direction2 = dec_arr[4][23][acodec.decode(aMSC_423, forbidden)];
          break;
        case 424:
          direction2 = dec_arr[4][24][acodec.decode(aMSC_424, forbidden)];
          break;
        case 425:
          direction2 = dec_arr[4][25][acodec.decode(aMSC_425, forbidden)];
          break;
        case 426:
          direction2 = dec_arr[4][26][acodec.decode(aMSC_426, forbidden)];
          break;
        case 500:
          direction2 = dec_arr[5][0][acodec.decode(aMSC_50, forbidden)];
          break;
        case 501:
          direction2 = dec_arr[5][1][acodec.decode(aMSC_51, forbidden)];
          break;
        case 502:
          direction2 = dec_arr[5][2][acodec.decode(aMSC_52, forbidden)];
          break;
        case 503:
          direction2 = dec_arr[5][3][acodec.decode(aMSC_53, forbidden)];
          break;
        case 504:
          direction2 = dec_arr[5][4][acodec.decode(aMSC_54, forbidden)];
          break;
        case 505:
          direction2 = dec_arr[5][5][acodec.decode(aMSC_55, forbidden)];
          break;
        case 506:
          direction2 = dec_arr[5][6][acodec.decode(aMSC_56, forbidden)];
          break;
        case 507:
          direction2 = dec_arr[5][7][acodec.decode(aMSC_57, forbidden)];
          break;
        case 508:
          direction2 = dec_arr[5][8][acodec.decode(aMSC_58, forbidden)];
          break;
        case 509:
          direction2 = dec_arr[5][9][acodec.decode(aMSC_59, forbidden)];
          break;
        case 510:
          direction2 = dec_arr[5][10][acodec.decode(aMSC_510, forbidden)];
          break;
        case 511:
          direction2 = dec_arr[5][11][acodec.decode(aMSC_511, forbidden)];
          break;
        case 512:
          direction2 = dec_arr[5][12][acodec.decode(aMSC_512, forbidden)];
          break;
        case 513:
          direction2 = dec_arr[5][13][acodec.decode(aMSC_513, forbidden)];
          break;
        case 514:
          direction2 = dec_arr[5][14][acodec.decode(aMSC_514, forbidden)];
          break;
        case 515:
          direction2 = dec_arr[5][15][acodec.decode(aMSC_515, forbidden)];
          break;
        case 516:
          direction2 = dec_arr[5][16][acodec.decode(aMSC_516, forbidden)];
          break;
        case 517:
          direction2 = dec_arr[5][17][acodec.decode(aMSC_517, forbidden)];
          break;
        case 518:
          direction2 = dec_arr[5][18][acodec.decode(aMSC_518, forbidden)];
          break;
        case 519:
          direction2 = dec_arr[5][19][acodec.decode(aMSC_519, forbidden)];
          break;
        case 520:
          direction2 = dec_arr[5][20][acodec.decode(aMSC_520, forbidden)];
          break;
        case 521:
          direction2 = dec_arr[5][21][acodec.decode(aMSC_521, forbidden)];
          break;
        case 522:
          direction2 = dec_arr[5][22][acodec.decode(aMSC_522, forbidden)];
          break;
        case 523:
          direction2 = dec_arr[5][23][acodec.decode(aMSC_523, forbidden)];
          break;
        case 524:
          direction2 = dec_arr[5][24][acodec.decode(aMSC_524, forbidden)];
          break;
        case 525:
          direction2 = dec_arr[5][25][acodec.decode(aMSC_525, forbidden)];
          break;
        case 526:
          direction2 = dec_arr[5][26][acodec.decode(aMSC_526, forbidden)];
          break;
        case 600:
          direction2 = dec_arr[6][0][acodec.decode(aMSC_60, forbidden)];
          break;
        case 601:
          direction2 = dec_arr[6][1][acodec.decode(aMSC_61, forbidden)];
          break;
        case 602:
          direction2 = dec_arr[6][2][acodec.decode(aMSC_62, forbidden)];
          break;
        case 603:
          direction2 = dec_arr[6][3][acodec.decode(aMSC_63, forbidden)];
          break;
        case 604:
          direction2 = dec_arr[6][4][acodec.decode(aMSC_64, forbidden)];
          break;
        case 605:
          direction2 = dec_arr[6][5][acodec.decode(aMSC_65, forbidden)];
          break;
        case 606:
          direction2 = dec_arr[6][6][acodec.decode(aMSC_66, forbidden)];
          break;
        case 607:
          direction2 = dec_arr[6][7][acodec.decode(aMSC_67, forbidden)];
          break;
        case 608:
          direction2 = dec_arr[6][8][acodec.decode(aMSC_68, forbidden)];
          break;
        case 609:
          direction2 = dec_arr[6][9][acodec.decode(aMSC_69, forbidden)];
          break;
        case 610:
          direction2 = dec_arr[6][10][acodec.decode(aMSC_610, forbidden)];
          break;
        case 611:
          direction2 = dec_arr[6][11][acodec.decode(aMSC_611, forbidden)];
          break;
        case 612:
          direction2 = dec_arr[6][12][acodec.decode(aMSC_612, forbidden)];
          break;
        case 613:
          direction2 = dec_arr[6][13][acodec.decode(aMSC_613, forbidden)];
          break;
        case 614:
          direction2 = dec_arr[6][14][acodec.decode(aMSC_614, forbidden)];
          break;
        case 615:
          direction2 = dec_arr[6][15][acodec.decode(aMSC_615, forbidden)];
          break;
        case 616:
          direction2 = dec_arr[6][16][acodec.decode(aMSC_616, forbidden)];
          break;
        case 617:
          direction2 = dec_arr[6][17][acodec.decode(aMSC_617, forbidden)];
          break;
        case 618:
          direction2 = dec_arr[6][18][acodec.decode(aMSC_618, forbidden)];
          break;
        case 619:
          direction2 = dec_arr[6][19][acodec.decode(aMSC_619, forbidden)];
          break;
        case 620:
          direction2 = dec_arr[6][20][acodec.decode(aMSC_620, forbidden)];
          break;
        case 621:
          direction2 = dec_arr[6][21][acodec.decode(aMSC_621, forbidden)];
          break;
        case 622:
          direction2 = dec_arr[6][22][acodec.decode(aMSC_622, forbidden)];
          break;
        case 623:
          direction2 = dec_arr[6][23][acodec.decode(aMSC_623, forbidden)];
          break;
        case 624:
          direction2 = dec_arr[6][24][acodec.decode(aMSC_624, forbidden)];
          break;
        case 625:
          direction2 = dec_arr[6][25][acodec.decode(aMSC_625, forbidden)];
          break;
        case 626:
          direction2 = dec_arr[6][26][acodec.decode(aMSC_626, forbidden)];
          break;
        case 700:
          direction2 = dec_arr[7][0][acodec.decode(aMSC_70, forbidden)];
          break;
        case 701:
          direction2 = dec_arr[7][1][acodec.decode(aMSC_71, forbidden)];
          break;
        case 702:
          direction2 = dec_arr[7][2][acodec.decode(aMSC_72, forbidden)];
          break;
        case 703:
          direction2 = dec_arr[7][3][acodec.decode(aMSC_73, forbidden)];
          break;
        case 704:
          direction2 = dec_arr[7][4][acodec.decode(aMSC_74, forbidden)];
          break;
        case 705:
          direction2 = dec_arr[7][5][acodec.decode(aMSC_75, forbidden)];
          break;
        case 706:
          direction2 = dec_arr[7][6][acodec.decode(aMSC_76, forbidden)];
          break;
        case 707:
          direction2 = dec_arr[7][7][acodec.decode(aMSC_77, forbidden)];
          break;
        case 708:
          direction2 = dec_arr[7][8][acodec.decode(aMSC_78, forbidden)];
          break;
        case 709:
          direction2 = dec_arr[7][9][acodec.decode(aMSC_79, forbidden)];
          break;
        case 710:
          direction2 = dec_arr[7][10][acodec.decode(aMSC_710, forbidden)];
          break;
        case 711:
          direction2 = dec_arr[7][11][acodec.decode(aMSC_711, forbidden)];
          break;
        case 712:
          direction2 = dec_arr[7][12][acodec.decode(aMSC_712, forbidden)];
          break;
        case 713:
          direction2 = dec_arr[7][13][acodec.decode(aMSC_713, forbidden)];
          break;
        case 714:
          direction2 = dec_arr[7][14][acodec.decode(aMSC_714, forbidden)];
          break;
        case 715:
          direction2 = dec_arr[7][15][acodec.decode(aMSC_715, forbidden)];
          break;
        case 716:
          direction2 = dec_arr[7][16][acodec.decode(aMSC_716, forbidden)];
          break;
        case 717:
          direction2 = dec_arr[7][17][acodec.decode(aMSC_717, forbidden)];
          break;
        case 718:
          direction2 = dec_arr[7][18][acodec.decode(aMSC_718, forbidden)];
          break;
        case 719:
          direction2 = dec_arr[7][19][acodec.decode(aMSC_719, forbidden)];
          break;
        case 720:
          direction2 = dec_arr[7][20][acodec.decode(aMSC_720, forbidden)];
          break;
        case 721:
          direction2 = dec_arr[7][21][acodec.decode(aMSC_721, forbidden)];
          break;
        case 722:
          direction2 = dec_arr[7][22][acodec.decode(aMSC_722, forbidden)];
          break;
        case 723:
          direction2 = dec_arr[7][23][acodec.decode(aMSC_723, forbidden)];
          break;
        case 724:
          direction2 = dec_arr[7][24][acodec.decode(aMSC_724, forbidden)];
          break;
        case 725:
          direction2 = dec_arr[7][25][acodec.decode(aMSC_725, forbidden)];
          break;
        case 726:
          direction2 = dec_arr[7][26][acodec.decode(aMSC_726, forbidden)];
          break;
        case 800:
          direction2 = dec_arr[8][0][acodec.decode(aMSC_80, forbidden)];
          break;
        case 801:
          direction2 = dec_arr[8][1][acodec.decode(aMSC_81, forbidden)];
          break;
        case 802:
          direction2 = dec_arr[8][2][acodec.decode(aMSC_82, forbidden)];
          break;
        case 803:
          direction2 = dec_arr[8][3][acodec.decode(aMSC_83, forbidden)];
          break;
        case 804:
          direction2 = dec_arr[8][4][acodec.decode(aMSC_84, forbidden)];
          break;
        case 805:
          direction2 = dec_arr[8][5][acodec.decode(aMSC_85, forbidden)];
          break;
        case 806:
          direction2 = dec_arr[8][6][acodec.decode(aMSC_86, forbidden)];
          break;
        case 807:
          direction2 = dec_arr[8][7][acodec.decode(aMSC_87, forbidden)];
          break;
        case 808:
          direction2 = dec_arr[8][8][acodec.decode(aMSC_88, forbidden)];
          break;
        case 809:
          direction2 = dec_arr[8][9][acodec.decode(aMSC_89, forbidden)];
          break;
        case 810:
          direction2 = dec_arr[8][10][acodec.decode(aMSC_810, forbidden)];
          break;
        case 811:
          direction2 = dec_arr[8][11][acodec.decode(aMSC_811, forbidden)];
          break;
        case 812:
          direction2 = dec_arr[8][12][acodec.decode(aMSC_812, forbidden)];
          break;
        case 813:
          direction2 = dec_arr[8][13][acodec.decode(aMSC_813, forbidden)];
          break;
        case 814:
          direction2 = dec_arr[8][14][acodec.decode(aMSC_814, forbidden)];
          break;
        case 815:
          direction2 = dec_arr[8][15][acodec.decode(aMSC_815, forbidden)];
          break;
        case 816:
          direction2 = dec_arr[8][16][acodec.decode(aMSC_816, forbidden)];
          break;
        case 817:
          direction2 = dec_arr[8][17][acodec.decode(aMSC_817, forbidden)];
          break;
        case 818:
          direction2 = dec_arr[8][18][acodec.decode(aMSC_818, forbidden)];
          break;
        case 819:
          direction2 = dec_arr[8][19][acodec.decode(aMSC_819, forbidden)];
          break;
        case 820:
          direction2 = dec_arr[8][20][acodec.decode(aMSC_820, forbidden)];
          break;
        case 821:
          direction2 = dec_arr[8][21][acodec.decode(aMSC_821, forbidden)];
          break;
        case 822:
          direction2 = dec_arr[8][22][acodec.decode(aMSC_822, forbidden)];
          break;
        case 823:
          direction2 = dec_arr[8][23][acodec.decode(aMSC_823, forbidden)];
          break;
        case 824:
          direction2 = dec_arr[8][24][acodec.decode(aMSC_824, forbidden)];
          break;
        case 825:
          direction2 = dec_arr[8][25][acodec.decode(aMSC_825, forbidden)];
          break;
        case 826:
          direction2 = dec_arr[8][26][acodec.decode(aMSC_826, forbidden)];
          break;
        }
        direction = get_dec_MSC(direction_index, direction2);
      } else {
        direction = get_overlap(img, pic_height, pic_width, loc_y, loc_x,
                                dir_last, Available_val);
        direction2 = get_RMSC(direction_index, direction);
        runLength--;
        if (!runLength)
          newzero = true;
      }

      direction1_candi2 = get_direction1(direction, &direction_index);
      direction1 = direction1_candi1;
      direction1_candi1 = direction1_candi2;
    }
    dir_index++;

    // if (initial_loc_y == 5 && initial_loc_x == 197)
    //{
    //	if (direction == 5 && pre_direction == 13)
    //		printf("haha");
    //		//printf("%d\n", direction);
    //	pre_direction = direction;
    // }
    bool loop = false;
    switch (direction) {
    case 0:
      loc_x++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 0;
      }
      break;
    case 1:
      loc_x++;
      loc_y--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 1;
      }
      break;
    case 2:
      loc_y--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 2;
      }
      break;
    case 3:
      loc_x--;
      loc_y--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 3;
      }
      break;
    case 4:
      loc_x--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 4;
      }
      break;
    case 5:
      loc_x--;
      loc_y++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 5;
      }
      break;
    case 6:
      loc_y++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 6;
      }
      break;
    case 7:
      loc_x++;
      loc_y++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 7;
      }
      break;
    case 8:
      loc_x++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_x++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 0;
      }
      break;
    case 9:
      loc_x++;
      loc_y--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_x++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 0;
      }
      break;
    case 10:
      loc_x++;
      loc_y--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_x++;
      loc_y--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 1;
      }
      break;
    case 11:
      loc_y--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_x++;
      loc_y--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 1;
      }
      break;
    case 12:
      loc_y--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_y--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 2;
      }
      break;
    case 13:
      loc_x--;
      loc_y--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_y--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 2;
      }
      break;
    case 14:
      loc_x--;
      loc_y--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_x--;
      loc_y--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 3;
      }
      break;
    case 15:
      loc_x--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_x--;
      loc_y--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 3;
      }
      break;
    case 16:
      loc_x--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_x--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 4;
      }
      break;
    case 17:
      loc_x--;
      loc_y++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_x--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 4;
      }
      break;
    case 18:
      loc_x--;
      loc_y++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_x--;
      loc_y++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 5;
      }
      break;
    case 19:
      loc_y++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_x--;
      loc_y++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 5;
      }
      break;
    case 20:
      loc_y++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_y++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 6;
      }
      break;
    case 21:
      loc_x++;
      loc_y++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_y++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 6;
      }
      break;
    case 22:
      loc_x++;
      loc_y++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_x++;
      loc_y++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 7;
      }
      break;
    case 23:
      loc_x++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_x++;
      loc_y++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 7;
      }
      break;
    case 24:
      loc_x++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_x++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_x++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 0;
      }
      break;
    case 25:
      loc_x++;
      loc_y--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_x++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_x++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 0;
      }
      break;
    case 26:
      loc_y--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_y--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_x++;
      loc_y--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 1;
      }
      break;
    case 27:
      loc_y--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_y--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_y--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 2;
      }
      break;
    case 28:
      loc_x--;
      loc_y--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_y--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_y--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 2;
      }
      break;
    case 29:
      loc_x--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_x--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_x--;
      loc_y--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 3;
      }
      break;
    case 30:
      loc_x--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_x--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_x--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 4;
      }
      break;
    case 31:
      loc_x--;
      loc_y++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_x--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_x--;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 4;
      }
      break;
    case 32:
      loc_y++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_y++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_x--;
      loc_y++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 5;
      }
      break;
    case 33:
      loc_y++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_y++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_y++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 6;
      }
      break;
    case 34:
      loc_x++;
      loc_y++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_y++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_y++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 6;
      }
      break;
    case 35:
      loc_x++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_x++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
      }
      loc_x++;
      loc_y++;
      if (loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height) {
        if (loc_x == first_x && loc_y == first_y)
          loop = true;
        codedMap[loc_y * pic_width + loc_x] = -1;
        dir_last = 7;
      }
      break;
    }

    // printf("%d ", direction);

    if (!(loc_x >= 0 && loc_x < pic_width && loc_y >= 0 && loc_y < pic_height))
      break;
    if ((loc_x == 0 && dir_last == 4) || (loc_x == 0 && dir_last == 5) ||
        (loc_y == 0 && dir_last == 2) || (loc_y == 0 && dir_last == 3) ||
        (loc_y == pic_height - 1 && dir_last == 6) ||
        (loc_y == pic_height - 1 && dir_last == 7) ||
        (loc_x == pic_width - 1 && dir_last == 0) ||
        (loc_x == pic_width - 1 && dir_last == 1))
      break;
    if ((loc_x == 0) && (direction == 2 || direction == 12))
      break;
    if ((loc_y == 0) && (direction == 0 || direction == 8))
      break;
    if ((loc_y == pic_height - 1) && (direction == 4 || direction == 16))
      break;
    if ((loc_x == pic_width - 1) && (direction == 6 || direction == 20))
      break;
    if (dir_index > 2 && !boundary && (loc_x == first_x && loc_y == first_y))
      break;
    if (loop && !boundary)
      break;

  } while (1);

  // printf("\n");

  decObjectExpand(img, pic_height, pic_width, initial_loc_y, initial_loc_x,
                  color);
}

int to_direction(int pre_direction, int direction, int *turn) {
  if (direction == 0)
    return pre_direction;
  else if (direction == 1) {
    *turn = 1 - *turn;
    if (*turn == 0)
      return (pre_direction + 1) % 4;
    else
      return (pre_direction + 3) % 4;
  } else {
    if (*turn == 0)
      return (pre_direction + 1) % 4;
    else
      return (pre_direction + 3) % 4;
  }
}

int get_overlap_3OT(unsigned char *img, int pic_height, int pic_width,
                    int y_run, int x_run, int pre_direction, int turn,
                    int *Available_val) {
  switch (pre_direction) {
  case 0:
    if (Available_val[img[y_run * pic_width + x_run]]) {
      if (turn)
        return 2;
      else
        return 1;
    } else if (Available_val[img[(y_run - 1) * pic_width + x_run]])
      return 0;
    else if (Available_val[img[(y_run - 1) * pic_width + x_run - 1]]) {
      if (turn)
        return 1;
      else
        return 2;
    }
  case 1:
    if (Available_val[img[(y_run - 1) * pic_width + x_run]]) {
      if (turn)
        return 2;
      else
        return 1;
    } else if (Available_val[img[(y_run - 1) * pic_width + x_run - 1]])
      return 0;
    else if (Available_val[img[y_run * pic_width + x_run - 1]]) {
      if (turn)
        return 1;
      else
        return 2;
    }
  case 2:
    if (Available_val[img[(y_run - 1) * pic_width + x_run - 1]]) {
      if (turn)
        return 2;
      else
        return 1;
    } else if (Available_val[img[y_run * pic_width + x_run - 1]])
      return 0;
    else if (Available_val[img[y_run * pic_width + x_run]]) {
      if (turn)
        return 1;
      else
        return 2;
    }
  case 3:
    if (Available_val[img[y_run * pic_width + x_run - 1]]) {
      if (turn)
        return 2;
      else
        return 1;
    } else if (Available_val[img[y_run * pic_width + x_run]])
      return 0;
    else if (Available_val[img[(y_run - 1) * pic_width + x_run]]) {
      if (turn)
        return 1;
      else
        return 2;
    }
  }
}

void deObjectEdge_3OT(unsigned char *img, int pic_height, int pic_width,
                      int initial_loc_y, int initial_loc_x, int color) {
  int loc_y, loc_x, start_y, start_x, end_y, end_x;
  int direction, dir_last, dir_index, direction1, direction2, direction3,
      direction4, pre_direction, cur_direction;
  int start_index;
  int Available_val[256];
  int RunFlag;
  int runLength;
  bool end;
  bool newzero = false;

  loc_y = initial_loc_y;
  loc_x = initial_loc_x;

  // printf("%d %d\n", initial_loc_y, initial_loc_x);

  start_y = initial_loc_y;
  start_x = initial_loc_x;
  end_y = initial_loc_y + 1;
  end_x = initial_loc_x;

  if (initial_loc_x == 0) {
    loc_y -= 1;
    dir_last = 0;
    pre_direction = 0;
  } else if (initial_loc_y == pic_height - 1) {
    loc_x -= 1;
    dir_last = 2;
    pre_direction = 1;
    start_y++;
  } else if (initial_loc_x == pic_width - 1) {
    loc_y += 1;
    dir_last = 4;
    pre_direction = 2;
    start_y++;
    start_x++;
  } else if (initial_loc_y == 0) {
    loc_x += 1;
    dir_last = 6;
    pre_direction = 3;
    start_x++;
  } else {
    loc_x -= 1;
    dir_last = 2;
    pre_direction = 0;
  }

  start_index = get_position_3OT(start_x, start_y, pic_width, pic_height);

  if (initial_loc_x == 0) {
    start_x++;
  } else if (initial_loc_y == pic_height - 1) {
    start_y--;
  } else if (initial_loc_x == pic_width - 1) {
    start_x--;
  } else if (initial_loc_y == 0) {
    start_y++;
  } else {
    start_x++;
  }

  // encCodedMap[start_y*pic_width + start_x] = 1;

  bool boundary = false;
  if (initial_loc_x == 0 || initial_loc_x == pic_width - 1 ||
      initial_loc_y == 0 || initial_loc_y == pic_height - 1)
    boundary = true;

  int high_point = initial_loc_y;
  if (boundary)
    high_point = -1;
  int left_point = initial_loc_x;
  if (boundary)
    left_point = -1;

  int turn = 0; // left
  if (!boundary)
    turn = 1; // right

  for (int j = 0; j < pic_height * pic_width; j++)
    codedMap[j] = 255;
  codedMap[loc_y * pic_width + loc_x] = -1;
  if (!boundary) {
    codedMap[(loc_y - 1) * pic_width + loc_x + 1] = -1;
    loc_y--;
    loc_x++;
  }

  int forbidden[5] = {0};
  dir_index = 0;

  for (int i = 0; i < 256; i++)
    Available_val[i] = 1;
  Available_val[255] = 0;
  Available_val[img[initial_loc_y * pic_width + initial_loc_x]] = 0;
  runLength = 0;
  newzero = false;

  do {
    if (dir_index == 0) {
      if (Available_val[img[loc_y * pic_width + loc_x]]) {
        end = acodec.decode(aEndFlag);
        if (end)
          runLength = 10000000;
        else
          runLength = decGolomb(0, 3);
      }
      if (!runLength) {
        newzero = false;
        get_forbidden_3OT(start_x, start_y, pic_width, pic_height,
                          pre_direction, turn, forbidden, boundary, start_index,
                          high_point, left_point);
        if (boundary) {
          if (initial_loc_x == 0)
            direction = acodec.decode(a3OT_L, forbidden);
          else if (initial_loc_y == pic_height - 1)
            direction = acodec.decode(a3OT_B, forbidden);
          else if (initial_loc_x == pic_width - 1)
            direction = acodec.decode(a3OT_R, forbidden);
          else if (initial_loc_y == 0)
            direction = acodec.decode(a3OT_A, forbidden);
        } else {
          direction = acodec.decode(a3OT_I, forbidden);
        }
      } else {
        direction =
            get_overlap_3OT(img, pic_height, pic_width, start_y, start_x,
                            pre_direction, turn, Available_val);
        runLength--;
        if (!runLength)
          newzero = true;
      }
      cur_direction = to_direction(pre_direction, direction, &turn);
      direction1 = direction;
    } else if (dir_index == 1) {
      if (Available_val[img[loc_y * pic_width + loc_x]] && runLength == 0 &&
          !newzero) {
        end = acodec.decode(aEndFlag);
        if (end)
          runLength = 10000000;
        else
          runLength = decGolomb(0, 3);
      }
      if (!runLength) {
        newzero = false;
        get_forbidden_3OT(start_x, start_y, pic_width, pic_height,
                          pre_direction, turn, forbidden, boundary, start_index,
                          high_point, left_point);
        switch (direction1) {
        case 0:
          direction = acodec.decode(a3OT_0, forbidden);
          break;
        case 1:
          direction = acodec.decode(a3OT_1, forbidden);
          break;
        case 2:
          direction = acodec.decode(a3OT_2, forbidden);
          break;
        }
      } else {
        direction =
            get_overlap_3OT(img, pic_height, pic_width, start_y, start_x,
                            pre_direction, turn, Available_val);
        runLength--;
        if (!runLength)
          newzero = true;
      }
      cur_direction = to_direction(pre_direction, direction, &turn);
      direction2 = direction;
    } else if (dir_index == 2) {
      if (Available_val[img[loc_y * pic_width + loc_x]] && runLength == 0 &&
          !newzero) {
        end = acodec.decode(aEndFlag);
        if (end)
          runLength = 10000000;
        else
          runLength = decGolomb(0, 3);
      }
      if (!runLength) {
        newzero = false;
        get_forbidden_3OT(start_x, start_y, pic_width, pic_height,
                          pre_direction, turn, forbidden, boundary, start_index,
                          high_point, left_point);
        switch (direction1 * 3 + direction2) {
        case 0:
          direction = acodec.decode(a3OT_00, forbidden);
          break;
        case 1:
          direction = acodec.decode(a3OT_01, forbidden);
          break;
        case 2:
          direction = acodec.decode(a3OT_02, forbidden);
          break;
        case 3:
          direction = acodec.decode(a3OT_10, forbidden);
          break;
        case 4:
          direction = acodec.decode(a3OT_11, forbidden);
          break;
        case 5:
          direction = acodec.decode(a3OT_12, forbidden);
          break;
        case 6:
          direction = acodec.decode(a3OT_20, forbidden);
          break;
        case 7:
          direction = acodec.decode(a3OT_21, forbidden);
          break;
        case 8:
          direction = acodec.decode(a3OT_22, forbidden);
          break;
        }
      } else {
        direction =
            get_overlap_3OT(img, pic_height, pic_width, start_y, start_x,
                            pre_direction, turn, Available_val);
        runLength--;
        if (!runLength)
          newzero = true;
      }
      cur_direction = to_direction(pre_direction, direction, &turn);
      direction3 = direction;
    } else if (dir_index == 3) {
      if (Available_val[img[loc_y * pic_width + loc_x]] && runLength == 0 &&
          !newzero) {
        end = acodec.decode(aEndFlag);
        if (end)
          runLength = 10000000;
        else
          runLength = decGolomb(0, 3);
      }
      if (!runLength) {
        newzero = false;
        get_forbidden_3OT(start_x, start_y, pic_width, pic_height,
                          pre_direction, turn, forbidden, boundary, start_index,
                          high_point, left_point);
        switch (direction1 * 9 + direction2 * 3 + direction3) {
        case 0:
          direction = acodec.decode(a3OT_000, forbidden);
          break;
        case 1:
          direction = acodec.decode(a3OT_001, forbidden);
          break;
        case 2:
          direction = acodec.decode(a3OT_002, forbidden);
          break;
        case 3:
          direction = acodec.decode(a3OT_010, forbidden);
          break;
        case 4:
          direction = acodec.decode(a3OT_011, forbidden);
          break;
        case 5:
          direction = acodec.decode(a3OT_012, forbidden);
          break;
        case 6:
          direction = acodec.decode(a3OT_020, forbidden);
          break;
        case 7:
          direction = acodec.decode(a3OT_021, forbidden);
          break;
        case 8:
          direction = acodec.decode(a3OT_022, forbidden);
          break;
        case 9:
          direction = acodec.decode(a3OT_100, forbidden);
          break;
        case 10:
          direction = acodec.decode(a3OT_101, forbidden);
          break;
        case 11:
          direction = acodec.decode(a3OT_102, forbidden);
          break;
        case 12:
          direction = acodec.decode(a3OT_110, forbidden);
          break;
        case 13:
          direction = acodec.decode(a3OT_111, forbidden);
          break;
        case 14:
          direction = acodec.decode(a3OT_112, forbidden);
          break;
        case 15:
          direction = acodec.decode(a3OT_120, forbidden);
          break;
        case 16:
          direction = acodec.decode(a3OT_121, forbidden);
          break;
        case 17:
          direction = acodec.decode(a3OT_122, forbidden);
          break;
        case 18:
          direction = acodec.decode(a3OT_200, forbidden);
          break;
        case 19:
          direction = acodec.decode(a3OT_201, forbidden);
          break;
        case 20:
          direction = acodec.decode(a3OT_202, forbidden);
          break;
        case 21:
          direction = acodec.decode(a3OT_210, forbidden);
          break;
        case 22:
          direction = acodec.decode(a3OT_211, forbidden);
          break;
        case 23:
          direction = acodec.decode(a3OT_212, forbidden);
          break;
        case 24:
          direction = acodec.decode(a3OT_220, forbidden);
          break;
        case 25:
          direction = acodec.decode(a3OT_221, forbidden);
          break;
        case 26:
          direction = acodec.decode(a3OT_222, forbidden);
          break;
        }
      } else {
        direction =
            get_overlap_3OT(img, pic_height, pic_width, start_y, start_x,
                            pre_direction, turn, Available_val);
        runLength--;
        if (!runLength)
          newzero = true;
      }
      cur_direction = to_direction(pre_direction, direction, &turn);
      direction4 = direction;
    } else {
      if (Available_val[img[loc_y * pic_width + loc_x]] && runLength == 0 &&
          !newzero) {
        end = acodec.decode(aEndFlag);
        if (end)
          runLength = 10000000;
        else
          runLength = decGolomb(0, 3);
      }
      if (!runLength) {
        newzero = false;
        get_forbidden_3OT(start_x, start_y, pic_width, pic_height,
                          pre_direction, turn, forbidden, boundary, start_index,
                          high_point, left_point);
        switch (direction1 * 27 + direction2 * 9 + direction3 * 3 +
                direction4) {
        case 0:
          direction = acodec.decode(a3OT_0000, forbidden);
          break;
        case 1:
          direction = acodec.decode(a3OT_0001, forbidden);
          break;
        case 2:
          direction = acodec.decode(a3OT_0002, forbidden);
          break;
        case 3:
          direction = acodec.decode(a3OT_0010, forbidden);
          break;
        case 4:
          direction = acodec.decode(a3OT_0011, forbidden);
          break;
        case 5:
          direction = acodec.decode(a3OT_0012, forbidden);
          break;
        case 6:
          direction = acodec.decode(a3OT_0020, forbidden);
          break;
        case 7:
          direction = acodec.decode(a3OT_0021, forbidden);
          break;
        case 8:
          direction = acodec.decode(a3OT_0022, forbidden);
          break;
        case 9:
          direction = acodec.decode(a3OT_0100, forbidden);
          break;
        case 10:
          direction = acodec.decode(a3OT_0101, forbidden);
          break;
        case 11:
          direction = acodec.decode(a3OT_0102, forbidden);
          break;
        case 12:
          direction = acodec.decode(a3OT_0110, forbidden);
          break;
        case 13:
          direction = acodec.decode(a3OT_0111, forbidden);
          break;
        case 14:
          direction = acodec.decode(a3OT_0112, forbidden);
          break;
        case 15:
          direction = acodec.decode(a3OT_0120, forbidden);
          break;
        case 16:
          direction = acodec.decode(a3OT_0121, forbidden);
          break;
        case 17:
          direction = acodec.decode(a3OT_0122, forbidden);
          break;
        case 18:
          direction = acodec.decode(a3OT_0200, forbidden);
          break;
        case 19:
          direction = acodec.decode(a3OT_0201, forbidden);
          break;
        case 20:
          direction = acodec.decode(a3OT_0202, forbidden);
          break;
        case 21:
          direction = acodec.decode(a3OT_0210, forbidden);
          break;
        case 22:
          direction = acodec.decode(a3OT_0211, forbidden);
          break;
        case 23:
          direction = acodec.decode(a3OT_0212, forbidden);
          break;
        case 24:
          direction = acodec.decode(a3OT_0220, forbidden);
          break;
        case 25:
          direction = acodec.decode(a3OT_0221, forbidden);
          break;
        case 26:
          direction = acodec.decode(a3OT_0222, forbidden);
          break;
        case 27:
          direction = acodec.decode(a3OT_1000, forbidden);
          break;
        case 28:
          direction = acodec.decode(a3OT_1001, forbidden);
          break;
        case 29:
          direction = acodec.decode(a3OT_1002, forbidden);
          break;
        case 30:
          direction = acodec.decode(a3OT_1010, forbidden);
          break;
        case 31:
          direction = acodec.decode(a3OT_1011, forbidden);
          break;
        case 32:
          direction = acodec.decode(a3OT_1012, forbidden);
          break;
        case 33:
          direction = acodec.decode(a3OT_1020, forbidden);
          break;
        case 34:
          direction = acodec.decode(a3OT_1021, forbidden);
          break;
        case 35:
          direction = acodec.decode(a3OT_1022, forbidden);
          break;
        case 36:
          direction = acodec.decode(a3OT_1100, forbidden);
          break;
        case 37:
          direction = acodec.decode(a3OT_1101, forbidden);
          break;
        case 38:
          direction = acodec.decode(a3OT_1102, forbidden);
          break;
        case 39:
          direction = acodec.decode(a3OT_1110, forbidden);
          break;
        case 40:
          direction = acodec.decode(a3OT_1111, forbidden);
          break;
        case 41:
          direction = acodec.decode(a3OT_1112, forbidden);
          break;
        case 42:
          direction = acodec.decode(a3OT_1120, forbidden);
          break;
        case 43:
          direction = acodec.decode(a3OT_1121, forbidden);
          break;
        case 44:
          direction = acodec.decode(a3OT_1122, forbidden);
          break;
        case 45:
          direction = acodec.decode(a3OT_1200, forbidden);
          break;
        case 46:
          direction = acodec.decode(a3OT_1201, forbidden);
          break;
        case 47:
          direction = acodec.decode(a3OT_1202, forbidden);
          break;
        case 48:
          direction = acodec.decode(a3OT_1210, forbidden);
          break;
        case 49:
          direction = acodec.decode(a3OT_1211, forbidden);
          break;
        case 50:
          direction = acodec.decode(a3OT_1212, forbidden);
          break;
        case 51:
          direction = acodec.decode(a3OT_1220, forbidden);
          break;
        case 52:
          direction = acodec.decode(a3OT_1221, forbidden);
          break;
        case 53:
          direction = acodec.decode(a3OT_1222, forbidden);
          break;
        case 54:
          direction = acodec.decode(a3OT_2000, forbidden);
          break;
        case 55:
          direction = acodec.decode(a3OT_2001, forbidden);
          break;
        case 56:
          direction = acodec.decode(a3OT_2002, forbidden);
          break;
        case 57:
          direction = acodec.decode(a3OT_2010, forbidden);
          break;
        case 58:
          direction = acodec.decode(a3OT_2011, forbidden);
          break;
        case 59:
          direction = acodec.decode(a3OT_2012, forbidden);
          break;
        case 60:
          direction = acodec.decode(a3OT_2020, forbidden);
          break;
        case 61:
          direction = acodec.decode(a3OT_2021, forbidden);
          break;
        case 62:
          direction = acodec.decode(a3OT_2022, forbidden);
          break;
        case 63:
          direction = acodec.decode(a3OT_2100, forbidden);
          break;
        case 64:
          direction = acodec.decode(a3OT_2101, forbidden);
          break;
        case 65:
          direction = acodec.decode(a3OT_2102, forbidden);
          break;
        case 66:
          direction = acodec.decode(a3OT_2110, forbidden);
          break;
        case 67:
          direction = acodec.decode(a3OT_2111, forbidden);
          break;
        case 68:
          direction = acodec.decode(a3OT_2112, forbidden);
          break;
        case 69:
          direction = acodec.decode(a3OT_2120, forbidden);
          break;
        case 70:
          direction = acodec.decode(a3OT_2121, forbidden);
          break;
        case 71:
          direction = acodec.decode(a3OT_2122, forbidden);
          break;
        case 72:
          direction = acodec.decode(a3OT_2200, forbidden);
          break;
        case 73:
          direction = acodec.decode(a3OT_2201, forbidden);
          break;
        case 74:
          direction = acodec.decode(a3OT_2202, forbidden);
          break;
        case 75:
          direction = acodec.decode(a3OT_2210, forbidden);
          break;
        case 76:
          direction = acodec.decode(a3OT_2211, forbidden);
          break;
        case 77:
          direction = acodec.decode(a3OT_2212, forbidden);
          break;
        case 78:
          direction = acodec.decode(a3OT_2220, forbidden);
          break;
        case 79:
          direction = acodec.decode(a3OT_2221, forbidden);
          break;
        case 80:
          direction = acodec.decode(a3OT_2222, forbidden);
          break;
        }
      } else {
        direction =
            get_overlap_3OT(img, pic_height, pic_width, start_y, start_x,
                            pre_direction, turn, Available_val);
        runLength--;
        if (!runLength)
          newzero = true;
      }
      cur_direction = to_direction(pre_direction, direction, &turn);
      direction1 = direction2;
      direction2 = direction3;
      direction3 = direction4;
      direction4 = direction;
    }
    dir_index++;

    // if (initial_loc_y == 5 && initial_loc_x == 197)
    //{
    //	if (direction == 5 && pre_direction == 13)
    //		printf("haha");
    //		//printf("%d\n", direction);
    //	pre_direction = direction;
    // }
    switch (cur_direction) {
    case 0:
      start_x++;
      codedMap[(start_y - 1) * pic_width + start_x - 1] = -1;
      break;
    case 1:
      start_y--;
      codedMap[start_y * pic_width + start_x - 1] = -1;
      break;
    case 2:
      start_x--;
      codedMap[start_y * pic_width + start_x] = -1;
      break;
    case 3:
      start_y++;
      codedMap[(start_y - 1) * pic_width + start_x] = -1;
      break;
    }

    // printf("%d ", cur_direction);

    if (start_x == 0 || start_x == pic_width || start_y == 0 ||
        start_y == pic_height)
      break;
    if (!boundary && (start_x == end_x && start_y == end_y))
      break;

    pre_direction = cur_direction;

    switch (cur_direction) {
    case 0:
      loc_y = start_y - 1;
      loc_x = start_x - 1;
      break;
    case 1:
      loc_y = start_y;
      loc_x = start_x - 1;
      break;
    case 2:
      loc_y = start_y;
      loc_x = start_x;
      break;
    case 3:
      loc_y = start_y - 1;
      loc_x = start_x;
      break;
    }

    // encCodedMap[start_y*pic_width + start_x] = 1;

  } while (1);

  // printf("\n");

  decObjectExpand(img, pic_height, pic_width, initial_loc_y, initial_loc_x,
                  color);
}

void deObjectEdge(unsigned char *img, int pic_height, int pic_width) {
  int old_val = 0, new_val;
  int initial_loc_y = 0, initial_loc_x = 0, loc_y, loc_x, first_y, first_x;
  int color;
  int direction, dir_last, dir_index, direction1, direction2, direction_index,
      direction1_candi1, direction1_candi2;
  int start_index;
  int Available_val[256];
  int runLength;
  bool end;
  bool newzero = false;

  for (int i = 0; i < edge_num + inner_num; i++) {
    color = acodec.decode(aColor);

    if (i == edge_num)
      old_val = pic_width - 2 - 1;
    new_val = decGolomb(0, position_K) + old_val + 1;

    position_A += new_val - old_val - 1;
    position_N += 1;
    position_K = getBitSize(position_A / (2 * position_N));
    if (position_N >= 8) {
      position_N /= 2;
      position_A /= 2;
    }

    old_val = new_val;

    if (i < edge_num)
      dec_edge_position(&initial_loc_y, &initial_loc_x, pic_height, pic_width,
                        new_val);
    else {
      initial_loc_y = new_val / (pic_width - 2);
      initial_loc_x = new_val - initial_loc_y * (pic_width - 2) + 1;
    }

    // printf("%d %d\n", initial_loc_y, initial_loc_x);

    if (chain_mode == 0)
      deObjectEdge_MSC(img, pic_height, pic_width, initial_loc_y, initial_loc_x,
                       color);
    else if (chain_mode == 1)
      deObjectEdge_3OT(img, pic_height, pic_width, initial_loc_y, initial_loc_x,
                       color);
    else if (chain_mode == 2) {
      int chainType = acodec.decode(aChainType);
      if (chainType == 0)
        deObjectEdge_MSC(img, pic_height, pic_width, initial_loc_y,
                         initial_loc_x, color);
      else if (chainType == 1)
        deObjectEdge_3OT(img, pic_height, pic_width, initial_loc_y,
                         initial_loc_x, color);
    }
  }
}

int main(int argc, char **argv) {
  int begin, end;
  begin = clock();

  char filein[1000];
  char fileout[1000];
  readOptions(argc, argv, filein, fileout);
  FILE *pFile;
  int size;
  fopen_s(&pFile, filein, "rb");
  size = getFSize(pFile);
  unsigned char *buffer = new unsigned char[size];
  fread(buffer, 1, size, pFile);
  fclose(pFile);

  acodec.set_buffer(10000000, buffer);
  acodec.start_decoder();

  int pic_height = readByArithmetic(&acodec, &ahead, 16);
  int pic_width = readByArithmetic(&acodec, &ahead, 16);
  int frameNum = readByArithmetic(&acodec, &ahead, 16);
  int type = acodec.decode(ahead);

  numC = readByArithmetic(&acodec, &ahead, 8);

  int *m_colorMap = new int[numC];

  for (int i = 0; i < numC; i++) {
    m_colorMap[i] = readByArithmetic(&acodec, &ahead, 8);
  }

  unsigned char *pic =
      new unsigned char[(pic_height * pic_width * frameNum * (type + 2)) >> 1];
  for (int i = 0; i < (pic_height * pic_width * frameNum * (type + 2)) >> 1;
       i++)
    pic[i] = 0;

  if (numC == 1) {
    int color = m_colorMap[0];
    for (int k = 0; k < frameNum; k++) {
      int offset = (pic_height * pic_width * k * (type + 2)) >> 1;
      for (int i = 0; i < pic_height; i++) {
        for (int j = 0; j < pic_width; j++) {
          pic[offset + i * pic_width + j] = color;
        }
      }
    }
    acodec.stop_decoder();
    write2bin(pic, pic_width * (pic_height * frameNum * (type + 2)) >> 1,
              fileout);
    end = clock();
    cout << "time: " << (end - begin) / 1000.0 << " sec" << endl;
    delete[] buffer;
    return 0;
  }

  aColor.set_alphabet(numC);
  codedMap = new int[pic_height * pic_width];
  encCodedMap = new int[pic_height * pic_width];
  unsigned char *slice = pic;
  for (int i = 0; i < frameNum; i++) {
    for (int j = 0; j < pic_height * pic_width; j++)
      slice[j] = 255;
    aColor.reset();
    aflag.reset();
    aGolomb.reset();
    edge_num = decGolomb(0, 1);
    inner_num = decGolomb(0, 3);
    first_color = acodec.decode(aColor);
    if (edge_num + inner_num > 0) {
      dec_global();
      reset_arithmetic();
      deObjectEdge(slice, pic_height, pic_width);
    }

    advancedExpand(slice, pic_height, pic_width, first_color, 0, 0);

    slice += (pic_height * pic_width * (type + 2)) >> 1;
  }
  acodec.stop_decoder();

  int offset = (pic_height * pic_width * (type + 2)) >> 1;
  for (int k = 0; k < frameNum; k++) {
    for (int i = 0; i < pic_height; i++) {
      for (int j = 0; j < pic_width; j++) {
        pic[k * offset + i * pic_width + j] =
            m_colorMap[pic[k * offset + i * pic_width + j]];
      }
    }
  }

  end = clock();
  cout << "time: " << (end - begin) / 1000.0 << " sec" << endl;

  write2bin(pic, pic_width * (pic_height * frameNum * (type + 2)) >> 1,
            fileout);

  delete[] buffer;
  delete[] codedMap;
  delete[] encCodedMap;
  return 0;
}