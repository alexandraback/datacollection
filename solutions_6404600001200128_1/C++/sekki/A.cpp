#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {

  long long ncases;
  cin >> ncases;

  for (long long i = 0; i < ncases; i++) {
    long long intervals;
    cin >> intervals;

    vector<long long> mushrooms;

    long long eaten1 = 0;
    long long eaten2 = 0;
    long long maxdiff = 0;
    long long prev = 0;
    
    for (long long j = 0; j < intervals; j++) {
      long long nmush;
      cin >> nmush;

      //method 1
      if (nmush < prev) eaten1 += (prev-nmush);
      //method 2
      if (prev-nmush > maxdiff) maxdiff = prev-nmush;
      mushrooms.push_back(nmush);

      prev = nmush;
    }

    for (long long j = 1; j < intervals; j++) {
      if ((mushrooms[j-1] - mushrooms[j]) < maxdiff) eaten2 += min(mushrooms[j-1],maxdiff);
      else eaten2 += maxdiff;
    }

    cout << "Case #" << i+1 << ": " << eaten1 << " " << eaten2 << endl;
  }
  return 0;
}
