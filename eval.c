#include <stdlib.h>

typedef unsigned char byte;
typedef unsigned int uint;

extern unsigned long BT[65535];
extern unsigned long BT2[65535];
extern byte WON[65535];
extern byte MOVES[14348907][14];

void eval (uint you, uint opp, unsigned long val) {
  MOVES[val][0] = 12;
}