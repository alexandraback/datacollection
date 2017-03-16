/* Written by Filip Hlasek 2015 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

vector<int> nb;
int solve(int R, int C, int N, int which) {
  if ((R * C + 1) / 2 >= N) return 0;
  nb.clear();
  REP(i, R) REP(j, C) if ((i + j) % 2 == which) {
    int n = 4;
    if (i == 0) n--;
    if (i == R - 1) n--;
    if (j == 0) n--;
    if (j == C - 1) n--;
    nb.push_back(n);
  }
  sort(nb.begin(), nb.end()); reverse(nb.begin(), nb.end());
  int ans = (R - 1) * C + (C - 1) * R;
  REP(i, R * C - N) ans -= nb[i];
  return ans;
}

int solve_slow(int R, int C, int N) {
  int best = R * C * 2;
  REP(mask, 1 << (R * C)) {
    int cnt = 0;
    REP(i, R * C) if (mask & (1 << i)) cnt++;
    if (cnt != N) continue;
    int ans = 0;
    REP(i, R) REP(j, C) if (mask & (1 << (i * C + j))) {
      FOR(dx, -1, 1) FOR(dy, -1, 1) if (dx * dx + dy * dy == 1) {
        int x = i + dx, y = j + dy;
        if (x < 0 || x >= R || y < 0 || y >= C) continue;
        if (mask & (1 << (x * C + y))) ans ++;
      }
    }
    /*
    if (best > ans) {
      REP(i, R) {
        REP(j, C) printf("%d", (int)((mask & (1 << (i * C + j))) != 0));
        printf("\n");
      }
      printf("-----------\n");
    }
    */
    best = min(best, ans / 2);
  }
  return best;
}

int solve_fast(int R, int C, int N) { return min(solve(R, C, N, 0), solve(R, C, N, 1)); }

int main(int argc, char *argv[]) {
  /*
  FOR(R, 1, 25) FOR(C, 1, R) if (R * C < 25) FOR(N, R * C / 2, R * C - 1) {
    if (solve_fast(R, C, N) != solve_slow(R, C, N)) {
      printf("%d %d %d\n", R, C, N);
    }
  }
  printf("ok\n");
  */
  int T;
  scanf("%d", &T);
  FOR(t, 1, T) {
    int R, C, N;
    scanf("%d%d%d", &R, &C, &N);
    printf("Case #%d: %d\n", t, solve_fast(R, C, N));
  }
  return 0;
}
