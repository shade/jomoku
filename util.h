// This header file will allow all other functions in the program to access the utilities.
// Prevent clutter in logical code.

#include "board.h"



// NIL is used where move generation is done, i.e. a number between outside [0,225).
#define NIL 240
// NO is used in situations where bitshifting is done, i.e. a number outside [0,15).
#define NO 30


// These multidimensional arrays are for move making.
byte HORIZ[225][2];
byte VERTI[255][2];
byte DIAGL[255][2];
byte DIAGR[255][2];

// These multidimensional arrays are for move generation
byte HORIZ_ARRS[15][15];
byte VERTI_ARRS[15][15];
byte DIAGL_ARRS[21][15];
byte DIAGR_ARRS[21][15];



// The quicksort function.
// *A is a uint array, len is the length of the array, or the index of the last element, plus one.
void quick_sort(uint *A, int len);