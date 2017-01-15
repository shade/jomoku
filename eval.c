
#include <stdlib.h>
#include "jomoku.h"

void eval (uint you, uint opp, unsigned long val)
{
  for(int i = 0; i < 15; i++) {
    MOVES[val][i] = 10;
  }
}