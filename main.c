#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "jomoku.h"

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
  while (1) {
  }
}
