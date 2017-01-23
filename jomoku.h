
// Declare types
typedef unsigned char byte;
typedef unsigned int uint;

// Quick move look up
byte MOVES [14348907][15];
uint EVAL [14348907];
// Quick won look up
byte WON [65535];

// Quick binary to ternary lookup
uint BT [65535];
uint BT2 [65535];











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



























#define FIVE_VAL 0
#define FOUR_VAL_1 1
#define FOUR_VAL_2 2
#define FOUR_VAL_3 3
#define FOUR_VAL_4 4
#define THRE_VAL_1 5
#define THRE_VAL_2 6
#define THRE_VAL_3 7
#define THRE_VAL_4 8
#define THRE_VAL_5 9
#define TWO_VAL_1 10
#define TWO_VAL_2 11
#define TWO_VAL_3 12
#define TWO_VAL_4 14

#define MIN(a,b) (((a)<(b))?(a):(b))

#define MIX(a,b) (a<b ? a:b)

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