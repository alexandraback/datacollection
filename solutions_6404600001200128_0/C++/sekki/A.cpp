#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {

  int ncases;
  cin >> ncases;

  for (int i = 0; i < ncases; i++) {
    int intervals;
    cin >> intervals;

    vector<int> mushrooms;

    int eaten1 = 0;
    int eaten2 = 0;
    int maxdiff = 0;
    int prev = 0;
    
    for (int j = 0; j < intervals; j++) {
      int nmush;
      cin >> nmush;

      //method 1
      if (nmush < prev) eaten1 += (prev-nmush);
      //method 2
      if (prev-nmush > maxdiff) maxdiff = prev-nmush;
      mushrooms.push_back(nmush);

      prev = nmush;
    }

    for (int j = 1; j < intervals; j++) {
      if ((mushrooms[j-1] - mushrooms[j]) < maxdiff) eaten2 += min(mushrooms[j-1],maxdiff);
      else eaten2 += maxdiff;
    }

    cout << "Case #" << i+1 << ": " << eaten1 << " " << eaten2 << endl;
  }
  return 0;
}
