#include "board.h"

void Board::Board (string board)
{

  clear();
  char const *brd = board.c_str();

  for(int i = 0; i < 225; i++) {
    byte piece = *(brd + i);
    if (piece != 0) {
      
    }
  }
}


void Board::placePiece(byte place, bool white)
{
  if (white) {
    multi[place] = 1;
    horiz_y[HORIZ[place][0]] ^= (1 << HORIZ[place][1]);
    verti_y[VERTI[place][0]] ^= (1 << VERTI[place][1]);
    if (DIAGL[place][0] != NO) {diagl_y[DIAGL[place][0]] ^= (1 << DIAGL[place][1]);}
    if (DIAGR[place][0] != NO) {diagr_y[DIAGR[place][0]] ^= (1 << DIAGR[place][1]);}
  } else {
    multi[place] = 2;
    horiz_o[HORIZ[place][0]] ^= (1 << HORIZ[place][1]);
    verti_o[VERTI[place][0]] ^= (1 << VERTI[place][1]);
    if (DIAGL[place][0] != NO) {diagl_o[DIAGL[place][0]] ^= (1 << DIAGL[place][1]);}
    if (DIAGR[place][0] != NO) {diagr_o[DIAGR[place][0]] ^= (1 << DIAGR[place][1]);}
  }
}

void Board::removePiece(byte place, bool white)
{
  multi[place] = 0;
  if (white) {
    horiz_y[HORIZ[place][0]] ^= (1 << HORIZ[place][1]);
    verti_y[VERTI[place][0]] ^= (1 << VERTI[place][1]);
    if (DIAGL[place][0] != NO) {diagl_y[DIAGL[place][0]] ^= (1 << DIAGL[place][1]);}
    if (DIAGR[place][0] != NO) {diagr_y[DIAGR[place][0]] ^= (1 << DIAGR[place][1]);}
  } else {
    horiz_o[HORIZ[place][0]] ^= (1 << HORIZ[place][1]);
    verti_o[VERTI[place][0]] ^= (1 << VERTI[place][1]);
    if (DIAGL[place][0] != NO) {diagl_o[DIAGL[place][0]] ^= (1 << DIAGL[place][1]);}
    if (DIAGR[place][0] != NO) {diagr_o[DIAGR[place][0]] ^= (1 << DIAGR[place][1]);}
  }
}

void Board::clear()
{
  for (int i = 0;i < 15; i++) {
    horiz_y[i] = 0;
    horiz_o[i] = 0;
    verti_y[i] = 0;
    verti_o[i] = 0;
  }
  
  for (int i = 0;i < 21; i++) {
    diagr_y[i] = 0;
    diagr_o[i] = 0;
    diagl_y[i] = 0;
    diagl_o[i] = 0;
  }

  for (int i = 0;i < 225; i++) {
    multi[i] = 0;
  }
}







byte Board::moves(uint moves[255])
{

  // The counter to iterate through the rows.
  int i = 0;

  // The code in the 2 while loops has been tested, so it works, too lazy to comment on it.
  while(i < 15)
  {

    int val_h = BT[horiz_y[i]] + BT2[horiz_o[i]];
    int val_v = BT[verti_y[i]] + BT2[verti_o[i]];
    int val_r = BT[diagr_y[i]] + BT2[diagr_o[i]];
    int val_l = BT[diagl_y[i]] + BT2[diagl_o[i]];

    byte h_i = MOVES[val_h][14];
    byte v_i = MOVES[val_v][14];
    byte r_i = MOVES[val_r][14];
    byte l_i = MOVES[val_l][14];
    
    byte* h_arr; h_arr = MOVES[val_h];
    byte* v_arr; v_arr = MOVES[val_v];
    byte* l_arr; l_arr = MOVES[val_l];
    byte* r_arr; r_arr = MOVES[val_r];

    while(h_i | v_i | r_i | l_i)
    {
      if (h_i)
      {
        h_i--;
        byte h = *(h_arr + h_i);
        byte val = h >> 4;
        byte loc = H[i][14 - (h & 15)]; // 15 is the same as 0b00001111
        moves[loc] += VALS[val];
      }

      if (v_i)
      {
        v_i--;
        byte v = *(v_arr + v_i);
        byte val = v >> 4;
        byte loc = V[i][14 - (v & 15)]; // 15 is the same as 0b00001111
        moves[loc] += VALS[val];
      }

      if (l_i)
      {
        l_i--;
        byte l = *(l_arr + l_i);
        byte val = l >> 4;
        byte loc = L[i][l & 15]; // 15 is the same as 0b00001111.
        ((loc != NIL) && (moves[loc] += VALS[val])); // Bounds checking on diagonals.
      }

      if (r_i)
      {
        r_i--;
        byte r = *(r_arr + r_i);
        byte val = r >> 4;
        byte loc = R[i][r & 15]; // 15 is the same as 0b00001111.
        ((loc != NIL) && (moves[loc] += VALS[val])); // Bounds checking on diagonals.
      }
    }

    i++;
  }

  while (i < 22)
  {
    int val_r = BT[diagr_y[i]] + BT2[diagr_o[i]];
    int val_l = BT[diagl_y[i]] + BT2[diagl_o[i]];

    byte r_i = MOVES[val_r][14];
    byte l_i = MOVES[val_l][14];

    byte* l_arr; l_arr = MOVES[val_l];
    byte* r_arr; r_arr = MOVES[val_r];

    while(r_i | l_i)
    {
      if (l_i)
      {
        l_i--;
        byte l = *(l_arr + l_i);
        byte val = l >> 4;
        byte loc = L[i][l & 15]; // 15 is the same as 0b00001111.
        ((loc != NIL) && (moves[loc] += VALS[val])); // Bounds checking on diagonals.
      }

      if (r_i)
      {
        r_i--;
        byte r = *(r_arr + r_i);
        byte val = r >> 4;
        byte loc = R[i][r & 15]; // 15 is the same as 0b00001111.
        ((loc != NIL) && (moves[loc] += VALS[val])); // Bounds checking on diagonals.
      }
    }

    i++;
  }

  // Initialize the counter.
  uint c = 0;

  // Shift the moves to the left of the array and encode the position into the thing
  for (int i = 0; i < 225; i++)
  {
    if (moves[i] != NIL)
    {
      moves[c++] = ((moves[i] << 8) | i);
    }
  }

  // Sort.
  quickSort(moves, c);

  return c;
}



