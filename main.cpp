#include <iostream>
#include <string>

using namespace std;

void buildAll();
void startGame();

int main ()
{
  cout << "COMMENT: BUILDING EVERYTHING!" << endl;
  buildAll();
  cout << "READY: yay" << endl;
  startGame();
  
  return 0;
}