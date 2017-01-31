#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "jomoku.h"
#include "board.h" 
#include <windows.h>

#define NIL 240
#define NO 30

void build_bt();
void build_won();
void test_suite();
void normal();
void write_fiel();
int search(struct Board brd, byte max, int depth, int alpha, int beta, LINE * pline);

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
  //write_fiel();
  //
  printf("THING: %dmoves\n",MOVES[B8(00100000)][14]);
  fflush(stdout);
    normal();

  struct Board brd;
  clear_brd(&brd);

  place_piece(&brd, 100, 1);
  place_piece(&brd, 101, 1);
  place_piece(&brd, 102, 1);  

  while (1)
  {
    double sum = 0;

    for(int i = 0; i < 1000; i++)
    {
      LARGE_INTEGER StartingTime, EndingTime, ElapsedMicroseconds;
      LARGE_INTEGER Frequency;
      uint moves[225] = {
          0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
          0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
          0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
          0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
          0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
          0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
          0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
          0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
          0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
          0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
          0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
          0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
          0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
          0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
          0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        };

      QueryPerformanceFrequency(&Frequency); 
      QueryPerformanceCounter(&StartingTime);

      byte k = gen_moves(&brd, moves);
      //printf("VAL: %d\n", moves[0][99]);

      QueryPerformanceCounter(&EndingTime);
      ElapsedMicroseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;

      ElapsedMicroseconds.QuadPart *= 1000000;
      ElapsedMicroseconds.QuadPart /= Frequency.QuadPart;

      sum += (double)(ElapsedMicroseconds.QuadPart);
    }
    printf("Avg Time: %.0f ns \n", (sum));
    Sleep(500);
  }
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
      int moves[225] = {
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      };

      byte a = gen_moves(&brd, moves);
      for (int i = 0; i < a; i++)
      {
        printf("SQ: [%d,%d]\n",moves[i] & 255,moves[i]>> 8);
        fflush(stdout);          
      }

      /*
      printf("thing %d,len %d; \n",a, moves[a][499]);
      fflush(stdout);
      for(int i = 0; i < moves[a][499]; i++)
      {
        printf("SQ: [%d,%d]\n",moves[a][i],a);
        fflush(stdout);
      }*/

      //next(&brd);
    }
  }

}


