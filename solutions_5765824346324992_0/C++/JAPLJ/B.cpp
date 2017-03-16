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
#include <list>
#include <stack>
#include <valarray>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef unsigned long long UInt;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }
int in() { int x; scanf("%d", &x); return x; }
double fin() { double x; scanf("%lf", &x); return x; }
Int lin() { Int x; scanf("%lld", &x); return x; }

int B, N, M[1024];

Int num(Int t) {
  Int res = 0;
  for (int i = 0; i < B; ++i) {
    res += t / M[i] + 1;
  }
  return res;
}

void solve() {
  B = in();
  N = in();

  for (int i = 0; i < B; ++i) {
    M[i] = in();
  }

  Int lo = -1, hi = INFLL;
  while (hi - lo > 1) {
    Int mid = (hi + lo) / 2;
    if (num(mid) >= N) {
      hi = mid;
    } else {
      lo = mid;
    }
  }

  Int idx = N - num(hi - 1);
  for (int i = 0; i < B; ++i) {
    if (hi % M[i] == 0) {
      if (--idx == 0) {
        printf("%d\n", i + 1);
        return;
      }
    }
  }
}

int main() {
  int TC = in();

  for (int CN = 1; CN <= TC; ++CN) {
    printf("Case #%d: ", CN);
    solve();
  }

  return 0;
}
