#include <string.h>
#include "eval.h"
#include "search.h"



int search(struct Board* brd, byte max, int depth, int alpha, int beta, LINE * pline)
{
    LINE line;

    int won = brd_won(brd);
    
    // If you've won, return it.
    if (won != 0)
    {
      pline->cmove = 0;
      return won;
    }

    // If this is the last move, return the evaluation.
    if (depth == 0)
    {
      pline->cmove = 0;
      return brd_eval(brd);
    }

    // Create a byte array of moves.
    uint moves[225] = {0};
    // Initialize a counter created 
    byte count = gen_moves(brd, moves);
    
    // Iterate through all the moves
    while (count--)
    {
      // This is the current move, the last byte.
      byte move = (byte)(moves[count] & 0xFF);

      // Place piece, recurse, remove piece.
      place_piece(brd, move, max);
      int val = -search(brd, !max, depth - 1, -beta, -alpha, &line);
      remove_piece(brd, move, max);

      // If, the previous one is won, return the beta.
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



int start_minmax()
{

}