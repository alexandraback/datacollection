#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <array>

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }
int in() { int x; scanf("%d", &x); return x; }

void solve() {
  int cand[16] = {0};
  for (int i = 0; i < 2; ++i) {
    int r = in();
    for (int j = 0; j < 4; ++j) {
      for (int k = 0; k < 4; ++k) {
        int x = in();
        if (r - 1 == j) {
          ++cand[x - 1];
        }
      }
    }
  }

  int* p = max_element(cand, cand + 16);
  if (*p <= 1) {
    cout << "Volunteer cheated!" << endl;
  } else if (count(cand, cand + 16, 2) >= 2) {
    cout << "Bad magician!" << endl;
  } else {
    cout << p - cand + 1 << endl;
  }
}

int main()
{
  int T = in();

  for (int CN = 1; CN <= T; ++CN) {
    cout << "Case #" << CN << ": ";
    solve();
  }

  return 0;
}
