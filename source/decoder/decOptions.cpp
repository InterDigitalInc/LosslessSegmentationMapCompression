#include "decOptions.h"
#include <cstring>
#include <iostream>
using namespace std;

int readOptions(int argc, char *argv[], char *filein, char *fileout) {
  int i;
  // get input para
  for (i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      switch (argv[i][1]) {
      case 'h':
        cout
            << " There are three kinds of commands.\n -h(help information) -i(input file which created by our encoder) -o(output file which is .yuv) \
					\nfor example: -i output.bin -o recover.yuv "
            << endl;
        return -1;
        break;
      case 'i':
        i++;
        copyArg(filein, NAME_LENGTH, argv[i]);
        break;
      case 'o':
        i++;
        copyArg(fileout, NAME_LENGTH, argv[i]);
        break;
      default:
        cout << "unsupport commands exist" << endl;
        cout
            << " There are three kinds of commands.\n -h(help information) -i(input file which created by our encoder) -o(output file which is .yuv) \
					\nfor example: -i output.bin -o recover.yuv "
            << endl;
        return -1;
        break;
      }
    }
  }
  return 0;
}
