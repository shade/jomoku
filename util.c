/**
 * This page is for utility functions and arrays.
 * Mainly to prevent clutter in other functions.
 */

#include "util.h"
#include "board.h"

// Declare all the arrays
const byte HORIZ[225][2] = {
  {0,14},{0,13},{0,12},{0,11},{0,10},{0,9},{0,8},{0,7},{0,6},{0,5},{0,4},{0,3},{0,2},{0,1},{0,0},
  {1,14},{1,13},{1,12},{1,11},{1,10},{1,9},{1,8},{1,7},{1,6},{1,5},{1,4},{1,3},{1,2},{1,1},{1,0},
  {2,14},{2,13},{2,12},{2,11},{2,10},{2,9},{2,8},{2,7},{2,6},{2,5},{2,4},{2,3},{2,2},{2,1},{2,0},
  {3,14},{3,13},{3,12},{3,11},{3,10},{3,9},{3,8},{3,7},{3,6},{3,5},{3,4},{3,3},{3,2},{3,1},{3,0},
  {4,14},{4,13},{4,12},{4,11},{4,10},{4,9},{4,8},{4,7},{4,6},{4,5},{4,4},{4,3},{4,2},{4,1},{4,0},
  {5,14},{5,13},{5,12},{5,11},{5,10},{5,9},{5,8},{5,7},{5,6},{5,5},{5,4},{5,3},{5,2},{5,1},{5,0},
  {6,14},{6,13},{6,12},{6,11},{6,10},{6,9},{6,8},{6,7},{6,6},{6,5},{6,4},{6,3},{6,2},{6,1},{6,0},
  {7,14},{7,13},{7,12},{7,11},{7,10},{7,9},{7,8},{7,7},{7,6},{7,5},{7,4},{7,3},{7,2},{7,1},{7,0},
  {8,14},{8,13},{8,12},{8,11},{8,10},{8,9},{8,8},{8,7},{8,6},{8,5},{8,4},{8,3},{8,2},{8,1},{8,0},
  {9,14},{9,13},{9,12},{9,11},{9,10},{9,9},{9,8},{9,7},{9,6},{9,5},{9,4},{9,3},{9,2},{9,1},{9,0},
  {10,14},{10,13},{10,12},{10,11},{10,10},{10,9},{10,8},{10,7},{10,6},{10,5},{10,4},{10,3},{10,2},{10,1},{10,0},
  {11,14},{11,13},{11,12},{11,11},{11,10},{11,9},{11,8},{11,7},{11,6},{11,5},{11,4},{11,3},{11,2},{11,1},{11,0},
  {12,14},{12,13},{12,12},{12,11},{12,10},{12,9},{12,8},{12,7},{12,6},{12,5},{12,4},{12,3},{12,2},{12,1},{12,0},
  {13,14},{13,13},{13,12},{13,11},{13,10},{13,9},{13,8},{13,7},{13,6},{13,5},{13,4},{13,3},{13,2},{13,1},{13,0},
  {14,14},{14,13},{14,12},{14,11},{14,10},{14,9},{14,8},{14,7},{14,6},{14,5},{14,4},{14,3},{14,2},{14,1},{14,0}
};

const byte VERTI[255][2] = {
  {00,14},{1,14},{2,14},{3,14},{4,14},{5,14},{6,14},{7,14},{8,14},{9,14},{10,14},{11,14},{12,14},{13,14},{14,14},
  {00,13},{1,13},{2,13},{3,13},{4,13},{5,13},{6,13},{7,13},{8,13},{9,13},{10,13},{11,13},{12,13},{13,13},{14,13},
  {00,12},{1,12},{2,12},{3,12},{4,12},{5,12},{6,12},{7,12},{8,12},{9,12},{10,12},{11,12},{12,12},{13,12},{14,12},
  {00,11},{1,11},{2,11},{3,11},{4,11},{5,11},{6,11},{7,11},{8,11},{9,11},{10,11},{11,11},{12,11},{13,11},{14,11},
  {00,10},{1,10},{2,10},{3,10},{4,10},{5,10},{6,10},{7,10},{8,10},{9,10},{10,10},{11,10},{12,10},{13,10},{14,10},
  {00,9},{1,9},{2,9},{3,9},{4,9},{5,9},{6,9},{7,9},{8,9},{9,9},{10,9},{11,9},{12,9},{13,9},{14,9},
  {00,8},{1,8},{2,8},{3,8},{4,8},{5,8},{6,8},{7,8},{8,8},{9,8},{10,8},{11,8},{12,8},{13,8},{14,8},
  {00,7},{1,7},{2,7},{3,7},{4,7},{5,7},{6,7},{7,7},{8,7},{9,7},{10,7},{11,7},{12,7},{13,7},{14,7},
  {00,6},{1,6},{2,6},{3,6},{4,6},{5,6},{6,6},{7,6},{8,6},{9,6},{10,6},{11,6},{12,6},{13,6},{14,6},
  {00,5},{1,5},{2,5},{3,5},{4,5},{5,5},{6,5},{7,5},{8,5},{9,5},{10,5},{11,5},{12,5},{13,5},{14,5},
  {00,4},{1,4},{2,4},{3,4},{4,4},{5,4},{6,4},{7,4},{8,4},{9,4},{10,4},{11,4},{12,4},{13,4},{14,4},
  {00,3},{1,3},{2,3},{3,3},{4,3},{5,3},{6,3},{7,3},{8,3},{9,3},{10,3},{11,3},{12,3},{13,3},{14,3},
  {00,2},{1,2},{2,2},{3,2},{4,2},{5,2},{6,2},{7,2},{8,2},{9,2},{10,2},{11,2},{12,2},{13,2},{14,2},
  {00,1},{1,1},{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1},{12,1},{13,1},{14,1},
  {00,00},{1,00},{2,00},{3,00},{4,00},{5,00},{6,00},{7,00},{8,00},{9,00},{10,00},{11,00},{12,00},{13,00},{14,00},
};

const byte DIAGL[255][2] = {
  {NO,NO},{NO,NO},{NO,NO},{NO,NO},{00,00},{1,00},{2,00},{3,00},{4,00},{5,00},{6,00},{7,00},{8,00},{9,00},{10,00},
  {NO,NO},{NO,NO},{NO,NO},{00,1},{1,1},{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,00},
  {NO,NO},{NO,NO},{00,2},{1,2},{2,2},{3,2},{4,2},{5,2},{6,2},{7,2},{8,2},{9,2},{10,2},{11,1},{12,00},
  {NO,NO},{00,3},{1,3},{2,3},{3,3},{4,3},{5,3},{6,3},{7,3},{8,3},{9,3},{10,3},{11,2},{12,1},{13,00},
  {00,4},{1,4},{2,4},{3,4},{4,4},{5,4},{6,4},{7,4},{8,4},{9,4},{10,4},{11,3},{12,2},{13,1},{14,00},
  {1,5},{2,5},{3,5},{4,5},{5,5},{6,5},{7,5},{8,5},{9,5},{10,5},{11,4},{12,3},{13,2},{14,1},{15,00},
  {2,6},{3,6},{4,6},{5,6},{6,6},{7,6},{8,6},{9,6},{10,6},{11,5},{12,4},{13,3},{14,2},{15,1},{16,00},
  {3,7},{4,7},{5,7},{6,7},{7,7},{8,7},{9,7},{10,7},{11,6},{12,5},{13,4},{14,3},{15,2},{16,1},{17,00},
  {4,8},{5,8},{6,8},{7,8},{8,8},{9,8},{10,8},{11,7},{12,6},{13,5},{14,4},{15,3},{16,2},{17,1},{18,00},
  {5,9},{6,9},{7,9},{8,9},{9,9},{10,9},{11,8},{12,7},{13,6},{14,5},{15,4},{16,3},{17,2},{18,1},{19,00},
  {6,10},{7,10},{8,10},{9,10},{10,10},{11,9},{12,8},{13,7},{14,6},{15,5},{16,4},{17,3},{18,2},{19,1},{20,00},
  {7,11},{8,11},{9,11},{10,11},{11,10},{12,9},{13,8},{14,7},{15,6},{16,5},{17,4},{18,3},{19,2},{20,1},{NO,NO},
  {8,12},{9,12},{10,12},{11,11},{12,10},{13,9},{14,8},{15,7},{16,6},{17,5},{18,4},{19,3},{20,2},{NO,NO},{NO,NO},
  {9,13},{10,13},{11,12},{12,11},{13,10},{14,9},{15,8},{16,7},{17,6},{18,5},{19,4},{20,3},{NO,NO},{NO,NO},{NO,NO},
  {10,14},{11,13},{12,12},{13,11},{14,10},{15,9},{16,8},{17,7},{18,6},{19,5},{20,4},{NO,NO},{NO,NO},{NO,NO},{NO,NO}
};

const byte DIAGR[255][2] = {
  {10,14},{9,13}, {8,12},{7,11},{6,10},{5,9},{4,8},{3,7},{2,6},{1,5},{00,4},{NO,NO},{NO,NO},{NO,NO},{NO,NO},
  {11,13},{10,13},{9,12},{8,11},{7,10},{6,9},{5,8},{4,7},{3,6},{2,5},{1,4},{00,3},{NO,NO},{NO,NO},{NO,NO},
  {12,12},{11,12},{10,12},{9,11},{8,10},{7,9},{6,8},{5,7},{4,6},{3,5},{2,4},{1,3},{00,2},{NO,NO},{NO,NO},
  {13,11},{12,11},{11,11},{10,11},{9,10},{8,9},{7,8},{6,7},{5,6},{4,5},{3,4},{2,3},{1,2},{00,1},{NO,NO},
  {14,10},{13,10},{12,10},{11,10},{10,10},{9,9},{8,8},{7,7},{6,6},{5,5},{4,4},{3,3},{2,2},{1,1},{00,00},
  {15,9},{14,9},{13,9},{12,9},{11,9},{10,9},{9,8},{8,7},{7,6},{6,5},{5,4},{4,3},{3,2},{2,1},{1,00},
  {16,8},{15,8},{14,8},{13,8},{12,8},{11,8},{10,8},{9,7},{8,6},{7,5},{6,4},{5,3},{4,2},{3,1},{2,00},
  {17,7},{16,7},{15,7},{14,7},{13,7},{12,7},{11,7},{10,7},{9,6},{8,5},{7,4},{6,3},{5,2},{4,1},{3,00},
  {18,6},{17,6},{16,6},{15,6},{14,6},{13,6},{12,6},{11,6},{10,6},{9,5},{8,4},{7,3},{6,2},{5,1},{4,00},
  {19,5},{18,5},{17,5},{16,5},{15,5},{14,5},{13,5},{12,5},{11,5},{10,5},{9,4},{8,3},{7,2},{6,1},{5,00},
  {20,4},{19,4},{18,4},{17,4},{16,4},{15,4},{14,4},{13,4},{12,4},{11,4},{10,4},{9,3},{8,2},{7,1},{6,00},
  {NO,NO},{20,3},{19,3},{18,3},{17,3},{16,3},{15,3},{14,3},{13,3},{12,3},{11,3},{10,3},{9,2},{8,1},{7,00},
  {NO,NO},{NO,NO},{20,2},{19,2},{18,2},{17,2},{16,2},{15,2},{14,2},{13,2},{12,2},{11,2},{10,2},{9,1},{8,00},
  {NO,NO},{NO,NO},{NO,NO},{20,1},{19,1},{18,1},{17,1},{16,1},{15,1},{14,1},{13,1},{12,1},{11,1},{10,1},{9,00},
  {NO,NO},{NO,NO},{NO,NO},{NO,NO},{20,00},{19,00},{18,00},{17,00},{16,00},{15,00},{14,00},{13,00},{12,00},{11,00},{10,00}
};


const byte HORIZ_ARRS[15][15] = {
  {000,1,2,3,4,5,6,7,8,9,10,11,12,13,14},
  {15,16,17,18,19,20,21,22,23,24,25,26,27,28,29},
  {30,31,32,33,34,35,36,37,38,39,40,41,42,43,44},
  {45,46,47,48,49,50,51,52,53,54,55,56,57,58,59},
  {60,61,62,63,64,65,66,67,68,69,70,71,72,73,74},
  {75,76,77,78,79,80,81,82,83,84,85,86,87,88,89},
  {90,91,92,93,94,95,96,97,98,99,100,101,102,103,104},
  {105,106,107,108,109,110,111,112,113,114,115,116,117,118,119},
  {120,121,122,123,124,125,126,127,128,129,130,131,132,133,134},
  {135,136,137,138,139,140,141,142,143,144,145,146,147,148,149},
  {150,151,152,153,154,155,156,157,158,159,160,161,162,163,164},
  {165,166,167,168,169,170,171,172,173,174,175,176,177,178,179},
  {180,181,182,183,184,185,186,187,188,189,190,191,192,193,194},
  {195,196,197,198,199,200,201,202,203,204,205,206,207,208,209},
  {210,211,212,213,214,215,216,217,218,219,220,221,222,223,224}
};

const byte VERTI_ARRS[15][15] = {
  {000,15,30,45,60,75,90,105,120,135,150,165,180,195,210},
  {1,16,31,46,61,76,91,106,121,136,151,166,181,196,211},
  {2,17,32,47,62,77,92,107,122,137,152,167,182,197,212},
  {3,18,33,48,63,78,93,108,123,138,153,168,183,198,213},
  {4,19,34,49,64,79,94,109,124,139,154,169,184,199,214},
  {5,20,35,50,65,80,95,110,125,140,155,170,185,200,215},
  {6,21,36,51,66,81,96,111,126,141,156,171,186,201,216},
  {7,22,37,52,67,82,97,112,127,142,157,172,187,202,217},
  {8,23,38,53,68,83,98,113,128,143,158,173,188,203,218},
  {9,24,39,54,69,84,99,114,129,144,159,174,189,204,219},
  {10,25,40,55,70,85,100,115,130,145,160,175,190,205,220},
  {11,26,41,56,71,86,101,116,131,146,161,176,191,206,221},
  {12,27,42,57,72,87,102,117,132,147,162,177,192,207,222},
  {13,28,43,58,73,88,103,118,133,148,163,178,193,208,223},
  {14,29,44,59,74,89,104,119,134,149,164,179,194,209,224}
};

const byte DIAGL_ARRS[21][15] = {
  {4,18,32,46,60,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL},
  {5,19,33,47,61,75,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL},
  {6,20,34,48,62,76,90,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL},
  {7,21,35,49,63,77,91,105,NIL,NIL,NIL,NIL,NIL,NIL,NIL},
  {8,22,36,50,64,78,92,106,120,NIL,NIL,NIL,NIL,NIL,NIL},
  {9,23,37,51,65,79,93,107,121,135,NIL,NIL,NIL,NIL,NIL},
  {10,24,38,52,66,80,94,108,122,136,150,NIL,NIL,NIL,NIL},
  {11,25,39,53,67,81,95,109,123,137,151,165,NIL,NIL,NIL},
  {12,26,40,54,68,82,96,110,124,138,152,166,180,NIL,NIL},
  {13,27,41,55,69,83,97,111,125,139,153,167,181,195,NIL},
  {14,28,42,56,70,84,98,112,126,140,154,168,182,196,210},
  {29,43,57,71,85,99,113,127,141,155,169,183,197,211,NIL},
  {44,58,72,86,100,114,128,142,156,170,184,198,212,NIL,NIL},
  {59,73,87,101,115,129,143,157,171,185,199,213,NIL,NIL,NIL},
  {74,88,102,116,130,144,158,172,186,200,214,NIL,NIL,NIL,NIL},
  {89,103,117,131,145,159,173,187,201,215,NIL,NIL,NIL,NIL,NIL},
  {104,118,132,146,160,174,188,202,216,NIL,NIL,NIL,NIL,NIL,NIL},
  {119,133,147,161,175,189,203,217,NIL,NIL,NIL,NIL,NIL,NIL,NIL},
  {134,148,162,176,190,204,218,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL},
  {149,163,177,191,205,219,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL},
  {164,178,192,206,220,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL},
};

const byte DIAGR_ARRS[21][15] = {
  {74,58,42,26,10,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL},
  {89,73,57,41,25,9,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL},
  {104,88,72,56,40,24,8,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL},
  {119,103,87,71,55,39,23,7,NIL,NIL,NIL,NIL,NIL,NIL,NIL},
  {134,118,102,86,70,54,38,22,6,NIL,NIL,NIL,NIL,NIL,NIL},
  {149,133,117,101,85,69,53,37,21,5,NIL,NIL,NIL,NIL,NIL},
  {164,148,132,116,100,84,68,52,36,20,4,NIL,NIL,NIL,NIL},
  {179,163,147,131,115,99,83,67,51,35,19,3,NIL,NIL,NIL},
  {194,178,162,146,130,114,98,82,66,50,34,18,2,NIL,NIL},
  {209,193,177,161,145,129,113,97,81,65,49,33,17,1,NIL},
  {224,208,192,176,160,144,128,112,96,80,64,48,32,16,000},
  {223,207,191,175,159,143,127,111,95,79,63,47,31,15,NIL},
  {222,206,190,174,158,142,126,110,94,78,62,46,30,NIL,NIL},
  {221,205,189,173,157,141,125,109,93,77,61,45,NIL,NIL,NIL},
  {220,204,188,172,156,140,124,108,92,76,60,NIL,NIL,NIL,NIL},
  {219,203,187,171,155,139,123,107,91,75,NIL,NIL,NIL,NIL,NIL},
  {218,202,186,170,154,138,122,106,90,NIL,NIL,NIL,NIL,NIL,NIL},
  {217,201,185,169,153,137,121,105,NIL,NIL,NIL,NIL,NIL,NIL,NIL},
  {216,200,184,168,152,136,120,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL},
  {215,199,183,167,151,135,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL},
  {214,198,182,166,150,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL,NIL}
};





// The quicksort function
void quick_sort(uint *A, int len)
{
  if (len < 2) return;
 
  int pivot = A[len / 2];
 
  int i, j;
  for (i = 0, j = len - 1; ; i++, j--)
  {
    while (A[i] < pivot) i++;
    while (A[j] > pivot) j--;
 
    if (i >= j) break;

    // Cool XOR swapping
    A[i] ^= A[j];
    A[j] ^= A[i];
    A[i] ^= A[j];
  }
 
  quick_sort(A, i);
  quick_sort(A + i, len - i);
}