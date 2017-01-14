#include <math.h>
#include <stdio.h>

#define FIVE 31

typedef unsigned char byte;
typedef unsigned int uint;

extern unsigned long BT[65535];
extern unsigned long BT2[65535];
extern byte WON[65535];
extern byte MOVES [14348907][14];

void eval (uint you, uint opp, unsigned long moves);

unsigned long get_ternary (int bin) 
{
  unsigned long val = 0;

  for(int i = 0; i < 15; i++) {
    if ((bin >> i) & 1) {
      val += pow(3,i);
    }  
  }

  return val;
}


void build_bt () 
{
  // Go through all the possible one person thing
  for (int i = 0; i < 65535; i++) {
    BT[i] = get_ternary(i);
    BT2[i] = 2 * BT[i];
    // Get the one side thing
    for (int shift = 0; shift < 14; shift++) {
      if (((i >> shift) & FIVE) == FIVE) {
        WON[i] = 1;
        break;
      }
    }
  }
}

// Recurse through all the build things
void build_recurse (uint you, uint opp, int depth) 
{
  if ((WON[you]|WON[opp]) != 0) {
    return;
  }

  if (depth < 0) {
    // There we go :)
    unsigned long ayy = (unsigned long)BT[you]+(unsigned long)BT2[opp];
    eval(you, opp, ayy);
    return;
  }

  build_recurse(you | (1 << depth), opp, depth - 1);
  build_recurse(you, opp | (1 << depth), depth - 1);
  build_recurse(you, opp, depth - 1);
}

void build_won () 
{
  build_recurse(0,0,14);
}
