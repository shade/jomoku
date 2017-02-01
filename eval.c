// This component is used to do evaluations on the board including move generation.
// To be used with the minmax and test suite.

#include "eval.h"
#include "util.h"





/**
 * Returns the current value of the provided
 * @param  brd - the board struct
 * @param  moves - an array to be filled with moves
 * @return     the number of moves that can be made in this board
 */
int gen_moves(struct Board* brd, uint moves[225])
{
  // The counter to iterate through the rows.
  int i = 0;

  // The code in the 2 while loops has been tested, so it works, too lazy to comment on it.a
  while(i < 15)
  {

    uint val_h = BT[brd->horiz_y[i]] + BT2[brd->horiz_o[i]];
    uint val_v = BT[brd->verti_y[i]] + BT2[brd->verti_o[i]];
    uint val_r = BT[brd->diagr_y[i]] + BT2[brd->diagr_o[i]];
    uint val_l = BT[brd->diagl_y[i]] + BT2[brd->diagl_o[i]];

    byte h_i = M[val_h][14];
    byte v_i = M[val_v][14];
    byte r_i = M[val_r][14];
    byte l_i = M[val_l][14];

    byte* h_arr; h_arr = M[val_h];
    byte* v_arr; v_arr = M[val_v];
    byte* l_arr; l_arr = M[val_l];
    byte* r_arr; r_arr = M[val_r];

    while(h_i | v_i | r_i | l_i)
    {
      if (h_i)
      {
        h_i--;
        moves[H[i][14 - ((*(h_arr + h_i)) & 15)]] += VALS[h >> 4];
      }

      if (v_i)
      {
        v_i--;
        moves[V[i][14 - ((*(v_arr + v_i)) & 15)]] += VALS[v >> 4];
      }

      if (l_i)
      {
        l_i--;
        byte loc = L[i][(*(l_arr + l_i)) & 15];
        ((loc != NIL) && (moves[loc] += VALS[l >> 4])); // Bounds checking on diagonals.
      }

      if (r_i)
      {
        r_i--;
        byte loc = R[i][(*(r_arr + r_i)) & 15];
        ((loc != NIL) && (moves[loc] += VALS[r >> 4])); // Bounds checking on diagonals.
      }
    }

    i++;
  }

  while (i < 22)
  {
    int val_r = BT[brd->diagr_y[i]] + BT2[brd->diagr_o[i]];
    int val_l = BT[brd->diagl_y[i]] + BT2[brd->diagl_o[i]];

    byte r_i = M[val_r][14];
    byte l_i = M[val_l][14];

    byte* l_arr; l_arr = M[val_l];
    byte* r_arr; r_arr = M[val_r];

    while(r_i | l_i)
    {
      if (l_i)
      {
        l_i--;
        byte loc = L[i][(*(l_arr + l_i)) & 15];
        ((loc != NIL) && (moves[loc] += VALS[l >> 4])); // Bounds checking on diagonals.
      }

      if (r_i)
      {
        r_i--;
        byte loc = R[i][(*(r_arr + r_i)) & 15];
        ((loc != NIL) && (moves[loc] += VALS[r >> 4])); // Bounds checking on diagonals.
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
  quicksort(moves, c);

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

  // We're going to go from won  while (i < 15)
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