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

*/

void eval (uint you, uint opp, unsigned long val)
{
  byte m[] = {NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL};

  for (int i = 0; i < 15; i++)
  {
    // Check if the space is empty
    if (((you >> i) & 1) == 0)
    {
      int l = 0;
      int r = 0;
      int sr = i - 5;
      int sl = i + 5;

      if (sr < 0)
        sr = 0;
      if (sl > 15)
        sl = 15;

      // Check for a sequence of pieces, going right
      for (r = i; r < sr; r++)
        if (((opp >> r) & 1) == 0)
          break;

      // Now, going left
      for (l = i; l < sl; l++)
        if (((opp >> l) & 1) == 0)
          break;

      // If the sequence is less than 5, it's not worth it
      if ((r + l) < 4
        continue

      // Now the real fun begins
      for (int g = r; g < ; g++)
      {

      }
    }
  }

}
