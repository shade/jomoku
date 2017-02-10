
// First build the won table, then build the move table
void build_lookup_tables();
void build_won();
void build_ternary();
void build_value();
void build_moves();
void move_recognize(int you, int opp);

// Used on the TRY macros.
int VAL_OPEN[256];


// Define binary conversion macros.
// 
#define HEX__(n) 0x##n##LU
#define B8__(x) ((x&0x0000000FLU)?1:0) \
+((x&0x000000F0LU)?2:0) \
+((x&0x00000F00LU)?4:0) \
+((x&0x0000F000LU)?8:0) \
+((x&0x000F0000LU)?16:0) \
+((x&0x00F00000LU)?32:0) \
+((x&0x0F000000LU)?64:0) \
+((x&0xF0000000LU)?128:0)

// User-visible Macros
#define B8(d) ((unsigned char)B8__(HEX__(d)))


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

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))