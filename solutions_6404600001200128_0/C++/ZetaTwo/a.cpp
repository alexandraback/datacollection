#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

  int T;
  int c = 1;
  cin >> T;
  while (T--) {
    //Get test case
    size_t N;
    cin >> N;
    vector<int> shrooms(N);
    for (size_t i = 0; i < N; i++) {
      cin >> shrooms[i];
    }

    //Calculate with both methods
    int method1 = 0, method2 = 0;
    int rate = 0;

    for (size_t i = 1; i < N; i++)
    {
      int diff = shrooms[i - 1] - shrooms[i];
      if (diff > 0) {
        method1 += diff;

        if (diff > rate) {
          rate = diff;
        }
      }
    }

    for (size_t i = 1; i < N; i++)
    {
      method2 += min(shrooms[i - 1], rate);
    }

    //Method 2a - find rate

    cout << "Case #" << c++ << ": " << method1 << " " << method2 << endl;
  }

  return 0;
}