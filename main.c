#include <stdio.h>
#include "eval.h"
#include "tests.h"
#include "build.h"

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
  while (1)
  {
  }
}