#ifndef byte
  typedef unsigned char byte;
  typedef unsigned int uint;
#else
#endif


  
struct Board {
  byte multi[225];
  uint horiz_y[15];
  uint verti_y[15];
  uint diagr_y[21];
  uint diagl_y[21];

  uint horiz_o[15];
  uint verti_o[15];
  uint diagr_o[21];
  uint diagl_o[21];
};


void place_piece (struct Board *brd, byte place, byte you);
void remove_piece (struct Board *brd, byte place, byte you);
byte* get_moves (struct Board *brd);
byte brd_won (struct Board *brd);
uint brd_eval (struct Board *brd);
void read_pieces (struct Board *brd);
