
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

int kMax = 10001;

int64_t Solve1(const vector<int> &r) {
  int64_t res = 0;
  for (int i = 1; i < r.size(); i++) {
    if (r[i - 1] <= r[i])
      continue;
    res += r[i - 1] - r[i];
  }
  return res;
}

int64_t Solve2(const vector<int> &r) {
  int D = 0;
  for (int i = 1; i < r.size(); i++) {
    if (r[i - 1] <= r[i])
      continue;
    D = max(D, r[i - 1] - r[i]);
  }
  int64_t res = 0;
  for (int i = 0; i < r.size() - 1; i++) {
    res += min(D, r[i]);
  }
  return res;
}

int main(void) {
  int T;
  cin >> T;
  for (int TT = 0; TT < T; TT++) {
    int N;
    cin >> N;
    vector<int> r;
    r.reserve(N);
    while (N--) {
      int t;
      cin >> t;
      r.push_back(t);
    }
    cout << "Case #" << TT + 1 << ": " << Solve1(r) << ' ' << Solve2(r) << endl;
  }
  return 0;
}
