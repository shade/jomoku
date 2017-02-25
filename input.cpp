#include <iostream>
#include <string>
#include "board.h"

using namespace std;

void startGame ()
{

  while (1) {
    cout << "COMMENT: STARTING.." << endl;
    string board;

    cin >> board;
    cout << "COMMENT: GOT ONE.." << endl;

    Board* brd = new Board(board);
    uint moves[225] = {NIL};
    byte c = brd->moves(moves);

    cout << "COMMENT: THERE ARE " << (int)c << " MOVES" << endl;
    // Go through all the positions, and extract moves.
    for(int i = 0; i < c; i++){

      // If the value of the move is not zero, output it.
      if (moves[i]) {
        int val = moves[i] >> 8;
        int pos = moves[i] & 0b11111111;

        cout << "VALUE: [" << pos << "," << val << "]" << endl; 
      }
    }

    cout << "COMMENT: FINISHED ONE MOVE" << endl;
  }
}