#include <windows.h>
#include <time.h>



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
      return;
    }
    Sleep(250);
  }
}
















int deep_search (Board *brd, int depth, int alpha, int beta, byte max)
{
  int won = board_won(brd);
  if (won != 0)
  {
    return won;
  }

  if (depth == 0)
  {
    return board_eval(brd);    
  }

  byte nodes[225];
  board_getmoves(brd, nodes);

  byte num = 2 * nodes[225];
  byte bSearch = 1;

  for (int i = 0; i < num; i += 2)
  {

    byte move = nodes[num];
    place_piece(brd, moves, max);

    if (bSearch)
      score = -deep_search(brd, depth - 1, -alpha, -beta, ~max);
    else
    {
      score = -deep_search(brd, depth - 1, -alpha - 1, -alpha, ~max);
      if (score > alpha)
        score = -deep_search(brd, depth -1, -beta, -alpha, ~max);
    }

    remove_piece(brd, moves, max);

    if (score >= beta)
      return beta;

    if (score > alpha)
    {
      alpha = score;
      bSearch = false;
    }
  }

  return alpha;
}




















