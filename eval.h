// This header specifies methods for the minmax
include "board.h"

// Declare the arrays for moves.
byte MOVES[14348907][15];

// Declare the array for line evaluations.
int EVAL[14348907];

#define YOU_WON 10000
#define OPP_WON -YOU_WON


/** Method Declarations */

// Returns an integer containing the number of possible moves.
// Fills the moves array with moves to make in the following form.
byte gen_moves(struct Board* brd, byte moves[225]);
// Returns the current score of the board.
// This value is dependent of the weights of each position.
int brd_eval(struct Board* brd);
// Returns either YOU_WON, YOU_LOST or 0.
int brd_won(struct Board* brd);
