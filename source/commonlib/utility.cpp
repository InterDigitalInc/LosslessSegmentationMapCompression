#include "utility.h"
#include "coding_unit.h"
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

void advancedExpand(unsigned char *img, int height, int width, int color1,
                    int color2_y, int color2_x) {
  unsigned short indexStack[10000];
  int color2 = img[color2_y * width + color2_x];
  bool reachLeft = false;
  bool reachRight = false;
  int p = 0;
  while (color2_y >= 0 && img[color2_y * width + color2_x] == color2) {
    color2_y--;
  }
  indexStack[p++] = color2_y + 1;
  indexStack[p++] = color2_x;
  while (p > 0) {
    color2_x = indexStack[--p];
    color2_y = indexStack[--p];
    while (color2_y >= 0 && img[color2_y * width + color2_x] == color2) {
      color2_y--;
    }
    color2_y++;
    reachLeft = false;
    reachRight = false;
    for (int y = color2_y; y < height; y++) {
      if (img[y * width + color2_x] != color2)
        break;
      img[y * width + color2_x] = color1;
      if (color2_x > 0) {
        if (!reachLeft && img[y * width + color2_x - 1] == color2) {
          reachLeft = true;
          indexStack[p++] = y;
          indexStack[p++] = color2_x - 1;
        } else if (reachLeft && img[y * width + color2_x - 1] != color2) {
          reachLeft = false;
        }
      }
      if (color2_x < width - 1) {
        if (!reachRight && img[y * width + color2_x + 1] == color2) {
          reachRight = true;
          indexStack[p++] = y;
          indexStack[p++] = color2_x + 1;
        } else if (reachRight && img[y * width + color2_x + 1] != color2) {
          reachRight = false;
        }
      }
    }
  }
}

void objectExpand(unsigned char *img, int height, int width, int color2_y,
                  int color2_x, int color) {
  unsigned short indexStack[10000];
  int color2 = img[color2_y * width + color2_x];
  bool reachLeft = false;
  bool reachRight = false;
  int p = 0;
  while (color2_y >= 0 && img[color2_y * width + color2_x] == color2) {
    color2_y--;
  }
  indexStack[p++] = color2_y + 1;
  indexStack[p++] = color2_x;
  while (p > 0) {
    color2_x = indexStack[--p];
    color2_y = indexStack[--p];
    while (color2_y >= 0 && img[color2_y * width + color2_x] == color2 &&
           !codedMap[color2_y * width + color2_x]) {
      color2_y--;
    }
    color2_y++;
    reachLeft = false;
    reachRight = false;
    for (int y = color2_y; y < height; y++) {
      if (img[y * width + color2_x] != color2 || codedMap[y * width + color2_x])
        break;
      codedMap[y * width + color2_x] = color;
      if (color2_x > 0) {
        if (!reachLeft && img[y * width + color2_x - 1] == color2 &&
            !codedMap[y * width + color2_x - 1]) {
          reachLeft = true;
          indexStack[p++] = y;
          indexStack[p++] = color2_x - 1;
        } else if (reachLeft && img[y * width + color2_x - 1] != color2) {
          reachLeft = false;
        }
      }
      if (color2_x < width - 1) {
        if (!reachRight && img[y * width + color2_x + 1] == color2 &&
            !codedMap[y * width + color2_x + 1]) {
          reachRight = true;
          indexStack[p++] = y;
          indexStack[p++] = color2_x + 1;
        } else if (reachRight && img[y * width + color2_x + 1] != color2) {
          reachRight = false;
        }
      }
    }
  }
}

void decObjectExpand(unsigned char *img, int height, int width, int color2_y,
                     int color2_x, int color) {
  unsigned short indexStack[10000];
  int color2 = codedMap[color2_y * width + color2_x];
  bool reachLeft = false;
  bool reachRight = false;
  int p = 0;
  while (color2_y >= 0 && codedMap[color2_y * width + color2_x] == color2) {
    color2_y--;
  }
  indexStack[p++] = color2_y + 1;
  indexStack[p++] = color2_x;
  while (p > 0) {
    color2_x = indexStack[--p];
    color2_y = indexStack[--p];
    while (color2_y >= 0 && codedMap[color2_y * width + color2_x] == color2) {
      color2_y--;
    }
    color2_y++;
    reachLeft = false;
    reachRight = false;
    for (int y = color2_y; y < height; y++) {
      if (codedMap[y * width + color2_x] != color2)
        break;
      img[y * width + color2_x] = color;
      codedMap[y * width + color2_x] = color;
      if (color2_x > 0) {
        if (!reachLeft && codedMap[y * width + color2_x - 1] == color2) {
          reachLeft = true;
          indexStack[p++] = y;
          indexStack[p++] = color2_x - 1;
        } else if (reachLeft && codedMap[y * width + color2_x - 1] != color2) {
          reachLeft = false;
        }
      }
      if (color2_x < width - 1) {
        if (!reachRight && codedMap[y * width + color2_x + 1] == color2) {
          reachRight = true;
          indexStack[p++] = y;
          indexStack[p++] = color2_x + 1;
        } else if (reachRight && codedMap[y * width + color2_x + 1] != color2) {
          reachRight = false;
        }
      }
    }
  }
}

void encObjectExpand(unsigned char *img, int height, int width, int color2_y,
                     int color2_x, int color) {
  unsigned short indexStack[10000];
  int color2 = encCodedMap[color2_y * width + color2_x];
  bool reachLeft = false;
  bool reachRight = false;
  int p = 0;
  while (color2_y >= 0 && encCodedMap[color2_y * width + color2_x] == color2) {
    color2_y--;
  }
  indexStack[p++] = color2_y + 1;
  indexStack[p++] = color2_x;
  while (p > 0) {
    color2_x = indexStack[--p];
    color2_y = indexStack[--p];
    while (color2_y >= 0 &&
           encCodedMap[color2_y * width + color2_x] == color2) {
      color2_y--;
    }
    color2_y++;
    reachLeft = false;
    reachRight = false;
    for (int y = color2_y; y < height; y++) {
      if (encCodedMap[y * width + color2_x] != color2)
        break;
      img[y * width + color2_x] = color;
      encCodedMap[y * width + color2_x] = color;
      if (color2_x > 0) {
        if (!reachLeft && encCodedMap[y * width + color2_x - 1] == color2) {
          reachLeft = true;
          indexStack[p++] = y;
          indexStack[p++] = color2_x - 1;
        } else if (reachLeft &&
                   encCodedMap[y * width + color2_x - 1] != color2) {
          reachLeft = false;
        }
      }
      if (color2_x < width - 1) {
        if (!reachRight && encCodedMap[y * width + color2_x + 1] == color2) {
          reachRight = true;
          indexStack[p++] = y;
          indexStack[p++] = color2_x + 1;
        } else if (reachRight &&
                   encCodedMap[y * width + color2_x + 1] != color2) {
          reachRight = false;
        }
      }
    }
  }
}

int getBitSize(int num) {
  for (int i = 24; i >= 0; i--) {
    if (((num - 1) >> i) & 1)
      return i + 1;
  }
  return 0;
}

void encGolomb(int absV, int mode, int k) // 0: 0+  1:-0+  2:-+
{
  if (mode == 1) {
    if (absV > 0)
      absV = (absV - 1) * 2 + 1;
    else if (absV < 0)
      absV = -absV * 2;
  } else if (mode == 2) {
    if (absV > 0)
      absV = (absV - 1) * 2;
    else if (absV < 0)
      absV = -absV * 2 - 1;
  }
  int stopLoop = 0;
  do {
    if (absV >= (1 << k)) {
      acodec.encode(1, aGolomb);
      absV = absV - (1 << k);
      k++;
    } else {
      acodec.encode(0, aGolomb);
      while (k--)
        acodec.encode(((absV >> k) & 1), aGolomb);
      stopLoop = 1;
    }
  } while (!stopLoop);
}

float GolombBits(int absV, int mode, int k) // 0: 0+  1:-0+  2:-+
{
  float rate = 0;
  if (mode == 1) {
    if (absV > 0)
      absV = (absV - 1) * 2 + 1;
    else if (absV < 0)
      absV = -absV * 2;
  } else if (mode == 2) {
    if (absV > 0)
      absV = (absV - 1) * 2;
    else if (absV < 0)
      absV = -absV * 2 - 1;
  }
  int stopLoop = 0;
  do {
    if (absV >= (1 << k)) {
      rate += 1;
      absV = absV - (1 << k);
      k++;
    } else {
      rate += 1;
      while (k--)
        rate += 1;
      stopLoop = 1;
    }
  } while (!stopLoop);
  return rate;
}

int decGolomb(int mode, int k) {
  int absV1 = 0;
  int absV2 = 0;
  while (acodec.decode(aGolomb)) {
    absV1 += (1 << k);
    k++;
  }
  for (int i = 0; i < k; i++) {
    absV2 = 2 * absV2 + acodec.decode(aGolomb);
  }
  int absV = absV1 + absV2;
  if (mode == 1) {
    if (absV % 2 == 0)
      absV = -absV / 2;
    else
      absV = (absV + 1) / 2;
  } else if (mode == 2) {
    if (absV % 2 == 0)
      absV = absV / 2;
    else
      absV = (-absV - 1) / 2;
  }
  return absV;
}

void writeByArithmetic(Arithmetic_Codec *ace, Adaptive_Bit_Model *bit,
                       int output, int num) {
  for (int i = num; i > 0; i--) {
    int outBit = (output >> (i - 1)) & 1;
    ace->encode(outBit, *bit);
  }
}

int readByArithmetic(Arithmetic_Codec *acd, Adaptive_Bit_Model *bit, int num) {
  int output = 0;
  for (int i = 0; i < num; i++) {
    output = (output << 1) + acd->decode(*bit);
  }
  return output;
}

void write2bin(unsigned char *p, int size, char *file_name) {
  FILE *fid = openFile(file_name, "wb");
  if (fid == nullptr) {
    return;
  }
  fwrite(p, sizeof(unsigned char), size, fid);
  fclose(fid);
}

int getFSize(FILE *pFile) {
  int size;
  fseek(pFile, 0, SEEK_END);
  size = ftell(pFile);
  fseek(pFile, 0, SEEK_SET);
  return size;
}

int get_MSC(int direction1, int direction2, int direction3, int *num) {
  if (direction1 == 0 && direction2 == 0 && direction3 == 0) {
    *num = 3;
    return 24;
  } else if (direction1 == 1 && direction2 == 0 && direction3 == 0) {
    *num = 3;
    return 25;
  } else if (direction1 == 2 && direction2 == 2 && direction3 == 1) {
    *num = 3;
    return 26;
  } else if (direction1 == 2 && direction2 == 2 && direction3 == 2) {
    *num = 3;
    return 27;
  } else if (direction1 == 3 && direction2 == 2 && direction3 == 2) {
    *num = 3;
    return 28;
  } else if (direction1 == 4 && direction2 == 4 && direction3 == 3) {
    *num = 3;
    return 29;
  } else if (direction1 == 4 && direction2 == 4 && direction3 == 4) {
    *num = 3;
    return 30;
  } else if (direction1 == 5 && direction2 == 4 && direction3 == 4) {
    *num = 3;
    return 31;
  } else if (direction1 == 6 && direction2 == 6 && direction3 == 5) {
    *num = 3;
    return 32;
  } else if (direction1 == 6 && direction2 == 6 && direction3 == 6) {
    *num = 3;
    return 33;
  } else if (direction1 == 7 && direction2 == 6 && direction3 == 6) {
    *num = 3;
    return 34;
  } else if (direction1 == 0 && direction2 == 0 && direction3 == 7) {
    *num = 3;
    return 35;
  } else if (direction1 == 0 && direction2 == 0) {
    *num = 2;
    return 8;
  } else if (direction1 == 1 && direction2 == 0) {
    *num = 2;
    return 9;
  } else if (direction1 == 1 && direction2 == 1) {
    *num = 2;
    return 10;
  } else if (direction1 == 2 && direction2 == 1) {
    *num = 2;
    return 11;
  } else if (direction1 == 2 && direction2 == 2) {
    *num = 2;
    return 12;
  } else if (direction1 == 3 && direction2 == 2) {
    *num = 2;
    return 13;
  } else if (direction1 == 3 && direction2 == 3) {
    *num = 2;
    return 14;
  } else if (direction1 == 4 && direction2 == 3) {
    *num = 2;
    return 15;
  } else if (direction1 == 4 && direction2 == 4) {
    *num = 2;
    return 16;
  } else if (direction1 == 5 && direction2 == 4) {
    *num = 2;
    return 17;
  } else if (direction1 == 5 && direction2 == 5) {
    *num = 2;
    return 18;
  } else if (direction1 == 6 && direction2 == 5) {
    *num = 2;
    return 19;
  } else if (direction1 == 6 && direction2 == 6) {
    *num = 2;
    return 20;
  } else if (direction1 == 7 && direction2 == 6) {
    *num = 2;
    return 21;
  } else if (direction1 == 7 && direction2 == 7) {
    *num = 2;
    return 22;
  } else if (direction1 == 0 && direction2 == 7) {
    *num = 2;
    return 23;
  } else if (direction1 == 0) {
    *num = 1;
    return 0;
  } else if (direction1 == 1) {
    *num = 1;
    return 1;
  } else if (direction1 == 2) {
    *num = 1;
    return 2;
  } else if (direction1 == 3) {
    *num = 1;
    return 3;
  } else if (direction1 == 4) {
    *num = 1;
    return 4;
  } else if (direction1 == 5) {
    *num = 1;
    return 5;
  } else if (direction1 == 6) {
    *num = 1;
    return 6;
  } else if (direction1 == 7) {
    *num = 1;
    return 7;
  }
}

int get_3OT(int direction1, int direction2, int *direction_list, int *num,
            int *start_x, int *start_y, int end_x, int end_y, int pic_width,
            int pic_height, bool boundary) {
  if (!boundary && ((*start_x) == end_x && (*start_y) == end_y))
    return 0;
  if (direction1 == 0 || direction1 == 1) {
    switch (direction2) {
    case 7:
      (*start_y)++;
      direction_list[(*num)++] = 3;
      break;
    case 0:
      (*start_x)++;
      direction_list[(*num)++] = 0;
      break;
    case 1:
      (*start_y)--;
      direction_list[(*num)++] = 1;
      if ((*start_y) > 0) {
        (*start_x)++;
        direction_list[(*num)++] = 0;
      }
      break;
    case 2:
      (*start_y)--;
      direction_list[(*num)++] = 1;
      if (boundary || !((*start_x) == end_x && (*start_y) == end_y)) {
        (*start_y)--;
        direction_list[(*num)++] = 1;
      }
      break;
    case 3:
      (*start_y) -= 1;
      direction_list[(*num)++] = 1;
      (*start_x)--;
      direction_list[(*num)++] = 2;
      if (boundary || !((*start_x) == end_x && (*start_y) == end_y)) {
        (*start_y) -= 1;
        direction_list[(*num)++] = 1;
      }
      break;
    case 4:
      (*start_y)--;
      direction_list[(*num)++] = 1;
      (*start_x) -= 2;
      direction_list[(*num)++] = 2;
      direction_list[(*num)++] = 2;
      break;
    }
  } else if (direction1 == 2 || direction1 == 3) {
    switch (direction2) {
    case 1:
      (*start_x)++;
      direction_list[(*num)++] = 0;
      break;
    case 2:
      (*start_y)--;
      direction_list[(*num)++] = 1;
      break;
    case 3:
      (*start_x)--;
      direction_list[(*num)++] = 2;
      if ((*start_x) > 0 &&
          (boundary || !((*start_x) == end_x && (*start_y) == end_y))) {
        (*start_y)--;
        direction_list[(*num)++] = 1;
      }
      break;
    case 4:
      (*start_x) -= 2;
      direction_list[(*num)++] = 2;
      direction_list[(*num)++] = 2;
      break;
    case 5:
      (*start_x) -= 2;
      direction_list[(*num)++] = 2;
      (*start_y)++;
      direction_list[(*num)++] = 3;
      direction_list[(*num)++] = 2;
      break;
    case 6:
      (*start_x)--;
      direction_list[(*num)++] = 2;
      (*start_y) += 2;
      direction_list[(*num)++] = 3;
      direction_list[(*num)++] = 3;
      break;
    }
  } else if (direction1 == 4 || direction1 == 5) {
    switch (direction2) {
    case 3:
      (*start_y)--;
      direction_list[(*num)++] = 1;
      break;
    case 4:
      (*start_x)--;
      direction_list[(*num)++] = 2;
      break;
    case 5:
      (*start_y)++;
      direction_list[(*num)++] = 3;
      if ((*start_y) < pic_height) {
        (*start_x)--;
        direction_list[(*num)++] = 2;
      }
      break;
    case 6:
      (*start_y) += 2;
      direction_list[(*num)++] = 3;
      direction_list[(*num)++] = 3;
      break;
    case 7:
      (*start_y) += 2;
      direction_list[(*num)++] = 3;
      (*start_x)++;
      direction_list[(*num)++] = 0;
      direction_list[(*num)++] = 3;
      break;
    case 0:
      (*start_y)++;
      direction_list[(*num)++] = 3;
      (*start_x) += 2;
      direction_list[(*num)++] = 0;
      direction_list[(*num)++] = 0;
      break;
    }
  } else if (direction1 == 6 || direction1 == 7) {
    switch (direction2) {
    case 5:
      (*start_x)--;
      direction_list[(*num)++] = 2;
      break;
    case 6:
      (*start_y)++;
      direction_list[(*num)++] = 3;
      break;
    case 7:
      (*start_x)++;
      direction_list[(*num)++] = 0;
      if ((*start_x) < pic_width) {
        (*start_y)++;
        direction_list[(*num)++] = 3;
      }
      break;
    case 0:
      (*start_x) += 2;
      direction_list[(*num)++] = 0;
      direction_list[(*num)++] = 0;
      break;
    case 1:
      (*start_x) += 2;
      direction_list[(*num)++] = 0;
      (*start_y)--;
      direction_list[(*num)++] = 1;
      direction_list[(*num)++] = 0;
      break;
    case 2:
      (*start_x)++;
      direction_list[(*num)++] = 0;
      (*start_y) -= 1;
      direction_list[(*num)++] = 1;
      if (!boundary && ((*start_x) == end_x && (*start_y) == end_y))
        return 0;
      (*start_y) -= 1;
      direction_list[(*num)++] = 1;
      break;
    }
  }
}

int get_direction1(int direction, int *index) {
  if (direction == 0 || direction == 1 || direction == 11 || direction == 26 ||
      direction == 8 || direction == 9 || direction == 10 || direction == 24 ||
      direction == 25)
    *index = 0;
  else if (direction == 2 || direction == 3 || direction == 15 ||
           direction == 29 || direction == 12 || direction == 13 ||
           direction == 14 || direction == 27 || direction == 28)
    *index = 1;
  else if (direction == 4 || direction == 5 || direction == 19 ||
           direction == 32 || direction == 16 || direction == 17 ||
           direction == 18 || direction == 30 || direction == 31)
    *index = 2;
  else if (direction == 6 || direction == 7 || direction == 23 ||
           direction == 35 || direction == 20 || direction == 21 ||
           direction == 22 || direction == 33 || direction == 34)
    *index = 3;
  if (direction == 0 || direction == 2 || direction == 4 || direction == 6)
    return 0;
  else if (direction == 1 || direction == 3 || direction == 5 || direction == 7)
    return 1;
  else if (direction == 11 || direction == 15 || direction == 19 ||
           direction == 23)
    return 2;
  else if (direction == 26 || direction == 29 || direction == 32 ||
           direction == 35)
    return 3;
  else if (direction == 8 || direction == 12 || direction == 16 ||
           direction == 20)
    return 4;
  else if (direction == 9 || direction == 13 || direction == 17 ||
           direction == 21)
    return 5;
  else if (direction == 10 || direction == 14 || direction == 18 ||
           direction == 22)
    return 6;
  else if (direction == 24 || direction == 27 || direction == 30 ||
           direction == 33)
    return 7;
  else if (direction == 25 || direction == 28 || direction == 31 ||
           direction == 34)
    return 8;
}

int get_RMSC(int index, int direction) {
  if ((index == 0 && direction == 0) || (index == 1 && direction == 2) ||
      (index == 2 && direction == 4) || (index == 3 && direction == 6))
    return 0;
  else if ((index == 0 && direction == 1) || (index == 1 && direction == 3) ||
           (index == 2 && direction == 5) || (index == 3 && direction == 7))
    return 1;
  else if ((index == 0 && direction == 11) || (index == 1 && direction == 15) ||
           (index == 2 && direction == 19) || (index == 3 && direction == 23))
    return 2;
  else if ((index == 0 && direction == 26) || (index == 1 && direction == 29) ||
           (index == 2 && direction == 32) || (index == 3 && direction == 35))
    return 3;
  else if ((index == 0 && direction == 8) || (index == 1 && direction == 12) ||
           (index == 2 && direction == 16) || (index == 3 && direction == 20))
    return 4;
  else if ((index == 0 && direction == 9) || (index == 1 && direction == 13) ||
           (index == 2 && direction == 17) || (index == 3 && direction == 21))
    return 5;
  else if ((index == 0 && direction == 10) || (index == 1 && direction == 14) ||
           (index == 2 && direction == 18) || (index == 3 && direction == 22))
    return 6;
  else if ((index == 0 && direction == 24) || (index == 1 && direction == 27) ||
           (index == 2 && direction == 30) || (index == 3 && direction == 33))
    return 7;
  else if ((index == 0 && direction == 25) || (index == 1 && direction == 28) ||
           (index == 2 && direction == 31) || (index == 3 && direction == 34))
    return 8;
  else if ((index == 0 && direction == 2) || (index == 1 && direction == 4) ||
           (index == 2 && direction == 6) || (index == 3 && direction == 0))
    return 9;
  else if ((index == 0 && direction == 12) || (index == 1 && direction == 16) ||
           (index == 2 && direction == 20) || (index == 3 && direction == 8))
    return 10;
  else if ((index == 0 && direction == 27) || (index == 1 && direction == 30) ||
           (index == 2 && direction == 33) || (index == 3 && direction == 24))
    return 11;
  else if ((index == 0 && direction == 4) || (index == 1 && direction == 6) ||
           (index == 2 && direction == 0) || (index == 3 && direction == 2))
    return 12;
  else if ((index == 0 && direction == 3) || (index == 1 && direction == 5) ||
           (index == 2 && direction == 7) || (index == 3 && direction == 1))
    return 13;
  else if ((index == 0 && direction == 13) || (index == 1 && direction == 17) ||
           (index == 2 && direction == 21) || (index == 3 && direction == 9))
    return 14;
  else if ((index == 0 && direction == 28) || (index == 1 && direction == 31) ||
           (index == 2 && direction == 34) || (index == 3 && direction == 25))
    return 15;
  else if ((index == 0 && direction == 16) || (index == 1 && direction == 20) ||
           (index == 2 && direction == 8) || (index == 3 && direction == 12))
    return 16;
  else if ((index == 0 && direction == 15) || (index == 1 && direction == 19) ||
           (index == 2 && direction == 23) || (index == 3 && direction == 11))
    return 17;
  else if ((index == 0 && direction == 14) || (index == 1 && direction == 18) ||
           (index == 2 && direction == 22) || (index == 3 && direction == 10))
    return 18;
  else if ((index == 0 && direction == 30) || (index == 1 && direction == 33) ||
           (index == 2 && direction == 24) || (index == 3 && direction == 27))
    return 19;
  else if ((index == 0 && direction == 29) || (index == 1 && direction == 32) ||
           (index == 2 && direction == 35) || (index == 3 && direction == 26))
    return 20;
  else if ((index == 0 && direction == 7) || (index == 1 && direction == 1) ||
           (index == 2 && direction == 3) || (index == 3 && direction == 5))
    return 21;
  else if ((index == 0 && direction == 21) || (index == 1 && direction == 9) ||
           (index == 2 && direction == 13) || (index == 3 && direction == 17))
    return 22;
  else if ((index == 0 && direction == 34) || (index == 1 && direction == 25) ||
           (index == 2 && direction == 28) || (index == 3 && direction == 31))
    return 23;
  else if ((index == 0 && direction == 23) || (index == 1 && direction == 11) ||
           (index == 2 && direction == 15) || (index == 3 && direction == 19))
    return 24;
  else if ((index == 0 && direction == 22) || (index == 1 && direction == 10) ||
           (index == 2 && direction == 14) || (index == 3 && direction == 18))
    return 25;
  else if ((index == 0 && direction == 35) || (index == 1 && direction == 26) ||
           (index == 2 && direction == 29) || (index == 3 && direction == 32))
    return 26;
}

int get_dec_MSC(int index, int direction) {
  if ((index == 0 && direction == 0) || (index == 2 && direction == 12) ||
      (index == 3 && direction == 9))
    return 0;
  if ((index == 0 && direction == 1) || (index == 1 && direction == 21) ||
      (index == 3 && direction == 13))
    return 1;
  if ((index == 0 && direction == 2) || (index == 1 && direction == 24) ||
      (index == 3 && direction == 17))
    return 11;
  if ((index == 0 && direction == 3) || (index == 1 && direction == 26) ||
      (index == 3 && direction == 20))
    return 26;
  if ((index == 0 && direction == 4) || (index == 2 && direction == 16) ||
      (index == 3 && direction == 10))
    return 8;
  if ((index == 0 && direction == 5) || (index == 1 && direction == 22) ||
      (index == 3 && direction == 14))
    return 9;
  if ((index == 0 && direction == 6) || (index == 1 && direction == 25) ||
      (index == 3 && direction == 18))
    return 10;
  if ((index == 0 && direction == 7) || (index == 2 && direction == 19) ||
      (index == 3 && direction == 11))
    return 24;
  if ((index == 0 && direction == 8) || (index == 1 && direction == 23) ||
      (index == 3 && direction == 15))
    return 25;
  if ((index == 0 && direction == 9) || (index == 1 && direction == 0) ||
      (index == 3 && direction == 12))
    return 2;
  if ((index == 0 && direction == 10) || (index == 1 && direction == 4) ||
      (index == 3 && direction == 16))
    return 12;
  if ((index == 0 && direction == 11) || (index == 1 && direction == 7) ||
      (index == 3 && direction == 19))
    return 27;
  if ((index == 0 && direction == 12) || (index == 1 && direction == 9) ||
      (index == 2 && direction == 0))
    return 4;
  if ((index == 0 && direction == 13) || (index == 1 && direction == 1) ||
      (index == 2 && direction == 21))
    return 3;
  if ((index == 0 && direction == 14) || (index == 1 && direction == 5) ||
      (index == 2 && direction == 22))
    return 13;
  if ((index == 0 && direction == 15) || (index == 1 && direction == 8) ||
      (index == 2 && direction == 23))
    return 28;
  if ((index == 0 && direction == 16) || (index == 1 && direction == 10) ||
      (index == 2 && direction == 4))
    return 16;
  if ((index == 0 && direction == 17) || (index == 1 && direction == 2) ||
      (index == 2 && direction == 24))
    return 15;
  if ((index == 0 && direction == 18) || (index == 1 && direction == 6) ||
      (index == 2 && direction == 25))
    return 14;
  if ((index == 0 && direction == 19) || (index == 1 && direction == 11) ||
      (index == 2 && direction == 7))
    return 30;
  if ((index == 0 && direction == 20) || (index == 1 && direction == 3) ||
      (index == 2 && direction == 26))
    return 29;
  if ((index == 0 && direction == 21) || (index == 2 && direction == 13) ||
      (index == 3 && direction == 1))
    return 7;
  if ((index == 0 && direction == 22) || (index == 2 && direction == 14) ||
      (index == 3 && direction == 5))
    return 21;
  if ((index == 0 && direction == 23) || (index == 2 && direction == 15) ||
      (index == 3 && direction == 8))
    return 34;
  if ((index == 0 && direction == 24) || (index == 2 && direction == 17) ||
      (index == 3 && direction == 2))
    return 23;
  if ((index == 0 && direction == 25) || (index == 2 && direction == 18) ||
      (index == 3 && direction == 6))
    return 22;
  if ((index == 0 && direction == 26) || (index == 2 && direction == 20) ||
      (index == 3 && direction == 3))
    return 35;
  if ((index == 1 && direction == 12) || (index == 2 && direction == 9) ||
      (index == 3 && direction == 0))
    return 6;
  if ((index == 1 && direction == 13) || (index == 2 && direction == 1) ||
      (index == 3 && direction == 21))
    return 5;
  if ((index == 1 && direction == 14) || (index == 2 && direction == 5) ||
      (index == 3 && direction == 22))
    return 17;
  if ((index == 1 && direction == 15) || (index == 2 && direction == 8) ||
      (index == 3 && direction == 23))
    return 31;
  if ((index == 1 && direction == 16) || (index == 2 && direction == 10) ||
      (index == 3 && direction == 4))
    return 20;
  if ((index == 1 && direction == 17) || (index == 2 && direction == 2) ||
      (index == 3 && direction == 24))
    return 19;
  if ((index == 1 && direction == 18) || (index == 2 && direction == 6) ||
      (index == 3 && direction == 25))
    return 18;
  if ((index == 1 && direction == 19) || (index == 2 && direction == 11) ||
      (index == 3 && direction == 7))
    return 33;
  if ((index == 1 && direction == 20) || (index == 2 && direction == 3) ||
      (index == 3 && direction == 26))
    return 32;
}

void get_forbidden1(int x, int y, int pic_w, int pic_h, int *forbidden,
                    int start_index) {
  int forbidden_num = 0;
  for (int direction = 0; direction < 36; direction++) {
    switch (direction) {
    case 0:
      if (x + 1 >= pic_w || y == pic_h - 1) {
        forbidden_num++;
        forbidden[forbidden_num] = 0;
        break;
      } // out border
      if ((y == 0 && x + 1 <= pic_w - 1) || x + 1 == pic_w - 1) {
        if (get_position_index(x + 1, y, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 0;
          break;
        }
      }
      break;
    case 1:
      if (x + 1 >= pic_w) {
        forbidden_num++;
        forbidden[forbidden_num] = 1;
        break;
      }
      if (x + 1 == pic_w - 1 && y - 1 >= 0) {
        if (get_position_index(x + 1, y - 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 1;
          break;
        }
      }
      if (y == 0) {
        if (get_position_index(x, y, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 1;
          break;
        }
      }
      break;
    case 2:
      if (y - 1 < 0 || x == pic_w - 1) {
        forbidden_num++;
        forbidden[forbidden_num] = 2;
        break;
      }
      if (y - 1 == 0 || (x == 0 && y - 1 >= 0)) {
        if (get_position_index(x, y - 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 2;
          break;
        }
      }
      break;
    case 3:
      if (y - 1 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 3;
        break;
      }
      if (y - 1 == 0 && x - 1 >= 0) {
        if (get_position_index(x - 1, y - 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 3;
          break;
        }
      }
      if (x == 0) {
        if (get_position_index(x, y, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 3;
          break;
        }
      }
      break;
    case 4:
      if (x - 1 < 0 || y == 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 4;
        break;
      }
      if ((y == pic_h - 1 && x - 1 >= 0) || x - 1 == 0) {
        if (get_position_index(x - 1, y, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 4;
          break;
        }
      }
      break;
    case 5:
      if (x - 1 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 5;
        break;
      }
      if (x - 1 == 0 && y + 1 <= pic_h - 1) {
        if (get_position_index(x - 1, y + 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 5;
          break;
        }
      }
      if (y == pic_h - 1) {
        if (get_position_index(x, y, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 5;
          break;
        }
      }
      break;
    case 6:
      if (y + 1 >= pic_h || x == 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 6;
        break;
      }
      if (y + 1 == pic_h - 1 || (x == pic_w - 1 && y + 1 <= pic_h - 1)) {
        if (get_position_index(x, y + 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 6;
          break;
        }
      }
      break;
    case 7:
      if (y + 1 >= pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 7;
        break;
      }
      if (y + 1 == pic_h - 1 && x + 1 <= pic_w - 1) {
        if (get_position_index(x + 1, y + 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 7;
          break;
        }
      }
      if (x == pic_w - 1) {
        if (get_position_index(x, y, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 7;
          break;
        }
      }
      break;
    case 8:
      if (x + 2 >= pic_w || y == pic_h - 1) {
        forbidden_num++;
        forbidden[forbidden_num] = 8;
        break;
      }
      if ((y == 0 && x + 2 <= pic_w - 1) || x + 2 == pic_w - 1) {
        if (get_position_index(x + 2, y, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 8;
          break;
        }
      }
      break;
    case 9:
      if (x + 2 >= pic_w || y - 1 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 9;
        break;
      }
      if (x + 2 == pic_w - 1 && y - 1 >= 0) {
        if (get_position_index(x + 2, y - 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 9;
          break;
        }
      }
      break;
    case 10:
      if (x + 2 >= pic_w || y - 1 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 10;
        break;
      }
      if (x + 2 == pic_w - 1 && y - 2 >= 0) {
        if (get_position_index(x + 2, y - 2, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 10;
          break;
        }
      }
      if (y - 1 == 0 && x + 1 <= pic_w - 1) {
        if (get_position_index(x + 1, y - 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 10;
          break;
        }
      }
      break;
    case 11:
      if (x + 1 >= pic_w || y - 2 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 11;
        break;
      }
      if (x + 1 == pic_w - 1 && y - 2 >= 0) {
        if (get_position_index(x + 1, y - 2, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 11;
          break;
        }
      }
      break;
    case 12:
      if (y - 2 < 0 || x == pic_w - 1) {
        forbidden_num++;
        forbidden[forbidden_num] = 12;
        break;
      }
      if (y - 2 == 0 || (x == 0 && y - 2 >= 0)) {
        if (get_position_index(x, y - 2, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 12;
          break;
        }
      }
      break;
    case 13:
      if (x - 1 < 0 || y - 2 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 13;
        break;
      }
      if (y - 2 == 0 && x - 1 >= 0) {
        if (get_position_index(x - 1, y - 2, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 13;
          break;
        }
      }
      break;
    case 14:
      if (x - 1 < 0 || y - 2 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 14;
        break;
      }
      if (y - 2 == 0 && x - 2 >= 0) {
        if (get_position_index(x - 2, y - 2, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 14;
          break;
        }
      }
      if (x - 1 == 0 && y - 1 >= 0) {
        if (get_position_index(x - 1, y - 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 14;
          break;
        }
      }
      break;
    case 15:
      if (x - 2 < 0 || y - 1 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 15;
        break;
      }
      if (y - 1 == 0 && x - 2 >= 0) {
        if (get_position_index(x - 2, y - 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 15;
          break;
        }
      }
      break;
    case 16:
      if (x - 2 < 0 || y == 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 16;
        break;
      }
      if ((y == pic_h - 1 && x - 2 >= 0) || x - 2 == 0) {
        if (get_position_index(x - 2, y, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 16;
          break;
        }
      }
      break;
    case 17:
      if (x - 2 < 0 || y + 1 >= pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 17;
        break;
      }
      if (x - 2 == 0 && y + 1 <= pic_h - 1) {
        if (get_position_index(x - 2, y + 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 17;
          break;
        }
      }
      break;
    case 18:
      if (x - 2 < 0 || y + 2 > pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 18;
        break;
      }
      if (x - 2 == 0 && y + 2 <= pic_h - 1) {
        if (get_position_index(x - 2, y + 2, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 18;
          break;
        }
      }
      if (y + 1 == pic_h - 1 && x - 1 >= 0) {
        if (get_position_index(x - 1, y + 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 18;
          break;
        }
      }
      break;
    case 19:
      if (x - 1 < 0 || y + 2 >= pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 19;
        break;
      }
      if (x - 1 == 0 && y + 2 <= pic_h - 1) {
        if (get_position_index(x - 1, y + 2, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 19;
          break;
        }
      }
      break;
    case 20:
      if (y + 2 >= pic_h || x == 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 20;
        break;
      }
      if (y + 2 == pic_h - 1 || (x == pic_w - 1 && y + 2 <= pic_h - 1)) {
        if (get_position_index(x, y + 2, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 20;
          break;
        }
      }
      break;
    case 21:
      if (x + 1 >= pic_w || y + 2 >= pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 21;
        break;
      }
      if (y + 2 == pic_h - 1 && x + 1 <= pic_w - 1) {
        if (get_position_index(x + 1, y + 2, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 21;
          break;
        }
      }
      break;
    case 22:
      if (x + 2 > pic_w || y + 2 >= pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 22;
        break;
      }
      if (y + 2 == pic_h - 1 && x + 2 <= pic_w - 1) {
        if (get_position_index(x + 2, y + 2, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 22;
          break;
        }
      }
      if (x + 1 == pic_w - 1 && y + 1 <= pic_h - 1) {
        if (get_position_index(x + 1, y + 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 22;
          break;
        }
      }
      break;
    case 23:
      if (x + 2 >= pic_w || y + 1 >= pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 23;
        break;
      }
      if (y + 1 == pic_h - 1 && x + 2 <= pic_w - 1) {
        if (get_position_index(x + 2, y + 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 23;
          break;
        }
      }
      break;
    case 24:
      if (x + 3 >= pic_w || y == pic_h - 1) {
        forbidden_num++;
        forbidden[forbidden_num] = 24;
        break;
      }
      if (x + 3 == pic_w - 1) {
        if (get_position_index(x + 3, y, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 24;
          break;
        }
      }
      break;
    case 25:
      if (x + 3 >= pic_w || y - 1 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 25;
        break;
      }
      if (x + 3 == pic_w - 1 && y - 1 >= 0) {
        if (get_position_index(x + 3, y - 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 25;
          break;
        }
      }
      break;
    case 26:
      if (x + 1 >= pic_w || y - 3 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 26;
        break;
      }
      if (x + 1 == pic_w - 1 && y - 3 >= 0) {
        if (get_position_index(x + 1, y - 3, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 26;
          break;
        }
      }
      break;
    case 27:
      if (y - 3 < 0 || x == pic_w - 1) {
        forbidden_num++;
        forbidden[forbidden_num] = 27;
        break;
      }
      if (y - 3 == 0) {
        if (get_position_index(x, y - 3, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 27;
          break;
        }
      }
      break;
    case 28:
      if (x - 1 < 0 || y - 3 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 28;
        break;
      }
      if (y - 3 == 0 && x - 1 >= 0) {
        if (get_position_index(x - 1, y - 3, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 28;
          break;
        }
      }
      break;
    case 29:
      if (x - 3 < 0 || y - 1 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 29;
        break;
      }
      if (y - 1 == 0 && x - 3 >= 0) {
        if (get_position_index(x - 3, y - 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 29;
          break;
        }
      }
      break;
    case 30:
      if (x - 3 < 0 || y == 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 30;
        break;
      }
      if (x - 3 == 0) {
        if (get_position_index(x - 3, y, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 30;
          break;
        }
      }
      break;
    case 31:
      if (x - 3 < 0 || y + 1 >= pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 31;
        break;
      }
      if (x - 3 == 0 && y + 1 >= pic_h - 1) {
        if (get_position_index(x - 3, y + 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 31;
          break;
        }
      }
      break;
    case 32:
      if (x - 1 < 0 || y + 3 >= pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 32;
        break;
      }
      if (x - 1 == 0 && y + 3 <= pic_h - 1) {
        if (get_position_index(x - 1, y + 3, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 32;
          break;
        }
      }
      break;
    case 33:
      if (y + 3 >= pic_h || x == 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 33;
        break;
      }
      if (y + 3 == pic_h - 1) {
        if (get_position_index(x, y + 3, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 33;
          break;
        }
      }
      break;
    case 34:
      if (x + 1 >= pic_w || y + 3 >= pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 34;
        break;
      }
      if (y + 3 == pic_h - 1 && x + 1 <= pic_w - 1) {
        if (get_position_index(x + 1, y + 3, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 34;
          break;
        }
      }
      break;
    case 35:
      if (x + 3 >= pic_w || y + 1 >= pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 35;
        break;
      }
      if (y + 1 == pic_h - 1 && x + 3 <= pic_w - 1) {
        if (get_position_index(x + 3, y + 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 35;
          break;
        }
      }
      break;
    }
  }
  forbidden[0] = forbidden_num;
}

void get_forbidden2(int x, int y, int pic_w, int pic_h, int direction_index,
                    int direction1, int *forbidden, int start_index,
                    int high_point, int left_point) {
  int forbidden_num = 0;
  for (int direction = 0; direction < num_arr1[direction1]; direction++) {
    int direction_ori = dec_arr1[direction1][direction];
    direction_ori = get_dec_MSC(direction_index, direction_ori);

    switch (direction_ori) {
    case 0:
      if (x + 1 >= pic_w || y == pic_h - 1) {
        forbidden_num++;
        forbidden[forbidden_num] = 0;
        break;
      } // out border
      if ((y == 0 && x + 1 <= pic_w - 1) || x + 1 == pic_w - 1) {
        if (get_position_index(x + 1, y, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 0;
          break;
        }
      }
      break;
    case 1:
      if (y - 1 < high_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 1;
        break;
      }
      if (y - 1 == high_point && x + 1 < left_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 1;
        break;
      }
      if (x + 1 >= pic_w) {
        forbidden_num++;
        forbidden[forbidden_num] = 1;
        break;
      }
      if (x + 1 == pic_w - 1 && y - 1 >= 0) {
        if (get_position_index(x + 1, y - 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 1;
          break;
        }
      }
      if (y == 0) {
        if (get_position_index(x, y, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 1;
          break;
        }
      }
      break;
    case 2:
      if (y - 1 < high_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 2;
        break;
      }
      if (y - 1 == high_point && x < left_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 2;
        break;
      }
      if (y - 1 < 0 || x == pic_w - 1) {
        forbidden_num++;
        forbidden[forbidden_num] = 2;
        break;
      }
      if (y - 1 == 0 || (x == 0 && y - 1 >= 0)) {
        if (get_position_index(x, y - 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 2;
          break;
        }
      }
      break;
    case 3:
      if (y - 1 < high_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 3;
        break;
      }
      if (y - 1 == high_point && x - 1 < left_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 3;
        break;
      }
      if (y - 1 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 3;
        break;
      }
      if (y - 1 == 0 && x - 1 >= 0) {
        if (get_position_index(x - 1, y - 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 3;
          break;
        }
      }
      if (x == 0) {
        if (get_position_index(x, y, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 3;
          break;
        }
      }
      break;
    case 4:
      if (x - 1 < 0 || y == 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 4;
        break;
      }
      if ((y == pic_h - 1 && x - 1 >= 0) || x - 1 == 0) {
        if (get_position_index(x - 1, y, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 4;
          break;
        }
      }
      break;
    case 5:
      if (x - 1 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 5;
        break;
      }
      if (x - 1 == 0 && y + 1 <= pic_h - 1) {
        if (get_position_index(x - 1, y + 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 5;
          break;
        }
      }
      if (y == pic_h - 1) {
        if (get_position_index(x, y, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 5;
          break;
        }
      }
      break;
    case 6:
      if (y + 1 >= pic_h || x == 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 6;
        break;
      }
      if (y + 1 == pic_h - 1 || (x == pic_w - 1 && y + 1 <= pic_h - 1)) {
        if (get_position_index(x, y + 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 6;
          break;
        }
      }
      break;
    case 7:
      if (y + 1 >= pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 7;
        break;
      }
      if (y + 1 == pic_h - 1 && x + 1 <= pic_w - 1) {
        if (get_position_index(x + 1, y + 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 7;
          break;
        }
      }
      if (x == pic_w - 1) {
        if (get_position_index(x, y, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 7;
          break;
        }
      }
      break;
    case 8:
      if (x + 2 >= pic_w || y == pic_h - 1) {
        forbidden_num++;
        forbidden[forbidden_num] = 8;
        break;
      }
      if ((y == 0 && x + 2 <= pic_w - 1) || x + 2 == pic_w - 1) {
        if (get_position_index(x + 2, y, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 8;
          break;
        }
      }
      break;
    case 9:
      if (y - 1 < high_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 9;
        break;
      }
      if (y - 1 == high_point && x + 2 < left_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 9;
        break;
      }
      if (x + 2 >= pic_w || y - 1 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 9;
        break;
      }
      if (x + 2 == pic_w - 1 && y - 1 >= 0) {
        if (get_position_index(x + 2, y - 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 9;
          break;
        }
      }
      break;
    case 10:
      if (y - 2 < high_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 10;
        break;
      }
      if (y - 2 == high_point && x + 2 < left_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 10;
        break;
      }
      if (x + 2 >= pic_w || y - 1 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 10;
        break;
      }
      if (x + 2 == pic_w - 1 && y - 2 >= 0) {
        if (get_position_index(x + 2, y - 2, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 10;
          break;
        }
      }
      if (y - 1 == 0 && x + 1 <= pic_w - 1) {
        if (get_position_index(x + 1, y - 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 10;
          break;
        }
      }
      break;
    case 11:
      if (y - 2 < high_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 11;
        break;
      }
      if (y - 2 == high_point && x + 1 < left_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 11;
        break;
      }
      if (x + 1 >= pic_w || y - 2 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 11;
        break;
      }
      if (x + 1 == pic_w - 1 && y - 2 >= 0) {
        if (get_position_index(x + 1, y - 2, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 11;
          break;
        }
      }
      break;
    case 12:
      if (y - 2 < high_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 12;
        break;
      }
      if (y - 2 == high_point && x < left_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 12;
        break;
      }
      if (y - 2 < 0 || x == pic_w - 1) {
        forbidden_num++;
        forbidden[forbidden_num] = 12;
        break;
      }
      if (y - 2 == 0 || (x == 0 && y - 2 >= 0)) {
        if (get_position_index(x, y - 2, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 12;
          break;
        }
      }
      break;
    case 13:
      if (y - 2 < high_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 13;
        break;
      }
      if (y - 2 == high_point && x - 1 < left_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 13;
        break;
      }
      if (x - 1 < 0 || y - 2 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 13;
        break;
      }
      if (y - 2 == 0 && x - 1 >= 0) {
        if (get_position_index(x - 1, y - 2, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 13;
          break;
        }
      }
      break;
    case 14:
      if (y - 2 < high_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 14;
        break;
      }
      if (y - 2 == high_point && x - 2 < left_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 14;
        break;
      }
      if (x - 1 < 0 || y - 2 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 14;
        break;
      }
      if (y - 2 == 0 && x - 2 >= 0) {
        if (get_position_index(x - 2, y - 2, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 14;
          break;
        }
      }
      if (x - 1 == 0 && y - 1 >= 0) {
        if (get_position_index(x - 1, y - 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 14;
          break;
        }
      }
      break;
    case 15:
      if (y - 1 < high_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 15;
        break;
      }
      if (y - 1 == high_point && x - 2 < left_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 15;
        break;
      }
      if (x - 2 < 0 || y - 1 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 15;
        break;
      }
      if (y - 1 == 0 && x - 2 >= 0) {
        if (get_position_index(x - 2, y - 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 15;
          break;
        }
      }
      break;
    case 16:
      if (x - 2 < 0 || y == 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 16;
        break;
      }
      if ((y == pic_h - 1 && x - 2 >= 0) || x - 2 == 0) {
        if (get_position_index(x - 2, y, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 16;
          break;
        }
      }
      break;
    case 17:
      if (x - 2 < 0 || y + 1 >= pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 17;
        break;
      }
      if (x - 2 == 0 && y + 1 <= pic_h - 1) {
        if (get_position_index(x - 2, y + 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 17;
          break;
        }
      }
      break;
    case 18:
      if (x - 2 < 0 || y + 2 > pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 18;
        break;
      }
      if (x - 2 == 0 && y + 2 <= pic_h - 1) {
        if (get_position_index(x - 2, y + 2, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 18;
          break;
        }
      }
      if (y + 1 == pic_h - 1 && x - 1 >= 0) {
        if (get_position_index(x - 1, y + 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 18;
          break;
        }
      }
      break;
    case 19:
      if (x - 1 < 0 || y + 2 >= pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 19;
        break;
      }
      if (x - 1 == 0 && y + 2 <= pic_h - 1) {
        if (get_position_index(x - 1, y + 2, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 19;
          break;
        }
      }
      break;
    case 20:
      if (y + 2 >= pic_h || x == 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 20;
        break;
      }
      if (y + 2 == pic_h - 1 || (x == pic_w - 1 && y + 2 <= pic_h - 1)) {
        if (get_position_index(x, y + 2, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 20;
          break;
        }
      }
      break;
    case 21:
      if (x + 1 >= pic_w || y + 2 >= pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 21;
        break;
      }
      if (y + 2 == pic_h - 1 && x + 1 <= pic_w - 1) {
        if (get_position_index(x + 1, y + 2, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 21;
          break;
        }
      }
      break;
    case 22:
      if (x + 2 > pic_w || y + 2 >= pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 22;
        break;
      }
      if (y + 2 == pic_h - 1 && x + 2 <= pic_w - 1) {
        if (get_position_index(x + 2, y + 2, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 22;
          break;
        }
      }
      if (x + 1 == pic_w - 1 && y + 1 <= pic_h - 1) {
        if (get_position_index(x + 1, y + 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 22;
          break;
        }
      }
      break;
    case 23:
      if (x + 2 >= pic_w || y + 1 >= pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 23;
        break;
      }
      if (y + 1 == pic_h - 1 && x + 2 <= pic_w - 1) {
        if (get_position_index(x + 2, y + 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 23;
          break;
        }
      }
      break;
    case 24:
      if (x + 3 >= pic_w || y == pic_h - 1) {
        forbidden_num++;
        forbidden[forbidden_num] = 24;
        break;
      }
      if (x + 3 == pic_w - 1) {
        if (get_position_index(x + 3, y, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 24;
          break;
        }
      }
      break;
    case 25:
      if (y - 1 < high_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 25;
        break;
      }
      if (y - 1 == high_point && x + 3 < left_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 25;
        break;
      }
      if (x + 3 >= pic_w || y - 1 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 25;
        break;
      }
      if (x + 3 == pic_w - 1 && y - 1 >= 0) {
        if (get_position_index(x + 3, y - 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 25;
          break;
        }
      }
      break;
    case 26:
      if (y - 3 < high_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 26;
        break;
      }
      if (y - 3 == high_point && x + 1 < left_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 26;
        break;
      }
      if (x + 1 >= pic_w || y - 3 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 26;
        break;
      }
      if (x + 1 == pic_w - 1 && y - 3 >= 0) {
        if (get_position_index(x + 1, y - 3, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 26;
          break;
        }
      }
      break;
    case 27:
      if (y - 3 < high_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 27;
        break;
      }
      if (y - 3 == high_point && x < left_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 27;
        break;
      }
      if (y - 3 < 0 || x == pic_w - 1) {
        forbidden_num++;
        forbidden[forbidden_num] = 27;
        break;
      }
      if (y - 3 == 0) {
        if (get_position_index(x, y - 3, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 27;
          break;
        }
      }
      break;
    case 28:
      if (y - 3 < high_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 28;
        break;
      }
      if (y - 3 == high_point && x - 1 < left_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 28;
        break;
      }
      if (x - 1 < 0 || y - 3 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 28;
        break;
      }
      if (y - 3 == 0 && x - 1 >= 0) {
        if (get_position_index(x - 1, y - 3, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 28;
          break;
        }
      }
      break;
    case 29:
      if (y - 1 < high_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 29;
        break;
      }
      if (y - 1 == high_point && x - 3 < left_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 29;
        break;
      }
      if (x - 3 < 0 || y - 1 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 29;
        break;
      }
      if (y - 1 == 0 && x - 3 >= 0) {
        if (get_position_index(x - 3, y - 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 29;
          break;
        }
      }
      break;
    case 30:
      if (x - 3 < 0 || y == 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 30;
        break;
      }
      if (x - 3 == 0) {
        if (get_position_index(x - 3, y, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 30;
          break;
        }
      }
      break;
    case 31:
      if (x - 3 < 0 || y + 1 >= pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 31;
        break;
      }
      if (x - 3 == 0 && y + 1 >= pic_h - 1) {
        if (get_position_index(x - 3, y + 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 31;
          break;
        }
      }
      break;
    case 32:
      if (x - 1 < 0 || y + 3 >= pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 32;
        break;
      }
      if (x - 1 == 0 && y + 3 <= pic_h - 1) {
        if (get_position_index(x - 1, y + 3, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 32;
          break;
        }
      }
      break;
    case 33:
      if (y + 3 >= pic_h || x == 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 33;
        break;
      }
      if (y + 3 == pic_h - 1) {
        if (get_position_index(x, y + 3, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 33;
          break;
        }
      }
      break;
    case 34:
      if (x + 1 >= pic_w || y + 3 >= pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 34;
        break;
      }
      if (y + 3 == pic_h - 1 && x + 1 <= pic_w - 1) {
        if (get_position_index(x + 1, y + 3, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 34;
          break;
        }
      }
      break;
    case 35:
      if (x + 3 >= pic_w || y + 1 >= pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 35;
        break;
      }
      if (y + 1 == pic_h - 1 && x + 3 <= pic_w - 1) {
        if (get_position_index(x + 3, y + 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 35;
          break;
        }
      }
      break;
    }
  }
  forbidden[0] = forbidden_num;

  for (int i = 0; i < forbidden[0]; i++) {
    forbidden[i + 1] =
        enc_arr1[direction1][get_RMSC(direction_index, forbidden[i + 1])];
  }
}

void get_forbidden3(int x, int y, int pic_w, int pic_h, int direction_index,
                    int direction1, int direction2, int *forbidden,
                    int start_index, int high_point, int left_point) {
  int forbidden_num = 0;
  for (int direction = 0; direction < num_arr[direction1][direction2];
       direction++) {
    int direction_ori = dec_arr[direction1][direction2][direction];
    direction_ori = get_dec_MSC(direction_index, direction_ori);

    switch (direction_ori) {
    case 0:
      if (x + 1 >= pic_w || y == pic_h - 1) {
        forbidden_num++;
        forbidden[forbidden_num] = 0;
        break;
      } // out border
      if ((y == 0 && x + 1 <= pic_w - 1) || x + 1 == pic_w - 1) {
        if (get_position_index(x + 1, y, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 0;
          break;
        }
      }
      break;
    case 1:
      if (y - 1 < high_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 1;
        break;
      }
      if (y - 1 == high_point && x + 1 < left_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 1;
        break;
      }
      if (x + 1 >= pic_w) {
        forbidden_num++;
        forbidden[forbidden_num] = 1;
        break;
      }
      if (x + 1 == pic_w - 1 && y - 1 >= 0) {
        if (get_position_index(x + 1, y - 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 1;
          break;
        }
      }
      if (y == 0) {
        if (get_position_index(x, y, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 1;
          break;
        }
      }
      break;
    case 2:
      if (y - 1 < high_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 2;
        break;
      }
      if (y - 1 == high_point && x < left_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 2;
        break;
      }
      if (y - 1 < 0 || x == pic_w - 1) {
        forbidden_num++;
        forbidden[forbidden_num] = 2;
        break;
      }
      if (y - 1 == 0 || (x == 0 && y - 1 >= 0)) {
        if (get_position_index(x, y - 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 2;
          break;
        }
      }
      break;
    case 3:
      if (y - 1 < high_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 3;
        break;
      }
      if (y - 1 == high_point && x - 1 < left_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 3;
        break;
      }
      if (y - 1 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 3;
        break;
      }
      if (y - 1 == 0 && x - 1 >= 0) {
        if (get_position_index(x - 1, y - 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 3;
          break;
        }
      }
      if (x == 0) {
        if (get_position_index(x, y, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 3;
          break;
        }
      }
      break;
    case 4:
      if (x - 1 < 0 || y == 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 4;
        break;
      }
      if ((y == pic_h - 1 && x - 1 >= 0) || x - 1 == 0) {
        if (get_position_index(x - 1, y, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 4;
          break;
        }
      }
      break;
    case 5:
      if (x - 1 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 5;
        break;
      }
      if (x - 1 == 0 && y + 1 <= pic_h - 1) {
        if (get_position_index(x - 1, y + 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 5;
          break;
        }
      }
      if (y == pic_h - 1) {
        if (get_position_index(x, y, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 5;
          break;
        }
      }
      break;
    case 6:
      if (y + 1 >= pic_h || x == 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 6;
        break;
      }
      if (y + 1 == pic_h - 1 || (x == pic_w - 1 && y + 1 <= pic_h - 1)) {
        if (get_position_index(x, y + 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 6;
          break;
        }
      }
      break;
    case 7:
      if (y + 1 >= pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 7;
        break;
      }
      if (y + 1 == pic_h - 1 && x + 1 <= pic_w - 1) {
        if (get_position_index(x + 1, y + 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 7;
          break;
        }
      }
      if (x == pic_w - 1) {
        if (get_position_index(x, y, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 7;
          break;
        }
      }
      break;
    case 8:
      if (x + 2 >= pic_w || y == pic_h - 1) {
        forbidden_num++;
        forbidden[forbidden_num] = 8;
        break;
      }
      if ((y == 0 && x + 2 <= pic_w - 1) || x + 2 == pic_w - 1) {
        if (get_position_index(x + 2, y, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 8;
          break;
        }
      }
      break;
    case 9:
      if (y - 1 < high_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 9;
        break;
      }
      if (y - 1 == high_point && x + 2 < left_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 9;
        break;
      }
      if (x + 2 >= pic_w || y - 1 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 9;
        break;
      }
      if (x + 2 == pic_w - 1 && y - 1 >= 0) {
        if (get_position_index(x + 2, y - 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 9;
          break;
        }
      }
      break;
    case 10:
      if (y - 2 < high_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 10;
        break;
      }
      if (y - 2 == high_point && x + 2 < left_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 10;
        break;
      }
      if (x + 2 >= pic_w || y - 1 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 10;
        break;
      }
      if (x + 2 == pic_w - 1 && y - 2 >= 0) {
        if (get_position_index(x + 2, y - 2, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 10;
          break;
        }
      }
      if (y - 1 == 0 && x + 1 <= pic_w - 1) {
        if (get_position_index(x + 1, y - 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 10;
          break;
        }
      }
      break;
    case 11:
      if (y - 2 < high_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 11;
        break;
      }
      if (y - 2 == high_point && x + 1 < left_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 11;
        break;
      }
      if (x + 1 >= pic_w || y - 2 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 11;
        break;
      }
      if (x + 1 == pic_w - 1 && y - 2 >= 0) {
        if (get_position_index(x + 1, y - 2, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 11;
          break;
        }
      }
      break;
    case 12:
      if (y - 2 < high_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 12;
        break;
      }
      if (y - 2 == high_point && x < left_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 12;
        break;
      }
      if (y - 2 < 0 || x == pic_w - 1) {
        forbidden_num++;
        forbidden[forbidden_num] = 12;
        break;
      }
      if (y - 2 == 0 || (x == 0 && y - 2 >= 0)) {
        if (get_position_index(x, y - 2, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 12;
          break;
        }
      }
      break;
    case 13:
      if (y - 2 < high_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 13;
        break;
      }
      if (y - 2 == high_point && x - 1 < left_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 13;
        break;
      }
      if (x - 1 < 0 || y - 2 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 13;
        break;
      }
      if (y - 2 == 0 && x - 1 >= 0) {
        if (get_position_index(x - 1, y - 2, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 13;
          break;
        }
      }
      break;
    case 14:
      if (y - 2 < high_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 14;
        break;
      }
      if (y - 2 == high_point && x - 2 < left_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 14;
        break;
      }
      if (x - 1 < 0 || y - 2 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 14;
        break;
      }
      if (y - 2 == 0 && x - 2 >= 0) {
        if (get_position_index(x - 2, y - 2, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 14;
          break;
        }
      }
      if (x - 1 == 0 && y - 1 >= 0) {
        if (get_position_index(x - 1, y - 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 14;
          break;
        }
      }
      break;
    case 15:
      if (y - 1 < high_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 15;
        break;
      }
      if (y - 1 == high_point && x - 2 < left_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 15;
        break;
      }
      if (x - 2 < 0 || y - 1 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 15;
        break;
      }
      if (y - 1 == 0 && x - 2 >= 0) {
        if (get_position_index(x - 2, y - 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 15;
          break;
        }
      }
      break;
    case 16:
      if (x - 2 < 0 || y == 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 16;
        break;
      }
      if ((y == pic_h - 1 && x - 2 >= 0) || x - 2 == 0) {
        if (get_position_index(x - 2, y, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 16;
          break;
        }
      }
      break;
    case 17:
      if (x - 2 < 0 || y + 1 >= pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 17;
        break;
      }
      if (x - 2 == 0 && y + 1 <= pic_h - 1) {
        if (get_position_index(x - 2, y + 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 17;
          break;
        }
      }
      break;
    case 18:
      if (x - 2 < 0 || y + 2 > pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 18;
        break;
      }
      if (x - 2 == 0 && y + 2 <= pic_h - 1) {
        if (get_position_index(x - 2, y + 2, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 18;
          break;
        }
      }
      if (y + 1 == pic_h - 1 && x - 1 >= 0) {
        if (get_position_index(x - 1, y + 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 18;
          break;
        }
      }
      break;
    case 19:
      if (x - 1 < 0 || y + 2 >= pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 19;
        break;
      }
      if (x - 1 == 0 && y + 2 <= pic_h - 1) {
        if (get_position_index(x - 1, y + 2, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 19;
          break;
        }
      }
      break;
    case 20:
      if (y + 2 >= pic_h || x == 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 20;
        break;
      }
      if (y + 2 == pic_h - 1 || (x == pic_w - 1 && y + 2 <= pic_h - 1)) {
        if (get_position_index(x, y + 2, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 20;
          break;
        }
      }
      break;
    case 21:
      if (x + 1 >= pic_w || y + 2 >= pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 21;
        break;
      }
      if (y + 2 == pic_h - 1 && x + 1 <= pic_w - 1) {
        if (get_position_index(x + 1, y + 2, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 21;
          break;
        }
      }
      break;
    case 22:
      if (x + 2 > pic_w || y + 2 >= pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 22;
        break;
      }
      if (y + 2 == pic_h - 1 && x + 2 <= pic_w - 1) {
        if (get_position_index(x + 2, y + 2, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 22;
          break;
        }
      }
      if (x + 1 == pic_w - 1 && y + 1 <= pic_h - 1) {
        if (get_position_index(x + 1, y + 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 22;
          break;
        }
      }
      break;
    case 23:
      if (x + 2 >= pic_w || y + 1 >= pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 23;
        break;
      }
      if (y + 1 == pic_h - 1 && x + 2 <= pic_w - 1) {
        if (get_position_index(x + 2, y + 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 23;
          break;
        }
      }
      break;
    case 24:
      if (x + 3 >= pic_w || y == pic_h - 1) {
        forbidden_num++;
        forbidden[forbidden_num] = 24;
        break;
      }
      if (x + 3 == pic_w - 1) {
        if (get_position_index(x + 3, y, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 24;
          break;
        }
      }
      break;
    case 25:
      if (y - 1 < high_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 25;
        break;
      }
      if (y - 1 == high_point && x + 3 < left_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 25;
        break;
      }
      if (x + 3 >= pic_w || y - 1 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 25;
        break;
      }
      if (x + 3 == pic_w - 1 && y - 1 >= 0) {
        if (get_position_index(x + 3, y - 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 25;
          break;
        }
      }
      break;
    case 26:
      if (y - 3 < high_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 26;
        break;
      }
      if (y - 3 == high_point && x + 1 < left_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 26;
        break;
      }
      if (x + 1 >= pic_w || y - 3 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 26;
        break;
      }
      if (x + 1 == pic_w - 1 && y - 3 >= 0) {
        if (get_position_index(x + 1, y - 3, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 26;
          break;
        }
      }
      break;
    case 27:
      if (y - 3 < high_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 27;
        break;
      }
      if (y - 3 == high_point && x < left_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 27;
        break;
      }
      if (y - 3 < 0 || x == pic_w - 1) {
        forbidden_num++;
        forbidden[forbidden_num] = 27;
        break;
      }
      if (y - 3 == 0) {
        if (get_position_index(x, y - 3, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 27;
          break;
        }
      }
      break;
    case 28:
      if (y - 3 < high_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 28;
        break;
      }
      if (y - 3 == high_point && x - 1 < left_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 28;
        break;
      }
      if (x - 1 < 0 || y - 3 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 28;
        break;
      }
      if (y - 3 == 0 && x - 1 >= 0) {
        if (get_position_index(x - 1, y - 3, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 28;
          break;
        }
      }
      break;
    case 29:
      if (y - 1 < high_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 29;
        break;
      }
      if (y - 1 == high_point && x - 3 < left_point) {
        forbidden_num++;
        forbidden[forbidden_num] = 29;
        break;
      }
      if (x - 3 < 0 || y - 1 < 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 29;
        break;
      }
      if (y - 1 == 0 && x - 3 >= 0) {
        if (get_position_index(x - 3, y - 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 29;
          break;
        }
      }
      break;
    case 30:
      if (x - 3 < 0 || y == 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 30;
        break;
      }
      if (x - 3 == 0) {
        if (get_position_index(x - 3, y, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 30;
          break;
        }
      }
      break;
    case 31:
      if (x - 3 < 0 || y + 1 >= pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 31;
        break;
      }
      if (x - 3 == 0 && y + 1 >= pic_h - 1) {
        if (get_position_index(x - 3, y + 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 31;
          break;
        }
      }
      break;
    case 32:
      if (x - 1 < 0 || y + 3 >= pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 32;
        break;
      }
      if (x - 1 == 0 && y + 3 <= pic_h - 1) {
        if (get_position_index(x - 1, y + 3, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 32;
          break;
        }
      }
      break;
    case 33:
      if (y + 3 >= pic_h || x == 0) {
        forbidden_num++;
        forbidden[forbidden_num] = 33;
        break;
      }
      if (y + 3 == pic_h - 1) {
        if (get_position_index(x, y + 3, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 33;
          break;
        }
      }
      break;
    case 34:
      if (x + 1 >= pic_w || y + 3 >= pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 34;
        break;
      }
      if (y + 3 == pic_h - 1 && x + 1 <= pic_w - 1) {
        if (get_position_index(x + 1, y + 3, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 34;
          break;
        }
      }
      break;
    case 35:
      if (x + 3 >= pic_w || y + 1 >= pic_h) {
        forbidden_num++;
        forbidden[forbidden_num] = 35;
        break;
      }
      if (y + 1 == pic_h - 1 && x + 3 <= pic_w - 1) {
        if (get_position_index(x + 3, y + 1, pic_w, pic_h) <= start_index) {
          forbidden_num++;
          forbidden[forbidden_num] = 35;
          break;
        }
      }
      break;
    }
  }
  forbidden[0] = forbidden_num;

  for (int i = 0; i < forbidden[0]; i++) {
    forbidden[i + 1] = enc_arr[direction1][direction2]
                              [get_RMSC(direction_index, forbidden[i + 1])];
  }
}

void adapt_position(int *x, int *y, int direction) {
  switch (direction) {
  case 0:
    *x += 1;
    break;
  case 1:
    *x += 1;
    *y -= 1;
    break;
  case 2:
    *y -= 1;
    break;
  case 3:
    *x -= 1;
    *y -= 1;
    break;
  case 4:
    *x -= 1;
    break;
  case 5:
    *x -= 1;
    *y += 1;
    break;
  case 6:
    *y += 1;
    break;
  case 7:
    *x += 1;
    *y += 1;
    break;
  case 8:
    *x += 2;
    break;
  case 9:
    *x += 2;
    *y -= 1;
    break;
  case 10:
    *x += 2;
    *y -= 2;
    break;
  case 11:
    *x += 1;
    *y -= 2;
    break;
  case 12:
    *y -= 2;
    break;
  case 13:
    *x -= 1;
    *y -= 2;
    break;
  case 14:
    *x -= 2;
    *y -= 2;
    break;
  case 15:
    *x -= 2;
    *y -= 1;
    break;
  case 16:
    *x -= 2;
    break;
  case 17:
    *x -= 2;
    *y += 1;
    break;
  case 18:
    *x -= 2;
    *y += 2;
    break;
  case 19:
    *x -= 1;
    *y += 2;
    break;
  case 20:
    *y += 2;
    break;
  case 21:
    *x += 1;
    *y += 2;
    break;
  case 22:
    *x += 2;
    *y += 2;
    break;
  case 23:
    *x += 2;
    *y += 1;
    break;
  case 24:
    *x += 3;
    break;
  case 25:
    *x += 3;
    *y -= 1;
    break;
  case 26:
    *x += 1;
    *y -= 3;
    break;
  case 27:
    *y -= 3;
    break;
  case 28:
    *x -= 1;
    *y -= 3;
    break;
  case 29:
    *x -= 3;
    *y -= 1;
    break;
  case 30:
    *x -= 3;
    break;
  case 31:
    *x -= 3;
    *y += 1;
    break;
  case 32:
    *x -= 1;
    *y += 3;
    break;
  case 33:
    *y += 3;
    break;
  case 34:
    *x += 1;
    *y += 3;
    break;
  case 35:
    *x += 3;
    *y += 1;
    break;
  }
}

int get_position_index(int x, int y, int pic_w, int pic_h) {
  if (x == 0 && y == 0)
    return 2 * pic_h + 2 * pic_w - 4;
  else if (x == 0)
    return y;
  else if (y == pic_h - 1)
    return pic_h - 1 + x;
  else if (x == pic_w - 1)
    return 2 * pic_h - 2 + pic_w - 1 - y;
  else if (y == 0)
    return 2 * pic_h - 2 + 2 * pic_w - 2 - x;
  else
    return -1;
}

void encodeEdgeLength_MSC(CodingUnit *CU, bool encode) {
  int *edge = CU->Edge_MSC;
  int *overlap = CU->Overlap_MSC;
  if (encode) {
    int loc_y = CU->location_row;
    int loc_x = CU->location_col;
    int pic_h = CU->pic_height;
    int pic_w = CU->pic_width;
    int forbidden[38] = {0};
    int x = loc_x, y = loc_y;
    if (x == 0)
      y -= 1;
    else if (y == pic_h - 1)
      x -= 1;
    else if (x == pic_w - 1)
      y += 1;
    else if (y == 0)
      x += 1;
    else
      x -= 1;
    bool boundary = false;
    if (loc_x == 0 || loc_x == pic_w - 1 || loc_y == 0 || loc_y == pic_h - 1)
      boundary = true;
    int high_point = loc_y - 1;
    if (boundary)
      high_point = -1;
    int left_point = loc_x;
    if (boundary)
      left_point = -1;

    int direction1, direction2, direction3, direct_temp;
    int index;
    int start_index = get_position_index(loc_x, loc_y, pic_w, pic_h);
    int runLength = 0;
    bool newzero = false;

    if (overlap[0] > 0 && runLength == 0) {
      bool end = true;
      for (int j = 0; j < edge[0]; j++) {
        if (overlap[j] < 2) {
          end = false;
          break;
        } else
          runLength++;
      }
      acodec.encode(end, aEndFlag);
      if (!end)
        encGolomb(runLength, 0, 3);
    }
    if (overlap[0] < 2) {
      if (boundary) {
        get_forbidden1(x, y, pic_w, pic_h, forbidden, start_index);
        if (loc_x == 0)
          acodec.encode(edge[1], aMSC_L, forbidden);
        else if (loc_y == pic_h - 1)
          acodec.encode(edge[1], aMSC_B, forbidden);
        else if (loc_x == pic_w - 1)
          acodec.encode(edge[1], aMSC_R, forbidden);
        else if (loc_y == 0)
          acodec.encode(edge[1], aMSC_A, forbidden);
      } else {
        if (edge[1] == 1)
          acodec.encode(0, aMSC_I);
        else if (edge[1] == 9)
          acodec.encode(1, aMSC_I);
        else if (edge[1] == 25)
          acodec.encode(2, aMSC_I);
        else
          printf("error");
      }
    } else if (overlap[0] == 2) {
      runLength--;
      if (runLength == 0)
        newzero = true;
    }

    direction1 = get_direction1(edge[1], &index);

    if (edge[0] > 1) {
      adapt_position(&x, &y, edge[1]);
      direction2 = get_RMSC(index, edge[2]);

      if (overlap[1] > 0 && runLength == 0 && !newzero) {
        bool end = true;
        for (int j = 1; j < edge[0]; j++) {
          if (overlap[j] < 2) {
            end = false;
            break;
          } else
            runLength++;
        }
        acodec.encode(end, aEndFlag);
        if (!end)
          encGolomb(runLength, 0, 3);
      }
      if (overlap[1] < 2) {
        newzero = false;
        get_forbidden2(x, y, pic_w, pic_h, index, direction1, forbidden,
                       start_index, high_point, left_point);
        switch (direction1) {
        case 0:
          acodec.encode(enc_arr1[0][direction2], aMSC_0, forbidden);
          break;
        case 1:
          acodec.encode(enc_arr1[1][direction2], aMSC_1, forbidden);
          break;
        case 2:
          acodec.encode(enc_arr1[2][direction2], aMSC_2, forbidden);
          break;
        case 3:
          acodec.encode(enc_arr1[3][direction2], aMSC_3, forbidden);
          break;
        case 4:
          acodec.encode(enc_arr1[4][direction2], aMSC_4, forbidden);
          break;
        case 5:
          acodec.encode(enc_arr1[5][direction2], aMSC_5, forbidden);
          break;
        case 6:
          acodec.encode(enc_arr1[6][direction2], aMSC_6, forbidden);
          break;
        case 7:
          acodec.encode(enc_arr1[7][direction2], aMSC_7, forbidden);
          break;
        case 8:
          acodec.encode(enc_arr1[8][direction2], aMSC_8, forbidden);
          break;
        }
      } else if (overlap[1] == 2) {
        runLength--;
        if (runLength == 0)
          newzero = true;
      }

      adapt_position(&x, &y, edge[2]);
    }
    for (int i = 3; i < edge[0] + 1; i++) {
      direct_temp = direction2;
      direction2 = get_direction1(edge[i - 1], &index);
      direction3 = get_RMSC(index, edge[i]);

      if (overlap[i - 1] > 0 && runLength == 0 && !newzero) {
        bool end = true;
        for (int j = i - 1; j < edge[0]; j++) {
          if (overlap[j] < 2) {
            end = false;
            break;
          } else
            runLength++;
        }
        acodec.encode(end, aEndFlag);
        if (!end)
          encGolomb(runLength, 0, 3);
      }
      if (overlap[i - 1] < 2) {
        newzero = false;
        get_forbidden3(x, y, pic_w, pic_h, index, direction1, direct_temp,
                       forbidden, start_index, high_point, left_point);
        switch (direction1 * 100 + direct_temp) {
        case 0:
          acodec.encode(enc_arr[0][0][direction3], aMSC_00, forbidden);
          break;
        case 1:
          acodec.encode(enc_arr[0][1][direction3], aMSC_01, forbidden);
          break;
        case 2:
          acodec.encode(enc_arr[0][2][direction3], aMSC_02, forbidden);
          break;
        case 3:
          acodec.encode(enc_arr[0][3][direction3], aMSC_03, forbidden);
          break;
        case 4:
          acodec.encode(enc_arr[0][4][direction3], aMSC_04, forbidden);
          break;
        case 5:
          acodec.encode(enc_arr[0][5][direction3], aMSC_05, forbidden);
          break;
        case 6:
          acodec.encode(enc_arr[0][6][direction3], aMSC_06, forbidden);
          break;
        case 7:
          acodec.encode(enc_arr[0][7][direction3], aMSC_07, forbidden);
          break;
        case 8:
          acodec.encode(enc_arr[0][8][direction3], aMSC_08, forbidden);
          break;
        case 9:
          acodec.encode(enc_arr[0][9][direction3], aMSC_09, forbidden);
          break;
        case 10:
          acodec.encode(enc_arr[0][10][direction3], aMSC_010, forbidden);
          break;
        case 11:
          acodec.encode(enc_arr[0][11][direction3], aMSC_011, forbidden);
          break;
        case 12:
          acodec.encode(enc_arr[0][12][direction3], aMSC_012, forbidden);
          break;
        case 13:
          acodec.encode(enc_arr[0][13][direction3], aMSC_013, forbidden);
          break;
        case 14:
          acodec.encode(enc_arr[0][14][direction3], aMSC_014, forbidden);
          break;
        case 15:
          acodec.encode(enc_arr[0][15][direction3], aMSC_015, forbidden);
          break;
        case 16:
          acodec.encode(enc_arr[0][16][direction3], aMSC_016, forbidden);
          break;
        case 17:
          acodec.encode(enc_arr[0][17][direction3], aMSC_017, forbidden);
          break;
        case 18:
          acodec.encode(enc_arr[0][18][direction3], aMSC_018, forbidden);
          break;
        case 19:
          acodec.encode(enc_arr[0][19][direction3], aMSC_019, forbidden);
          break;
        case 20:
          acodec.encode(enc_arr[0][20][direction3], aMSC_020, forbidden);
          break;
        case 21:
          acodec.encode(enc_arr[0][21][direction3], aMSC_021, forbidden);
          break;
        case 22:
          acodec.encode(enc_arr[0][22][direction3], aMSC_022, forbidden);
          break;
        case 23:
          acodec.encode(enc_arr[0][23][direction3], aMSC_023, forbidden);
          break;
        case 24:
          acodec.encode(enc_arr[0][24][direction3], aMSC_024, forbidden);
          break;
        case 25:
          acodec.encode(enc_arr[0][25][direction3], aMSC_025, forbidden);
          break;
        case 26:
          acodec.encode(enc_arr[0][26][direction3], aMSC_026, forbidden);
          break;
        case 100:
          acodec.encode(enc_arr[1][0][direction3], aMSC_10, forbidden);
          break;
        case 101:
          acodec.encode(enc_arr[1][1][direction3], aMSC_11, forbidden);
          break;
        case 102:
          acodec.encode(enc_arr[1][2][direction3], aMSC_12, forbidden);
          break;
        case 103:
          acodec.encode(enc_arr[1][3][direction3], aMSC_13, forbidden);
          break;
        case 104:
          acodec.encode(enc_arr[1][4][direction3], aMSC_14, forbidden);
          break;
        case 105:
          acodec.encode(enc_arr[1][5][direction3], aMSC_15, forbidden);
          break;
        case 106:
          acodec.encode(enc_arr[1][6][direction3], aMSC_16, forbidden);
          break;
        case 107:
          acodec.encode(enc_arr[1][7][direction3], aMSC_17, forbidden);
          break;
        case 108:
          acodec.encode(enc_arr[1][8][direction3], aMSC_18, forbidden);
          break;
        case 109:
          acodec.encode(enc_arr[1][9][direction3], aMSC_19, forbidden);
          break;
        case 110:
          acodec.encode(enc_arr[1][10][direction3], aMSC_110, forbidden);
          break;
        case 111:
          acodec.encode(enc_arr[1][11][direction3], aMSC_111, forbidden);
          break;
        case 112:
          acodec.encode(enc_arr[1][12][direction3], aMSC_112, forbidden);
          break;
        case 113:
          acodec.encode(enc_arr[1][13][direction3], aMSC_113, forbidden);
          break;
        case 114:
          acodec.encode(enc_arr[1][14][direction3], aMSC_114, forbidden);
          break;
        case 115:
          acodec.encode(enc_arr[1][15][direction3], aMSC_115, forbidden);
          break;
        case 116:
          acodec.encode(enc_arr[1][16][direction3], aMSC_116, forbidden);
          break;
        case 117:
          acodec.encode(enc_arr[1][17][direction3], aMSC_117, forbidden);
          break;
        case 118:
          acodec.encode(enc_arr[1][18][direction3], aMSC_118, forbidden);
          break;
        case 119:
          acodec.encode(enc_arr[1][19][direction3], aMSC_119, forbidden);
          break;
        case 120:
          acodec.encode(enc_arr[1][20][direction3], aMSC_120, forbidden);
          break;
        case 121:
          acodec.encode(enc_arr[1][21][direction3], aMSC_121, forbidden);
          break;
        case 122:
          acodec.encode(enc_arr[1][22][direction3], aMSC_122, forbidden);
          break;
        case 123:
          acodec.encode(enc_arr[1][23][direction3], aMSC_123, forbidden);
          break;
        case 124:
          acodec.encode(enc_arr[1][24][direction3], aMSC_124, forbidden);
          break;
        case 125:
          acodec.encode(enc_arr[1][25][direction3], aMSC_125, forbidden);
          break;
        case 126:
          acodec.encode(enc_arr[1][26][direction3], aMSC_126, forbidden);
          break;
        case 200:
          acodec.encode(enc_arr[2][0][direction3], aMSC_20, forbidden);
          break;
        case 201:
          acodec.encode(enc_arr[2][1][direction3], aMSC_21, forbidden);
          break;
        case 202:
          acodec.encode(enc_arr[2][2][direction3], aMSC_22, forbidden);
          break;
        case 203:
          acodec.encode(enc_arr[2][3][direction3], aMSC_23, forbidden);
          break;
        case 204:
          acodec.encode(enc_arr[2][4][direction3], aMSC_24, forbidden);
          break;
        case 205:
          acodec.encode(enc_arr[2][5][direction3], aMSC_25, forbidden);
          break;
        case 206:
          acodec.encode(enc_arr[2][6][direction3], aMSC_26, forbidden);
          break;
        case 207:
          acodec.encode(enc_arr[2][7][direction3], aMSC_27, forbidden);
          break;
        case 208:
          acodec.encode(enc_arr[2][8][direction3], aMSC_28, forbidden);
          break;
        case 209:
          acodec.encode(enc_arr[2][9][direction3], aMSC_29, forbidden);
          break;
        case 210:
          acodec.encode(enc_arr[2][10][direction3], aMSC_210, forbidden);
          break;
        case 211:
          acodec.encode(enc_arr[2][11][direction3], aMSC_211, forbidden);
          break;
        case 212:
          acodec.encode(enc_arr[2][12][direction3], aMSC_212, forbidden);
          break;
        case 213:
          acodec.encode(enc_arr[2][13][direction3], aMSC_213, forbidden);
          break;
        case 214:
          acodec.encode(enc_arr[2][14][direction3], aMSC_214, forbidden);
          break;
        case 215:
          acodec.encode(enc_arr[2][15][direction3], aMSC_215, forbidden);
          break;
        case 216:
          acodec.encode(enc_arr[2][16][direction3], aMSC_216, forbidden);
          break;
        case 217:
          acodec.encode(enc_arr[2][17][direction3], aMSC_217, forbidden);
          break;
        case 218:
          acodec.encode(enc_arr[2][18][direction3], aMSC_218, forbidden);
          break;
        case 219:
          acodec.encode(enc_arr[2][19][direction3], aMSC_219, forbidden);
          break;
        case 220:
          acodec.encode(enc_arr[2][20][direction3], aMSC_220, forbidden);
          break;
        case 221:
          acodec.encode(enc_arr[2][21][direction3], aMSC_221, forbidden);
          break;
        case 222:
          acodec.encode(enc_arr[2][22][direction3], aMSC_222, forbidden);
          break;
        case 223:
          acodec.encode(enc_arr[2][23][direction3], aMSC_223, forbidden);
          break;
        case 224:
          acodec.encode(enc_arr[2][24][direction3], aMSC_224, forbidden);
          break;
        case 225:
          acodec.encode(enc_arr[2][25][direction3], aMSC_225, forbidden);
          break;
        case 226:
          acodec.encode(enc_arr[2][26][direction3], aMSC_226, forbidden);
          break;
        case 300:
          acodec.encode(enc_arr[3][0][direction3], aMSC_30, forbidden);
          break;
        case 301:
          acodec.encode(enc_arr[3][1][direction3], aMSC_31, forbidden);
          break;
        case 302:
          acodec.encode(enc_arr[3][2][direction3], aMSC_32, forbidden);
          break;
        case 303:
          acodec.encode(enc_arr[3][3][direction3], aMSC_33, forbidden);
          break;
        case 304:
          acodec.encode(enc_arr[3][4][direction3], aMSC_34, forbidden);
          break;
        case 305:
          acodec.encode(enc_arr[3][5][direction3], aMSC_35, forbidden);
          break;
        case 306:
          acodec.encode(enc_arr[3][6][direction3], aMSC_36, forbidden);
          break;
        case 307:
          acodec.encode(enc_arr[3][7][direction3], aMSC_37, forbidden);
          break;
        case 308:
          acodec.encode(enc_arr[3][8][direction3], aMSC_38, forbidden);
          break;
        case 309:
          acodec.encode(enc_arr[3][9][direction3], aMSC_39, forbidden);
          break;
        case 310:
          acodec.encode(enc_arr[3][10][direction3], aMSC_310, forbidden);
          break;
        case 311:
          acodec.encode(enc_arr[3][11][direction3], aMSC_311, forbidden);
          break;
        case 312:
          acodec.encode(enc_arr[3][12][direction3], aMSC_312, forbidden);
          break;
        case 313:
          acodec.encode(enc_arr[3][13][direction3], aMSC_313, forbidden);
          break;
        case 314:
          acodec.encode(enc_arr[3][14][direction3], aMSC_314, forbidden);
          break;
        case 315:
          acodec.encode(enc_arr[3][15][direction3], aMSC_315, forbidden);
          break;
        case 316:
          acodec.encode(enc_arr[3][16][direction3], aMSC_316, forbidden);
          break;
        case 317:
          acodec.encode(enc_arr[3][17][direction3], aMSC_317, forbidden);
          break;
        case 318:
          acodec.encode(enc_arr[3][18][direction3], aMSC_318, forbidden);
          break;
        case 319:
          acodec.encode(enc_arr[3][19][direction3], aMSC_319, forbidden);
          break;
        case 320:
          acodec.encode(enc_arr[3][20][direction3], aMSC_320, forbidden);
          break;
        case 321:
          acodec.encode(enc_arr[3][21][direction3], aMSC_321, forbidden);
          break;
        case 322:
          acodec.encode(enc_arr[3][22][direction3], aMSC_322, forbidden);
          break;
        case 323:
          acodec.encode(enc_arr[3][23][direction3], aMSC_323, forbidden);
          break;
        case 324:
          acodec.encode(enc_arr[3][24][direction3], aMSC_324, forbidden);
          break;
        case 325:
          acodec.encode(enc_arr[3][25][direction3], aMSC_325, forbidden);
          break;
        case 326:
          acodec.encode(enc_arr[3][26][direction3], aMSC_326, forbidden);
          break;
        case 400:
          acodec.encode(enc_arr[4][0][direction3], aMSC_40, forbidden);
          break;
        case 401:
          acodec.encode(enc_arr[4][1][direction3], aMSC_41, forbidden);
          break;
        case 402:
          acodec.encode(enc_arr[4][2][direction3], aMSC_42, forbidden);
          break;
        case 403:
          acodec.encode(enc_arr[4][3][direction3], aMSC_43, forbidden);
          break;
        case 404:
          acodec.encode(enc_arr[4][4][direction3], aMSC_44, forbidden);
          break;
        case 405:
          acodec.encode(enc_arr[4][5][direction3], aMSC_45, forbidden);
          break;
        case 406:
          acodec.encode(enc_arr[4][6][direction3], aMSC_46, forbidden);
          break;
        case 407:
          acodec.encode(enc_arr[4][7][direction3], aMSC_47, forbidden);
          break;
        case 408:
          acodec.encode(enc_arr[4][8][direction3], aMSC_48, forbidden);
          break;
        case 409:
          acodec.encode(enc_arr[4][9][direction3], aMSC_49, forbidden);
          break;
        case 410:
          acodec.encode(enc_arr[4][10][direction3], aMSC_410, forbidden);
          break;
        case 411:
          acodec.encode(enc_arr[4][11][direction3], aMSC_411, forbidden);
          break;
        case 412:
          acodec.encode(enc_arr[4][12][direction3], aMSC_412, forbidden);
          break;
        case 413:
          acodec.encode(enc_arr[4][13][direction3], aMSC_413, forbidden);
          break;
        case 414:
          acodec.encode(enc_arr[4][14][direction3], aMSC_414, forbidden);
          break;
        case 415:
          acodec.encode(enc_arr[4][15][direction3], aMSC_415, forbidden);
          break;
        case 416:
          acodec.encode(enc_arr[4][16][direction3], aMSC_416, forbidden);
          break;
        case 417:
          acodec.encode(enc_arr[4][17][direction3], aMSC_417, forbidden);
          break;
        case 418:
          acodec.encode(enc_arr[4][18][direction3], aMSC_418, forbidden);
          break;
        case 419:
          acodec.encode(enc_arr[4][19][direction3], aMSC_419, forbidden);
          break;
        case 420:
          acodec.encode(enc_arr[4][20][direction3], aMSC_420, forbidden);
          break;
        case 421:
          acodec.encode(enc_arr[4][21][direction3], aMSC_421, forbidden);
          break;
        case 422:
          acodec.encode(enc_arr[4][22][direction3], aMSC_422, forbidden);
          break;
        case 423:
          acodec.encode(enc_arr[4][23][direction3], aMSC_423, forbidden);
          break;
        case 424:
          acodec.encode(enc_arr[4][24][direction3], aMSC_424, forbidden);
          break;
        case 425:
          acodec.encode(enc_arr[4][25][direction3], aMSC_425, forbidden);
          break;
        case 426:
          acodec.encode(enc_arr[4][26][direction3], aMSC_426, forbidden);
          break;
        case 500:
          acodec.encode(enc_arr[5][0][direction3], aMSC_50, forbidden);
          break;
        case 501:
          acodec.encode(enc_arr[5][1][direction3], aMSC_51, forbidden);
          break;
        case 502:
          acodec.encode(enc_arr[5][2][direction3], aMSC_52, forbidden);
          break;
        case 503:
          acodec.encode(enc_arr[5][3][direction3], aMSC_53, forbidden);
          break;
        case 504:
          acodec.encode(enc_arr[5][4][direction3], aMSC_54, forbidden);
          break;
        case 505:
          acodec.encode(enc_arr[5][5][direction3], aMSC_55, forbidden);
          break;
        case 506:
          acodec.encode(enc_arr[5][6][direction3], aMSC_56, forbidden);
          break;
        case 507:
          acodec.encode(enc_arr[5][7][direction3], aMSC_57, forbidden);
          break;
        case 508:
          acodec.encode(enc_arr[5][8][direction3], aMSC_58, forbidden);
          break;
        case 509:
          acodec.encode(enc_arr[5][9][direction3], aMSC_59, forbidden);
          break;
        case 510:
          acodec.encode(enc_arr[5][10][direction3], aMSC_510, forbidden);
          break;
        case 511:
          acodec.encode(enc_arr[5][11][direction3], aMSC_511, forbidden);
          break;
        case 512:
          acodec.encode(enc_arr[5][12][direction3], aMSC_512, forbidden);
          break;
        case 513:
          acodec.encode(enc_arr[5][13][direction3], aMSC_513, forbidden);
          break;
        case 514:
          acodec.encode(enc_arr[5][14][direction3], aMSC_514, forbidden);
          break;
        case 515:
          acodec.encode(enc_arr[5][15][direction3], aMSC_515, forbidden);
          break;
        case 516:
          acodec.encode(enc_arr[5][16][direction3], aMSC_516, forbidden);
          break;
        case 517:
          acodec.encode(enc_arr[5][17][direction3], aMSC_517, forbidden);
          break;
        case 518:
          acodec.encode(enc_arr[5][18][direction3], aMSC_518, forbidden);
          break;
        case 519:
          acodec.encode(enc_arr[5][19][direction3], aMSC_519, forbidden);
          break;
        case 520:
          acodec.encode(enc_arr[5][20][direction3], aMSC_520, forbidden);
          break;
        case 521:
          acodec.encode(enc_arr[5][21][direction3], aMSC_521, forbidden);
          break;
        case 522:
          acodec.encode(enc_arr[5][22][direction3], aMSC_522, forbidden);
          break;
        case 523:
          acodec.encode(enc_arr[5][23][direction3], aMSC_523, forbidden);
          break;
        case 524:
          acodec.encode(enc_arr[5][24][direction3], aMSC_524, forbidden);
          break;
        case 525:
          acodec.encode(enc_arr[5][25][direction3], aMSC_525, forbidden);
          break;
        case 526:
          acodec.encode(enc_arr[5][26][direction3], aMSC_526, forbidden);
          break;
        case 600:
          acodec.encode(enc_arr[6][0][direction3], aMSC_60, forbidden);
          break;
        case 601:
          acodec.encode(enc_arr[6][1][direction3], aMSC_61, forbidden);
          break;
        case 602:
          acodec.encode(enc_arr[6][2][direction3], aMSC_62, forbidden);
          break;
        case 603:
          acodec.encode(enc_arr[6][3][direction3], aMSC_63, forbidden);
          break;
        case 604:
          acodec.encode(enc_arr[6][4][direction3], aMSC_64, forbidden);
          break;
        case 605:
          acodec.encode(enc_arr[6][5][direction3], aMSC_65, forbidden);
          break;
        case 606:
          acodec.encode(enc_arr[6][6][direction3], aMSC_66, forbidden);
          break;
        case 607:
          acodec.encode(enc_arr[6][7][direction3], aMSC_67, forbidden);
          break;
        case 608:
          acodec.encode(enc_arr[6][8][direction3], aMSC_68, forbidden);
          break;
        case 609:
          acodec.encode(enc_arr[6][9][direction3], aMSC_69, forbidden);
          break;
        case 610:
          acodec.encode(enc_arr[6][10][direction3], aMSC_610, forbidden);
          break;
        case 611:
          acodec.encode(enc_arr[6][11][direction3], aMSC_611, forbidden);
          break;
        case 612:
          acodec.encode(enc_arr[6][12][direction3], aMSC_612, forbidden);
          break;
        case 613:
          acodec.encode(enc_arr[6][13][direction3], aMSC_613, forbidden);
          break;
        case 614:
          acodec.encode(enc_arr[6][14][direction3], aMSC_614, forbidden);
          break;
        case 615:
          acodec.encode(enc_arr[6][15][direction3], aMSC_615, forbidden);
          break;
        case 616:
          acodec.encode(enc_arr[6][16][direction3], aMSC_616, forbidden);
          break;
        case 617:
          acodec.encode(enc_arr[6][17][direction3], aMSC_617, forbidden);
          break;
        case 618:
          acodec.encode(enc_arr[6][18][direction3], aMSC_618, forbidden);
          break;
        case 619:
          acodec.encode(enc_arr[6][19][direction3], aMSC_619, forbidden);
          break;
        case 620:
          acodec.encode(enc_arr[6][20][direction3], aMSC_620, forbidden);
          break;
        case 621:
          acodec.encode(enc_arr[6][21][direction3], aMSC_621, forbidden);
          break;
        case 622:
          acodec.encode(enc_arr[6][22][direction3], aMSC_622, forbidden);
          break;
        case 623:
          acodec.encode(enc_arr[6][23][direction3], aMSC_623, forbidden);
          break;
        case 624:
          acodec.encode(enc_arr[6][24][direction3], aMSC_624, forbidden);
          break;
        case 625:
          acodec.encode(enc_arr[6][25][direction3], aMSC_625, forbidden);
          break;
        case 626:
          acodec.encode(enc_arr[6][26][direction3], aMSC_626, forbidden);
          break;
        case 700:
          acodec.encode(enc_arr[7][0][direction3], aMSC_70, forbidden);
          break;
        case 701:
          acodec.encode(enc_arr[7][1][direction3], aMSC_71, forbidden);
          break;
        case 702:
          acodec.encode(enc_arr[7][2][direction3], aMSC_72, forbidden);
          break;
        case 703:
          acodec.encode(enc_arr[7][3][direction3], aMSC_73, forbidden);
          break;
        case 704:
          acodec.encode(enc_arr[7][4][direction3], aMSC_74, forbidden);
          break;
        case 705:
          acodec.encode(enc_arr[7][5][direction3], aMSC_75, forbidden);
          break;
        case 706:
          acodec.encode(enc_arr[7][6][direction3], aMSC_76, forbidden);
          break;
        case 707:
          acodec.encode(enc_arr[7][7][direction3], aMSC_77, forbidden);
          break;
        case 708:
          acodec.encode(enc_arr[7][8][direction3], aMSC_78, forbidden);
          break;
        case 709:
          acodec.encode(enc_arr[7][9][direction3], aMSC_79, forbidden);
          break;
        case 710:
          acodec.encode(enc_arr[7][10][direction3], aMSC_710, forbidden);
          break;
        case 711:
          acodec.encode(enc_arr[7][11][direction3], aMSC_711, forbidden);
          break;
        case 712:
          acodec.encode(enc_arr[7][12][direction3], aMSC_712, forbidden);
          break;
        case 713:
          acodec.encode(enc_arr[7][13][direction3], aMSC_713, forbidden);
          break;
        case 714:
          acodec.encode(enc_arr[7][14][direction3], aMSC_714, forbidden);
          break;
        case 715:
          acodec.encode(enc_arr[7][15][direction3], aMSC_715, forbidden);
          break;
        case 716:
          acodec.encode(enc_arr[7][16][direction3], aMSC_716, forbidden);
          break;
        case 717:
          acodec.encode(enc_arr[7][17][direction3], aMSC_717, forbidden);
          break;
        case 718:
          acodec.encode(enc_arr[7][18][direction3], aMSC_718, forbidden);
          break;
        case 719:
          acodec.encode(enc_arr[7][19][direction3], aMSC_719, forbidden);
          break;
        case 720:
          acodec.encode(enc_arr[7][20][direction3], aMSC_720, forbidden);
          break;
        case 721:
          acodec.encode(enc_arr[7][21][direction3], aMSC_721, forbidden);
          break;
        case 722:
          acodec.encode(enc_arr[7][22][direction3], aMSC_722, forbidden);
          break;
        case 723:
          acodec.encode(enc_arr[7][23][direction3], aMSC_723, forbidden);
          break;
        case 724:
          acodec.encode(enc_arr[7][24][direction3], aMSC_724, forbidden);
          break;
        case 725:
          acodec.encode(enc_arr[7][25][direction3], aMSC_725, forbidden);
          break;
        case 726:
          acodec.encode(enc_arr[7][26][direction3], aMSC_726, forbidden);
          break;
        case 800:
          acodec.encode(enc_arr[8][0][direction3], aMSC_80, forbidden);
          break;
        case 801:
          acodec.encode(enc_arr[8][1][direction3], aMSC_81, forbidden);
          break;
        case 802:
          acodec.encode(enc_arr[8][2][direction3], aMSC_82, forbidden);
          break;
        case 803:
          acodec.encode(enc_arr[8][3][direction3], aMSC_83, forbidden);
          break;
        case 804:
          acodec.encode(enc_arr[8][4][direction3], aMSC_84, forbidden);
          break;
        case 805:
          acodec.encode(enc_arr[8][5][direction3], aMSC_85, forbidden);
          break;
        case 806:
          acodec.encode(enc_arr[8][6][direction3], aMSC_86, forbidden);
          break;
        case 807:
          acodec.encode(enc_arr[8][7][direction3], aMSC_87, forbidden);
          break;
        case 808:
          acodec.encode(enc_arr[8][8][direction3], aMSC_88, forbidden);
          break;
        case 809:
          acodec.encode(enc_arr[8][9][direction3], aMSC_89, forbidden);
          break;
        case 810:
          acodec.encode(enc_arr[8][10][direction3], aMSC_810, forbidden);
          break;
        case 811:
          acodec.encode(enc_arr[8][11][direction3], aMSC_811, forbidden);
          break;
        case 812:
          acodec.encode(enc_arr[8][12][direction3], aMSC_812, forbidden);
          break;
        case 813:
          acodec.encode(enc_arr[8][13][direction3], aMSC_813, forbidden);
          break;
        case 814:
          acodec.encode(enc_arr[8][14][direction3], aMSC_814, forbidden);
          break;
        case 815:
          acodec.encode(enc_arr[8][15][direction3], aMSC_815, forbidden);
          break;
        case 816:
          acodec.encode(enc_arr[8][16][direction3], aMSC_816, forbidden);
          break;
        case 817:
          acodec.encode(enc_arr[8][17][direction3], aMSC_817, forbidden);
          break;
        case 818:
          acodec.encode(enc_arr[8][18][direction3], aMSC_818, forbidden);
          break;
        case 819:
          acodec.encode(enc_arr[8][19][direction3], aMSC_819, forbidden);
          break;
        case 820:
          acodec.encode(enc_arr[8][20][direction3], aMSC_820, forbidden);
          break;
        case 821:
          acodec.encode(enc_arr[8][21][direction3], aMSC_821, forbidden);
          break;
        case 822:
          acodec.encode(enc_arr[8][22][direction3], aMSC_822, forbidden);
          break;
        case 823:
          acodec.encode(enc_arr[8][23][direction3], aMSC_823, forbidden);
          break;
        case 824:
          acodec.encode(enc_arr[8][24][direction3], aMSC_824, forbidden);
          break;
        case 825:
          acodec.encode(enc_arr[8][25][direction3], aMSC_825, forbidden);
          break;
        case 826:
          acodec.encode(enc_arr[8][26][direction3], aMSC_826, forbidden);
          break;
        }
      } else if (overlap[i - 1] == 2) {
        runLength--;
        if (runLength == 0)
          newzero = true;
      }

      direction1 = direction2;
      direction2 = direction3;
      adapt_position(&x, &y, edge[i]);
    }

    // printf("%d %d\n", loc_y, loc_x);
    // for (int i = 0; i < edge[0]; i++)
    //{
    //	printf("%d ", edge[i+1]);
    // }
    // printf("\n");
    // for (int i = 0; i < edge[0]; i++)
    //{
    //	printf("%d ", overlap[i]);
    // }
    // printf("\n");
  } else {
    int direction1, direction2, index;
    for (int i = 1; i < edge[0] + 1; i++) {
      if (i == 1 || overlap[i - 1] == 2)
        continue;
      direction1 = get_direction1(edge[i - 1], &index);
      direction2 = get_RMSC(index, edge[i]);
      aMSC[direction2]++;
    }
  }
}

int to_3OT(int direct_pre, int direct_cur, int *turn) {
  if (direct_cur == direct_pre)
    return 0;
  else if ((direct_cur - direct_pre + 4) % 4 == 1) {
    if (*turn == 0)
      return 2;
    else {
      *turn = 0;
      return 1;
    }
  } else if ((direct_cur - direct_pre + 4) % 4 == 3) {
    if (*turn == 1)
      return 2;
    else {
      *turn = 1;
      return 1;
    }
  }
}

int get_position_3OT(int x, int y, int pic_w, int pic_h) {
  if (x == 0)
    return y;
  else if (y == pic_h)
    return pic_h + x;
  else if (x == pic_w)
    return 2 * pic_h + pic_w - y;
  else if (y == 0)
    return 2 * pic_h + 2 * pic_w - x;
  else
    return 2 * pic_h + 2 * pic_w;
}

void get_forbidden_3OT(int x, int y, int pic_w, int pic_h, int pre_direction,
                       int turn, int *forbidden, bool boundary, int start_index,
                       int high_point, int left_point) {
  int forbidden_num = 0;
  int cur_direction;
  int x_cur, y_cur;
  for (int direction = 0; direction < 3; direction++) {
    if (direction == 0)
      cur_direction = pre_direction;
    else if (direction == 1) {
      if (turn == 0)
        cur_direction = (pre_direction + 3) % 4;
      else
        cur_direction = (pre_direction + 1) % 4;
    } else {
      if (turn == 0)
        cur_direction = (pre_direction + 1) % 4;
      else
        cur_direction = (pre_direction + 3) % 4;
    }

    x_cur = x;
    y_cur = y;
    switch (cur_direction) {
    case 0:
      x_cur++;
      break;
    case 1:
      y_cur--;
      break;
    case 2:
      x_cur--;
      break;
    case 3:
      y_cur++;
      break;
    }
    if ((x_cur == pic_w || x_cur == 0 || y_cur == 0 || y_cur == pic_h) &&
        get_position_3OT(x_cur, y_cur, pic_w, pic_h) <= start_index) {
      forbidden_num++;
      forbidden[forbidden_num] = direction;
    } else if ((y_cur < high_point && x_cur > left_point) ||
               (y_cur <= high_point && x_cur <= left_point)) {
      forbidden_num++;
      forbidden[forbidden_num] = direction;
    }
    // else if (y_cur < pic_h && x_cur < pic_w && encCodedMap[y_cur*pic_w +
    // x_cur]) { forbidden_num++; forbidden[forbidden_num] = direction; }
  }
  forbidden[0] = forbidden_num;
}

void adapt_position_3OT(int *x, int *y, int direction) {
  switch (direction) {
  case 0:
    *x += 1;
    break;
  case 1:
    *y -= 1;
    break;
  case 2:
    *x -= 1;
    break;
  case 3:
    *y += 1;
    break;
  }
}

void encodeEdgeLength_3OT(CodingUnit *CU) {
  int *edge = CU->Edge_3OT;
  int *overlap = CU->Overlap_3OT;

  int loc_y = CU->location_row;
  int loc_x = CU->location_col;
  int pic_h = CU->pic_height;
  int pic_w = CU->pic_width;
  int forbidden[5] = {0};
  // for (int k = 0; k < pic_h*pic_w; k++) encCodedMap[k] = 0;

  int x = loc_x, y = loc_y;

  if (loc_x == 0)
    ;
  else if (loc_y == pic_h - 1)
    y++;
  else if (loc_x == pic_w - 1) {
    x++;
    y++;
  } else if (loc_y == 0)
    x++;

  int start_index = get_position_3OT(x, y, pic_w, pic_h);

  int pre_direction;
  if (loc_x == 0) {
    x++;
    pre_direction = 0;
  } else if (loc_y == pic_h - 1) {
    y--;
    pre_direction = 1;
  } else if (loc_x == pic_w - 1) {
    x--;
    pre_direction = 2;
  } else if (loc_y == 0) {
    y++;
    pre_direction = 3;
  } else {
    x++;
    pre_direction = 0;
  }

  // encCodedMap[y*pic_w + x] = 1;

  bool boundary = false;
  if (loc_x == 0 || loc_x == pic_w - 1 || loc_y == 0 || loc_y == pic_h - 1)
    boundary = true;

  int high_point = loc_y;
  if (boundary)
    high_point = -1;
  int left_point = loc_x;
  if (boundary)
    left_point = -1;

  int direction1, direction2, direction3, direction4, direct_cur;
  int turn = 0; // left
  if (!boundary)
    turn = 1; // right

  int runLength = 0;
  bool end;

  if (overlap[0] == 1 && runLength == 0) {
    end = true;
    for (int j = 1; j < edge[0] + 1; j++) {
      if (overlap[j] < 2) {
        end = false;
        break;
      } else
        runLength++;
    }
    acodec.encode(end, aEndFlag);
    if (!end)
      encGolomb(runLength, 0, 3);
  }
  if (overlap[1] < 2) {
    get_forbidden_3OT(x, y, pic_w, pic_h, pre_direction, turn, forbidden,
                      boundary, start_index, high_point, left_point);

    if (boundary) {
      if (loc_x == 0) {
        direct_cur = to_3OT(pre_direction, edge[1], &turn);
        acodec.encode(direct_cur, a3OT_L, forbidden);
      } else if (loc_y == pic_h - 1) {
        direct_cur = to_3OT(pre_direction, edge[1], &turn);
        acodec.encode(direct_cur, a3OT_B, forbidden);
      } else if (loc_x == pic_w - 1) {
        direct_cur = to_3OT(pre_direction, edge[1], &turn);
        acodec.encode(direct_cur, a3OT_R, forbidden);
      } else if (loc_y == 0) {
        direct_cur = to_3OT(pre_direction, edge[1], &turn);
        acodec.encode(direct_cur, a3OT_A, forbidden);
      }
    } else {
      direct_cur = to_3OT(pre_direction, edge[1], &turn);
      acodec.encode(direct_cur, a3OT_I, forbidden);
    }
  } else if (overlap[1] == 2) {
    direct_cur = to_3OT(pre_direction, edge[1], &turn);
    runLength--;
  }
  direction1 = direct_cur;
  adapt_position_3OT(&x, &y, edge[1]);

  if (edge[0] > 1) {
    if (overlap[1] == 1 && runLength == 0) {
      end = true;
      for (int j = 2; j < edge[0] + 1; j++) {
        if (overlap[j] < 2) {
          end = false;
          break;
        } else
          runLength++;
      }
      acodec.encode(end, aEndFlag);
      if (!end)
        encGolomb(runLength, 0, 3);
    }
    if (overlap[2] < 2) {
      // encCodedMap[y*pic_w + x] = 1;
      get_forbidden_3OT(x, y, pic_w, pic_h, edge[1], turn, forbidden, boundary,
                        start_index, high_point, left_point);
      direction2 = to_3OT(edge[1], edge[2], &turn);
      switch (direction1) {
      case 0:
        acodec.encode(direction2, a3OT_0, forbidden);
        break;
      case 1:
        acodec.encode(direction2, a3OT_1, forbidden);
        break;
      case 2:
        acodec.encode(direction2, a3OT_2, forbidden);
        break;
      }
    } else if (overlap[2] == 2) {
      direction2 = to_3OT(edge[1], edge[2], &turn);
      runLength--;
    }
    adapt_position_3OT(&x, &y, edge[2]);
  }

  if (edge[0] > 2) {
    if (overlap[2] == 1 && runLength == 0) {
      end = true;
      for (int j = 3; j < edge[0] + 1; j++) {
        if (overlap[j] < 2) {
          end = false;
          break;
        } else
          runLength++;
      }
      acodec.encode(end, aEndFlag);
      if (!end)
        encGolomb(runLength, 0, 3);
    }
    if (overlap[3] < 2) {
      // encCodedMap[y*pic_w + x] = 1;
      get_forbidden_3OT(x, y, pic_w, pic_h, edge[2], turn, forbidden, boundary,
                        start_index, high_point, left_point);
      direction3 = to_3OT(edge[2], edge[3], &turn);
      switch (direction1 * 3 + direction2) {
      case 0:
        acodec.encode(direction3, a3OT_00, forbidden);
        break;
      case 1:
        acodec.encode(direction3, a3OT_01, forbidden);
        break;
      case 2:
        acodec.encode(direction3, a3OT_02, forbidden);
        break;
      case 3:
        acodec.encode(direction3, a3OT_10, forbidden);
        break;
      case 4:
        acodec.encode(direction3, a3OT_11, forbidden);
        break;
      case 5:
        acodec.encode(direction3, a3OT_12, forbidden);
        break;
      case 6:
        acodec.encode(direction3, a3OT_20, forbidden);
        break;
      case 7:
        acodec.encode(direction3, a3OT_21, forbidden);
        break;
      case 8:
        acodec.encode(direction3, a3OT_22, forbidden);
        break;
      }
    } else if (overlap[3] == 2) {
      direction3 = to_3OT(edge[2], edge[3], &turn);
      runLength--;
    }
    adapt_position_3OT(&x, &y, edge[3]);
  }

  if (edge[0] > 3) {
    if (overlap[3] == 1 && runLength == 0) {
      end = true;
      for (int j = 4; j < edge[0] + 1; j++) {
        if (overlap[j] < 2) {
          end = false;
          break;
        } else
          runLength++;
      }
      acodec.encode(end, aEndFlag);
      if (!end)
        encGolomb(runLength, 0, 3);
    }
    if (overlap[4] < 2) {
      // encCodedMap[y*pic_w + x] = 1;
      get_forbidden_3OT(x, y, pic_w, pic_h, edge[3], turn, forbidden, boundary,
                        start_index, high_point, left_point);
      direction4 = to_3OT(edge[3], edge[4], &turn);
      switch (direction1 * 9 + direction2 * 3 + direction3) {
      case 0:
        acodec.encode(direction4, a3OT_000, forbidden);
        break;
      case 1:
        acodec.encode(direction4, a3OT_001, forbidden);
        break;
      case 2:
        acodec.encode(direction4, a3OT_002, forbidden);
        break;
      case 3:
        acodec.encode(direction4, a3OT_010, forbidden);
        break;
      case 4:
        acodec.encode(direction4, a3OT_011, forbidden);
        break;
      case 5:
        acodec.encode(direction4, a3OT_012, forbidden);
        break;
      case 6:
        acodec.encode(direction4, a3OT_020, forbidden);
        break;
      case 7:
        acodec.encode(direction4, a3OT_021, forbidden);
        break;
      case 8:
        acodec.encode(direction4, a3OT_022, forbidden);
        break;
      case 9:
        acodec.encode(direction4, a3OT_100, forbidden);
        break;
      case 10:
        acodec.encode(direction4, a3OT_101, forbidden);
        break;
      case 11:
        acodec.encode(direction4, a3OT_102, forbidden);
        break;
      case 12:
        acodec.encode(direction4, a3OT_110, forbidden);
        break;
      case 13:
        acodec.encode(direction4, a3OT_111, forbidden);
        break;
      case 14:
        acodec.encode(direction4, a3OT_112, forbidden);
        break;
      case 15:
        acodec.encode(direction4, a3OT_120, forbidden);
        break;
      case 16:
        acodec.encode(direction4, a3OT_121, forbidden);
        break;
      case 17:
        acodec.encode(direction4, a3OT_122, forbidden);
        break;
      case 18:
        acodec.encode(direction4, a3OT_200, forbidden);
        break;
      case 19:
        acodec.encode(direction4, a3OT_201, forbidden);
        break;
      case 20:
        acodec.encode(direction4, a3OT_202, forbidden);
        break;
      case 21:
        acodec.encode(direction4, a3OT_210, forbidden);
        break;
      case 22:
        acodec.encode(direction4, a3OT_211, forbidden);
        break;
      case 23:
        acodec.encode(direction4, a3OT_212, forbidden);
        break;
      case 24:
        acodec.encode(direction4, a3OT_220, forbidden);
        break;
      case 25:
        acodec.encode(direction4, a3OT_221, forbidden);
        break;
      case 26:
        acodec.encode(direction4, a3OT_222, forbidden);
        break;
      }
    } else if (overlap[4] == 2) {
      direction4 = to_3OT(edge[3], edge[4], &turn);
      runLength--;
    }
    adapt_position_3OT(&x, &y, edge[4]);
  }

  for (int i = 5; i < edge[0] + 1; i++) {
    if (overlap[i - 1] == 1 && runLength == 0) {
      end = true;
      for (int j = i; j < edge[0] + 1; j++) {
        if (overlap[j] < 2) {
          end = false;
          break;
        } else
          runLength++;
      }
      acodec.encode(end, aEndFlag);
      if (!end)
        encGolomb(runLength, 0, 3);
    }
    if (overlap[i] < 2) {
      // encCodedMap[y*pic_w + x] = 1;
      get_forbidden_3OT(x, y, pic_w, pic_h, edge[i - 1], turn, forbidden,
                        boundary, start_index, high_point, left_point);
      direct_cur = to_3OT(edge[i - 1], edge[i], &turn);
      // if (edge[i] == 2)
      //{
      //	edge[i] = 2;
      // }

      switch (direction1 * 27 + direction2 * 9 + direction3 * 3 + direction4) {
      case 0:
        acodec.encode(direct_cur, a3OT_0000, forbidden);
        break;
      case 1:
        acodec.encode(direct_cur, a3OT_0001, forbidden);
        break;
      case 2:
        acodec.encode(direct_cur, a3OT_0002, forbidden);
        break;
      case 3:
        acodec.encode(direct_cur, a3OT_0010, forbidden);
        break;
      case 4:
        acodec.encode(direct_cur, a3OT_0011, forbidden);
        break;
      case 5:
        acodec.encode(direct_cur, a3OT_0012, forbidden);
        break;
      case 6:
        acodec.encode(direct_cur, a3OT_0020, forbidden);
        break;
      case 7:
        acodec.encode(direct_cur, a3OT_0021, forbidden);
        break;
      case 8:
        acodec.encode(direct_cur, a3OT_0022, forbidden);
        break;
      case 9:
        acodec.encode(direct_cur, a3OT_0100, forbidden);
        break;
      case 10:
        acodec.encode(direct_cur, a3OT_0101, forbidden);
        break;
      case 11:
        acodec.encode(direct_cur, a3OT_0102, forbidden);
        break;
      case 12:
        acodec.encode(direct_cur, a3OT_0110, forbidden);
        break;
      case 13:
        acodec.encode(direct_cur, a3OT_0111, forbidden);
        break;
      case 14:
        acodec.encode(direct_cur, a3OT_0112, forbidden);
        break;
      case 15:
        acodec.encode(direct_cur, a3OT_0120, forbidden);
        break;
      case 16:
        acodec.encode(direct_cur, a3OT_0121, forbidden);
        break;
      case 17:
        acodec.encode(direct_cur, a3OT_0122, forbidden);
        break;
      case 18:
        acodec.encode(direct_cur, a3OT_0200, forbidden);
        break;
      case 19:
        acodec.encode(direct_cur, a3OT_0201, forbidden);
        break;
      case 20:
        acodec.encode(direct_cur, a3OT_0202, forbidden);
        break;
      case 21:
        acodec.encode(direct_cur, a3OT_0210, forbidden);
        break;
      case 22:
        acodec.encode(direct_cur, a3OT_0211, forbidden);
        break;
      case 23:
        acodec.encode(direct_cur, a3OT_0212, forbidden);
        break;
      case 24:
        acodec.encode(direct_cur, a3OT_0220, forbidden);
        break;
      case 25:
        acodec.encode(direct_cur, a3OT_0221, forbidden);
        break;
      case 26:
        acodec.encode(direct_cur, a3OT_0222, forbidden);
        break;
      case 27:
        acodec.encode(direct_cur, a3OT_1000, forbidden);
        break;
      case 28:
        acodec.encode(direct_cur, a3OT_1001, forbidden);
        break;
      case 29:
        acodec.encode(direct_cur, a3OT_1002, forbidden);
        break;
      case 30:
        acodec.encode(direct_cur, a3OT_1010, forbidden);
        break;
      case 31:
        acodec.encode(direct_cur, a3OT_1011, forbidden);
        break;
      case 32:
        acodec.encode(direct_cur, a3OT_1012, forbidden);
        break;
      case 33:
        acodec.encode(direct_cur, a3OT_1020, forbidden);
        break;
      case 34:
        acodec.encode(direct_cur, a3OT_1021, forbidden);
        break;
      case 35:
        acodec.encode(direct_cur, a3OT_1022, forbidden);
        break;
      case 36:
        acodec.encode(direct_cur, a3OT_1100, forbidden);
        break;
      case 37:
        acodec.encode(direct_cur, a3OT_1101, forbidden);
        break;
      case 38:
        acodec.encode(direct_cur, a3OT_1102, forbidden);
        break;
      case 39:
        acodec.encode(direct_cur, a3OT_1110, forbidden);
        break;
      case 40:
        acodec.encode(direct_cur, a3OT_1111, forbidden);
        break;
      case 41:
        acodec.encode(direct_cur, a3OT_1112, forbidden);
        break;
      case 42:
        acodec.encode(direct_cur, a3OT_1120, forbidden);
        break;
      case 43:
        acodec.encode(direct_cur, a3OT_1121, forbidden);
        break;
      case 44:
        acodec.encode(direct_cur, a3OT_1122, forbidden);
        break;
      case 45:
        acodec.encode(direct_cur, a3OT_1200, forbidden);
        break;
      case 46:
        acodec.encode(direct_cur, a3OT_1201, forbidden);
        break;
      case 47:
        acodec.encode(direct_cur, a3OT_1202, forbidden);
        break;
      case 48:
        acodec.encode(direct_cur, a3OT_1210, forbidden);
        break;
      case 49:
        acodec.encode(direct_cur, a3OT_1211, forbidden);
        break;
      case 50:
        acodec.encode(direct_cur, a3OT_1212, forbidden);
        break;
      case 51:
        acodec.encode(direct_cur, a3OT_1220, forbidden);
        break;
      case 52:
        acodec.encode(direct_cur, a3OT_1221, forbidden);
        break;
      case 53:
        acodec.encode(direct_cur, a3OT_1222, forbidden);
        break;
      case 54:
        acodec.encode(direct_cur, a3OT_2000, forbidden);
        break;
      case 55:
        acodec.encode(direct_cur, a3OT_2001, forbidden);
        break;
      case 56:
        acodec.encode(direct_cur, a3OT_2002, forbidden);
        break;
      case 57:
        acodec.encode(direct_cur, a3OT_2010, forbidden);
        break;
      case 58:
        acodec.encode(direct_cur, a3OT_2011, forbidden);
        break;
      case 59:
        acodec.encode(direct_cur, a3OT_2012, forbidden);
        break;
      case 60:
        acodec.encode(direct_cur, a3OT_2020, forbidden);
        break;
      case 61:
        acodec.encode(direct_cur, a3OT_2021, forbidden);
        break;
      case 62:
        acodec.encode(direct_cur, a3OT_2022, forbidden);
        break;
      case 63:
        acodec.encode(direct_cur, a3OT_2100, forbidden);
        break;
      case 64:
        acodec.encode(direct_cur, a3OT_2101, forbidden);
        break;
      case 65:
        acodec.encode(direct_cur, a3OT_2102, forbidden);
        break;
      case 66:
        acodec.encode(direct_cur, a3OT_2110, forbidden);
        break;
      case 67:
        acodec.encode(direct_cur, a3OT_2111, forbidden);
        break;
      case 68:
        acodec.encode(direct_cur, a3OT_2112, forbidden);
        break;
      case 69:
        acodec.encode(direct_cur, a3OT_2120, forbidden);
        break;
      case 70:
        acodec.encode(direct_cur, a3OT_2121, forbidden);
        break;
      case 71:
        acodec.encode(direct_cur, a3OT_2122, forbidden);
        break;
      case 72:
        acodec.encode(direct_cur, a3OT_2200, forbidden);
        break;
      case 73:
        acodec.encode(direct_cur, a3OT_2201, forbidden);
        break;
      case 74:
        acodec.encode(direct_cur, a3OT_2202, forbidden);
        break;
      case 75:
        acodec.encode(direct_cur, a3OT_2210, forbidden);
        break;
      case 76:
        acodec.encode(direct_cur, a3OT_2211, forbidden);
        break;
      case 77:
        acodec.encode(direct_cur, a3OT_2212, forbidden);
        break;
      case 78:
        acodec.encode(direct_cur, a3OT_2220, forbidden);
        break;
      case 79:
        acodec.encode(direct_cur, a3OT_2221, forbidden);
        break;
      case 80:
        acodec.encode(direct_cur, a3OT_2222, forbidden);
        break;
      }
    } else if (overlap[i] == 2) {
      direct_cur = to_3OT(edge[i - 1], edge[i], &turn);
      runLength--;
    }

    direction1 = direction2;
    direction2 = direction3;
    direction3 = direction4;
    direction4 = direct_cur;
    adapt_position_3OT(&x, &y, edge[i]);
  }

  // printf("%d %d\n", loc_y, loc_x);
  // for (int i = 0; i < edge[0]; i++)
  //{
  //	printf("%d ", edge[i+1]);
  // }
  // printf("\n");
  // for (int i = 0; i < edge[0] + 1; i++)
  //{
  //	printf("%d ", overlap[i]);
  // }
  // printf("\n");
}

float getBits_MSC(CodingUnit *CU) {
  int *edge = CU->Edge_MSC;
  int *overlap = CU->Overlap_MSC;

  int loc_y = CU->location_row;
  int loc_x = CU->location_col;
  int pic_h = CU->pic_height;
  int pic_w = CU->pic_width;
  int forbidden[38] = {0};
  int x = loc_x, y = loc_y;
  if (x == 0)
    y -= 1;
  else if (y == pic_h - 1)
    x -= 1;
  else if (x == pic_w - 1)
    y += 1;
  else if (y == 0)
    x += 1;
  else
    x -= 1;
  bool boundary = false;
  if (loc_x == 0 || loc_x == pic_w - 1 || loc_y == 0 || loc_y == pic_h - 1)
    boundary = true;
  int high_point = loc_y - 1;
  if (boundary)
    high_point = -1;
  int left_point = loc_x;
  if (boundary)
    left_point = -1;

  int direction1, direction2, direction3, direct_temp;
  int index;
  int start_index = get_position_index(loc_x, loc_y, pic_w, pic_h);
  int runLength = 0;
  bool newzero = false;

  float rate = 0;

  if (overlap[0] > 0 && runLength == 0) {
    bool end = true;
    for (int j = 0; j < edge[0]; j++) {
      if (overlap[j] < 2) {
        end = false;
        break;
      } else
        runLength++;
    }
    rate += 1;
    if (!end)
      rate += GolombBits(runLength, 0, 3);
  }
  if (overlap[0] < 2) {
    if (boundary) {
      get_forbidden1(x, y, pic_w, pic_h, forbidden, start_index);
      if (loc_x == 0)
        rate += acodec.getBits(edge[1], aMSC_L, forbidden);
      else if (loc_y == pic_h - 1)
        rate += acodec.getBits(edge[1], aMSC_B, forbidden);
      else if (loc_x == pic_w - 1)
        rate += acodec.getBits(edge[1], aMSC_R, forbidden);
      else if (loc_y == 0)
        rate += acodec.getBits(edge[1], aMSC_A, forbidden);
    } else {
      if (edge[1] == 1)
        rate += acodec.getBits(0, aMSC_I, forbidden);
      else if (edge[1] == 9)
        rate += acodec.getBits(1, aMSC_I, forbidden);
      else if (edge[1] == 25)
        rate += acodec.getBits(2, aMSC_I, forbidden);
      else
        printf("error");
    }
  } else if (overlap[0] == 2) {
    runLength--;
    if (runLength == 0)
      newzero = true;
  }

  direction1 = get_direction1(edge[1], &index);

  if (edge[0] > 1) {
    adapt_position(&x, &y, edge[1]);
    direction2 = get_RMSC(index, edge[2]);

    if (overlap[1] > 0 && runLength == 0 && !newzero) {
      bool end = true;
      for (int j = 1; j < edge[0]; j++) {
        if (overlap[j] < 2) {
          end = false;
          break;
        } else
          runLength++;
      }
      rate += 1;
      if (!end)
        rate += GolombBits(runLength, 0, 3);
    }
    if (overlap[1] < 2) {
      newzero = false;
      get_forbidden2(x, y, pic_w, pic_h, index, direction1, forbidden,
                     start_index, high_point, left_point);
      switch (direction1) {
      case 0:
        rate += acodec.getBits(enc_arr1[0][direction2], aMSC_0, forbidden);
        break;
      case 1:
        rate += acodec.getBits(enc_arr1[1][direction2], aMSC_1, forbidden);
        break;
      case 2:
        rate += acodec.getBits(enc_arr1[2][direction2], aMSC_2, forbidden);
        break;
      case 3:
        rate += acodec.getBits(enc_arr1[3][direction2], aMSC_3, forbidden);
        break;
      case 4:
        rate += acodec.getBits(enc_arr1[4][direction2], aMSC_4, forbidden);
        break;
      case 5:
        rate += acodec.getBits(enc_arr1[5][direction2], aMSC_5, forbidden);
        break;
      case 6:
        rate += acodec.getBits(enc_arr1[6][direction2], aMSC_6, forbidden);
        break;
      case 7:
        rate += acodec.getBits(enc_arr1[7][direction2], aMSC_7, forbidden);
        break;
      case 8:
        rate += acodec.getBits(enc_arr1[8][direction2], aMSC_8, forbidden);
        break;
      }
    } else if (overlap[1] == 2) {
      runLength--;
      if (runLength == 0)
        newzero = true;
    }

    adapt_position(&x, &y, edge[2]);
  }
  for (int i = 3; i < edge[0] + 1; i++) {
    direct_temp = direction2;
    direction2 = get_direction1(edge[i - 1], &index);
    direction3 = get_RMSC(index, edge[i]);

    if (overlap[i - 1] > 0 && runLength == 0 && !newzero) {
      bool end = true;
      for (int j = i - 1; j < edge[0]; j++) {
        if (overlap[j] < 2) {
          end = false;
          break;
        } else
          runLength++;
      }
      rate += 1;
      if (!end)
        rate += GolombBits(runLength, 0, 3);
    }
    if (overlap[i - 1] < 2) {
      newzero = false;
      get_forbidden3(x, y, pic_w, pic_h, index, direction1, direct_temp,
                     forbidden, start_index, high_point, left_point);
      switch (direction1 * 100 + direct_temp) {
      case 0:
        rate += acodec.getBits(enc_arr[0][0][direction3], aMSC_00, forbidden);
        break;
      case 1:
        rate += acodec.getBits(enc_arr[0][1][direction3], aMSC_01, forbidden);
        break;
      case 2:
        rate += acodec.getBits(enc_arr[0][2][direction3], aMSC_02, forbidden);
        break;
      case 3:
        rate += acodec.getBits(enc_arr[0][3][direction3], aMSC_03, forbidden);
        break;
      case 4:
        rate += acodec.getBits(enc_arr[0][4][direction3], aMSC_04, forbidden);
        break;
      case 5:
        rate += acodec.getBits(enc_arr[0][5][direction3], aMSC_05, forbidden);
        break;
      case 6:
        rate += acodec.getBits(enc_arr[0][6][direction3], aMSC_06, forbidden);
        break;
      case 7:
        rate += acodec.getBits(enc_arr[0][7][direction3], aMSC_07, forbidden);
        break;
      case 8:
        rate += acodec.getBits(enc_arr[0][8][direction3], aMSC_08, forbidden);
        break;
      case 9:
        rate += acodec.getBits(enc_arr[0][9][direction3], aMSC_09, forbidden);
        break;
      case 10:
        rate += acodec.getBits(enc_arr[0][10][direction3], aMSC_010, forbidden);
        break;
      case 11:
        rate += acodec.getBits(enc_arr[0][11][direction3], aMSC_011, forbidden);
        break;
      case 12:
        rate += acodec.getBits(enc_arr[0][12][direction3], aMSC_012, forbidden);
        break;
      case 13:
        rate += acodec.getBits(enc_arr[0][13][direction3], aMSC_013, forbidden);
        break;
      case 14:
        rate += acodec.getBits(enc_arr[0][14][direction3], aMSC_014, forbidden);
        break;
      case 15:
        rate += acodec.getBits(enc_arr[0][15][direction3], aMSC_015, forbidden);
        break;
      case 16:
        rate += acodec.getBits(enc_arr[0][16][direction3], aMSC_016, forbidden);
        break;
      case 17:
        rate += acodec.getBits(enc_arr[0][17][direction3], aMSC_017, forbidden);
        break;
      case 18:
        rate += acodec.getBits(enc_arr[0][18][direction3], aMSC_018, forbidden);
        break;
      case 19:
        rate += acodec.getBits(enc_arr[0][19][direction3], aMSC_019, forbidden);
        break;
      case 20:
        rate += acodec.getBits(enc_arr[0][20][direction3], aMSC_020, forbidden);
        break;
      case 21:
        rate += acodec.getBits(enc_arr[0][21][direction3], aMSC_021, forbidden);
        break;
      case 22:
        rate += acodec.getBits(enc_arr[0][22][direction3], aMSC_022, forbidden);
        break;
      case 23:
        rate += acodec.getBits(enc_arr[0][23][direction3], aMSC_023, forbidden);
        break;
      case 24:
        rate += acodec.getBits(enc_arr[0][24][direction3], aMSC_024, forbidden);
        break;
      case 25:
        rate += acodec.getBits(enc_arr[0][25][direction3], aMSC_025, forbidden);
        break;
      case 26:
        rate += acodec.getBits(enc_arr[0][26][direction3], aMSC_026, forbidden);
        break;
      case 100:
        rate += acodec.getBits(enc_arr[1][0][direction3], aMSC_10, forbidden);
        break;
      case 101:
        rate += acodec.getBits(enc_arr[1][1][direction3], aMSC_11, forbidden);
        break;
      case 102:
        rate += acodec.getBits(enc_arr[1][2][direction3], aMSC_12, forbidden);
        break;
      case 103:
        rate += acodec.getBits(enc_arr[1][3][direction3], aMSC_13, forbidden);
        break;
      case 104:
        rate += acodec.getBits(enc_arr[1][4][direction3], aMSC_14, forbidden);
        break;
      case 105:
        rate += acodec.getBits(enc_arr[1][5][direction3], aMSC_15, forbidden);
        break;
      case 106:
        rate += acodec.getBits(enc_arr[1][6][direction3], aMSC_16, forbidden);
        break;
      case 107:
        rate += acodec.getBits(enc_arr[1][7][direction3], aMSC_17, forbidden);
        break;
      case 108:
        rate += acodec.getBits(enc_arr[1][8][direction3], aMSC_18, forbidden);
        break;
      case 109:
        rate += acodec.getBits(enc_arr[1][9][direction3], aMSC_19, forbidden);
        break;
      case 110:
        rate += acodec.getBits(enc_arr[1][10][direction3], aMSC_110, forbidden);
        break;
      case 111:
        rate += acodec.getBits(enc_arr[1][11][direction3], aMSC_111, forbidden);
        break;
      case 112:
        rate += acodec.getBits(enc_arr[1][12][direction3], aMSC_112, forbidden);
        break;
      case 113:
        rate += acodec.getBits(enc_arr[1][13][direction3], aMSC_113, forbidden);
        break;
      case 114:
        rate += acodec.getBits(enc_arr[1][14][direction3], aMSC_114, forbidden);
        break;
      case 115:
        rate += acodec.getBits(enc_arr[1][15][direction3], aMSC_115, forbidden);
        break;
      case 116:
        rate += acodec.getBits(enc_arr[1][16][direction3], aMSC_116, forbidden);
        break;
      case 117:
        rate += acodec.getBits(enc_arr[1][17][direction3], aMSC_117, forbidden);
        break;
      case 118:
        rate += acodec.getBits(enc_arr[1][18][direction3], aMSC_118, forbidden);
        break;
      case 119:
        rate += acodec.getBits(enc_arr[1][19][direction3], aMSC_119, forbidden);
        break;
      case 120:
        rate += acodec.getBits(enc_arr[1][20][direction3], aMSC_120, forbidden);
        break;
      case 121:
        rate += acodec.getBits(enc_arr[1][21][direction3], aMSC_121, forbidden);
        break;
      case 122:
        rate += acodec.getBits(enc_arr[1][22][direction3], aMSC_122, forbidden);
        break;
      case 123:
        rate += acodec.getBits(enc_arr[1][23][direction3], aMSC_123, forbidden);
        break;
      case 124:
        rate += acodec.getBits(enc_arr[1][24][direction3], aMSC_124, forbidden);
        break;
      case 125:
        rate += acodec.getBits(enc_arr[1][25][direction3], aMSC_125, forbidden);
        break;
      case 126:
        rate += acodec.getBits(enc_arr[1][26][direction3], aMSC_126, forbidden);
        break;
      case 200:
        rate += acodec.getBits(enc_arr[2][0][direction3], aMSC_20, forbidden);
        break;
      case 201:
        rate += acodec.getBits(enc_arr[2][1][direction3], aMSC_21, forbidden);
        break;
      case 202:
        rate += acodec.getBits(enc_arr[2][2][direction3], aMSC_22, forbidden);
        break;
      case 203:
        rate += acodec.getBits(enc_arr[2][3][direction3], aMSC_23, forbidden);
        break;
      case 204:
        rate += acodec.getBits(enc_arr[2][4][direction3], aMSC_24, forbidden);
        break;
      case 205:
        rate += acodec.getBits(enc_arr[2][5][direction3], aMSC_25, forbidden);
        break;
      case 206:
        rate += acodec.getBits(enc_arr[2][6][direction3], aMSC_26, forbidden);
        break;
      case 207:
        rate += acodec.getBits(enc_arr[2][7][direction3], aMSC_27, forbidden);
        break;
      case 208:
        rate += acodec.getBits(enc_arr[2][8][direction3], aMSC_28, forbidden);
        break;
      case 209:
        rate += acodec.getBits(enc_arr[2][9][direction3], aMSC_29, forbidden);
        break;
      case 210:
        rate += acodec.getBits(enc_arr[2][10][direction3], aMSC_210, forbidden);
        break;
      case 211:
        rate += acodec.getBits(enc_arr[2][11][direction3], aMSC_211, forbidden);
        break;
      case 212:
        rate += acodec.getBits(enc_arr[2][12][direction3], aMSC_212, forbidden);
        break;
      case 213:
        rate += acodec.getBits(enc_arr[2][13][direction3], aMSC_213, forbidden);
        break;
      case 214:
        rate += acodec.getBits(enc_arr[2][14][direction3], aMSC_214, forbidden);
        break;
      case 215:
        rate += acodec.getBits(enc_arr[2][15][direction3], aMSC_215, forbidden);
        break;
      case 216:
        rate += acodec.getBits(enc_arr[2][16][direction3], aMSC_216, forbidden);
        break;
      case 217:
        rate += acodec.getBits(enc_arr[2][17][direction3], aMSC_217, forbidden);
        break;
      case 218:
        rate += acodec.getBits(enc_arr[2][18][direction3], aMSC_218, forbidden);
        break;
      case 219:
        rate += acodec.getBits(enc_arr[2][19][direction3], aMSC_219, forbidden);
        break;
      case 220:
        rate += acodec.getBits(enc_arr[2][20][direction3], aMSC_220, forbidden);
        break;
      case 221:
        rate += acodec.getBits(enc_arr[2][21][direction3], aMSC_221, forbidden);
        break;
      case 222:
        rate += acodec.getBits(enc_arr[2][22][direction3], aMSC_222, forbidden);
        break;
      case 223:
        rate += acodec.getBits(enc_arr[2][23][direction3], aMSC_223, forbidden);
        break;
      case 224:
        rate += acodec.getBits(enc_arr[2][24][direction3], aMSC_224, forbidden);
        break;
      case 225:
        rate += acodec.getBits(enc_arr[2][25][direction3], aMSC_225, forbidden);
        break;
      case 226:
        rate += acodec.getBits(enc_arr[2][26][direction3], aMSC_226, forbidden);
        break;
      case 300:
        rate += acodec.getBits(enc_arr[3][0][direction3], aMSC_30, forbidden);
        break;
      case 301:
        rate += acodec.getBits(enc_arr[3][1][direction3], aMSC_31, forbidden);
        break;
      case 302:
        rate += acodec.getBits(enc_arr[3][2][direction3], aMSC_32, forbidden);
        break;
      case 303:
        rate += acodec.getBits(enc_arr[3][3][direction3], aMSC_33, forbidden);
        break;
      case 304:
        rate += acodec.getBits(enc_arr[3][4][direction3], aMSC_34, forbidden);
        break;
      case 305:
        rate += acodec.getBits(enc_arr[3][5][direction3], aMSC_35, forbidden);
        break;
      case 306:
        rate += acodec.getBits(enc_arr[3][6][direction3], aMSC_36, forbidden);
        break;
      case 307:
        rate += acodec.getBits(enc_arr[3][7][direction3], aMSC_37, forbidden);
        break;
      case 308:
        rate += acodec.getBits(enc_arr[3][8][direction3], aMSC_38, forbidden);
        break;
      case 309:
        rate += acodec.getBits(enc_arr[3][9][direction3], aMSC_39, forbidden);
        break;
      case 310:
        rate += acodec.getBits(enc_arr[3][10][direction3], aMSC_310, forbidden);
        break;
      case 311:
        rate += acodec.getBits(enc_arr[3][11][direction3], aMSC_311, forbidden);
        break;
      case 312:
        rate += acodec.getBits(enc_arr[3][12][direction3], aMSC_312, forbidden);
        break;
      case 313:
        rate += acodec.getBits(enc_arr[3][13][direction3], aMSC_313, forbidden);
        break;
      case 314:
        rate += acodec.getBits(enc_arr[3][14][direction3], aMSC_314, forbidden);
        break;
      case 315:
        rate += acodec.getBits(enc_arr[3][15][direction3], aMSC_315, forbidden);
        break;
      case 316:
        rate += acodec.getBits(enc_arr[3][16][direction3], aMSC_316, forbidden);
        break;
      case 317:
        rate += acodec.getBits(enc_arr[3][17][direction3], aMSC_317, forbidden);
        break;
      case 318:
        rate += acodec.getBits(enc_arr[3][18][direction3], aMSC_318, forbidden);
        break;
      case 319:
        rate += acodec.getBits(enc_arr[3][19][direction3], aMSC_319, forbidden);
        break;
      case 320:
        rate += acodec.getBits(enc_arr[3][20][direction3], aMSC_320, forbidden);
        break;
      case 321:
        rate += acodec.getBits(enc_arr[3][21][direction3], aMSC_321, forbidden);
        break;
      case 322:
        rate += acodec.getBits(enc_arr[3][22][direction3], aMSC_322, forbidden);
        break;
      case 323:
        rate += acodec.getBits(enc_arr[3][23][direction3], aMSC_323, forbidden);
        break;
      case 324:
        rate += acodec.getBits(enc_arr[3][24][direction3], aMSC_324, forbidden);
        break;
      case 325:
        rate += acodec.getBits(enc_arr[3][25][direction3], aMSC_325, forbidden);
        break;
      case 326:
        rate += acodec.getBits(enc_arr[3][26][direction3], aMSC_326, forbidden);
        break;
      case 400:
        rate += acodec.getBits(enc_arr[4][0][direction3], aMSC_40, forbidden);
        break;
      case 401:
        rate += acodec.getBits(enc_arr[4][1][direction3], aMSC_41, forbidden);
        break;
      case 402:
        rate += acodec.getBits(enc_arr[4][2][direction3], aMSC_42, forbidden);
        break;
      case 403:
        rate += acodec.getBits(enc_arr[4][3][direction3], aMSC_43, forbidden);
        break;
      case 404:
        rate += acodec.getBits(enc_arr[4][4][direction3], aMSC_44, forbidden);
        break;
      case 405:
        rate += acodec.getBits(enc_arr[4][5][direction3], aMSC_45, forbidden);
        break;
      case 406:
        rate += acodec.getBits(enc_arr[4][6][direction3], aMSC_46, forbidden);
        break;
      case 407:
        rate += acodec.getBits(enc_arr[4][7][direction3], aMSC_47, forbidden);
        break;
      case 408:
        rate += acodec.getBits(enc_arr[4][8][direction3], aMSC_48, forbidden);
        break;
      case 409:
        rate += acodec.getBits(enc_arr[4][9][direction3], aMSC_49, forbidden);
        break;
      case 410:
        rate += acodec.getBits(enc_arr[4][10][direction3], aMSC_410, forbidden);
        break;
      case 411:
        rate += acodec.getBits(enc_arr[4][11][direction3], aMSC_411, forbidden);
        break;
      case 412:
        rate += acodec.getBits(enc_arr[4][12][direction3], aMSC_412, forbidden);
        break;
      case 413:
        rate += acodec.getBits(enc_arr[4][13][direction3], aMSC_413, forbidden);
        break;
      case 414:
        rate += acodec.getBits(enc_arr[4][14][direction3], aMSC_414, forbidden);
        break;
      case 415:
        rate += acodec.getBits(enc_arr[4][15][direction3], aMSC_415, forbidden);
        break;
      case 416:
        rate += acodec.getBits(enc_arr[4][16][direction3], aMSC_416, forbidden);
        break;
      case 417:
        rate += acodec.getBits(enc_arr[4][17][direction3], aMSC_417, forbidden);
        break;
      case 418:
        rate += acodec.getBits(enc_arr[4][18][direction3], aMSC_418, forbidden);
        break;
      case 419:
        rate += acodec.getBits(enc_arr[4][19][direction3], aMSC_419, forbidden);
        break;
      case 420:
        rate += acodec.getBits(enc_arr[4][20][direction3], aMSC_420, forbidden);
        break;
      case 421:
        rate += acodec.getBits(enc_arr[4][21][direction3], aMSC_421, forbidden);
        break;
      case 422:
        rate += acodec.getBits(enc_arr[4][22][direction3], aMSC_422, forbidden);
        break;
      case 423:
        rate += acodec.getBits(enc_arr[4][23][direction3], aMSC_423, forbidden);
        break;
      case 424:
        rate += acodec.getBits(enc_arr[4][24][direction3], aMSC_424, forbidden);
        break;
      case 425:
        rate += acodec.getBits(enc_arr[4][25][direction3], aMSC_425, forbidden);
        break;
      case 426:
        rate += acodec.getBits(enc_arr[4][26][direction3], aMSC_426, forbidden);
        break;
      case 500:
        rate += acodec.getBits(enc_arr[5][0][direction3], aMSC_50, forbidden);
        break;
      case 501:
        rate += acodec.getBits(enc_arr[5][1][direction3], aMSC_51, forbidden);
        break;
      case 502:
        rate += acodec.getBits(enc_arr[5][2][direction3], aMSC_52, forbidden);
        break;
      case 503:
        rate += acodec.getBits(enc_arr[5][3][direction3], aMSC_53, forbidden);
        break;
      case 504:
        rate += acodec.getBits(enc_arr[5][4][direction3], aMSC_54, forbidden);
        break;
      case 505:
        rate += acodec.getBits(enc_arr[5][5][direction3], aMSC_55, forbidden);
        break;
      case 506:
        rate += acodec.getBits(enc_arr[5][6][direction3], aMSC_56, forbidden);
        break;
      case 507:
        rate += acodec.getBits(enc_arr[5][7][direction3], aMSC_57, forbidden);
        break;
      case 508:
        rate += acodec.getBits(enc_arr[5][8][direction3], aMSC_58, forbidden);
        break;
      case 509:
        rate += acodec.getBits(enc_arr[5][9][direction3], aMSC_59, forbidden);
        break;
      case 510:
        rate += acodec.getBits(enc_arr[5][10][direction3], aMSC_510, forbidden);
        break;
      case 511:
        rate += acodec.getBits(enc_arr[5][11][direction3], aMSC_511, forbidden);
        break;
      case 512:
        rate += acodec.getBits(enc_arr[5][12][direction3], aMSC_512, forbidden);
        break;
      case 513:
        rate += acodec.getBits(enc_arr[5][13][direction3], aMSC_513, forbidden);
        break;
      case 514:
        rate += acodec.getBits(enc_arr[5][14][direction3], aMSC_514, forbidden);
        break;
      case 515:
        rate += acodec.getBits(enc_arr[5][15][direction3], aMSC_515, forbidden);
        break;
      case 516:
        rate += acodec.getBits(enc_arr[5][16][direction3], aMSC_516, forbidden);
        break;
      case 517:
        rate += acodec.getBits(enc_arr[5][17][direction3], aMSC_517, forbidden);
        break;
      case 518:
        rate += acodec.getBits(enc_arr[5][18][direction3], aMSC_518, forbidden);
        break;
      case 519:
        rate += acodec.getBits(enc_arr[5][19][direction3], aMSC_519, forbidden);
        break;
      case 520:
        rate += acodec.getBits(enc_arr[5][20][direction3], aMSC_520, forbidden);
        break;
      case 521:
        rate += acodec.getBits(enc_arr[5][21][direction3], aMSC_521, forbidden);
        break;
      case 522:
        rate += acodec.getBits(enc_arr[5][22][direction3], aMSC_522, forbidden);
        break;
      case 523:
        rate += acodec.getBits(enc_arr[5][23][direction3], aMSC_523, forbidden);
        break;
      case 524:
        rate += acodec.getBits(enc_arr[5][24][direction3], aMSC_524, forbidden);
        break;
      case 525:
        rate += acodec.getBits(enc_arr[5][25][direction3], aMSC_525, forbidden);
        break;
      case 526:
        rate += acodec.getBits(enc_arr[5][26][direction3], aMSC_526, forbidden);
        break;
      case 600:
        rate += acodec.getBits(enc_arr[6][0][direction3], aMSC_60, forbidden);
        break;
      case 601:
        rate += acodec.getBits(enc_arr[6][1][direction3], aMSC_61, forbidden);
        break;
      case 602:
        rate += acodec.getBits(enc_arr[6][2][direction3], aMSC_62, forbidden);
        break;
      case 603:
        rate += acodec.getBits(enc_arr[6][3][direction3], aMSC_63, forbidden);
        break;
      case 604:
        rate += acodec.getBits(enc_arr[6][4][direction3], aMSC_64, forbidden);
        break;
      case 605:
        rate += acodec.getBits(enc_arr[6][5][direction3], aMSC_65, forbidden);
        break;
      case 606:
        rate += acodec.getBits(enc_arr[6][6][direction3], aMSC_66, forbidden);
        break;
      case 607:
        rate += acodec.getBits(enc_arr[6][7][direction3], aMSC_67, forbidden);
        break;
      case 608:
        rate += acodec.getBits(enc_arr[6][8][direction3], aMSC_68, forbidden);
        break;
      case 609:
        rate += acodec.getBits(enc_arr[6][9][direction3], aMSC_69, forbidden);
        break;
      case 610:
        rate += acodec.getBits(enc_arr[6][10][direction3], aMSC_610, forbidden);
        break;
      case 611:
        rate += acodec.getBits(enc_arr[6][11][direction3], aMSC_611, forbidden);
        break;
      case 612:
        rate += acodec.getBits(enc_arr[6][12][direction3], aMSC_612, forbidden);
        break;
      case 613:
        rate += acodec.getBits(enc_arr[6][13][direction3], aMSC_613, forbidden);
        break;
      case 614:
        rate += acodec.getBits(enc_arr[6][14][direction3], aMSC_614, forbidden);
        break;
      case 615:
        rate += acodec.getBits(enc_arr[6][15][direction3], aMSC_615, forbidden);
        break;
      case 616:
        rate += acodec.getBits(enc_arr[6][16][direction3], aMSC_616, forbidden);
        break;
      case 617:
        rate += acodec.getBits(enc_arr[6][17][direction3], aMSC_617, forbidden);
        break;
      case 618:
        rate += acodec.getBits(enc_arr[6][18][direction3], aMSC_618, forbidden);
        break;
      case 619:
        rate += acodec.getBits(enc_arr[6][19][direction3], aMSC_619, forbidden);
        break;
      case 620:
        rate += acodec.getBits(enc_arr[6][20][direction3], aMSC_620, forbidden);
        break;
      case 621:
        rate += acodec.getBits(enc_arr[6][21][direction3], aMSC_621, forbidden);
        break;
      case 622:
        rate += acodec.getBits(enc_arr[6][22][direction3], aMSC_622, forbidden);
        break;
      case 623:
        rate += acodec.getBits(enc_arr[6][23][direction3], aMSC_623, forbidden);
        break;
      case 624:
        rate += acodec.getBits(enc_arr[6][24][direction3], aMSC_624, forbidden);
        break;
      case 625:
        rate += acodec.getBits(enc_arr[6][25][direction3], aMSC_625, forbidden);
        break;
      case 626:
        rate += acodec.getBits(enc_arr[6][26][direction3], aMSC_626, forbidden);
        break;
      case 700:
        rate += acodec.getBits(enc_arr[7][0][direction3], aMSC_70, forbidden);
        break;
      case 701:
        rate += acodec.getBits(enc_arr[7][1][direction3], aMSC_71, forbidden);
        break;
      case 702:
        rate += acodec.getBits(enc_arr[7][2][direction3], aMSC_72, forbidden);
        break;
      case 703:
        rate += acodec.getBits(enc_arr[7][3][direction3], aMSC_73, forbidden);
        break;
      case 704:
        rate += acodec.getBits(enc_arr[7][4][direction3], aMSC_74, forbidden);
        break;
      case 705:
        rate += acodec.getBits(enc_arr[7][5][direction3], aMSC_75, forbidden);
        break;
      case 706:
        rate += acodec.getBits(enc_arr[7][6][direction3], aMSC_76, forbidden);
        break;
      case 707:
        rate += acodec.getBits(enc_arr[7][7][direction3], aMSC_77, forbidden);
        break;
      case 708:
        rate += acodec.getBits(enc_arr[7][8][direction3], aMSC_78, forbidden);
        break;
      case 709:
        rate += acodec.getBits(enc_arr[7][9][direction3], aMSC_79, forbidden);
        break;
      case 710:
        rate += acodec.getBits(enc_arr[7][10][direction3], aMSC_710, forbidden);
        break;
      case 711:
        rate += acodec.getBits(enc_arr[7][11][direction3], aMSC_711, forbidden);
        break;
      case 712:
        rate += acodec.getBits(enc_arr[7][12][direction3], aMSC_712, forbidden);
        break;
      case 713:
        rate += acodec.getBits(enc_arr[7][13][direction3], aMSC_713, forbidden);
        break;
      case 714:
        rate += acodec.getBits(enc_arr[7][14][direction3], aMSC_714, forbidden);
        break;
      case 715:
        rate += acodec.getBits(enc_arr[7][15][direction3], aMSC_715, forbidden);
        break;
      case 716:
        rate += acodec.getBits(enc_arr[7][16][direction3], aMSC_716, forbidden);
        break;
      case 717:
        rate += acodec.getBits(enc_arr[7][17][direction3], aMSC_717, forbidden);
        break;
      case 718:
        rate += acodec.getBits(enc_arr[7][18][direction3], aMSC_718, forbidden);
        break;
      case 719:
        rate += acodec.getBits(enc_arr[7][19][direction3], aMSC_719, forbidden);
        break;
      case 720:
        rate += acodec.getBits(enc_arr[7][20][direction3], aMSC_720, forbidden);
        break;
      case 721:
        rate += acodec.getBits(enc_arr[7][21][direction3], aMSC_721, forbidden);
        break;
      case 722:
        rate += acodec.getBits(enc_arr[7][22][direction3], aMSC_722, forbidden);
        break;
      case 723:
        rate += acodec.getBits(enc_arr[7][23][direction3], aMSC_723, forbidden);
        break;
      case 724:
        rate += acodec.getBits(enc_arr[7][24][direction3], aMSC_724, forbidden);
        break;
      case 725:
        rate += acodec.getBits(enc_arr[7][25][direction3], aMSC_725, forbidden);
        break;
      case 726:
        rate += acodec.getBits(enc_arr[7][26][direction3], aMSC_726, forbidden);
        break;
      case 800:
        rate += acodec.getBits(enc_arr[8][0][direction3], aMSC_80, forbidden);
        break;
      case 801:
        rate += acodec.getBits(enc_arr[8][1][direction3], aMSC_81, forbidden);
        break;
      case 802:
        rate += acodec.getBits(enc_arr[8][2][direction3], aMSC_82, forbidden);
        break;
      case 803:
        rate += acodec.getBits(enc_arr[8][3][direction3], aMSC_83, forbidden);
        break;
      case 804:
        rate += acodec.getBits(enc_arr[8][4][direction3], aMSC_84, forbidden);
        break;
      case 805:
        rate += acodec.getBits(enc_arr[8][5][direction3], aMSC_85, forbidden);
        break;
      case 806:
        rate += acodec.getBits(enc_arr[8][6][direction3], aMSC_86, forbidden);
        break;
      case 807:
        rate += acodec.getBits(enc_arr[8][7][direction3], aMSC_87, forbidden);
        break;
      case 808:
        rate += acodec.getBits(enc_arr[8][8][direction3], aMSC_88, forbidden);
        break;
      case 809:
        rate += acodec.getBits(enc_arr[8][9][direction3], aMSC_89, forbidden);
        break;
      case 810:
        rate += acodec.getBits(enc_arr[8][10][direction3], aMSC_810, forbidden);
        break;
      case 811:
        rate += acodec.getBits(enc_arr[8][11][direction3], aMSC_811, forbidden);
        break;
      case 812:
        rate += acodec.getBits(enc_arr[8][12][direction3], aMSC_812, forbidden);
        break;
      case 813:
        rate += acodec.getBits(enc_arr[8][13][direction3], aMSC_813, forbidden);
        break;
      case 814:
        rate += acodec.getBits(enc_arr[8][14][direction3], aMSC_814, forbidden);
        break;
      case 815:
        rate += acodec.getBits(enc_arr[8][15][direction3], aMSC_815, forbidden);
        break;
      case 816:
        rate += acodec.getBits(enc_arr[8][16][direction3], aMSC_816, forbidden);
        break;
      case 817:
        rate += acodec.getBits(enc_arr[8][17][direction3], aMSC_817, forbidden);
        break;
      case 818:
        rate += acodec.getBits(enc_arr[8][18][direction3], aMSC_818, forbidden);
        break;
      case 819:
        rate += acodec.getBits(enc_arr[8][19][direction3], aMSC_819, forbidden);
        break;
      case 820:
        rate += acodec.getBits(enc_arr[8][20][direction3], aMSC_820, forbidden);
        break;
      case 821:
        rate += acodec.getBits(enc_arr[8][21][direction3], aMSC_821, forbidden);
        break;
      case 822:
        rate += acodec.getBits(enc_arr[8][22][direction3], aMSC_822, forbidden);
        break;
      case 823:
        rate += acodec.getBits(enc_arr[8][23][direction3], aMSC_823, forbidden);
        break;
      case 824:
        rate += acodec.getBits(enc_arr[8][24][direction3], aMSC_824, forbidden);
        break;
      case 825:
        rate += acodec.getBits(enc_arr[8][25][direction3], aMSC_825, forbidden);
        break;
      case 826:
        rate += acodec.getBits(enc_arr[8][26][direction3], aMSC_826, forbidden);
        break;
      }
    } else if (overlap[i - 1] == 2) {
      runLength--;
      if (runLength == 0)
        newzero = true;
    }

    direction1 = direction2;
    direction2 = direction3;
    adapt_position(&x, &y, edge[i]);
  }
  return rate;
}

float getBits_3OT(CodingUnit *CU) {
  int *edge = CU->Edge_3OT;
  int *overlap = CU->Overlap_3OT;

  int loc_y = CU->location_row;
  int loc_x = CU->location_col;
  int pic_h = CU->pic_height;
  int pic_w = CU->pic_width;
  int forbidden[5] = {0};
  // for (int k = 0; k < pic_h*pic_w; k++) encCodedMap[k] = 0;

  int x = loc_x, y = loc_y;

  if (loc_x == 0)
    ;
  else if (loc_y == pic_h - 1)
    y++;
  else if (loc_x == pic_w - 1) {
    x++;
    y++;
  } else if (loc_y == 0)
    x++;

  int start_index = get_position_3OT(x, y, pic_w, pic_h);

  int pre_direction;
  if (loc_x == 0) {
    x++;
    pre_direction = 0;
  } else if (loc_y == pic_h - 1) {
    y--;
    pre_direction = 1;
  } else if (loc_x == pic_w - 1) {
    x--;
    pre_direction = 2;
  } else if (loc_y == 0) {
    y++;
    pre_direction = 3;
  } else {
    x++;
    pre_direction = 0;
  }

  // encCodedMap[y*pic_w + x] = 1;

  bool boundary = false;
  if (loc_x == 0 || loc_x == pic_w - 1 || loc_y == 0 || loc_y == pic_h - 1)
    boundary = true;

  int high_point = loc_y;
  if (boundary)
    high_point = -1;
  int left_point = loc_x;
  if (boundary)
    left_point = -1;

  int direction1, direction2, direction3, direction4, direct_cur;
  int turn = 0; // left
  if (!boundary)
    turn = 1; // right

  int runLength = 0;
  bool end;

  float rate = 0;

  if (overlap[0] == 1 && runLength == 0) {
    end = true;
    for (int j = 1; j < edge[0] + 1; j++) {
      if (overlap[j] < 2) {
        end = false;
        break;
      } else
        runLength++;
    }
    rate += 1;
    if (!end)
      rate += GolombBits(runLength, 0, 3);
  }
  if (overlap[1] < 2) {
    get_forbidden_3OT(x, y, pic_w, pic_h, pre_direction, turn, forbidden,
                      boundary, start_index, high_point, left_point);

    if (boundary) {
      if (loc_x == 0) {
        direct_cur = to_3OT(pre_direction, edge[1], &turn);
        rate += acodec.getBits(direct_cur, a3OT_L, forbidden);
      } else if (loc_y == pic_h - 1) {
        direct_cur = to_3OT(pre_direction, edge[1], &turn);
        rate += acodec.getBits(direct_cur, a3OT_B, forbidden);
      } else if (loc_x == pic_w - 1) {
        direct_cur = to_3OT(pre_direction, edge[1], &turn);
        rate += acodec.getBits(direct_cur, a3OT_R, forbidden);
      } else if (loc_y == 0) {
        direct_cur = to_3OT(pre_direction, edge[1], &turn);
        rate += acodec.getBits(direct_cur, a3OT_A, forbidden);
      }
    } else {
      direct_cur = to_3OT(pre_direction, edge[1], &turn);
      rate += acodec.getBits(direct_cur, a3OT_I, forbidden);
    }
  } else if (overlap[1] == 2) {
    direct_cur = to_3OT(pre_direction, edge[1], &turn);
    runLength--;
  }
  direction1 = direct_cur;
  adapt_position_3OT(&x, &y, edge[1]);

  if (edge[0] > 1) {
    if (overlap[1] == 1 && runLength == 0) {
      end = true;
      for (int j = 2; j < edge[0] + 1; j++) {
        if (overlap[j] < 2) {
          end = false;
          break;
        } else
          runLength++;
      }
      rate += 1;
      if (!end)
        rate += GolombBits(runLength, 0, 3);
    }
    if (overlap[2] < 2) {
      // encCodedMap[y*pic_w + x] = 1;
      get_forbidden_3OT(x, y, pic_w, pic_h, edge[1], turn, forbidden, boundary,
                        start_index, high_point, left_point);
      direction2 = to_3OT(edge[1], edge[2], &turn);
      switch (direction1) {
      case 0:
        rate += acodec.getBits(direction2, a3OT_0, forbidden);
        break;
      case 1:
        rate += acodec.getBits(direction2, a3OT_1, forbidden);
        break;
      case 2:
        rate += acodec.getBits(direction2, a3OT_2, forbidden);
        break;
      }
    } else if (overlap[2] == 2) {
      direction2 = to_3OT(edge[1], edge[2], &turn);
      runLength--;
    }
    adapt_position_3OT(&x, &y, edge[2]);
  }

  if (edge[0] > 2) {
    if (overlap[2] == 1 && runLength == 0) {
      end = true;
      for (int j = 3; j < edge[0] + 1; j++) {
        if (overlap[j] < 2) {
          end = false;
          break;
        } else
          runLength++;
      }
      rate += 1;
      if (!end)
        rate += GolombBits(runLength, 0, 3);
    }
    if (overlap[3] < 2) {
      // encCodedMap[y*pic_w + x] = 1;
      get_forbidden_3OT(x, y, pic_w, pic_h, edge[2], turn, forbidden, boundary,
                        start_index, high_point, left_point);
      direction3 = to_3OT(edge[2], edge[3], &turn);
      switch (direction1 * 3 + direction2) {
      case 0:
        rate += acodec.getBits(direction3, a3OT_00, forbidden);
        break;
      case 1:
        rate += acodec.getBits(direction3, a3OT_01, forbidden);
        break;
      case 2:
        rate += acodec.getBits(direction3, a3OT_02, forbidden);
        break;
      case 3:
        rate += acodec.getBits(direction3, a3OT_10, forbidden);
        break;
      case 4:
        rate += acodec.getBits(direction3, a3OT_11, forbidden);
        break;
      case 5:
        rate += acodec.getBits(direction3, a3OT_12, forbidden);
        break;
      case 6:
        rate += acodec.getBits(direction3, a3OT_20, forbidden);
        break;
      case 7:
        rate += acodec.getBits(direction3, a3OT_21, forbidden);
        break;
      case 8:
        rate += acodec.getBits(direction3, a3OT_22, forbidden);
        break;
      }
    } else if (overlap[3] == 2) {
      direction3 = to_3OT(edge[2], edge[3], &turn);
      runLength--;
    }
    adapt_position_3OT(&x, &y, edge[3]);
  }

  if (edge[0] > 3) {
    if (overlap[3] == 1 && runLength == 0) {
      end = true;
      for (int j = 4; j < edge[0] + 1; j++) {
        if (overlap[j] < 2) {
          end = false;
          break;
        } else
          runLength++;
      }
      rate += 1;
      if (!end)
        rate += GolombBits(runLength, 0, 3);
    }
    if (overlap[4] < 2) {
      // encCodedMap[y*pic_w + x] = 1;
      get_forbidden_3OT(x, y, pic_w, pic_h, edge[3], turn, forbidden, boundary,
                        start_index, high_point, left_point);
      direction4 = to_3OT(edge[3], edge[4], &turn);
      switch (direction1 * 9 + direction2 * 3 + direction3) {
      case 0:
        rate += acodec.getBits(direction4, a3OT_000, forbidden);
        break;
      case 1:
        rate += acodec.getBits(direction4, a3OT_001, forbidden);
        break;
      case 2:
        rate += acodec.getBits(direction4, a3OT_002, forbidden);
        break;
      case 3:
        rate += acodec.getBits(direction4, a3OT_010, forbidden);
        break;
      case 4:
        rate += acodec.getBits(direction4, a3OT_011, forbidden);
        break;
      case 5:
        rate += acodec.getBits(direction4, a3OT_012, forbidden);
        break;
      case 6:
        rate += acodec.getBits(direction4, a3OT_020, forbidden);
        break;
      case 7:
        rate += acodec.getBits(direction4, a3OT_021, forbidden);
        break;
      case 8:
        rate += acodec.getBits(direction4, a3OT_022, forbidden);
        break;
      case 9:
        rate += acodec.getBits(direction4, a3OT_100, forbidden);
        break;
      case 10:
        rate += acodec.getBits(direction4, a3OT_101, forbidden);
        break;
      case 11:
        rate += acodec.getBits(direction4, a3OT_102, forbidden);
        break;
      case 12:
        rate += acodec.getBits(direction4, a3OT_110, forbidden);
        break;
      case 13:
        rate += acodec.getBits(direction4, a3OT_111, forbidden);
        break;
      case 14:
        rate += acodec.getBits(direction4, a3OT_112, forbidden);
        break;
      case 15:
        rate += acodec.getBits(direction4, a3OT_120, forbidden);
        break;
      case 16:
        rate += acodec.getBits(direction4, a3OT_121, forbidden);
        break;
      case 17:
        rate += acodec.getBits(direction4, a3OT_122, forbidden);
        break;
      case 18:
        rate += acodec.getBits(direction4, a3OT_200, forbidden);
        break;
      case 19:
        rate += acodec.getBits(direction4, a3OT_201, forbidden);
        break;
      case 20:
        rate += acodec.getBits(direction4, a3OT_202, forbidden);
        break;
      case 21:
        rate += acodec.getBits(direction4, a3OT_210, forbidden);
        break;
      case 22:
        rate += acodec.getBits(direction4, a3OT_211, forbidden);
        break;
      case 23:
        rate += acodec.getBits(direction4, a3OT_212, forbidden);
        break;
      case 24:
        rate += acodec.getBits(direction4, a3OT_220, forbidden);
        break;
      case 25:
        rate += acodec.getBits(direction4, a3OT_221, forbidden);
        break;
      case 26:
        rate += acodec.getBits(direction4, a3OT_222, forbidden);
        break;
      }
    } else if (overlap[4] == 2) {
      direction4 = to_3OT(edge[3], edge[4], &turn);
      runLength--;
    }
    adapt_position_3OT(&x, &y, edge[4]);
  }

  for (int i = 5; i < edge[0] + 1; i++) {
    if (overlap[i - 1] == 1 && runLength == 0) {
      end = true;
      for (int j = i; j < edge[0] + 1; j++) {
        if (overlap[j] < 2) {
          end = false;
          break;
        } else
          runLength++;
      }
      rate += 1;
      if (!end)
        rate += GolombBits(runLength, 0, 3);
    }
    if (overlap[i] < 2) {
      // encCodedMap[y*pic_w + x] = 1;
      get_forbidden_3OT(x, y, pic_w, pic_h, edge[i - 1], turn, forbidden,
                        boundary, start_index, high_point, left_point);
      direct_cur = to_3OT(edge[i - 1], edge[i], &turn);
      // if (edge[i] == 2)
      //{
      //	edge[i] = 2;
      // }

      switch (direction1 * 27 + direction2 * 9 + direction3 * 3 + direction4) {
      case 0:
        rate += acodec.getBits(direct_cur, a3OT_0000, forbidden);
        break;
      case 1:
        rate += acodec.getBits(direct_cur, a3OT_0001, forbidden);
        break;
      case 2:
        rate += acodec.getBits(direct_cur, a3OT_0002, forbidden);
        break;
      case 3:
        rate += acodec.getBits(direct_cur, a3OT_0010, forbidden);
        break;
      case 4:
        rate += acodec.getBits(direct_cur, a3OT_0011, forbidden);
        break;
      case 5:
        rate += acodec.getBits(direct_cur, a3OT_0012, forbidden);
        break;
      case 6:
        rate += acodec.getBits(direct_cur, a3OT_0020, forbidden);
        break;
      case 7:
        rate += acodec.getBits(direct_cur, a3OT_0021, forbidden);
        break;
      case 8:
        rate += acodec.getBits(direct_cur, a3OT_0022, forbidden);
        break;
      case 9:
        rate += acodec.getBits(direct_cur, a3OT_0100, forbidden);
        break;
      case 10:
        rate += acodec.getBits(direct_cur, a3OT_0101, forbidden);
        break;
      case 11:
        rate += acodec.getBits(direct_cur, a3OT_0102, forbidden);
        break;
      case 12:
        rate += acodec.getBits(direct_cur, a3OT_0110, forbidden);
        break;
      case 13:
        rate += acodec.getBits(direct_cur, a3OT_0111, forbidden);
        break;
      case 14:
        rate += acodec.getBits(direct_cur, a3OT_0112, forbidden);
        break;
      case 15:
        rate += acodec.getBits(direct_cur, a3OT_0120, forbidden);
        break;
      case 16:
        rate += acodec.getBits(direct_cur, a3OT_0121, forbidden);
        break;
      case 17:
        rate += acodec.getBits(direct_cur, a3OT_0122, forbidden);
        break;
      case 18:
        rate += acodec.getBits(direct_cur, a3OT_0200, forbidden);
        break;
      case 19:
        rate += acodec.getBits(direct_cur, a3OT_0201, forbidden);
        break;
      case 20:
        rate += acodec.getBits(direct_cur, a3OT_0202, forbidden);
        break;
      case 21:
        rate += acodec.getBits(direct_cur, a3OT_0210, forbidden);
        break;
      case 22:
        rate += acodec.getBits(direct_cur, a3OT_0211, forbidden);
        break;
      case 23:
        rate += acodec.getBits(direct_cur, a3OT_0212, forbidden);
        break;
      case 24:
        rate += acodec.getBits(direct_cur, a3OT_0220, forbidden);
        break;
      case 25:
        rate += acodec.getBits(direct_cur, a3OT_0221, forbidden);
        break;
      case 26:
        rate += acodec.getBits(direct_cur, a3OT_0222, forbidden);
        break;
      case 27:
        rate += acodec.getBits(direct_cur, a3OT_1000, forbidden);
        break;
      case 28:
        rate += acodec.getBits(direct_cur, a3OT_1001, forbidden);
        break;
      case 29:
        rate += acodec.getBits(direct_cur, a3OT_1002, forbidden);
        break;
      case 30:
        rate += acodec.getBits(direct_cur, a3OT_1010, forbidden);
        break;
      case 31:
        rate += acodec.getBits(direct_cur, a3OT_1011, forbidden);
        break;
      case 32:
        rate += acodec.getBits(direct_cur, a3OT_1012, forbidden);
        break;
      case 33:
        rate += acodec.getBits(direct_cur, a3OT_1020, forbidden);
        break;
      case 34:
        rate += acodec.getBits(direct_cur, a3OT_1021, forbidden);
        break;
      case 35:
        rate += acodec.getBits(direct_cur, a3OT_1022, forbidden);
        break;
      case 36:
        rate += acodec.getBits(direct_cur, a3OT_1100, forbidden);
        break;
      case 37:
        rate += acodec.getBits(direct_cur, a3OT_1101, forbidden);
        break;
      case 38:
        rate += acodec.getBits(direct_cur, a3OT_1102, forbidden);
        break;
      case 39:
        rate += acodec.getBits(direct_cur, a3OT_1110, forbidden);
        break;
      case 40:
        rate += acodec.getBits(direct_cur, a3OT_1111, forbidden);
        break;
      case 41:
        rate += acodec.getBits(direct_cur, a3OT_1112, forbidden);
        break;
      case 42:
        rate += acodec.getBits(direct_cur, a3OT_1120, forbidden);
        break;
      case 43:
        rate += acodec.getBits(direct_cur, a3OT_1121, forbidden);
        break;
      case 44:
        rate += acodec.getBits(direct_cur, a3OT_1122, forbidden);
        break;
      case 45:
        rate += acodec.getBits(direct_cur, a3OT_1200, forbidden);
        break;
      case 46:
        rate += acodec.getBits(direct_cur, a3OT_1201, forbidden);
        break;
      case 47:
        rate += acodec.getBits(direct_cur, a3OT_1202, forbidden);
        break;
      case 48:
        rate += acodec.getBits(direct_cur, a3OT_1210, forbidden);
        break;
      case 49:
        rate += acodec.getBits(direct_cur, a3OT_1211, forbidden);
        break;
      case 50:
        rate += acodec.getBits(direct_cur, a3OT_1212, forbidden);
        break;
      case 51:
        rate += acodec.getBits(direct_cur, a3OT_1220, forbidden);
        break;
      case 52:
        rate += acodec.getBits(direct_cur, a3OT_1221, forbidden);
        break;
      case 53:
        rate += acodec.getBits(direct_cur, a3OT_1222, forbidden);
        break;
      case 54:
        rate += acodec.getBits(direct_cur, a3OT_2000, forbidden);
        break;
      case 55:
        rate += acodec.getBits(direct_cur, a3OT_2001, forbidden);
        break;
      case 56:
        rate += acodec.getBits(direct_cur, a3OT_2002, forbidden);
        break;
      case 57:
        rate += acodec.getBits(direct_cur, a3OT_2010, forbidden);
        break;
      case 58:
        rate += acodec.getBits(direct_cur, a3OT_2011, forbidden);
        break;
      case 59:
        rate += acodec.getBits(direct_cur, a3OT_2012, forbidden);
        break;
      case 60:
        rate += acodec.getBits(direct_cur, a3OT_2020, forbidden);
        break;
      case 61:
        rate += acodec.getBits(direct_cur, a3OT_2021, forbidden);
        break;
      case 62:
        rate += acodec.getBits(direct_cur, a3OT_2022, forbidden);
        break;
      case 63:
        rate += acodec.getBits(direct_cur, a3OT_2100, forbidden);
        break;
      case 64:
        rate += acodec.getBits(direct_cur, a3OT_2101, forbidden);
        break;
      case 65:
        rate += acodec.getBits(direct_cur, a3OT_2102, forbidden);
        break;
      case 66:
        rate += acodec.getBits(direct_cur, a3OT_2110, forbidden);
        break;
      case 67:
        rate += acodec.getBits(direct_cur, a3OT_2111, forbidden);
        break;
      case 68:
        rate += acodec.getBits(direct_cur, a3OT_2112, forbidden);
        break;
      case 69:
        rate += acodec.getBits(direct_cur, a3OT_2120, forbidden);
        break;
      case 70:
        rate += acodec.getBits(direct_cur, a3OT_2121, forbidden);
        break;
      case 71:
        rate += acodec.getBits(direct_cur, a3OT_2122, forbidden);
        break;
      case 72:
        rate += acodec.getBits(direct_cur, a3OT_2200, forbidden);
        break;
      case 73:
        rate += acodec.getBits(direct_cur, a3OT_2201, forbidden);
        break;
      case 74:
        rate += acodec.getBits(direct_cur, a3OT_2202, forbidden);
        break;
      case 75:
        rate += acodec.getBits(direct_cur, a3OT_2210, forbidden);
        break;
      case 76:
        rate += acodec.getBits(direct_cur, a3OT_2211, forbidden);
        break;
      case 77:
        rate += acodec.getBits(direct_cur, a3OT_2212, forbidden);
        break;
      case 78:
        rate += acodec.getBits(direct_cur, a3OT_2220, forbidden);
        break;
      case 79:
        rate += acodec.getBits(direct_cur, a3OT_2221, forbidden);
        break;
      case 80:
        rate += acodec.getBits(direct_cur, a3OT_2222, forbidden);
        break;
      }
    } else if (overlap[i] == 2) {
      direct_cur = to_3OT(edge[i - 1], edge[i], &turn);
      runLength--;
    }

    direction1 = direction2;
    direction2 = direction3;
    direction3 = direction4;
    direction4 = direct_cur;
    adapt_position_3OT(&x, &y, edge[i]);
  }
  return rate;
}

// portable helpers to process input arguments
void copyArg(char *dst, size_t dstSize, const char *src) {
  if (dst == nullptr || src == nullptr || dstSize == 0) {
    return;
  }

  std::strncpy(dst, src, dstSize - 1);
  dst[dstSize - 1] = '\0';
}

bool parseIntArg(const char *src, int *value) {
  if (src == nullptr || value == nullptr) {
    return false;
  }

  return std::sscanf(src, "%d", value) == 1;
}

FILE *openFile(const char *path, const char *mode) {
  if (path == nullptr || mode == nullptr) {
    return nullptr;
  }

  return std::fopen(path, mode);
}
