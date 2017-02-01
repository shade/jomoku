/* We're going to use this header in all files. */


// Declare the types used in the entire project.
typedef unsigned char byte;
typedef unsigned int uint;

// Declare the arrays for moves.
byte MOVES[14348907][15];

// Declare the array for line evaluations.
uint EVAL[14348907];



// Declare the board struct.
// All arrays with the suffix 'y' contain bit encoded lines of your pieces.
// All arrays with the suffix 'o' contain bit encoded lines of the opp pieces.
struct Board {
  byte multi[225];
  uint horiz_y[15];
  uint verti_y[15];
  
  uint diagr_y[21];
  uint diagl_y[21];

  uint horiz_o[15];
  uint verti_o[15];

  uint diagr_o[21];
  uint diagl_o[21];
};



// These are the headers for the private functions on the board struct.
// Shifts the appropriate thing into place.

// used to place the piece on the board
void place_piece (struct Board *brd, byte place, byte you);
// used to remove the piece on the board
void remove_piece (struct Board *brd, byte place, byte you);
