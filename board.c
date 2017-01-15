#include "jomoku.h"
#include "board.h"
#include "linkedlist.h"

/**
 * Places the piece by bit shifting based on the specifications of the array
 * @param brd   -the board struct
 * @param place -the location on the board [0-225)
 * @param you   -boolean value, whether this is you or not
 */
void place_piece (struct Board brd, byte place, byte you) 
{
  if (you) {
    brd.horiz_y[HORIZ[place][0]] |= (1 << HORIZ[place][1]);
    brd.verti_y[VERTI[place][0]] |= (1 << VERTI[place][1]);
    if (DIAGL[place][0] != NO) {brd.diagl_y[DIAGL[place][0]] |= (1 << DIAGL[place][1]);}
    if (DIAGR[place][0] != NO) {brd.diagr_y[DIAGR[place][0]] |= (1 << DIAGR[place][1]);}
  } else {
    brd.horiz_o[HORIZ[place][0]] |= (1 << HORIZ[place][1]);
    brd.verti_o[VERTI[place][0]] |= (1 << VERTI[place][1]);
    if (DIAGL[place][0] != NO) {brd.diagl_o[DIAGL[place][0]] |= (1 << DIAGL[place][1]);}
    if (DIAGR[place][0] != NO) {brd.diagr_o[DIAGR[place][0]] |= (1 << DIAGR[place][1]);}
  }
}

/**
 * Removes the piece by XORing after a bit shift based on the array
 * @param brd   -the board struct
 * @param place -the location on the board [0-225)
 * @param you   -boolean value whether this is you or not
 */
void remove_piece (struct Board brd, byte place, byte you) 
{
  if (you) {
    brd.horiz_y[HORIZ[place][0]] ^= (1 << HORIZ[place][1]);
    brd.verti_y[VERTI[place][0]] ^= (1 << VERTI[place][1]);
    if (DIAGL[place][0] != NO) {brd.diagl_y[DIAGL[place][0]] ^= (1 << DIAGL[place][1]);}
    if (DIAGR[place][0] != NO) {brd.diagr_y[DIAGR[place][0]] ^= (1 << DIAGR[place][1]);}
  } else {
    brd.horiz_o[HORIZ[place][0]] ^= (1 << HORIZ[place][1]);
    brd.verti_o[VERTI[place][0]] ^= (1 << VERTI[place][1]);
    if (DIAGL[place][0] != NO) {brd.diagl_o[DIAGL[place][0]] ^= (1 << DIAGL[place][1]);}
    if (DIAGR[place][0] != NO) {brd.diagr_o[DIAGR[place][0]] ^= (1 << DIAGR[place][1]);}
  }

}

void get_moves (struct Board *brd) 
{

}

byte won (struct Board *brd) 
{
  return 0;
}














