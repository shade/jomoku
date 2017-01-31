#include <stdlib.h>
#include <stdio.h>
#include "jomoku.h"

#define NIL 240
#define NO 30
#define END_MASK 65537
int REVERSE[127];

void full_capped(byte m[], int shift, uint you_cur);
void non_capped(byte m[], int shift, uint you_cur);
void full_capped_eval(int m[], int shift, uint you_cur, byte thing);
void non_capped_eval(int m[], int shift, uint you_cur, byte thing);

void bit_build ()
{
  for (int i = 0; i < 256; i++)
  {
    int c = 0;

    for (int b = 0; b < 8; b++)
      if ((i>>b) & 1)
        c++;

    BITS[i] = c;
  }

  VAL_OPEN[B8(00000011)] = TWO_0; VAL_OPEN[B8(00000101)] = TWO_1;
  VAL_OPEN[B8(00000110)] = TWO_0; VAL_OPEN[B8(00000111)] = THR_0;
  VAL_OPEN[B8(00001001)] = TWO_2; VAL_OPEN[B8(00001010)] = TWO_1;
  VAL_OPEN[B8(00001011)] = THR_1; VAL_OPEN[B8(00001100)] = TWO_0;
  VAL_OPEN[B8(00001101)] = THR_1; VAL_OPEN[B8(00001110)] = THR_0;
  VAL_OPEN[B8(00001111)] = FOR_0; VAL_OPEN[B8(00010010)] = TWO_2;
  VAL_OPEN[B8(00010011)] = THR_2; VAL_OPEN[B8(00010100)] = TWO_1;
  VAL_OPEN[B8(00010101)] = THR_1; VAL_OPEN[B8(00010110)] = THR_1;
  VAL_OPEN[B8(00010111)] = FOR_1; VAL_OPEN[B8(00011000)] = TWO_0;
  VAL_OPEN[B8(00011001)] = THR_2; VAL_OPEN[B8(00011010)] = THR_1;
  VAL_OPEN[B8(00011011)] = FOR_2; VAL_OPEN[B8(00011100)] = THR_0;
  VAL_OPEN[B8(00011101)] = FOR_1; VAL_OPEN[B8(00011110)] = FOR_0;
  VAL_OPEN[B8(00011111)] = FIVER; // Ya win ere
}

/*
0000001000000
00001000000

1111 1111
0000 0000
*/

void eval (uint you, uint opp, unsigned long val)
{
  byte m[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int e[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  
  uint you_state = (you << 1) | 65537;
  uint opp_state = (opp << 1) | 65537;

  // This is to catagorically assign move values
  
  for (int i = 0; i < 11; i++)
  {
    uint you_cur = (you_state >> i) & 127;
    uint opp_cur = (opp_state >> i) & 127;

    switch (opp_cur)
    {
      case 0:
      case 1:
      case 64:
        non_capped(m, i, ((you_cur >> 1) & 15));
        non_capped_eval(e, i, ((you_cur >> 1) & 15), 1);
        break;
      case 65:
        full_capped(m, i, ((you_cur >> 1) & 15));
        full_capped_eval(e, i, ((you_cur >> 1) & 15), 1);
        break;
    }
    switch (you_cur)
    {
      case 0:
      case 1:
      case 64:
        non_capped(m, i, ((opp_cur >> 1) & 15));
        non_capped_eval(e, i, ((you_cur >> 1) & 15), 0);
        break;
      case 65:
        full_capped(m, i, ((opp_cur >> 1) & 15));
        full_capped_eval(e, i, ((you_cur >> 1) & 15), 0);
        break;
    }
  }
  int c = 0;
  for (int i = 0; i < 15; i++)
  {
    EVAL[val][i] = e[i];

    if(m[i])
    {
      MOVES[val][c++] = (m[i] << 4) | (i);
    }
  }

  MOVES[val][14] = c;
}