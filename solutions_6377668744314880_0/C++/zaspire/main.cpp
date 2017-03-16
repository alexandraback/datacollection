
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
  class Line {
  public:
    Line(A x1, A y1, A x2, A y2): _x1(x1), _y1(y1), _x2(x2), _y2(y2) {
      assert((x2 - x1) || (y2 - y1));
    }

    int64_t Check(A x, A y) {
      return (x - _x1) * (_y2 - _y1) - (y - _y1) * (_x2 - _x1);
    }
  private:
    A _x1, _x2, _y1, _y2;
  };

int64_t CCount(const vector<pair<int64_t, int64_t>> &r, int64_t i, int64_t k) {
  Line<int64_t> l(r[i].first, r[i].second, r[k].first, r[k].second);
  int64_t n = 0, p = 0;
  for (int64_t i = 0; i < r.size(); i++) {
    int64_t rr = l.Check(r[i].first, r[i].second);
    if (rr == 0)
      continue;
    if (rr > 0)
      p++;
    else
      n++;
  }
  return min(n, p);
}

int main(void) {
  int64_t T;
  cin >> T;
  for (int64_t TT = 0; TT < T; TT++) {
    int64_t N;
    cin >> N;
    vector<pair<int64_t, int64_t>> r(N);
    for (int64_t i = 0; i < N; i++) {
      cin >> r[i].first >> r[i].second;
    }
    cout << "Case #" << TT + 1 << ": " << endl;
    for (int64_t i = 0; i < N; i++) {
      int64_t m = r.size() - 1;
      for (int64_t k = 0; k < N; k++) {
        if (i == k)
          continue;
        m = min(CCount(r, i, k), m);
      }
      cout << m << endl;
    }
  }
  return 0;
}
