#include <windows.h>
#include <stdio.h>
#include "board.h"

#define NIL 240
#define NO 30

#define YOU_WON 10000
#define OPP_WON -10000

#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)

uint minmax (struct Board* brd, int depth, int alpha, int beta, int max)
{
  int won = brd_won(brd);

  if (won) {
    return (won == 1? YOU_WON : OPP_WON);
  }
  if (depth == 0) {
    return brd_eval(brd);
  }

  byte* moves = get_moves(brd);
  int v = 0;

  if (max) {
    v = -20000; 
    for(int move = 0; move < 225; move++){
      byte value = moves[move];

      if (value != NIL) {
        place_piece(brd, move, 1);
        v = MAX(v, minmax(brd, depth - 1, alpha, beta, 0));
        remove_piece(brd, move, 1);

        alpha = MAX(alpha, v);
        if (beta <= alpha) {
          break;
        }
      }
    }
  } else {
    v = 20000;  
    for(int move = 0; move < 225; move++){
      byte value = moves[move];

      if (value != NIL) {
        place_piece(brd, move, 0);
        v = MIN(v, minmax(brd, depth - 1, alpha, beta, 1));
        remove_piece(brd, move, 0);

        beta = MIN(beta, v);
        if (beta <= alpha) {
          break;
        }
      }
    }
  }
  free(moves);

  return v;
}


void next (struct Board* brd)
{
  byte* moves = get_moves(brd);
  printf("%d,%d\n", moves[0],moves[1]);
  for(int move = 2; move < 225; move++){
    byte value = moves[move];
    if (value != NIL) {
      printf("MAKING MOVE %d, VALUE: %d\n", move, value);
      place_piece(brd, move, 1);
      uint val = minmax(brd, 5, OPP_WON, YOU_WON, 0);
      remove_piece(brd, move, 1);
      printf("MOVE %d VALUE %d\n",move,val);
    }
  }

  free(moves);
}

