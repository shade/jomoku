
// Type definition of a unsigned 32 bit integer, and 8 bit integer, repectively.
typedef unsigned long int uint;
typedef unsigned long long u64;
typedef unsigned char byte;

// Create a board class.
class Board {
private:
  u64 multi[8];
  uint horiz_y[15];
  uint verti_y[15];
  uint horiz_o[15];
  uint verti_o[15];

  uint diagr_y[21];
  uint diagl_y[21];
  uint diagr_o[21];
  uint diagl_o[21];
public:
  // Constructor accepts a string board
  void Board();
  // Signatures for methods to add and remove pieces
  void placePiece(byte place, bool white);
  void removePiece(byte place, bool white);

  // Signature of the move generating thing. 
  // The moves array provided will hold the moves, and this returns the number of moves.
  byte moves(uint moves[255]);

  // Function to clear the board.
  void clear();
  
  // Signatures for the move evaluation 
  int evaluate();
  byte won();
};


// NIL is used where move generation is done, i.e. a number between outside [0,225).
#define NIL 240
// NO is used in situations where bitshifting is done, i.e. a number outside [0,15).
#define NO 30

// The values of you and opp winning.
#define YOU_WON 100000
#define OPP_WON -YOU_WON

// Definitions for renaming arrays
#define H HORIZ
#define V VERTI
#define L DIAGL
#define R DIAGR

// Declare the arrays for moves.
static byte MOVES[14348907][15];
// Declare the array for line evaluations.
static int EVAL[14348907];
static int WON[65540];
// Declare the VAL array, these are the weights, this should be mutable.
static int VALS[15];




// The arrays for the stuff.
static byte BT[65536];
static byte BT2[65536];

// Header for the quick sorting function
void quickSort(uint *A, int len);


// Declare all the arrays
extern byte HORIZ[225][2];
extern byte VERTI[255][2];
extern byte DIAGL[255][2];
extern byte DIAGR[255][2];

extern byte HORIZ_ARRS[15][15];
extern byte VERTI_ARRS[15][15];
extern byte DIAGL_ARRS[21][15];
extern byte DIAGR_ARRS[21][15];