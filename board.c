#include "jomoku.h"
#include "board.h"



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

void remove_piece (struct Board *brd, byte place, byte you) 
{

}

void get_moves (struct Board *brd) 
{

}

byte won (struct Board *brd) 
{
  return 0;
}


















/*
void remove_horiz_you (struct Board *brd, byte place) 
{
  brd.horiz_y[HORIZ[place][0]] ^= (1 << HORIZ[place][1]);
}
void remove_verti_you (struct Board *brd, byte place) 
{
  brd.verti_y[VERTI[place][0]] ^= (1 << VERTI[place][1]);
}
void remove_diagl_you (struct Board *brd, byte place) 
{
  if DIAGL[place][0] == NO {return;} brd.diagl_y[DIAGL[place][0]] ^= (1 << DIAGL[place][1]);
}
void remove_diagr_you (struct Board *brd, byte place) 
{
  if DIAGR[place][0] == NO {return;} brd.diagr_y[DIAGR[place][0]] ^= (1 << DIAGR[place][1]);
}*/
/*
void place_horiz_opp (struct Board *brd, byte place) {
mov = HORIZ[place]; brd.horiz_o[mov.0] |= (1 << mov.1);
}
void place_verti_opp (struct Board *brd, byte place) {
mov = VERTI[place]; brd.verti_o[mov.0] |= (1 << mov.1);
}
void place_diagl_opp (struct Board *brd, byte place) {
mov = DIAGL[place]; if mov.0 == NO {return;} brd.diagl_o[mov.0] |= (1 << mov.1);
}
void place_diagr_opp (struct Board *brd, byte place) {
mov = DIAGR[place]; if mov.0 == NO {return;} brd.diagr_o[mov.0] |= (1 << mov.1);
}


void remove_horiz_opp (struct Board *brd, byte place) {mov = HORIZ[place]; self.horiz_o[mov.0] ^= (1 << mov.1);}
void remove_verti_opp (struct Board *brd, byte place) {mov = VERTI[place]; self.verti_o[mov.0] ^= (1 << mov.1);}
void remove_diagl_opp (struct Board *brd, byte place) {mov = DIAGL[place]; if mov.0 == NO {return;} self.diagl_o[mov.0] ^= (1 << mov.1);}
void remove_diagr_opp (struct Board *brd, byte place) {mov = DIAGR[place]; if mov.0 == NO {return;} self.diagr_o[mov.0] ^= (1 << mov.1);}
*/