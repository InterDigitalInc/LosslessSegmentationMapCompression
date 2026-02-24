#include "../../source/commonlib/CodingUnit.h"
#include "../../source/commonlib/global_arithmetic.h"
#include "../../source/commonlib/utility.h"
#include "encOptions.h"
#include <assert.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <time.h>
using namespace std;

void get_object_edge(unsigned char *p, int h, int w, CodingUnit *object) {
  objectExpand(p, h, w, 0, 0, 1);

  first_color = p[0];
  edge_num = 0;
  bool first_object = true;
  for (int i = 1; i < h; i++) {
    if (!codedMap[i * w]) {
      objectExpand(p, h, w, i, 0, edge_num + 2);
      if (first_object) {
        if (chain_mode == 0)
          object->create_object_MSC(p, h, w, i, 0, edge_num + 2);
        else if (chain_mode == 1)
          object->create_object_3OT(p, h, w, i, 0, edge_num + 2);
        else if (chain_mode == 2) {
          object->create_object_MSC(p, h, w, i, 0, edge_num + 2, false);
          object->create_object_3OT(p, h, w, i, 0, edge_num + 2);
        }
        first_object = false;
      } else {
        CodingUnit *object2 = new CodingUnit;
        if (chain_mode == 0)
          object2->create_object_MSC(p, h, w, i, 0, edge_num + 2);
        else if (chain_mode == 1)
          object2->create_object_3OT(p, h, w, i, 0, edge_num + 2);
        else if (chain_mode == 2) {
          object2->create_object_MSC(p, h, w, i, 0, edge_num + 2, false);
          object2->create_object_3OT(p, h, w, i, 0, edge_num + 2);
        }
        object->next = object2;
        object = object2;
      }
      edge_num++;
    }
  }
  for (int j = 1; j < w; j++) {
    if (!codedMap[(h - 1) * w + j]) {
      objectExpand(p, h, w, h - 1, j, edge_num + 2);
      if (first_object) {
        if (chain_mode == 0)
          object->create_object_MSC(p, h, w, h - 1, j, edge_num + 2);
        else if (chain_mode == 1)
          object->create_object_3OT(p, h, w, h - 1, j, edge_num + 2);
        else if (chain_mode == 2) {
          object->create_object_MSC(p, h, w, h - 1, j, edge_num + 2, false);
          object->create_object_3OT(p, h, w, h - 1, j, edge_num + 2);
        }
        first_object = false;
      } else {
        CodingUnit *object2 = new CodingUnit;
        if (chain_mode == 0)
          object2->create_object_MSC(p, h, w, h - 1, j, edge_num + 2);
        else if (chain_mode == 1)
          object2->create_object_3OT(p, h, w, h - 1, j, edge_num + 2);
        else if (chain_mode == 2) {
          object2->create_object_MSC(p, h, w, h - 1, j, edge_num + 2, false);
          object2->create_object_3OT(p, h, w, h - 1, j, edge_num + 2);
        }
        object->next = object2;
        object = object2;
      }
      edge_num++;
    }
  }
  for (int i = h - 1; i >= 0; i--) {
    if (!codedMap[i * w + w - 1]) {
      objectExpand(p, h, w, i, w - 1, edge_num + 2);
      if (first_object) {
        if (chain_mode == 0)
          object->create_object_MSC(p, h, w, i, w - 1, edge_num + 2);
        else if (chain_mode == 1)
          object->create_object_3OT(p, h, w, i, w - 1, edge_num + 2);
        else if (chain_mode == 2) {
          object->create_object_MSC(p, h, w, i, w - 1, edge_num + 2, false);
          object->create_object_3OT(p, h, w, i, w - 1, edge_num + 2);
        }
        first_object = false;
      } else {
        CodingUnit *object2 = new CodingUnit;
        if (chain_mode == 0)
          object2->create_object_MSC(p, h, w, i, w - 1, edge_num + 2);
        else if (chain_mode == 1)
          object2->create_object_3OT(p, h, w, i, w - 1, edge_num + 2);
        else if (chain_mode == 2) {
          object2->create_object_MSC(p, h, w, i, w - 1, edge_num + 2, false);
          object2->create_object_3OT(p, h, w, i, w - 1, edge_num + 2);
        }
        object->next = object2;
        object = object2;
      }
      edge_num++;
    }
  }
  for (int j = w - 2; j > 0; j--) {
    if (!codedMap[j]) {
      objectExpand(p, h, w, 0, j, edge_num + 2);
      if (first_object) {
        if (chain_mode == 0)
          object->create_object_MSC(p, h, w, 0, j, edge_num + 2);
        else if (chain_mode == 1)
          object->create_object_3OT(p, h, w, 0, j, edge_num + 2);
        else if (chain_mode == 2) {
          object->create_object_MSC(p, h, w, 0, j, edge_num + 2, false);
          object->create_object_3OT(p, h, w, 0, j, edge_num + 2);
        }
        first_object = false;
      } else {
        CodingUnit *object2 = new CodingUnit;
        if (chain_mode == 0)
          object2->create_object_MSC(p, h, w, 0, j, edge_num + 2);
        else if (chain_mode == 1)
          object2->create_object_3OT(p, h, w, 0, j, edge_num + 2);
        else if (chain_mode == 2) {
          object2->create_object_MSC(p, h, w, 0, j, edge_num + 2, false);
          object2->create_object_3OT(p, h, w, 0, j, edge_num + 2);
        }
        object->next = object2;
        object = object2;
      }
      edge_num++;
    }
  }

  inner_num = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (!codedMap[i * w + j]) {
        objectExpand(p, h, w, i, j, edge_num + 2 + inner_num);
        if (first_object) {
          if (chain_mode == 0)
            object->create_object_MSC(p, h, w, i, j, edge_num + 2 + inner_num);
          else if (chain_mode == 1)
            object->create_object_3OT(p, h, w, i, j, edge_num + 2 + inner_num);
          else if (chain_mode == 2) {
            object->create_object_MSC(p, h, w, i, j, edge_num + 2 + inner_num,
                                      false);
            object->create_object_3OT(p, h, w, i, j, edge_num + 2 + inner_num);
          }
          first_object = false;
        } else {
          CodingUnit *object2 = new CodingUnit;
          if (chain_mode == 0)
            object2->create_object_MSC(p, h, w, i, j, edge_num + 2 + inner_num);
          else if (chain_mode == 1)
            object2->create_object_3OT(p, h, w, i, j, edge_num + 2 + inner_num);
          else if (chain_mode == 2) {
            object2->create_object_MSC(p, h, w, i, j, edge_num + 2 + inner_num,
                                       false);
            object2->create_object_3OT(p, h, w, i, j, edge_num + 2 + inner_num);
          }
          object->next = object2;
          object = object2;
        }
        inner_num++;
      }
    }
  }
}

void encodeHead(unsigned char *buffer, int rows, int cols, int frameNum,
                int type, char *file_name, unsigned char *encodeStream,
                int *cMap, int *numC) {
  acodec.set_buffer(10000000, encodeStream);
  acodec.start_encoder();

  writeByArithmetic(&acodec, &ahead, rows, 16);
  writeByArithmetic(&acodec, &ahead, cols, 16);
  writeByArithmetic(&acodec, &ahead, frameNum, 16);
  if (type == 400) {
    acodec.encode(0, ahead);
  } else {
    acodec.encode(1, ahead);
  }
  int m_numColor = 0;
  int offset = rows * cols;
  if (type == 420) {
    offset = (offset * 3) >> 1;
  }
  for (int k = 0; k < frameNum; k++) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        int index = buffer[offset * k + i * cols + j];
        if (cMap[index] > 255) {
          cMap[index] = m_numColor;
          buffer[offset * k + i * cols + j] = m_numColor;
          m_numColor++;
        } else {
          buffer[offset * k + i * cols + j] = cMap[index];
        }
      }
    }
  }
  writeByArithmetic(&acodec, &ahead, m_numColor, 8);
  *numC = m_numColor;

  for (int i = 0; i < m_numColor; i++) {
    for (int j = 0; j < 256; j++) {
      if (cMap[j] == i) {
        writeByArithmetic(&acodec, &ahead, j, 8);
        break;
      }
    }
  }
  if (m_numColor > 1) {
    aColor.set_alphabet(m_numColor);
  }
}

int main(int argc, char **argv) {
  int begin, end;
  begin = clock();
  int rows;
  int cols;
  int frameNum = 1;
  int skip = 0;
  int speed = 0;
  int type = 400;
  char filein[1000];
  char fileout[1000];
  int error = readOptions(argc, argv, filein, fileout, &rows, &cols, &frameNum,
                          &skip, &type);
  if (error < 0) {
    getchar();
    return 0;
  }

  int size;
  int real_size;
  int skip_size;
  FILE *pFile;
  fopen_s(&pFile, filein, "rb");
  size = getFSize(pFile);
  if (type == 400) {
    real_size = rows * cols * frameNum;
    skip_size = rows * cols * skip;
    assert(size >= real_size + skip_size);
  }
  if (type == 420) {
    real_size = ((rows * cols * frameNum * 3) >> 1);
    skip_size = ((rows * cols * skip * 3) >> 1);
    assert(size >= real_size + skip_size);
  }
  unsigned char *buffer = new unsigned char[real_size];
  fseek(pFile, skip_size, SEEK_SET);
  fread(buffer, 1, real_size, pFile);

  fclose(pFile);
  unsigned char *graph = buffer;
  unsigned char *encodeStream = new unsigned char[10000000];
  for (int i = 0; i < 10000000; i++)
    encodeStream[i] = 0;

  codedMap = new int[rows * cols];
  encCodedMap = new int[rows * cols];
  encImg = new unsigned char[rows * cols];

  int *cMap = new int[256];
  for (int i = 0; i < 256; i++)
    cMap[i] = 256;
  encodeHead(buffer, rows, cols, frameNum, type, fileout, encodeStream, cMap,
             &numC);

  if (numC > 1) {
    for (int i = 0; i < frameNum; i++) {

      for (int j = 0; j < rows * cols; j++)
        codedMap[j] = 0;
      for (int j = 0; j < rows * cols; j++)
        encImg[j] = 255;

      CodingUnit *object = new CodingUnit;
      CodingUnit *object_first = object;
      get_object_edge(graph, rows, cols, object);

      aColor.reset();
      aflag.reset();
      aGolomb.reset();
      encGolomb(edge_num, 0, 1);
      encGolomb(inner_num, 0, 3);
      acodec.encode(first_color, aColor);
      if (edge_num + inner_num > 0) {
        if (chain_mode == 2) {
          reset_arithmetic();
          save_MSC();
          save_3OT();
          object_first->selectChainMode();
          for (int k = 12; k < 21; k++)
            aMSC[k] = 0;
          object_first->setFlag();
        }

        enc_global();
        reset_arithmetic();
        object_first->enObjectEdge(0, 0);
        object_first->destroyObject();
      }

      if (type == 400) {
        graph += rows * cols;
      }
      if (type == 420) {
        graph += ((rows * cols * 3) >> 1);
      }
    }
  }

  // cout << edge_num + inner_num << endl;

  int bytenum = acodec.stop_encoder();
  write2bin(encodeStream, bytenum, fileout);
  cout << "byteNum: " << bytenum << endl;
  end = clock();
  cout << "time: " << (end - begin) / 1000.0 << " sec" << endl;
  // cout << "objects: " << edge_num + inner_num << endl;

  // for (int i = 0; i < 27; i++)
  //{
  //	 printf("%4d ", aMSC[i]);
  // }

  delete[] encodeStream;
  delete[] buffer;
  delete[] codedMap;
  delete[] encCodedMap;
  delete[] cMap;

  return 0;
}
