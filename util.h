// This header file will allow all other functions in the program to access the utilities.
// Prevent clutter in logical code.

// We can't re-include board.h here  
#ifndef byte
  typedef unsigned char byte;
  typedef unsigned int uint;
#endif

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



// The quicksort function.
// *A is a uint array, len is the length of the array, or the index of the last element, plus one.
void quick_sort(uint *A, int len);