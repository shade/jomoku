// This is to build all the lookup tables
#include "eval.h"

void build_lookup_tables ()
{
  build_won();
  build_ternary();
  build_moves(0,0,14);

  // Set the first MOVES to 0.
  MOVES[0][14] = 0;
}

/**
 * Builds the WON table for won evaluation.
 */
void build_won ()
{
  // For the numbers 0 to 1 << 16
  for (int i = 0; i < 32768; i++)
  {
    // Shift the line to 0
    for (int shift = 0; shift < 15; shift++)
    {
      if (((i >> shift) & 31) == 31)
      {
        WON[i] = 1;
        break;
      }
    }
  }
}

/**
 * Build the binary to ternary evaluation.
 */
void build_ternary ()
{
  // For the numbers 0 to 1 << 16
  for (int i = 0; i < 32768; i++)
  {
    int val = 0;
    // Go through the line from 0 to 15
    for (int shift = 0; shift < 15; shift++)
    {
      val += 3
    }
  }
}

/**
 * Build the MOVE table.
 */
void build_moves (int you, int opp, int depth)
{
  if (depth < 0)
  {
    move_recognize(you, opp);
    return;
  }

  build_moves(you | (1 << depth), opp, depth - 1);
  build_moves(you, opp | (1 << depth), depth - 1);
  build_moves(you, opp, depth - 1);
}
