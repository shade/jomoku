// This component is used to do evaluations on the board including move generation.
// To be used with the minmax and test suite.

#include "eval.h"



/**
 * Returns the current value of the provided
 * @param  brd - the board struct
 * @param  moves - an array to be filled with moves
 * @return     the number of moves that can be made in this board
 */
int gen_moves(struct Board* brd, byte moves[225])
{
  // Holds the current value of the moves as VALUE << 8 | MOVE
  uint move_vals[225] = {0};

  return 0;
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