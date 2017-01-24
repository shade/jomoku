#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "jomoku.h"
#include "board.h" 

#define NIL 240
#define NO 30

void build_bt();
void build_won();
void next (struct Board* brd);
void test_suite();
void normal();
void write_fiel();

void main(){
  /* Do work */
  printf("COMMENT: BUILDING NECESSARY BINARY TABLES\n");
  fflush(stdout);
  build_bt();
  printf("COMMENT: BUILDING STUFF\n");
  fflush(stdout);
  build_won();
  printf("COMMENT: DONE !\n");
  fflush(stdout);
  //test_suite();
  printf("EVENT: READY\n");
  fflush(stdout);
  write_fiel();
  normal();

  struct Board brd;
  clear_brd(&brd);

  place_piece(&brd, 100, 1);
  place_piece(&brd, 101, 1);
  place_piece(&brd, 102, 1);
  place_piece(&brd, 103, 1);
}

void normal() { 
  struct Board brd;
  clear_brd(&brd);
  while (1)
  {
    int i = 0;
    char c = getchar();
    if(c != EOF)
    {
      clear_brd(&brd);
      while(c != EOF && i < 225)
      {
        if (c == '1')
        {
          place_piece(&brd, i, 1);
        }
        else if (c == '2')
        {
          place_piece(&brd, i, 0);
        }
        c = getchar();
        i++;
      }
      next(&brd);
    }
  }

}


