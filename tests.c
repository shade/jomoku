#include <stdio.h>
#include <assert.h>
#include <windows.h>
#include <stdlib.h>

#include "eval.h"
#include "tests.h"

void test_all ()
{
  test_won();
}

void test_won ()
{
  // Various shifts.
  int shift[100] = {};
  // Go through array add shifts.
  for (int i = 0; i < 100; i++) 
    shift[i] = (rand() % 10);


  // Set up variables for iteration.
  int i = 100;
  double time_sum = 0;

  // loop through the shifts, test, and bench them.
  while (i--)
  {
    // 31 is 0b11111.
    int val = (31 << shift[i]);
    // 15 is 0b1111.
    int thing = (15 << shift[i]);

    // Make sure this is a won.
    assert(WON[val] != 0);
    // Make sure this is not a won.
    assert(WON[thing] == 0);

    // Construct the board
    struct Board brd;
    clear_brd(&brd);

    // Bench brd won thing.
    LARGE_INTEGER StartingTime, EndingTime, ElapsedMicroseconds;
    LARGE_INTEGER Frequency;

    QueryPerformanceFrequency(&Frequency); 
    QueryPerformanceCounter(&StartingTime);

    byte k = brd_won(&brd);

    QueryPerformanceCounter(&EndingTime);
    ElapsedMicroseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;

    ElapsedMicroseconds.QuadPart *= 1000000;
    ElapsedMicroseconds.QuadPart /= Frequency.QuadPart;

    time_sum += (double)(ElapsedMicroseconds.QuadPart);
  }
  time_sum /= 100;

  printf("TEST WON, AVG TIME: %d\n", time_sum);
}