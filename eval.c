#include <stdlib.h>
#include <stdio.h>
#include "jomoku.h"

#define NIL 240
#define NO 30

#define END_MASK 65537
int BITS[256];

void bit_build () 
{
  for (int i = 0; i < 256; i++) {
    int c = 0;
    for (int b = 0; b < 8; b++) {
      if ((i>>b) & 1) {
        c++;
      }
    }
    BITS[i] = c;
  }
}

void eval (uint you, uint opp, unsigned long val)
{
  int m[] = {NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL};

  you <<= 1;
  opp <<= 1;

  opp |= END_MASK;

  for (int s = 0; s < 11; s++) {
    byte opp_state = (opp >> s) & 62;
    byte you_state = ((you >> s) & 62) >> 1;

    if (opp_state == 0) {
      switch(BITS[you_state]) {
        case 4:
          switch (you_state) {
            case 30:m[0+s] = FIVE_VAL;break;
            case 29:m[1+s] = FIVE_VAL;break;
            case 27:m[2+s] = FIVE_VAL;break;
            case 23:m[3+s] = FIVE_VAL;break;
            case 15:m[4+s] = FIVE_VAL;break;
          }
          break;
        case 3:
          switch (you_state) {
            case B8(00001011): m[4+s] = MIN(FOUR_VAL_4,m[4+s]); m[2+s] = MIN(FOUR_VAL_2,m[2+s]);break;
            case B8(00010110): m[0+s] = MIN(FOUR_VAL_3,m[0+s]); m[2+s] = MIN(FOUR_VAL_2,m[2+s]);break;
            case B8(00001101): m[4+s] = MIN(FOUR_VAL_2,m[4+s]); m[2+s] = MIN(FOUR_VAL_4,m[2+s]);break;
            case B8(00011010): m[0+s] = MIN(FOUR_VAL_2,m[0+s]); m[2+s] = MIN(FOUR_VAL_3,m[2+s]);break;
            case B8(00010011): m[2+s] = MIN(FOUR_VAL_3,m[2+s]); m[3+s] = MIN(FOUR_VAL_4,m[3+s]);break;
            case B8(00010101): m[1+s] = MIN(FOUR_VAL_3,m[1+s]); m[3+s] = MIN(FOUR_VAL_3,m[3+s]);break;
            case B8(00011001): m[2+s] = MIN(FOUR_VAL_4,m[2+s]); m[3+s] = MIN(FOUR_VAL_3,m[3+s]);break;
            case B8(00011100): m[1+s] = MIN(FOUR_VAL_1,m[1+s]); m[0+s] = MIN(FOUR_VAL_3,m[0+s]);break;
            case B8(00001110): m[0+s] = MIN(FOUR_VAL_1,m[0+s]); m[4+s] = MIN(FOUR_VAL_1,m[4+s]);break;
            case B8(00000111): m[3+s] = MIN(FOUR_VAL_1,m[3+s]); m[4+s] = MIN(FOUR_VAL_3,m[4+s]);break;
          }
          break;
        case 2:
          switch (you_state) {
            case B8(00011000):m[0+s]=MIN(m[0+s],THRE_VAL_5); m[1+s]=MIN(THRE_VAL_3,m[1+s]); m[2+s]=MIN(THRE_VAL_1,m[2+s]);break;
            case B8(00001100):m[0+s]=MIN(m[0+s],THRE_VAL_3); m[1+s]=MIN(THRE_VAL_1,m[1+s]); m[4+s]=MIN(THRE_VAL_1,m[4+s]);break;
            case B8(00000110):m[0+s]=MIN(m[0+s],THRE_VAL_1); m[3+s]=MIN(THRE_VAL_1,m[3+s]); m[4+s]=MIN(THRE_VAL_3,m[4+s]);break;
            case B8(00000011):m[2+s]=MIN(m[2+s],THRE_VAL_1); m[3+s]=MIN(THRE_VAL_3,m[3+s]); m[4+s]=MIN(THRE_VAL_5,m[4+s]);break;
            case B8(00000101):m[1+s]=MIN(m[1+s],THRE_VAL_1); m[3+s]=MIN(THRE_VAL_3,m[3+s]); m[4+s]=MIN(THRE_VAL_4,m[4+s]);break;
            case B8(00001010):m[0+s]=MIN(m[0+s],THRE_VAL_3); m[2+s]=MIN(THRE_VAL_1,m[2+s]); m[4+s]=MIN(THRE_VAL_3,m[4+s]);break;
            case B8(00010100):m[0+s]=MIN(m[0+s],THRE_VAL_4); m[1+s]=MIN(THRE_VAL_3,m[1+s]); m[3+s]=MIN(THRE_VAL_1,m[3+s]);break;
            case B8(00001001):m[1+s]=MIN(m[1+s],THRE_VAL_3); m[2+s]=MIN(THRE_VAL_3,m[2+s]); m[4+s]=MIN(THRE_VAL_3,m[4+s]);break;
            case B8(00010010):m[0+s]=MIN(m[0+s],THRE_VAL_5); m[2+s]=MIN(THRE_VAL_3,m[2+s]); m[3+s]=MIN(THRE_VAL_3,m[3+s]);break;
            case B8(00010001):m[1+s]=MIN(m[1+s],THRE_VAL_5); m[2+2]=MIN(THRE_VAL_4,m[2+2]); m[3+s]=MIN(THRE_VAL_3,m[3+s]);break;
            }
          break;
        case 1:
          switch (you_state) {
            case B8(00000001):m[1+s]=MIN(m[1+s],TWO_VAL_1);break;
            case B8(00000010):m[0+s]=MIN(m[0+s],TWO_VAL_1);m[2+s]=MIN(m[2+s],TWO_VAL_1);break;
            case B8(00000100):m[1+s]=MIN(m[1+s],TWO_VAL_1);m[3+s]=MIN(m[3+s],TWO_VAL_1);break;
            case B8(00001000):m[2+s]=MIN(m[2+s],TWO_VAL_1);m[4+s]=MIN(m[4+s],TWO_VAL_1);break;
            case B8(00010000):m[3+s]=MIN(m[3+s],TWO_VAL_1);break;
          }
          break;
      }
    }
  }

  for(int i = 0; i < 15; i++) {
    if (m[i] != NIL) {
      MOVES[val][i] = m[i] + 1;
    } else {
      MOVES[val][i] = 0;
    }
  }

}