// Copyright (c) 2026, InterDigital
// All rights reserved.
// See LICENSE under the root folder.

#include "coding_unit.h"
#include "global_arithmetic.h"
#include "utility.h"
#include <assert.h>
#include <cmath>
#include <iostream>

using namespace std;

CodingUnit::CodingUnit(void) {}

CodingUnit::~CodingUnit() {}

void CodingUnit::destroyObject()
{
  if (Edge_MSC)
    delete[] Edge_MSC;
  if (Overlap_MSC)
    delete[] Overlap_MSC;
  if (Edge_3OT)
    delete[] Edge_3OT;
  if (Overlap_3OT)
    delete[] Overlap_3OT;
  if (this->next)
    this->next->destroyObject();
  this->next = NULL;
}

bool isPrefix(int dir_long, int dir_short)
{
  switch (dir_long)
  {
  case 8:
    if (dir_short == 0)
      return true;
    break;
  case 9:
    if (dir_short == 1)
      return true;
    break;
  case 10:
    if (dir_short == 1)
      return true;
    break;
  case 11:
    if (dir_short == 2)
      return true;
    break;
  case 12:
    if (dir_short == 2)
      return true;
    break;
  case 13:
    if (dir_short == 3)
      return true;
    break;
  case 14:
    if (dir_short == 3)
      return true;
    break;
  case 15:
    if (dir_short == 4)
      return true;
    break;
  case 16:
    if (dir_short == 4)
      return true;
    break;
  case 17:
    if (dir_short == 5)
      return true;
    break;
  case 18:
    if (dir_short == 5)
      return true;
    break;
  case 19:
    if (dir_short == 6)
      return true;
    break;
  case 20:
    if (dir_short == 6)
      return true;
    break;
  case 21:
    if (dir_short == 7)
      return true;
    break;
  case 22:
    if (dir_short == 7)
      return true;
    break;
  case 23:
    if (dir_short == 0)
      return true;
    break;
  case 24:
    if (dir_short == 0 || dir_short == 8)
      return true;
    break;
  case 25:
    if (dir_short == 1 || dir_short == 9)
      return true;
    break;
  case 26:
    if (dir_short == 2 || dir_short == 12)
      return true;
    break;
  case 27:
    if (dir_short == 2 || dir_short == 12)
      return true;
    break;
  case 28:
    if (dir_short == 3 || dir_short == 13)
      return true;
    break;
  case 29:
    if (dir_short == 4 || dir_short == 16)
      return true;
    break;
  case 30:
    if (dir_short == 4 || dir_short == 16)
      return true;
    break;
  case 31:
    if (dir_short == 5 || dir_short == 17)
      return true;
    break;
  case 32:
    if (dir_short == 6 || dir_short == 20)
      return true;
    break;
  case 33:
    if (dir_short == 6 || dir_short == 20)
      return true;
    break;
  case 34:
    if (dir_short == 7 || dir_short == 21)
      return true;
    break;
  case 35:
    if (dir_short == 0 || dir_short == 8)
      return true;
    break;
  }
  return false;
}

void CodingUnit::create_object_MSC(unsigned char *pImg, int h, int w,
                                   int loc_row, int loc_col, int index,
                                   bool paint)
{
  location_row = loc_row;
  location_col = loc_col;
  pic_width = w;
  pic_height = h;
  Edge_MSC = NULL;
  Overlap_MSC = NULL;
  colorValue = pImg[location_row * pic_width + location_col];
  object_index = index;
  next = NULL;
  if (paint)
  {
    for (int k = 0; k < pic_height * pic_width; k++)
      encCodedMap[k] = 255;
  }
  int x = location_col, y = location_row, j = 0, edgeLength = 0;
  int edgeline[256 * 256];
  bool boundary = false;

  int direction;
  if (location_col == 0)
  {
    direction = 0;
    y -= 1;
    boundary = true;
  }
  else if (location_row == pic_height - 1)
  {
    direction = 2;
    x -= 1;
    boundary = true;
  }
  else if (location_col == pic_width - 1)
  {
    direction = 4;
    y += 1;
    boundary = true;
  }
  else if (location_row == 0)
  {
    direction = 6;
    x += 1;
    boundary = true;
  }
  else
  {
    direction = 2;
    x -= 1;
  }
  int initial_y = y, initial_x = x;
  int x_run = x, y_run = y;
  if (paint)
    encCodedMap[initial_y * pic_width + initial_x] = -1;

  while (1)
  {
    x = x_run;
    y = y_run;
    if ((x == 0 && direction == 4) || (x == 0 && direction == 5) ||
        (y == 0 && direction == 2) || (y == 0 && direction == 3) ||
        (y == pic_height - 1 && direction == 6) ||
        (y == pic_height - 1 && direction == 7) ||
        (x == pic_width - 1 && direction == 0) ||
        (x == pic_width - 1 && direction == 1) ||
        !(x >= 0 && x < pic_width && y >= 0 && y < pic_height))
      break;
    if (edgeLength > 2 && !boundary && (x == initial_x && y == initial_y))
      break;

    direction = (direction + 5) % 8;
    bool find = false;
    while (x_run >= 0 && x_run < pic_width && y_run >= 0 &&
           y_run < pic_height)
    {
      direction = (direction + 1) % 8;
      switch (direction)
      {
      case 0:
        x_run = x + 1;
        y_run = y;
        if (!(x_run >= 0 && x_run < pic_width && y_run >= 0 &&
              y_run < pic_height))
        {
          edgeline[edgeLength++] = 0;
          break;
        }
        if (codedMap[y_run * pic_width + x_run] != object_index)
        {
          edgeline[edgeLength++] = 0;
          find = true;
        }
        break;
      case 1:
        x_run = x + 1;
        y_run = y - 1;
        if (!(x_run >= 0 && x_run < pic_width && y_run >= 0 &&
              y_run < pic_height))
        {
          edgeline[edgeLength++] = 1;
          break;
        }
        if (codedMap[y_run * pic_width + x_run] != object_index)
        {
          if (codedMap[y_run * pic_width + x_run - 1] == object_index)
            break;
          edgeline[edgeLength++] = 1;
          find = true;
        }
        break;
      case 2:
        x_run = x;
        y_run = y - 1;
        if (!(x_run >= 0 && x_run < pic_width && y_run >= 0 &&
              y_run < pic_height))
        {
          edgeline[edgeLength++] = 2;
          break;
        }
        if (codedMap[y_run * pic_width + x_run] != object_index)
        {
          edgeline[edgeLength++] = 2;
          find = true;
        }
        break;
      case 3:
        x_run = x - 1;
        y_run = y - 1;
        if (!(x_run >= 0 && x_run < pic_width && y_run >= 0 &&
              y_run < pic_height))
        {
          edgeline[edgeLength++] = 3;
          break;
        }
        if (codedMap[y_run * pic_width + x_run] != object_index)
        {
          if (codedMap[(y_run + 1) * pic_width + x_run] == object_index)
            break;
          edgeline[edgeLength++] = 3;
          find = true;
        }
        break;
      case 4:
        x_run = x - 1;
        y_run = y;
        if (!(x_run >= 0 && x_run < pic_width && y_run >= 0 &&
              y_run < pic_height))
        {
          edgeline[edgeLength++] = 4;
          break;
        }
        if (codedMap[y_run * pic_width + x_run] != object_index)
        {
          edgeline[edgeLength++] = 4;
          find = true;
        }
        break;
      case 5:
        x_run = x - 1;
        y_run = y + 1;
        if (!(x_run >= 0 && x_run < pic_width && y_run >= 0 &&
              y_run < pic_height))
        {
          edgeline[edgeLength++] = 5;
          break;
        }
        if (codedMap[y_run * pic_width + x_run] != object_index)
        {
          if (codedMap[y_run * pic_width + x_run + 1] == object_index)
            break;
          edgeline[edgeLength++] = 5;
          find = true;
        }
        break;
      case 6:
        x_run = x;
        y_run = y + 1;
        if (!(x_run >= 0 && x_run < pic_width && y_run >= 0 &&
              y_run < pic_height))
        {
          edgeline[edgeLength++] = 6;
          break;
        }
        if (codedMap[y_run * pic_width + x_run] != object_index)
        {
          edgeline[edgeLength++] = 6;
          find = true;
        }
        break;
      case 7:
        x_run = x + 1;
        y_run = y + 1;
        if (!(x_run >= 0 && x_run < pic_width && y_run >= 0 &&
              y_run < pic_height))
        {
          edgeline[edgeLength++] = 7;
          break;
        }
        if (codedMap[y_run * pic_width + x_run] != object_index)
        {
          if (codedMap[(y_run - 1) * pic_width + x_run] == object_index)
            break;
          edgeline[edgeLength++] = 7;
          find = true;
        }
        break;
      }
      if (find)
      {
        if (paint)
          encCodedMap[y_run * pic_width + x_run] = -1;
        break;
      }
    }
  }

  int cc_num = 0;
  y = initial_y;
  x = initial_x;
  for (int i = 0; i < edgeLength; i++)
  {
    if (edgeLength - i > 2)
    {
      edgeline[j] =
          get_MSC(edgeline[i], edgeline[i + 1], edgeline[i + 2], &cc_num);
      i += cc_num - 1;
    }
    else if (edgeLength - i == 2)
    {
      edgeline[j] = get_MSC(edgeline[i], edgeline[i + 1], -1, &cc_num);
      i += cc_num - 1;
    }
    else
    {
      edgeline[j] = get_MSC(edgeline[i], -1, -1, &cc_num);
      i += cc_num - 1;
    }
    j++;
    switch (edgeline[j - 1])
    {
    case 0:
      x += 1;
      break;
    case 1:
      x += 1;
      y -= 1;
      break;
    case 2:
      y -= 1;
      break;
    case 3:
      x -= 1;
      y -= 1;
      break;
    case 4:
      x -= 1;
      break;
    case 5:
      x -= 1;
      y += 1;
      break;
    case 6:
      y += 1;
      break;
    case 7:
      x += 1;
      y += 1;
      break;
    case 8:
      x += 2;
      break;
    case 9:
      x += 2;
      y -= 1;
      break;
    case 10:
      x += 2;
      y -= 2;
      break;
    case 11:
      x += 1;
      y -= 2;
      break;
    case 12:
      y -= 2;
      break;
    case 13:
      x -= 1;
      y -= 2;
      break;
    case 14:
      x -= 2;
      y -= 2;
      break;
    case 15:
      x -= 2;
      y -= 1;
      break;
    case 16:
      x -= 2;
      break;
    case 17:
      x -= 2;
      y += 1;
      break;
    case 18:
      x -= 2;
      y += 2;
      break;
    case 19:
      x -= 1;
      y += 2;
      break;
    case 20:
      y += 2;
      break;
    case 21:
      x += 1;
      y += 2;
      break;
    case 22:
      x += 2;
      y += 2;
      break;
    case 23:
      x += 2;
      y += 1;
      break;
    case 24:
      x += 3;
      break;
    case 25:
      x += 3;
      y -= 1;
      break;
    case 26:
      x += 1;
      y -= 3;
      break;
    case 27:
      y -= 3;
      break;
    case 28:
      x -= 1;
      y -= 3;
      break;
    case 29:
      x -= 3;
      y -= 1;
      break;
    case 30:
      x -= 3;
      break;
    case 31:
      x -= 3;
      y += 1;
      break;
    case 32:
      x -= 1;
      y += 3;
      break;
    case 33:
      y += 3;
      break;
    case 34:
      x += 1;
      y += 3;
      break;
    case 35:
      x += 3;
      y += 1;
      break;
    }
    if ((x == 0) && (edgeline[j - 1] == 2 || edgeline[j - 1] == 12))
      break;
    if ((y == 0) && (edgeline[j - 1] == 0 || edgeline[j - 1] == 8))
      break;
    if ((y == pic_height - 1) &&
        (edgeline[j - 1] == 4 || edgeline[j - 1] == 16))
      break;
    if ((x == pic_width - 1) && (edgeline[j - 1] == 6 || edgeline[j - 1] == 20))
      break;
  }

  Edge_MSC = new int[j + 1];
  Edge_MSC[0] = j;
  for (int i = 0; i < j; i++)
    Edge_MSC[1 + i] = edgeline[i];

  Overlap_MSC = new int[j];
  for (int i = 0; i < j; i++)
    Overlap_MSC[i] = 0;

  int Available_val[256];
  for (int i = 0; i < 256; i++)
    Available_val[i] = 1;
  Available_val[255] = 0;
  Available_val[encImg[location_row * pic_width + location_col]] = 0;

  y_run = initial_y;
  x_run = initial_x;
  y = initial_y;
  x = initial_x;
  int F8[3] = {-1, -1, -1}, MSC_ava;

  if (location_col == 0)
    direction = 0;
  else if (location_row == pic_height - 1)
    direction = 2;
  else if (location_col == pic_width - 1)
    direction = 4;
  else if (location_row == 0)
    direction = 6;
  else
    direction = 2;

  for (int i = 0; i < j; i++)
  {
    if (Available_val[encImg[initial_y * pic_width + initial_x]])
    {
      Overlap_MSC[i] += 1;

      F8[0] = -1;
      F8[1] = -1;
      F8[2] = -1;
      y_run = initial_y;
      x_run = initial_x;
      for (int k = 0; k < 3; k++)
      {
        x = x_run;
        y = y_run;
        direction = (direction + 5) % 8;
        int end_direction = direction;
        bool find = false;
        while (x_run >= 0 && x_run < pic_width && y_run >= 0 &&
               y_run < pic_height)
        {
          direction = (direction + 1) % 8;
          switch (direction)
          {
          case 0:
            x_run = x + 1;
            y_run = y;
            if (!(x_run >= 0 && x_run < pic_width && y_run >= 0 &&
                  y_run < pic_height))
            {
              F8[k] = 0;
              break;
            }
            if (Available_val[encImg[y_run * pic_width + x_run]])
            {
              F8[k] = 0;
              find = true;
            }
            break;
          case 1:
            x_run = x + 1;
            y_run = y - 1;
            if (!(x_run >= 0 && x_run < pic_width && y_run >= 0 &&
                  y_run < pic_height))
            {
              F8[k] = 1;
              break;
            }
            if (Available_val[encImg[y_run * pic_width + x_run]])
            {
              F8[k] = 1;
              find = true;
            }
            break;
          case 2:
            x_run = x;
            y_run = y - 1;
            if (!(x_run >= 0 && x_run < pic_width && y_run >= 0 &&
                  y_run < pic_height))
            {
              F8[k] = 2;
              break;
            }
            if (Available_val[encImg[y_run * pic_width + x_run]])
            {
              F8[k] = 2;
              find = true;
            }
            break;
          case 3:
            x_run = x - 1;
            y_run = y - 1;
            if (!(x_run >= 0 && x_run < pic_width && y_run >= 0 &&
                  y_run < pic_height))
            {
              F8[k] = 3;
              break;
            }
            if (Available_val[encImg[y_run * pic_width + x_run]])
            {
              F8[k] = 3;
              find = true;
            }
            break;
          case 4:
            x_run = x - 1;
            y_run = y;
            if (!(x_run >= 0 && x_run < pic_width && y_run >= 0 &&
                  y_run < pic_height))
            {
              F8[k] = 4;
              break;
            }
            if (Available_val[encImg[y_run * pic_width + x_run]])
            {
              F8[k] = 4;
              find = true;
            }
            break;
          case 5:
            x_run = x - 1;
            y_run = y + 1;
            if (!(x_run >= 0 && x_run < pic_width && y_run >= 0 &&
                  y_run < pic_height))
            {
              F8[k] = 5;
              break;
            }
            if (Available_val[encImg[y_run * pic_width + x_run]])
            {
              F8[k] = 5;
              find = true;
            }
            break;
          case 6:
            x_run = x;
            y_run = y + 1;
            if (!(x_run >= 0 && x_run < pic_width && y_run >= 0 &&
                  y_run < pic_height))
            {
              F8[k] = 6;
              break;
            }
            if (Available_val[encImg[y_run * pic_width + x_run]])
            {
              F8[k] = 6;
              find = true;
            }
            break;
          case 7:
            x_run = x + 1;
            y_run = y + 1;
            if (!(x_run >= 0 && x_run < pic_width && y_run >= 0 &&
                  y_run < pic_height))
            {
              F8[k] = 7;
              break;
            }
            if (Available_val[encImg[y_run * pic_width + x_run]])
            {
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
      MSC_ava = get_MSC(F8[0], F8[1], F8[2], &cc_num);
      if (MSC_ava == Edge_MSC[i + 1])
        Overlap_MSC[i] += 1;

      if (i == j - 1 && Overlap_MSC[i] == 1 &&
          isPrefix(MSC_ava, Edge_MSC[i + 1]))
        Overlap_MSC[i] += 1;
    }
    switch (Edge_MSC[i + 1])
    {
    case 0:
      initial_x += 1;
      direction = 0;
      break;
    case 1:
      initial_x += 1;
      initial_y -= 1;
      direction = 1;
      break;
    case 2:
      initial_y -= 1;
      direction = 2;
      break;
    case 3:
      initial_x -= 1;
      initial_y -= 1;
      direction = 3;
      break;
    case 4:
      initial_x -= 1;
      direction = 4;
      break;
    case 5:
      initial_x -= 1;
      initial_y += 1;
      direction = 5;
      break;
    case 6:
      initial_y += 1;
      direction = 6;
      break;
    case 7:
      initial_x += 1;
      initial_y += 1;
      direction = 7;
      break;
    case 8:
      initial_x += 2;
      direction = 0;
      break;
    case 9:
      initial_x += 2;
      initial_y -= 1;
      direction = 0;
      break;
    case 10:
      initial_x += 2;
      initial_y -= 2;
      direction = 1;
      break;
    case 11:
      initial_x += 1;
      initial_y -= 2;
      direction = 1;
      break;
    case 12:
      initial_y -= 2;
      direction = 2;
      break;
    case 13:
      initial_x -= 1;
      initial_y -= 2;
      direction = 2;
      break;
    case 14:
      initial_x -= 2;
      initial_y -= 2;
      direction = 3;
      break;
    case 15:
      initial_x -= 2;
      initial_y -= 1;
      direction = 3;
      break;
    case 16:
      initial_x -= 2;
      direction = 4;
      break;
    case 17:
      initial_x -= 2;
      initial_y += 1;
      direction = 4;
      break;
    case 18:
      initial_x -= 2;
      initial_y += 2;
      direction = 5;
      break;
    case 19:
      initial_x -= 1;
      initial_y += 2;
      direction = 5;
      break;
    case 20:
      initial_y += 2;
      direction = 6;
      break;
    case 21:
      initial_x += 1;
      initial_y += 2;
      direction = 6;
      break;
    case 22:
      initial_x += 2;
      initial_y += 2;
      direction = 7;
      break;
    case 23:
      initial_x += 2;
      initial_y += 1;
      direction = 7;
      break;
    case 24:
      initial_x += 3;
      direction = 0;
      break;
    case 25:
      initial_x += 3;
      initial_y -= 1;
      direction = 0;
      break;
    case 26:
      initial_x += 1;
      initial_y -= 3;
      direction = 1;
      break;
    case 27:
      initial_y -= 3;
      direction = 2;
      break;
    case 28:
      initial_x -= 1;
      initial_y -= 3;
      direction = 2;
      break;
    case 29:
      initial_x -= 3;
      initial_y -= 1;
      direction = 3;
      break;
    case 30:
      initial_x -= 3;
      direction = 4;
      break;
    case 31:
      initial_x -= 3;
      initial_y += 1;
      direction = 4;
      break;
    case 32:
      initial_x -= 1;
      initial_y += 3;
      direction = 5;
      break;
    case 33:
      initial_y += 3;
      direction = 6;
      break;
    case 34:
      initial_x += 1;
      initial_y += 3;
      direction = 6;
      break;
    case 35:
      initial_x += 3;
      initial_y += 1;
      direction = 7;
      break;
    }
  }

  if (paint)
    encObjectExpand(encImg, pic_height, pic_width, location_row, location_col,
                    colorValue);

  encodeEdgeLength_MSC(this, false);
}

void CodingUnit::create_object_3OT(unsigned char *pImg, int h, int w,
                                   int loc_row, int loc_col, int index)
{
  location_row = loc_row;
  location_col = loc_col;
  pic_width = w;
  pic_height = h;
  Edge_3OT = NULL;
  Overlap_3OT = NULL;
  colorValue = pImg[location_row * pic_width + location_col];
  object_index = index;
  next = NULL;
  for (int k = 0; k < pic_height * pic_width; k++)
    encCodedMap[k] = 255;

  int x = location_col, y = location_row, edgeLength = 0;
  int edgeline[256 * 256];
  bool boundary = false;

  int direction;
  if (location_col == 0)
  {
    direction = 0;
    y -= 1;
    boundary = true;
  }
  else if (location_row == pic_height - 1)
  {
    direction = 2;
    x -= 1;
    boundary = true;
  }
  else if (location_col == pic_width - 1)
  {
    direction = 4;
    y += 1;
    boundary = true;
  }
  else if (location_row == 0)
  {
    direction = 6;
    x += 1;
    boundary = true;
  }
  else
  {
    direction = 2;
    x -= 1;
  }
  int initial_y = y, initial_x = x;
  int x_run = x, y_run = y;
  encCodedMap[initial_y * pic_width + initial_x] = -1;

  while (1)
  {
    x = x_run;
    y = y_run;
    if ((x == 0 && direction == 4) || (x == 0 && direction == 5) ||
        (y == 0 && direction == 2) || (y == 0 && direction == 3) ||
        (y == pic_height - 1 && direction == 6) ||
        (y == pic_height - 1 && direction == 7) ||
        (x == pic_width - 1 && direction == 0) ||
        (x == pic_width - 1 && direction == 1) ||
        !(x >= 0 && x < pic_width && y >= 0 && y < pic_height))
      break;
    if (edgeLength > 2 && !boundary && ((x == initial_x) && (y == initial_y)))
      break;

    direction = (direction + 5) % 8;
    bool find = false;
    while (x_run >= 0 && x_run < pic_width && y_run >= 0 &&
           y_run < pic_height)
    {
      direction = (direction + 1) % 8;
      switch (direction)
      {
      case 0:
        x_run = x + 1;
        y_run = y;
        if (!(x_run >= 0 && x_run < pic_width && y_run >= 0 &&
              y_run < pic_height))
        {
          edgeline[edgeLength++] = 0;
          break;
        }
        if (codedMap[y_run * pic_width + x_run] != object_index)
        {
          edgeline[edgeLength++] = 0;
          find = true;
        }
        break;
      case 1:
        x_run = x + 1;
        y_run = y - 1;
        if (!(x_run >= 0 && x_run < pic_width && y_run >= 0 &&
              y_run < pic_height))
        {
          edgeline[edgeLength++] = 1;
          break;
        }
        if (codedMap[y_run * pic_width + x_run] != object_index)
        {
          if (codedMap[y_run * pic_width + x_run - 1] == object_index)
            break;
          edgeline[edgeLength++] = 1;
          find = true;
        }
        break;
      case 2:
        x_run = x;
        y_run = y - 1;
        if (!(x_run >= 0 && x_run < pic_width && y_run >= 0 &&
              y_run < pic_height))
        {
          edgeline[edgeLength++] = 2;
          break;
        }
        if (codedMap[y_run * pic_width + x_run] != object_index)
        {
          edgeline[edgeLength++] = 2;
          find = true;
        }
        break;
      case 3:
        x_run = x - 1;
        y_run = y - 1;
        if (!(x_run >= 0 && x_run < pic_width && y_run >= 0 &&
              y_run < pic_height))
        {
          edgeline[edgeLength++] = 3;
          break;
        }
        if (codedMap[y_run * pic_width + x_run] != object_index)
        {
          if (codedMap[(y_run + 1) * pic_width + x_run] == object_index)
            break;
          edgeline[edgeLength++] = 3;
          find = true;
        }
        break;
      case 4:
        x_run = x - 1;
        y_run = y;
        if (!(x_run >= 0 && x_run < pic_width && y_run >= 0 &&
              y_run < pic_height))
        {
          edgeline[edgeLength++] = 4;
          break;
        }
        if (codedMap[y_run * pic_width + x_run] != object_index)
        {
          edgeline[edgeLength++] = 4;
          find = true;
        }
        break;
      case 5:
        x_run = x - 1;
        y_run = y + 1;
        if (!(x_run >= 0 && x_run < pic_width && y_run >= 0 &&
              y_run < pic_height))
        {
          edgeline[edgeLength++] = 5;
          break;
        }
        if (codedMap[y_run * pic_width + x_run] != object_index)
        {
          if (codedMap[y_run * pic_width + x_run + 1] == object_index)
            break;
          edgeline[edgeLength++] = 5;
          find = true;
        }
        break;
      case 6:
        x_run = x;
        y_run = y + 1;
        if (!(x_run >= 0 && x_run < pic_width && y_run >= 0 &&
              y_run < pic_height))
        {
          edgeline[edgeLength++] = 6;
          break;
        }
        if (codedMap[y_run * pic_width + x_run] != object_index)
        {
          edgeline[edgeLength++] = 6;
          find = true;
        }
        break;
      case 7:
        x_run = x + 1;
        y_run = y + 1;
        if (!(x_run >= 0 && x_run < pic_width && y_run >= 0 &&
              y_run < pic_height))
        {
          edgeline[edgeLength++] = 7;
          break;
        }
        if (codedMap[y_run * pic_width + x_run] != object_index)
        {
          if (codedMap[(y_run - 1) * pic_width + x_run] == object_index)
            break;
          edgeline[edgeLength++] = 7;
          find = true;
        }
        break;
      }
      if (find)
      {
        encCodedMap[y_run * pic_width + x_run] = -1;
        break;
      }
    }
  }

  int start_y = location_row, start_x = location_col, end_y = location_row + 1,
      end_x = location_col;
  int edgeline_3OT[256 * 256];
  int edgeLength_3OT = 0;
  if (location_col == 0)
  {
    start_x++;
    if (edgeline[0] == 2)
    {
      start_y -= 2;
      edgeline_3OT[edgeLength_3OT++] = 1;
      edgeline_3OT[edgeLength_3OT++] = 1;
    }
    else if (edgeline[0] == 1)
    {
      start_y -= 1;
      edgeline_3OT[edgeLength_3OT++] = 1;
      if (start_y > 0)
      {
        start_x += 1;
        edgeline_3OT[edgeLength_3OT++] = 0;
      }
    }
    else if (edgeline[0] == 0)
    {
      start_x += 1;
      edgeline_3OT[edgeLength_3OT++] = 0;
    }
    else if (edgeline[0] == 7)
    {
      start_y += 1;
      edgeline_3OT[edgeLength_3OT++] = 3;
    }
  }
  else if (location_row == pic_height - 1)
  {
    if (edgeline[0] == 4)
    {
      start_x -= 2;
      edgeline_3OT[edgeLength_3OT++] = 2;
      edgeline_3OT[edgeLength_3OT++] = 2;
    }
    else if (edgeline[0] == 3)
    {
      start_x -= 1;
      edgeline_3OT[edgeLength_3OT++] = 2;
      if (start_x > 0)
      {
        start_y -= 1;
        edgeline_3OT[edgeLength_3OT++] = 1;
      }
    }
    else if (edgeline[0] == 2)
    {
      start_y -= 1;
      edgeline_3OT[edgeLength_3OT++] = 1;
    }
    else if (edgeline[0] == 1)
    {
      start_x += 1;
      edgeline_3OT[edgeLength_3OT++] = 0;
    }
  }
  else if (location_col == pic_width - 1)
  {
    start_y++;
    if (edgeline[0] == 6)
    {
      start_y += 2;
      edgeline_3OT[edgeLength_3OT++] = 3;
      edgeline_3OT[edgeLength_3OT++] = 3;
    }
    else if (edgeline[0] == 5)
    {
      start_y += 1;
      edgeline_3OT[edgeLength_3OT++] = 3;
      if (start_y < pic_height)
      {
        start_x -= 1;
        edgeline_3OT[edgeLength_3OT++] = 2;
      }
    }
    else if (edgeline[0] == 4)
    {
      start_x -= 1;
      edgeline_3OT[edgeLength_3OT++] = 2;
    }
    else if (edgeline[0] == 3)
    {
      start_y -= 1;
      edgeline_3OT[edgeLength_3OT++] = 1;
    }
  }
  else if (location_row == 0)
  {
    start_x++;
    start_y++;
    if (edgeline[0] == 0)
    {
      start_x += 2;
      edgeline_3OT[edgeLength_3OT++] = 0;
      edgeline_3OT[edgeLength_3OT++] = 0;
    }
    else if (edgeline[0] == 7)
    {
      start_x += 1;
      edgeline_3OT[edgeLength_3OT++] = 0;
      if (start_x < pic_width)
      {
        start_y += 1;
        edgeline_3OT[edgeLength_3OT++] = 3;
      }
    }
    else if (edgeline[0] == 6)
    {
      start_y += 1;
      edgeline_3OT[edgeLength_3OT++] = 3;
    }
    else if (edgeline[0] == 5)
    {
      start_x -= 1;
      edgeline_3OT[edgeLength_3OT++] = 2;
    }
  }
  else
  {
    start_x++;
  }

  for (int i = 0; i < edgeLength - 1; i++)
  {
    get_3OT(edgeline[i], edgeline[i + 1], edgeline_3OT, &edgeLength_3OT,
            &start_x, &start_y, end_x, end_y, pic_width, pic_height, boundary);
  }

  Edge_3OT = new int[edgeLength_3OT + 1];
  Edge_3OT[0] = edgeLength_3OT;
  for (int i = 0; i < edgeLength_3OT; i++)
    Edge_3OT[1 + i] = edgeline_3OT[i];

  Overlap_3OT = new int[edgeLength_3OT + 1];
  for (int i = 0; i < edgeLength_3OT + 1; i++)
    Overlap_3OT[i] = 0;

  int Available_val[256];
  for (int i = 0; i < 256; i++)
    Available_val[i] = 1;
  Available_val[255] = 0;
  Available_val[encImg[location_row * pic_width + location_col]] = 0;

  start_y = location_row;
  start_x = location_col;
  initial_y = location_row;
  initial_x = location_col;
  if (location_col == 0)
  {
    start_x++;
    direction = 0;
    initial_y--;
  }
  else if (location_row == pic_height - 1)
  {
    direction = 1;
    initial_x--;
  }
  else if (location_col == pic_width - 1)
  {
    start_y++;
    direction = 2;
    initial_y++;
  }
  else if (location_row == 0)
  {
    start_x++;
    start_y++;
    direction = 3;
    initial_x++;
  }
  else
  {
    start_x++;
    direction = 0;
    initial_y--;
  }

  bool first = true;
  if (Available_val[encImg[initial_y * pic_width + initial_x]])
  {
    Overlap_3OT[0] = 2;
  }
  else
    Overlap_3OT[0] = 0;

  for (int i = 0; i < edgeLength_3OT; i++)
  {
    switch (Edge_3OT[i + 1])
    {
    case 0:
      start_x++;
      initial_y = start_y - 1;
      initial_x = start_x - 1;
      break;
    case 1:
      start_y--;
      initial_y = start_y;
      initial_x = start_x - 1;
      break;
    case 2:
      start_x--;
      initial_y = start_y;
      initial_x = start_x;
      break;
    case 3:
      start_y++;
      initial_y = start_y - 1;
      initial_x = start_x;
      break;
    }

    if (Available_val[encImg[initial_y * pic_width + initial_x]])
    {
      Overlap_3OT[i + 1] = 2;
    }
  }
  for (int i = 0; i < edgeLength_3OT + 1; i++)
  {
    if (Overlap_3OT[i] == 2 && first)
    {
      Overlap_3OT[i] = 1;
      first = false;
    }
    else if (Overlap_3OT[i] == 0)
      first = true;
  }

  encObjectExpand(encImg, pic_height, pic_width, location_row, location_col,
                  colorValue);
}

int get_edge_position(int loc_row, int loc_col, int h, int w)
{
  if (loc_col == 0)
    return loc_row;
  else if (loc_row == h - 1)
    return h - 1 + loc_col;
  else if (loc_col == w - 1)
    return h - 1 + w - 1 + h - 1 - loc_row;
  else
    return h - 1 + w - 1 + h - 1 + w - 1 - loc_col;
}

void CodingUnit::enObjectEdge(int loc_row, int loc_col)
{
  acodec.encode(colorValue, aColor);

  int old_val, new_val;
  if (location_row == 0 || location_row == pic_height - 1 ||
      location_col == 0 || location_col == pic_width - 1)
  {
    old_val = get_edge_position(loc_row, loc_col, pic_height, pic_width);
    new_val =
        get_edge_position(location_row, location_col, pic_height, pic_width);
    encGolomb(new_val - old_val - 1, 0, position_K);
  }
  else
  {
    old_val = loc_row * (pic_width - 2) + loc_col - 1;
    if (object_index == 2 + edge_num)
      old_val = pic_width - 2 - 1;
    new_val = location_row * (pic_width - 2) + location_col - 1;
    encGolomb(new_val - old_val - 1, 0, position_K);
  }

  position_A += new_val - old_val - 1;
  position_N += 1;
  position_K = getBitSize(position_A / (2 * position_N));
  if (position_N >= 8)
  {
    position_N /= 2;
    position_A /= 2;
  }

  if (chain_mode == 0)
    encodeEdgeLength_MSC(this, true);
  else if (chain_mode == 1)
    encodeEdgeLength_3OT(this);
  else if (chain_mode == 2)
  {
    acodec.encode(chainType, aChainType);
    if (chainType == 0)
      encodeEdgeLength_MSC(this, true);
    else if (chainType == 1)
      encodeEdgeLength_3OT(this);
  }

  if (this->next)
    this->next->enObjectEdge(location_row, location_col);
}

void CodingUnit::selectChainMode()
{
  float bits_MSC = getBits_MSC(this);
  float bits_3OT = getBits_3OT(this);

  if (bits_MSC <= bits_3OT)
  {
    chainType = 0;
    restore_3OT();
    save_MSC();
  }
  else
  {
    chainType = 1;
    restore_MSC();
    save_3OT();
  }

  if (this->next)
    this->next->selectChainMode();
}

void CodingUnit::setFlag()
{
  if (chainType == 0)
    encodeEdgeLength_MSC(this, false);
  if (this->next)
    this->next->setFlag();
}
