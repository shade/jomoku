
// Declare types
typedef unsigned char byte;
typedef unsigned int uint;

// Quick move look up
byte MOVES [14348907][15];
// Quick won look up
byte WON [65535];

// Quick binary to ternary lookup
uint BT [65535];
uint BT2 [65535];


enum MOVE_TYPES {
  OPEN_FOUR_1 = 1,
  OPEN_FOUR_2,
  OPEN_FOUR_3,
  OPEN_FOUR_4,

  CLOSED_FOUR_1,
  CLOSED_FOUR_2,
  CLOSED_FOUR_3,
  CLOSED_FOUR_4,

  OPEN_THREE_1,
  OPEN_THREE_2,
  OPEN_THREE_3,
  OPEN_THREE_4,

  CLOSED_THREE_1,
  CLOSED_THREE_2,
  CLOSED_THREE_3,
  CLOSED_THREE_4
};  

