#include <cstdio>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <iostream>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

namespace Alg1 {
  int cnt[5];

  void add(int x, int y, int R, int C) {
    if ((x+y) % 2) return;

    int k = 0;
    REP(i, 4) {
      int a = x+dx[i];
      int b = y+dy[i];
      if (a >= 0 && a < R && b >= 0 && b < C) ++k;
    }
    ++cnt[k];
  }

  void solve(int R, int C) {
    if (R > C) swap(R, C);
    REP(i, 5) cnt[i] = 0;

    if (R == 1) {
      cnt[2] = (C-1)/2;
      if (C%2 == 0) ++cnt[1];
      return;
    }
    assert(R >= 2 && C >= 2);

    REP(i, R) {
      if (i == 0 || i == R-1) {
        REP(j, C) add(i, j, R, C);
      } else {
        add(i, 0, R, C);
        add(i, C-1, R, C);
      }
    }

    R -= 2;
    C -= 2;
    REP(i, R) {
      int k = (C+1) / 2;
      cnt[4] += i%2 ? C-k : k;
    }
  }

  int run(int R, int C, int N) {
    solve(R, C);
    N = R*C - N;

    int ans = (R-1)*C + R*(C-1);
    for (int i = 4; i >= 0; --i) {
      int k = min(N, cnt[i]);
      ans -= k*i;
      N -= k;
    }
    return ans;
  }
}

namespace Alg2 {
  int cnt[5];

  void add(int x, int y, int R, int C) {
    if ((x+y) % 2 == 0) return;

    int k = 0;
    REP(i, 4) {
      int a = x+dx[i];
      int b = y+dy[i];
      if (a >= 0 && a < R && b >= 0 && b < C) ++k;
    }
    ++cnt[k];
  }

  void solve(int R, int C) {
    if (R > C) swap(R, C);
    REP(i, 5) cnt[i] = 0;

    if (R == 1) {
      cnt[2] = (C-1)/2;
      if (C%2 == 0) ++cnt[1];
      return;
    }
    assert(R >= 2 && C >= 2);

    REP(i, R) {
      if (i == 0 || i == R-1) {
        REP(j, C) add(i, j, R, C);
      } else {
        add(i, 0, R, C);
        add(i, C-1, R, C);
      }
    }

    R -= 2;
    C -= 2;
    REP(i, R) {
      int k = (C+1) / 2;
      cnt[4] += i%2 ? k : C-k;
    }
  }

  int run(int R, int C, int N) {
    solve(R, C);
    N = R*C - N;

    int ans = (R-1)*C + R*(C-1);
    for (int i = 4; i >= 0; --i) {
      int k = min(N, cnt[i]);
      ans -= k*i;
      N -= k;
    }
    return ans;
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int tt = 1; tt <= T; ++tt, fflush(stdout)) {
    int R, C, N; scanf("%d%d%d", &R, &C, &N);

    int ans = min(Alg1::run(R, C, N), Alg2::run(R, C, N));
    printf("Case #%d: %d\n", tt, ans);
  }
  return 0;
}
