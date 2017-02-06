#include <string.h>
#include "eval.h"
#include "search.h"




int minmax(struct Board* brd, int depth, byte max)
{
  int won = brd_won(brd);
  if (won != 0) 
    return won;
  if (depth == 0)
    return brd_eval(brd);

  uint moves[225] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  byte num_moves = gen_moves(brd, moves);
  int best = (max? OPP_WON: YOU_WON);

  for(int i = 0; i < num_moves; i++) {
    byte move = (byte)moves[i];

    place_piece(brd, move, max);
    int val = minmax(brd, depth - 1, !max);
    remove_piece(brd, move, max);

    if (max) {
      if (val > best) {
        best = val;
      }
    } else {
      if (val < best) {
        best = val;
      }
    }
  }

  return best;
}