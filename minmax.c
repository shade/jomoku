#include <windows.h>
#include "board.h"

#define YOU_WON 10000
#define OPP_WON -10000

#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)

void next (struct Board* brd)
{

}


uint minmax (struct Board* brd, int depth, int alpha, int beta, int max)
{
  int won = won(brd);

  if (won) {
    return (won == 1? YOU_WON : OPP_WON);
  }
  if (depth == 0) {
    return eval(brd);
  }

  int moves = *gen_moves(brd);
  int v = 0;

  if max {
    v = -20000;
    LinkedList move;
    while (move = pop_moves(moves) != NULL) {
      place_piece(brd, moves[i], 1);
      v = MAX(v, minmax(brd, depth - 1, alpha, beta, 1));
      remove_piece(brd, moves[i], 1);

      alpha = MAX(alpha, v);
      if (beta <= alpha) {
        break;
      }
    }
  } else {
    v = 20000;
    LinkedList move;
    while (move = pop_moves(moves) != NULL) {
      place_piece(brd, moves[i], 0);
      v = MIN(v, minmax(brd, depth - 1, alpha, beta, 0));
      remove_piece(brd, moves[i], 0);

      beta = MIN(beta, v);
      if beta <= alpha {
        break;
      }
    }
  }
  free(moves);

  return v;
}













