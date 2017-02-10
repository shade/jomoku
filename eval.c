// This component is used to do evaluations on the board including move generation.
// To be used with the minmax and test suite.
#include <stdio.h>
#include "eval.h"
#include "util.h"


/**
 * Returns the current value of the provided
 * @param  brd - the board struct
 * @param  moves - an array to be filled with moves
 * @return     the number of moves that can be made in this board
 */
byte gen_moves(struct Board* brd, uint moves[225])
{
  // The counter to iterate through the rows.
  int i = 0;

  // The code in the 2 while loops has been tested, so it works, too lazy to comment on it.a
  
  while(i < 15)
  {

    int val_h = BT[brd->horiz_y[i]] + BT2[brd->horiz_o[i]];
    int val_v = BT[brd->verti_y[i]] + BT2[brd->verti_o[i]];
    int val_r = BT[brd->diagr_y[i]] + BT2[brd->diagr_o[i]];
    int val_l = BT[brd->diagl_y[i]] + BT2[brd->diagl_o[i]];

    byte h_i = MOVES[val_h][14];
    byte v_i = MOVES[val_v][14];
    byte r_i = MOVES[val_r][14];
    byte l_i = MOVES[val_l][14];

    byte* h_arr; h_arr = MOVES[val_h];
    byte* v_arr; v_arr = MOVES[val_v];
    byte* l_arr; l_arr = MOVES[val_l];
    byte* r_arr; r_arr = MOVES[val_r];
    while(h_i | v_i | r_i | l_i)
    {
      if (h_i)
      {
        h_i--;
        byte h = *(h_arr + h_i);
        byte val = h >> 4;
        byte loc = H[i][14 - (h & 15)]; // 15 is the same as 0b00001111
        moves[loc] += VALS[val];
      }

      if (v_i)
      {
        v_i--;
        byte v = *(v_arr + v_i);
        byte val = v >> 4;
        byte loc = V[i][14 - (v & 15)]; // 15 is the same as 0b00001111
        moves[loc] += VALS[val];
      }

      if (l_i)
      {
        l_i--;
        byte l = *(l_arr + l_i);
        byte val = l >> 4;
        byte loc = L[i][l & 15]; // 15 is the same as 0b00001111.
        ((loc != NIL) && (moves[loc] += VALS[val])); // Bounds checking on diagonals.
      }

      if (r_i)
      {
        r_i--;
        byte r = *(r_arr + r_i);
        byte val = r >> 4;
        byte loc = R[i][r & 15]; // 15 is the same as 0b00001111.
        ((loc != NIL) && (moves[loc] += VALS[val])); // Bounds checking on diagonals.
      }
    }

    i++;
  }

  while (i < 22)
  {
    int val_r = BT[brd->diagr_y[i]] + BT2[brd->diagr_o[i]];
    int val_l = BT[brd->diagl_y[i]] + BT2[brd->diagl_o[i]];

    byte r_i = MOVES[val_r][14];
    byte l_i = MOVES[val_l][14];

    byte* l_arr; l_arr = MOVES[val_l];
    byte* r_arr; r_arr = MOVES[val_r];

    while(r_i | l_i)
    {
      if (l_i)
      {
        l_i--;
        byte l = *(l_arr + l_i);
        byte val = l >> 4;
        byte loc = L[i][l & 15]; // 15 is the same as 0b00001111.
        ((loc != NIL) && (moves[loc] += VALS[val])); // Bounds checking on diagonals.
      }

      if (r_i)
      {
        r_i--;
        byte r = *(r_arr + r_i);
        byte val = r >> 4;
        byte loc = R[i][r & 15]; // 15 is the same as 0b00001111.
        ((loc != NIL) && (moves[loc] += VALS[val])); // Bounds checking on diagonals.
      }
    }

    i++;
  }

  // Initialize the counter.
  uint c = 0;

  // Shift the moves to the left of the array and encode the position into the thing
  for (int i = 0; i < 225; i++)
  {
    if (moves[i] != 0)
    {
      moves[c++] = ((moves[i] << 8) | i);
    }
  }

  // Sort.
  quick_sort(moves, c);

  return c;
}














/**
 * Returns the current value of the provided
 * @param  brd - the board struct
 * @return     the current value of the board +/-
 */
int brd_eval(struct Board* brd)
{
  // Sum collector.
  int sum = 0;
  // Row iterator counter.
  int i = 0;

  // We only want to go from [0, 15) as that is the max rows and cols.
  while (i < 15)
  {
    // Do a lookup of the current row, in each orientation in the EVAL table.
    int val_h = EVAL[BT[brd->horiz_y[i]] + BT2[brd->horiz_o[i]]];
    int val_v = EVAL[BT[brd->verti_y[i]] + BT2[brd->verti_o[i]]];
    int val_r = EVAL[BT[brd->diagr_y[i]] + BT2[brd->diagr_o[i]]];
    int val_l = EVAL[BT[brd->diagl_y[i]] + BT2[brd->diagl_o[i]]];

    // Sum the values of all the rows together.
    sum += (val_l + val_r + val_r + val_l);

    // Go to the next row.
    i++;
  }

  // The diagonals go from [0, 22) so
  while (i < 22)
  {
    // Do a lookup of the current diagonals in the EVAL table.
    int val_r = EVAL[BT[brd->diagr_y[i]] + BT2[brd->diagr_o[i]]];
    int val_l = EVAL[BT[brd->diagl_y[i]] + BT2[brd->diagl_o[i]]];

    // Sum the row values together
    sum += (val_l + val_r);

    // Next row please.
    i++;
  }

  return sum;
}














/**
 * Checks to see if the board struct has a 5 in a row
 * @param  brd - the board struct
 * @return     {0, YOU_WON, OPP_WON}
 */
int brd_won(struct Board* brd)
{
  // Row iterator counter.
  int i = 0;

  // We're going to go from won
  while (i < 15)
  {
    // Check to see if you is a won row.
    
    if (WON[brd->horiz_y[i]]) return YOU_WON;
    if (WON[brd->verti_y[i]]) return YOU_WON;
    if (WON[brd->diagr_y[i]]) return YOU_WON;
    if (WON[brd->diagl_y[i]]) return YOU_WON;

    if (WON[brd->horiz_o[i]]) return OPP_WON;
    if (WON[brd->verti_o[i]]) return OPP_WON;
    if (WON[brd->diagr_o[i]]) return OPP_WON;
    if (WON[brd->diagl_o[i]]) return OPP_WON;

    // Go to the next row.
    i++;
  }

  // The diagonals go from [0, 22) so
  while (i < 22)
  {
    // Do a lookup of the current diagonals in the opp thing
    if (WON[brd->diagr_y[i]]) return YOU_WON;
    if (WON[brd->diagl_y[i]]) return YOU_WON;

    if (WON[brd->diagr_o[i]]) return OPP_WON;
    if (WON[brd->diagl_o[i]]) return OPP_WON;

    // Next row please.
    i++;
  }

  return 0;
}