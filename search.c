#include <windows.h>
#include <time.h>
#include "board.h"
#include "jomoku.h"

DWORD WINAPI timer (void* data)
{
  time_t start = time(NULL);
  // Loop foreva
  while (1) 
  {
    // If the time is greater than 5, end it.
    if (difftime(start, time(NULL)) > 5)
    {
      TerminateThread((HANDLE)data, 0);
      return 0;
    }
    Sleep(250);
  }

  return 0;
}



 
int search(struct Board *brd, byte max, int depth, int alpha, int beta, LINE * pline) {
 
    LINE line;

    if (depth == 0) {
        pline->cmove = 0;
        return brd_eval(brd);
    }

    uint moves[225] = {
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    };

    int move_count = gen_moves(brd, moves);
    while (--move_count) {
        byte move = (byte)(moves[move_count] & 255);

        place_piece(brd,move,max);
        int val = -search(brd, !max, depth - 1, -beta, -alpha, &line);
        remove_piece(brd,move,max);
 
        if (val >= beta) return beta;
        if (val > alpha) {
            alpha = val;
            pline->argmove[0] = move;
            memcpy(pline->argmove + 1, line.argmove, line.cmove);
            pline->cmove = line.cmove + 1;
        }
    }
    return alpha;
}