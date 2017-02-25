#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <ratio>


#include "board.h"
using namespace std;

void buildAll();
void startGame();

int main ()
{
  // Create the proper tables.
  cout << "COMMENT: BUILDING EVERYTHING!" << endl;
  buildAll();
  
  // Remove the loading sign on the GUI.
  cout << "READY: YAY" << endl;

  // Start the game.
  startGame();
  return 0;
}