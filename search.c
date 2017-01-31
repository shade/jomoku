#include <windows.h>
#include <time.h>
#include "board.h"
#include "jomoku.h"
#include <stdio.h>

DWORD WINAPI timer (void* data)
{
  int c = 0;
  // Loop foreva
  while (1) 
  {
    // If the time is greater than 5, end it.
    if (c++ > 10)
    {
      TerminateThread((HANDLE)search_thread, 0);
      return 0;
    }
    Sleep(500);
  }

  return 0;
}



 
int search(struct Board *brd, byte max, int depth, int alpha, int beta, LINE * pline)
{
  //printf("NODE\n");
    LINE line;
    int won = brd_won(brd);

    if (won != 0)
    {
      pline->cmove = 0;
      return won;
    }

    if (depth == 0)
    {
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
    while (--move_count)
    {
        byte move = (byte)(moves[move_count] & 255);

        place_piece(brd, move, max);
        int val = -search(brd, !max, depth - 1, -beta, -alpha, &line);
        remove_piece(brd, move, max);
 
        if (val >= beta) return beta;
        if (val > alpha)
        {
            alpha = val;
            pline->argmove[0] = move;
            memcpy(pline->argmove + 1, line.argmove, line.cmove);
            pline->cmove = line.cmove + 1;
        }
    }
    return alpha;
}