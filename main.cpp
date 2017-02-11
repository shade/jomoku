#include <iostream>
#include <string>

using namespace std;

int main ()
{
  while (true) {
    string input;
    cin >> input;

    switch (input.substr(0,5)) {
      case "RESTA":
      case "START":
      case "BEGIN":
        newBoard();
        break;
      case "TURN ":
        makeMove(input.substr(3));
        break;
      case "BOARD":
        clearBoard();
        break;
      default:

        break;
    }
  }

  return 0;
}