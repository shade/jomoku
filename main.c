#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "jomoku.h"
#include "board.h"

#define NIL 240
#define NO 30

void build_bt();
void build_won();

void main ()
{
  float startTime = (float)clock()/CLOCKS_PER_SEC;

  /* Do work */
  build_bt();
  printf("COMMENT: DONE BUILDING BINARY TREE\n");
  build_won();
  printf("COMMENT: DONE BUILDING WON TREE\n");
  
  printf("EVENT: READY\n");
  printf("%d\n", (int)MOVES[87480][0]);

  struct Board brd;
  for (int i = 0;i < 15; i++) {
    brd.horiz_y[i] = 0;
    brd.verti_y[i] = 0;
  }

  place_piece(&brd, 10, 1);

  while (1) {
   read_pieces(&brd); 
  }
}
