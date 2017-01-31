#include <windows.h>

// Declare types
typedef unsigned char byte;
typedef unsigned short u16;
typedef unsigned int uint;

// Quick move look up
byte MOVES [14348907][15];
uint EVAL [14348907];
// Quick won look up
byte WON [65535];

// Quick binary to ternary lookup
uint BT [65535];
uint BT2 [65535];

byte VAL_OPEN[31];

int BITS[256];
HANDLE search_thread;

typedef struct LINE {
    int cmove;
    byte argmove[100];
}   LINE;


void qs(uint *A, int len);


  #define FIVER 15;
  #define FOR_0 14;
  #define FOR_1 13;
  #define FOR_2 12;
  #define THR_0 11;
  #define THR_1 10;
  #define THR_2 9;
  #define TWO_0 8;
  #define TWO_1 7;
  #define TWO_2 6;

DWORD WINAPI timer (void* data);
/*


// FOR OPEN MOVES

// You win here
#define FIVE 200;

// Win next turn
#define OPEN_FOUR 50;
// It takes 2 of these to make an open four
#define OPEN_THREE OPEN_FOUR/2;
// It takes 3 of these to make an open four
#define OPEN_TWO OPEN_FOUR/3;



// FOR CLOSED MOVES

// It takes 2 to make an open 4.
#define CLOSED_FOUR OPEN_THREE;
// It takes 3 ish to make an open 4
#define CLOSED_THREE OPEN_TWO;
// 
#define CLOSED_TWO OPEN_ONE;






*/








#define YOU_WON 214748364
#define OPP_WON -214748364

#define FOUR 100
#define THREE 45
#define TWO 20
#define ONE 1

















#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

// Here to convert Binary Literals to a Hex Value
#define HEXIFY(X) 0x##X##LU

#define B8IFY(Y) (((Y&0x0000000FLU)?1:0)  + \
                  ((Y&0x000000F0LU)?2:0)  + \
                  ((Y&0x00000F00LU)?4:0)  + \
                  ((Y&0x0000F000LU)?8:0)  + \
                  ((Y&0x000F0000LU)?16:0) + \
                  ((Y&0x00F00000LU)?32:0) + \
                  ((Y&0x0F000000LU)?64:0) + \
                  ((Y&0xF0000000LU)?128:0))

#define B8(Z) ((unsigned char)B8IFY(HEXIFY(Z)))