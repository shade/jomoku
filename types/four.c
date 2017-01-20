#include "../jomoku.h"

//Types:
// Four line
// Four Split 2:
// Four Split 3.


void match_4_open (byte state, byte m[], int shift)
{
  switch (state)
  {
    case B8(00111): m[s + 3] = FOUR; m[s + 4] = FOUR_13; break;
    case B8(01011): m[s + 2] = FOUR; m[s + 4] = FOUR_22; break;
    case B8(01101): m[s + 1] = FOUR; m[s + 4] = FOUR_13; break;
    case B8(01110): m[s + 0] = FOUR; m[s + 4] = FOUR; break;
    case B8(10011): m[s + 2] = FOUR_13; m[s + 3] = FOUR_22; break;
    case B8(10101): m[s + 1] = FOUR_13; m[s + 3] = FOUR_13; break;
    case B8(10110): m[s + 0] = FIVE; m[s + 3] = FOUR; break;
    case B8(11001): m[s + 1] = FOUR_13; m[s + 2] = FOUR_13; break;
    case B8(11010): m[s + 0] = FOUR_22; m[s + 2] = FOUR; break;
    case B8(11100): m[s + 0] = FOUR_13; m[s + 1] = FOUR; break;
  }
}

void match_4_right (byte state, byte m[], int shift)
{
  switch (state)
  {
    case B8(00111): m[s + 3] = FOUR; m[s + 4] = FOUR_13; break;
    case B8(01011): m[s + 2] = FOUR; m[s + 4] = FOUR_22; break;
    case B8(01101): m[s + 1] = FOUR; m[s + 4] = FOUR_13; break;
    case B8(01110): m[s + 0] = FOUR; m[s + 4] = FOUR; break;
    case B8(10011): m[s + 2] = FOUR_13; m[s + 3] = FOUR_22; break;
    case B8(10101): m[s + 1] = FOUR_13; m[s + 3] = FOUR_13; break;
    case B8(10110): m[s + 0] = FIVE; m[s + 3] = FOUR; break;
    case B8(11001): m[s + 1] = FOUR_13; m[s + 2] = FOUR_13; break;
    case B8(11010): m[s + 0] = FOUR_22; m[s + 2] = FOUR; break;
    case B8(11100): m[s + 0] = FOUR_13; m[s + 1] = FOUR; break;
  }
}

void match_4_left (byte state, byte m[], int shift)
{
  switch (state)
  {
    case B8(00111): m[s + 3] = FOUR; m[s + 4] = FOUR_13; break;
    case B8(01011): m[s + 2] = FOUR; m[s + 4] = FOUR_22; break;
    case B8(01101): m[s + 1] = FOUR; m[s + 4] = FOUR_13; break;
    case B8(01110): m[s + 0] = FOUR; m[s + 4] = FOUR; break;
    case B8(10011): m[s + 2] = FOUR_13; m[s + 3] = FOUR_22; break;
    case B8(10101): m[s + 1] = FOUR_13; m[s + 3] = FOUR_13; break;
    case B8(10110): m[s + 0] = FIVE; m[s + 3] = FOUR; break;
    case B8(11001): m[s + 1] = FOUR_13; m[s + 2] = FOUR_13; break;
    case B8(11010): m[s + 0] = FOUR_22; m[s + 2] = FOUR; break;
    case B8(11100): m[s + 0] = FOUR_13; m[s + 1] = FOUR; break;
  }
}
