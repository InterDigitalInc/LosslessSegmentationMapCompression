/* Copyright (c) 2026, InterDigital
 * All rights reserved.
 * See LICENSE under the root folder.
 */

#include "encOptions.h"
#include <cstring>
#include <iostream>
using namespace std;

int readOptions(int argc, char *argv[], char *filein, char *fileout, int *rows,
                int *cols, int *frameNum, int *skip, int *type)
{
  int i;
  // get input para
  for (i = 1; i < argc; i++)
  {
    if (argv[i][0] == '-')
    {
      switch (argv[i][1])
      {
      case 'h':
        cout
            << " There are 9 kinds of commands.\n -h(help information) -i(input file which only support .yuv now) -o(output file) -r(row number of the graph) -c(col number of the graph) \
					-f(number of frames) -s(skip number of frames) -t(type of video include 400 and 420)\
           \nfor example: -i D:/input.yuv -r 1024 -c 2048 -f 1 -t 400 -o output.bin "
            << endl;
        return -1;
        break;
      case 'i':
        i++;
        copyArg(filein, NAME_LENGTH, argv[i]);
        if (filein[strlen(argv[i]) - 1] != 'v' ||
            filein[strlen(argv[i]) - 2] != 'u' ||
            filein[strlen(argv[i]) - 3] != 'y' ||
            filein[strlen(argv[i]) - 4] != '.')
        {
          cout << "only support .yuv now" << endl;
          return -1;
        }
        break;
      case 'o':
        i++;
        copyArg(fileout, NAME_LENGTH, argv[i]);
        break;
      case 'r':
        parseIntArg(argv[++i], rows);
        break;
      case 'c':
        parseIntArg(argv[++i], cols);
        break;
      case 'f':
        parseIntArg(argv[++i], frameNum);
        break;
      case 's':
        parseIntArg(argv[++i], skip);
        break;
      case 't':
        parseIntArg(argv[++i], type);
        break;
      default:
        cout << "unsupport command exist" << endl;
        cout
            << " There are 9 kinds of commands.\n -h(help information) -i(input file which only support .yuv now) -o(output file) \
					-r(row number of the graph) -c(col number of the graph) -f(number of frames) -t(type of video include 400 and 420)\
          \nfor example: -i D:/input.yuv -r 1024 -c 2048 -f 1 -t 400 -o output.bin "
            << endl;
        return -1;
        break;
      }
    }
  }
  return 0;
}
