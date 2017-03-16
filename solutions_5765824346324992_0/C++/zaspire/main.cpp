
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cassert>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

  template<typename A>
  A GreatestCommonDivisor(const A a, const A b) {
    if (a > b)
      return GreatestCommonDivisor(b, a);
    if (b % a == 0)
      return a;
    return GreatestCommonDivisor(a, b % a);
  }

int main(void) {
  int T;
  cin >> T;
  for (int TT = 0; TT < T; TT++) {
    int B, N;
    cin >> B >> N;
    vector<int> b;
    b.reserve(B);
    while (B--) {
      int t;
      cin >> t;
      b.push_back(t);
    }

    int gcd = b[0];
    int64_t m = b[0];
    for (int i = 1; i < b.size(); i++) {
      gcd = GreatestCommonDivisor(gcd, b[i]);
      m *= b[i];
    }
    m /= gcd;
    int64_t n = 0;
    vector<pair<int, int>> seq;
    for (int i = 0; i < b.size(); i++) {
      n += m / b[i];
      for (int k = 0; k < m / b[i]; k++) {
        seq.emplace_back(k * b[i], i);
      }
    }
    sort(seq.begin(), seq.end());

    N = N % n;

    if (N == 0) {
      N = seq.size() - 1;
    } else {
      N--;
    }

    cout << "Case #" << TT + 1 << ": " << seq[N].second + 1<< endl;
  }
  return 0;
}
