#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "jomoku.h"
#include "board.h" 

#define NIL 240
#define NO 30

void build_bt();
void build_won();
void next (struct Board* brd);

void main ()
{
  /* Do work */
  printf("COMMENT: BUILDING NECESSARY BINARY TABLES\n");
  build_bt();
  printf("COMMENT: BUILDING STUFF\n");
  build_won();
  printf("COMMENT: DONE !\n");
  
  printf("EVENT: READY\n");
  printf("%d\n", (int)MOVES[87480][0]);

  struct Board brd;
  for (int i = 0;i < 15; i++) {
    brd.horiz_y[i] = 0;
    brd.horiz_o[i] = 0;
    brd.verti_y[i] = 0;
    brd.verti_o[i] = 0;
  }
  for (int i = 0;i < 21; i++) {
    brd.diagr_y[i] = 0;
    brd.diagr_o[i] = 0;
    brd.diagl_y[i] = 0;
    brd.diagl_o[i] = 0;
  }
  for (int i = 0;i < 225; i++) {
    brd.multi[i] = 0;
  }
  place_piece(&brd, 0, 1);
  place_piece(&brd, 100, 1);
  place_piece(&brd, 101, 1);
  place_piece(&brd, 102, 1);
  place_piece(&brd, 103, 1);
  next(&brd);
  printf("HERE\n");
  while (1) {

  }
}
