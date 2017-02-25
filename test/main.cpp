#include <bitset>
#include <iostream>

using namespace std;

double solve (int you, int opp, bool max) {
  int taken = you | opp;

  // Check if there are no more moves left.
  if (taken == 0b1111111) {
    // Since there are 7 bits, only 3 possible win scenarios.
    if ((you & 0b11111) == 0b11111) {
      return 1;
    }
    if ((you & 0b111110) == 0b111110) {
      return 1;
    }
    if ((you & 0b1111100) == 0b1111100) {
      return 1;
    }

    // If neither won.
    return 0;
  }


  double sum = 0;
  double count = 0;
  for (int i = 0; i < 7; i++) {
    // Ignore iteration if taken.
    if (taken & (1 << i)) continue;
    
    // Max is true if it's you turn.
    if (max) {
      sum += solve(you | (1 << i), opp, !max);
    }
    else {
      sum += solve(you, opp | (1 << i), !max);
    }

    // We can increase the count by one, since this was successful.
    count++;
  }

  if (count == 0) {
    cout << "BAD COUNT" << endl;
  }

  return sum;
}


int main () {
  int OPP_MASKS[3] = {0,0b1000000,0b1000001};
  // Iterate through all the masks
  for (int side = 0; side < 3; side++) {
    // Cap one side, no sides, or both sides
    int opp = OPP_MASKS[side];

    // Iterate through all 5 vector combos
    for (int i = 0; i < 32; i++) {
      int you = i;
      // Create a bitset, of you for binary output
      bitset<7> bin_you(you << 1);
      // Create a bitset of the opp too.
      bitset<7> bin_opp(opp);

      // Calculate the value of this position.
      double value = solve(you << 1, opp, true);
      // Ouput results
      if (value) {
        cout << "BOARD SETUP: "<< bin_you << ',' << bin_opp << endl;
        cout << "VALUE: " << value << endl;
      }
    }
  }


  return 0;
}