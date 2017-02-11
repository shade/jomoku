#include <stdio.h>
#include "eval.h"
#include "tests.h"
#include "build.h"
#include "search.h"
void grab_input ();

// Just something quick for the output
void output (char* input, int inp)
{
  printf(input, inp);
  fflush(stdout);
}

// Main function for something
int main ()
{
  // Evaluate main lookup tables
  printf("COMMENT: BUILDING ALL THE LOOKUP TABLES\n");
  fflush(stdout);
  build_lookup_tables();

  // Do the test suites
  printf("COMMENT: TESTING EVERYTHING\n");
  fflush(stdout);
  test_all();

  grab_input();

  return 0;
}

// Grab an input
void grab_input () {
  struct Board brd;
  clear_brd(&brd);

  while (1)
  {/*
    char word[64];
    scanf("%d", word);
    fflush(stdin);
    next(&brd,3,moves);*/
  }
}