#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
#include <string>

using namespace std;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long double ld;

long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}

inline int myrand() {
  return abs((rand() << 15) ^ rand());
}

inline int rnd(int x) {
  return myrand() % x;
}

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())
#define TASKNAME "text"

const int INF = (int)1e9 + 1;
const ld EPS = 1e-9;

void precalc() {
}

int w, h, n;

bool read() {
  if (scanf("%d%d%d", &w, &h, &n) < 3) {
    return 0;
  }
  return 1;
}

const int maxn = 16;
int a[maxn][maxn];

void solve() {
  assert(w * h <= maxn);
  int res = INF;
  for (int mask = 0; mask < (1 << (w * h)); ++mask) {
    if (__builtin_popcount(mask) != n) {
      continue;
    }
    for (int i = 0, cur = 0; i < w; ++i) {
      for (int j = 0; j < h; ++j, ++cur) {
        a[i][j] = ((mask >> cur) & 1);
      }
    }
    int cur = 0;
    for (int i = 0; i < w; ++i) {
      for (int j = 0; j < h - 1; ++j) {
        cur += (a[i][j] && a[i][j + 1]);
      }
    }
    for (int i = 0; i < w - 1; ++i) {
      for (int j = 0; j < h; ++j) {
        cur += (a[i][j] && a[i + 1][j]);
      }
    }
    res = min(res, cur);
  }
  printf("%d\n", res);
}

int main() {
  srand(rdtsc());
#ifdef DEBUG
  freopen(TASKNAME".out", "w", stdout);
  assert(freopen(TASKNAME".in", "r", stdin));
#endif

  precalc();
  int maxt;
  while (scanf("%d", &maxt) == 1) {
    for (int t = 0; t < maxt; ++t) {
      assert(read());
      printf("Case #%d: ", t + 1);
      solve();
#ifdef DEBUG
      eprintf("%.18lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
    }
  }
  return 0;
}
