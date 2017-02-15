#include <iostream>
#include <math.h>
#include "board.h"


/**
 * Builds the WON table for won evaluation.
 */
void buildWon ()
{
  // For the numbers 0 to 1 << 16
  for (int i = 0; i < 32768; i++) {
    // Shift the line to 0
    for (int shift = 0; shift < 15; shift++) {
      if (((i >> shift) & 31) == 31) {
        WON[i] = 1;
        break;
      }
    }
  }
}

/**
 * Build the binary to ternary evaluation.
 */
void buildTernary ()
{
  // For the numbers 0 to 1 << 16
  for (int i = 0; i < 32768; i++) {
    int val = 0;
    // Go through the line from 0 to 15
    for (int n = 0; n < 15; n++) {
      if ((i >> n) & 1) {
        val += pow(3,n);
      }  
    }

    BT[i] = val;
    BT2[i] = (2 * val);
  }
}

/**
 * Analyze moves.
 */
void analyze (int opp, int you)
{
  byte m[] = {NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL};
  
  for (int i = 0; i < 10; i++) {
    int you_state = (you >> i) & 31;
    int opp_state = (opp >> i) & 31;

    if (!opp_state) {
      for (int shift = 0; shift < 5; shift++) {
        if (!((you_state >> shift) & 1)) {
          m[i + shift] += 1;
        }
      }
    }
    if (!you_state) {
      for (int shift = 0; shift < 5; shift++) {
        if (!((opp_state >> shift) & 1)) {
          m[i + shift] += 1;
        }
      }
    }
  }

  int state = BT2[opp] + BT[you];
  int c = 0;
  for (int i = 0; i < 15; i++) {
    if (m[i] != NIL) MOVES[state][c++] = (m[i] << 8) | i; 
  }

  MOVES[state][14] = c;
}

/**
 * Build the move table.
 */
void buildMove(int opp, int you, int depth)
{
  if (WON[opp] || WON[you]) return;

  if (depth < 0) {
    analyze(opp, you);
    return;
  }

  buildMove(opp, you, depth - 1);
  buildMove(opp | (1 << depth), you, depth - 1);
  buildMove(opp, you | (1 << depth), depth - 1);
}


/**
 * Builds everything!
 */
void buildAll ()
{
  buildWon();
  buildTernary();
  buildMove(0, 0, 14);
}
