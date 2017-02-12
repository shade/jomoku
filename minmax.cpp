#include "board.h"



int minmax (Board brd, int depth, int alpha, int beta, bool max)
{
  int won = brd.won();

  if (won) {
    return won;
  }

  if (depth <= 0) {
    return brd.evaluate();
  }

  // Generate all the moves in the current board state.
  uint moves[225];
  byte number = brd.moves(moves);

  // This is the variable to hold the best move so far.
  int v = max
  ? OPP_WON 
  : YOU_WON;

  // Go through all the moves.
  for (int i = 0; i < number; i++) {
    byte move = (byte)(moves[i]);

    // Make move, recurse, and remove move.
    brd.place_piece(move);
    int val = minmax(brd, depth - 1, alpha, beta, !max);
    brd.remove_piece(move);
  }

  return v;
}























