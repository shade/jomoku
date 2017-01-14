#include <time.h>
#include <stdlib.h>
#include <stdio.h>

typedef unsigned char byte;

byte MOVES [14348907][14];
byte WON [65535];
unsigned long BT [65535];
unsigned long BT2 [65535];

void build_bt();
void build_won();

void main () {
  build_bt();
  printf("COMMENT: DONE BUILDING BINARY TREE\n");
  build_won();
  printf("COMMENT: DONE BUILDING WON TREE\n");

  printf("EVENT: READY\n");
  printf("%d\n", (int)MOVES[87480][0]);
  while (1) {
  }
}
