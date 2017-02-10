// This is to build all the lookup tables
#include <math.h>

#include "eval.h"
#include "build.h"

void try_open (int shift, uint state, int m[15]);
void try_right (int shift, uint state, int m[15]);
void try_left (int shift, uint state, int m[15]);

void build_lookup_tables ()
{
  build_won();
  build_ternary();
  build_value();
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
    for(int n = 0; n < 15; n++)
    {
      if ((i >> n) & 1)
      {
        val += pow(3,n);
      }  
    }

    BT[i] = val;
    BT2[i] = (2 * val);
  }
}


void build_value()
{
  for (int i = 0; i < 256; i++) {
    VAL_OPEN[i] = 0;
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
  VAL_OPEN[B8(00011111)] = FIVER;
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

void move_recognize (int you, int opp)
{
  int val = BT[you] + BT2[opp];

  // Intitialize variables for iteration.
  int m[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

  // Iterate and mask to determine what to do with endpoints.
  for (int i = 0; i < 15; i++)
  {
    int you_state = (you >> i) & 127; // 127 is 7 bits, on.
    int opp_state = (opp >> i) & 127;

    switch (opp_state)
    {
      case 0:
        try_open(i, you_state >> 1, m);
        break;
      case 1:
        try_right(i, you_state >> 1, m);
        break;
      case 64:
        try_left(i, you_state >> 1, m);
        break;
    }

    switch (you_state)
    {
      case 0:
        try_open(i, opp_state >> 1, m);
        break;
      case 1:
        try_right(i, opp_state >> 1, m);
        break;
      case 64:
        try_left(i, opp_state >> 1, m);
        break;
    }
  }

  // Shift everything to the left, OR the location to the thing.
  int c = 0;
  for (int i = 0; i < 15; i++)
  {
    if (m[i])
    {
      MOVES[val][c++] = (m[i] << 8) | i;
    }
  }

  // The last one is the counter.
  MOVES[val][14] = c;
}


void try_open (int shift, uint state, int m[15])
{
  for (int i = 0; i < 5; i++)
  {
    uint new_state = (state | (1 << i));
    if (!(new_state&state)) m[shift + i] = VAL_OPEN[new_state];
  }
}

void try_right (int shift, uint state, int m[15])
{
  for (int i = 0; i < 5; i++)
  {
    uint new_state = (state | (1 << i));
    if (!(new_state&state)) m[shift + i] = VAL_OPEN[new_state];
  }
}

void try_left (int shift, uint state, int m[15])
{
  for (int i = 0; i < 5; i++)
  {
    uint new_state = (state | (1 << i));
    if (!(new_state&state)) m[shift + i] = VAL_OPEN[new_state];
  }
}