#include <cstdio>
#include <algorithm>
using namespace std;

int R, C, N, best;
bool path[100][100];
void dfs(int r, int c, int now, ans) {
  if (r == R) {
    if (best == -1 || ans < best) {
      best = ans;
    }
    return ;
  }
  if (c == C-1) {
    path[r][c] = 0;
    dfs(r+1, 0, now, ans);
  }
  path[r][c] = 1;
  dfs(r, c+1, now, ans);
}

void solve() {
  scanf("%d%d%d", &R, &C, &N);
  best = -1;
  dfs(R, C, N);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) {
    printf("Case #%d: ", i);
    solve();
  }
}

