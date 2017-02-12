
// Type definition of a unsigned 32 bit integer, and 8 bit integer, repectively.
typedef unsigned long int uint;
typedef unsigned long long u64;
typedef unsigned char byte;

// Create a board class.
class Board {
private:
  u64 multi[10];
  uint horiz_y[15];
  uint verti_y[15];
  uint diagr_y[21];
  uint diagl_y[21];
  uint horiz_o[15];
  uint verti_o[15];
  uint diagr_o[21];
  uint diagl_o[21];
public:
  // Signatures for methods to add and remove pieces
  int place_piece(byte place, bool white);
  int remove_piece(byte place, bool white);

  // Signature of the move generating thing. 
  // The moves array provided will hold the moves, and this returns the number of moves.
  byte moves(uint moves[255]);

  // Signatures for the move evaluation 
  int evaluate();
  byte won();
}


// NIL is used where move generation is done, i.e. a number between outside [0,225).
#define NIL 240
// NO is used in situations where bitshifting is done, i.e. a number outside [0,15).
#define NO 30

// The values of you and opp winning.
#define YOU_WON 100000;
#define OPP_WON -YOU_WON;


// These multidimensional arrays are for move making.
extern const byte HORIZ[225][2];
extern const byte VERTI[255][2];
extern const byte DIAGL[255][2];
extern const byte DIAGR[255][2];

// These multidimensional arrays are for move generation
extern const byte HORIZ_ARRS[15][15];
extern const byte VERTI_ARRS[15][15];
extern const byte DIAGL_ARRS[21][15];
extern const byte DIAGR_ARRS[21][15];

// Header for the quick sorting function
void quick_sort(uint *A, int len);