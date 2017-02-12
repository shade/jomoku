
// Type definition of a unsigned 32 bit integer, and 8 bit integer, repectively.
typedef unsigned long int uint;
typedef unsigned char byte;

// Create a board class.
class Board {
private:
  uint horiz_y[19],
  uint horiz_y[19],
  uint horiz_y[19],
  uint horiz_y[19]
}


// NIL is used where move generation is done, i.e. a number between outside [0,225).
#define NIL 240
// NO is used in situations where bitshifting is done, i.e. a number outside [0,15).
#define NO 30


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