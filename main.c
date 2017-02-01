#include <stdio.h>

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
  build_lookup_tables();
  // Do the test suites
  test_all();

  // Start the whole thing
  while (1)
  {

  }
}