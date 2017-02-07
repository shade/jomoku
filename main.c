#include <stdio.h>
#include "eval.h"
#include "tests.h"
#include "build.h"
#include "search.h"
#include "board.h"

// Just something quick for the output
void output (char* input, int inp)
{
  printf(input, inp);
  fflush(stdout);
}

// Main function for something
void main ()
{
  // Evaluate main lookup tables
  printf("COMMENT: BUILDING ALL THE LOOKUP TABLES\n");
  fflush(stdout);
  build_lookup_tables();

  // Do the test suites
  printf("COMMENT: TESTING EVERYTHING\n");
  fflush(stdout);
  test_all();

  // Start the whole thing
  // 
  byte moves[100];
  byte counter = 0;
  while (1)
  {
    struct Board brd;
    clear_brd(&brd);

    byte input = 0;
    scanf("u", input);
    moves[counter] = input;
    moves[99] = ++counter;
    next(&brd,3,moves);
  }
}