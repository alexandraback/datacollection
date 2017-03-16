#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <numeric>
#include <memory.h>
#include <cstdio>
#include <assert.h>
#include <limits>

using namespace std;

#define pb push_back
#define INF 1011111111
#define FOR(i, a, b) for (int _n(b), i(a); i < _n; i++)
#define rep(i, n) FOR(i, 0, n)
#define CL(a, v) memset((a), (v), sizeof(a))
#define mp make_pair
#define X first
#define Y second
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> pii;

/*** TEMPLATE CODE ENDS HERE */

VI a[10010];

int try_it(int R, int C, int N) {
  if (N <= 0) return 0;
  rep(i, 10010) a[i].clear();
  rep(i, R) a[i] = VI(C, 0);
  rep(i, R) rep(j, C) {
    if ((i + j) % 2 == 0) {
      a[i][j] = 1;
      --N;
      if (N <= 0) return 0;
    }
  }
  int ans = 0;
  for (; N > 0; --N) {
    int d = 5;
    int ii = -1, jj = -1;
    rep(i, R) rep(j, C) if (a[i][j]) {
      int cnt = 0;
      for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
          if (abs(dx) + abs(dy) == 0) continue;
          int x = i + dx;
          int y = j + dy;
          if (x < 0 || y < 0 || x >= R || y >= C) continue;
          cnt += a[x][y];
        }
      }
      if (cnt < d) {
        d = cnt;
        ii = i;
        jj = j;
      }
    }
    assert(ii != -1);
    ans += d + 1;
    a[ii][jj] = 1;
  }
  return ans;
}

void solve() {
  int R, C, N;
  cin >> R >> C >> N;
  int ans = min(try_it(R, C, N), try_it(C, R, N));
  cout << ans;
}

void solve_easy() {
  int A[22][22];
  int R, C, N;
  cin >> R >> C >> N;
  int K = R * C;
  int ans = 1000001;
  FOR(mask, 0, 1 << K) {
    int k = 0;
    CL(A, 0);
    int put = 0;
    rep(r, R) rep(c, C) {
      if (mask & (1 << k)) A[r][c] = 1, put++;
      ++k;
    }
    if (put != N) continue;
    int cnt = 0;
    rep(r, R) rep(c, C) if (A[r][c]) {
      for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
          if (abs(dx) + abs(dy) != 1) continue;
          int x = r + dx;
          int y = c + dy;
          if (x < 0 || y < 0 || x >= R || y >= C) continue;
          cnt += A[x][y];
        }
      }
    }
    ans = min(cnt / 2, ans);
  }
  cout << ans;
}

int main() {
#ifdef LOCAL_HOST
  //  freopen("input.txt", "r", stdin);
  freopen("B-small-attempt1.in", "r", stdin);
  freopen("B-small-attempt1.out", "w", stdout);
#endif

  cout.sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << "Case #" << t << ": ";
    solve_easy();
    cout << endl;
  }

  return 0;
}
