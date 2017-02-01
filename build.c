// This is to build all the lookup tables
#include "eval.h"

void build_lookup_tables ()
{
  build_won();
  build_ternary();
  build_moves();
}

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

void build_moves ()
{

}