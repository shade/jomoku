#include <stdlib.h>
#include <stdio.h>
#include "jomoku.h"

#define NIL 240
#define NO 30
#define END_MASK 65537
int BITS[256];
int REVERSE[127];


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
}

/*
0000001000000
00001000000

1111 1111
0000 0000
*/

void eval (uint you, uint opp, unsigned long val)
{
  byte m[] = {NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL};
  // This is to catagorically assign move values
  for (int i = 0; i < 11; i++)
  {
    byte you_state = (you>>i) & 31;
    byte opp_state = (opp>>i) & 31;

    byte num = (5 - BITS[you_state]);

    if (!opp_state && you_state)
      for(int shift = 0; shift < 5; shift++)
        if (!((you_state >> shift) & 1))
          m[shift+i] = MIN(m[shift+i],num);

    num = (5 - BITS[opp_state]);
    if (opp_state && !you_state)
      for(int shift = 0; shift < 5; shift++)
        if (!((opp_state >> shift) & 1))
          m[shift+i] = MIN(m[shift+i],num);
  }
  

  for (int i = 0; i < 15; i++)
  {
    MOVES[val][i] = m[i];
  }
}
