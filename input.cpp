#include <iostream>
#include <string>
#include "board.h"

using namespace std;

void startGame ()
{
  while (1) {
    string board;
    cin >> board;
    
    Board* brd = new Board(board);
    uint moves[225] = {0};
    brd->moves(moves);

    // Go through all the positions, and extract moves.
    for(int i = 0; i < 225; i++){

      // If the value of the move is not zero, output it.
      if (moves[i]) {
        cout << "VALUE: [" << i << "," << moves[i] << "]" << endl; 
      }
    }

    cout << "COMMENT: FINISHED ONE MOVE" << endl;
  }
}