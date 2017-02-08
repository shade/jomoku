#include <stdio.h>
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

/**
 * Takes the current board state and outputs all the next values. The byte of moves contains all the moves.
 */
int next(struct Board* brd, int depth, byte movs[100])
{
  printf("HERE\n");
  fflush(stdout);

  int i = movs[99];
  byte you = 1;
  while (i > 0) {
    i--;
    if (you) {
      place_piece(brd, movs[i], 1);
    } else {
      place_piece(brd, movs[i], 0);
    }
    you = !you;
    printf("%d,", movs[i]);
  }
  fflush(stdout);
  uint moves[225] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  byte num = gen_moves(brd, moves);
  printf("READY %d\n", num);
    fflush(stdout);

  for(int i = 0; i < num; i++)
  {
    byte move = (byte)moves[i];
    printf("DOING: %d\n", move);
    fflush(stdout);
    place_piece(brd, move, 1);
    int val = minmax(brd, depth, 0);
    remove_piece(brd, move, 1);
    printf("SQ: [%d,%d]\n", move, val);
    fflush(stdout);
  }

  return 0;
}