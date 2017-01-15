#ifndef byte
  typedef unsigned char byte;
  typedef unsigned int uint;
#else
#endif


struct Board {
  byte multi[225];
  unsigned long horiz_y[15];
  unsigned long verti_y[15];
  unsigned long diagr_y[21];
  unsigned long diagl_y[21];

  unsigned long horiz_o[15];
  unsigned long verti_o[15];
  unsigned long diagr_o[21];
  unsigned long diagl_o[21];
};


void place_piece (struct Board *brd, byte place, byte you);
void remove_piece (struct Board *brd, byte place, byte you);
byte* get_moves (struct Board *brd);
byte won (struct Board *brd);
void read_pieces (struct Board *brd);



/** YEAAA....  */
void place_horiz_you (struct Board *brd, byte place);
void place_verti_you (struct Board *brd, byte place);
void remove_horiz_you (struct Board *brd, byte place);
void remove_verti_you (struct Board *brd, byte place);
void place_diagl_you (struct Board *brd, byte place);
void place_diagr_you (struct Board *brd, byte place);
void remove_diagl_you (struct Board *brd, byte place);
void remove_diagr_you (struct Board *brd, byte place);
void place_horiz_opp (struct Board *brd, byte place);
void place_verti_opp (struct Board *brd, byte place);
void remove_horiz_opp (struct Board *brd, byte place);
void remove_verti_opp (struct Board *brd, byte place);
void place_diagl_opp (struct Board *brd, byte place);
void place_diagr_opp (struct Board *brd, byte place);
void remove_diagl_opp (struct Board *brd, byte place);
void remove_diagr_opp (struct Board *brd, byte place);



