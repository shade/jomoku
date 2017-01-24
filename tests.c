#include <assert.h>
#include <stdio.h>
#include "board.h"
#include "jomoku.h"

void test_wins () {
  assert(WON[B8(00001111)] == 0);
  assert(WON[B8(00101111)] == 0);
  assert(WON[B8(00111111)] != 0);
  assert(WON[B8(01111100)] != 0);
  assert(WON[B8(11111000)] != 0);
  printf("TEST: ALL WINS ARE LEGIT\n");
}

void test_moves (struct Board *brd) {
  for(int i = 0; i < 225; i++) {
    place_piece(brd,i,1);
  }
  for(int i = 0; i < 15; i++) {
    assert(brd->horiz_y[i] == 32767);
    assert(brd->verti_y[i] == 32767);
  }
  printf("TEST: PLACE PIECE WORKING\n");
  for(int i = 0; i < 225; i++) {
    remove_piece(brd,i,1);
  }
  for(int i = 0; i < 15; i++) {
    assert(brd->horiz_y[i] == 0);
    assert(brd->verti_y[i] == 0);
  }
  printf("TEST: REMOVE PIECE WORKING\n");
}

void test_generation (struct Board *brd) {
  byte moves[225];
  get_moves(brd, moves);
  for(int i = 1;i < 226; i++) {
    printf("%d,",moves[i - 1]);
    assert(moves[i - 1] == 240);
    if (i % 15 == 0) {
      printf("\n");
    }
  }
  printf("\n");
  place_piece(brd, 10, 1);
  place_piece(brd, 9, 1);
  place_piece(brd, 8, 1);
  get_moves(brd, moves);
  for(int i = 1;i < 226; i++) {
    printf("%d,",moves[i - 1]);
    if (i % 15 == 0) {
      printf("\n");
    }
  }
}


void test_suite () {

  struct Board brd;
  for (int i = 0;i < 15; i++) {
    brd.horiz_y[i] = 0;
    brd.horiz_o[i] = 0;
    brd.verti_y[i] = 0;
    brd.verti_o[i] = 0;
  }
  for (int i = 0;i < 21; i++) {
    brd.diagr_y[i] = 0;
    brd.diagr_o[i] = 0;
    brd.diagl_y[i] = 0;
    brd.diagl_o[i] = 0;
  }
  for (int i = 0;i < 225; i++) {
    brd.multi[i] = 0;
  }

  test_wins();
  test_moves(&brd);
  test_generation(&brd);
  printf("TEST: ALL TESTS PASSED!!!\n");
}






void write_fiel()
{
  printf("WRITING\n");
  FILE *fp = fopen("./MOVES", "w");
  for(int i = 0; i < 14348907; i++)
  {
    fwrite(MOVES[i], sizeof(byte), 15, fp);
  }
  fclose(fp); 
}