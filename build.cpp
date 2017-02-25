#include <iostream>
#include <math.h>
#include "board.h"

using namespace std;

// Declare the arrays for moves.
extern byte MOVES[14348907][20];
// Declare the array for line evaluations.
extern int EVAL[14348907];
extern int WON[65540];
// Declare the VAL array, these are the weights, this should be mutable.
extern int VALS[15];

// The arrays for the stuff.
extern int BT[65536];
extern int BT2[65536];

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
  for (int i = 0; i < 65536; i++) {
    int val = 0;
    // Go through the line from 0 to 15
    for (int n = 0; n < 16; n++) {
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
  byte m[15] = {NIL};

  int state = BT2[opp] + BT[you];

  for (int i = 0; i < 12; i++) {
    if ((((you|opp) >> i) & 0b010) == 0b010) {
      m[i] = 1;
      m[2] = 1;
    }
  }

  int c = 0;
  for (int i = 0; i < 15; i++) {
    if (m[i] != NIL) {
      MOVES[state][c++] = ((m[i] << 4) | i);
    } 
  }

  MOVES[state][14] = c;
}

/**
 * Build the move table.
 */
void buildMove(int opp, int you, int depth)
{
  //if (WON[opp] || WON[you]) return;

  if (depth < 0) {
    analyze(opp, you);
    return;
  }

  buildMove(opp | (1 << depth), you, depth - 1);
  buildMove(opp, you | (1 << depth), depth - 1);
  buildMove(opp, you, depth - 1);
}


/**
 * Builds everything!
 */
void buildAll ()
{
  std::cout << "COMMENT: BUILDING TERNARY TABLES" << std::endl;
  buildTernary();
  std::cout << "COMMENT: BUILDING WON TABLES" << std::endl;
  buildWon();
  std::cout << "COMMENT: BUILDING MOVE TABLES" << std::endl;
  buildMove(0, 0, 14);

  for (int i = 0; i < 15; i++)
    VALS[i] = 1;
}
