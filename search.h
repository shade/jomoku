
// We'll never go past 50, so it's fine
#define MAX_DEPTH 100

// Just the declaration for the LINE type struct
typedef struct LINE {
    int cmove;
    byte argmove[MAX_DEPTH]; 
} LINE;


/** METHOD DEFINITIONS */
int minmax(struct Board* brd, int depth, byte max);


int next(struct Board* brd, int depth, byte movs[100]);