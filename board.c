#include "util.h"
#include "board.h"

/**
 * Places the piece by bit shifting based on the specifications of the array
 * @param brd   -the board struct
 * @param place -the location on the board [0-225)
 * @param you   -boolean value, whether this is you or not
 */
void place_piece (struct Board *brd, byte place, byte you) 
{
  if (you) {
    brd->multi[place] = 1;
    brd->horiz_y[HORIZ[place][0]] ^= (1 << HORIZ[place][1]);
    brd->verti_y[VERTI[place][0]] ^= (1 << VERTI[place][1]);
    if (DIAGL[place][0] != NO) {brd->diagl_y[DIAGL[place][0]] ^= (1 << DIAGL[place][1]);}
    if (DIAGR[place][0] != NO) {brd->diagr_y[DIAGR[place][0]] ^= (1 << DIAGR[place][1]);}
  } else {
    brd->multi[place] = 2;
    brd->horiz_o[HORIZ[place][0]] ^= (1 << HORIZ[place][1]);
    brd->verti_o[VERTI[place][0]] ^= (1 << VERTI[place][1]);
    if (DIAGL[place][0] != NO) {brd->diagl_o[DIAGL[place][0]] ^= (1 << DIAGL[place][1]);}
    if (DIAGR[place][0] != NO) {brd->diagr_o[DIAGR[place][0]] ^= (1 << DIAGR[place][1]);}
  }
}

/**
 * Removes the piece by XORing after a bit shift based on the array
 * @param brd   -the board struct
 * @param place -the location on the board [0-225)
 * @param you   -boolean value whether this is you or not
 */
void remove_piece (struct Board *brd, byte place, byte you) 
{
  brd->multi[place] = 0;
  if (you) {
    brd->horiz_y[HORIZ[place][0]] ^= (1 << HORIZ[place][1]);
    brd->verti_y[VERTI[place][0]] ^= (1 << VERTI[place][1]);
    if (DIAGL[place][0] != NO) {brd->diagl_y[DIAGL[place][0]] ^= (1 << DIAGL[place][1]);}
    if (DIAGR[place][0] != NO) {brd->diagr_y[DIAGR[place][0]] ^= (1 << DIAGR[place][1]);}
  } else {
    brd->horiz_o[HORIZ[place][0]] ^= (1 << HORIZ[place][1]);
    brd->verti_o[VERTI[place][0]] ^= (1 << VERTI[place][1]);
    if (DIAGL[place][0] != NO) {brd->diagl_o[DIAGL[place][0]] ^= (1 << DIAGL[place][1]);}
    if (DIAGR[place][0] != NO) {brd->diagr_o[DIAGR[place][0]] ^= (1 << DIAGR[place][1]);}
  }
}

/**
 * Clears the board by setting all the values in all the arrays to 0.
 * @param brd -the board struct
 */
void clear_brd (struct Board *brd)
{

  for (int i = 0;i < 15; i++) {
    brd->horiz_y[i] = 0;
    brd->horiz_o[i] = 0;
    brd->verti_y[i] = 0;
    brd->verti_o[i] = 0;
  }
  for (int i = 0;i < 21; i++) {
    brd->diagr_y[i] = 0;
    brd->diagr_o[i] = 0;
    brd->diagl_y[i] = 0;
    brd->diagl_o[i] = 0;
  }
  for (int i = 0;i < 225; i++) {
    brd->multi[i] = 0;
  }
  
  return;
}














