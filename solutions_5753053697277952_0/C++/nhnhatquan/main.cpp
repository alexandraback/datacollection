#include <string>
#include <fstream>
#include <iostream>
#include <istream>
#include <sstream>
#include <functional>
#include <numeric>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void main() {
  int T;
  cin >> T;

  for (int t = 0; t != T; ++t) {
    int N;
    cin >> N;

    int p[500] = { 0, };
    int S = 0;

    for (int i = 0; i != N; ++i) {
      cin >> p[i];
      S += p[i];
    }

    string ret = "";

    int count = 0;

    do {
      char m = 0;
      for (int i = 0; i != N; ++i) {
        if (p[i] > p[m]) m = i;
      }

      ret += string(1, m + 'A');

      --p[m];
      --S;
      ++count;

      if (count == 2 || S == 2) {
        count = 0;
        if (S != 0)
          ret += " ";
      }
    } while (S != 0);

    cout << "Case #" << t + 1 << ": " << ret << endl;
  }
}