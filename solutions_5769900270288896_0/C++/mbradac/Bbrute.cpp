#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define LOG(x) cerr << #x << " = " << (x) << "\n"

typedef long long llint;
typedef pair<int,int> pii;
const int INF = 1e9;

void update(int &x, int y) {
  if (x > y) x = y;
}

int dp[17][17][1 << 5][17][2];

void solve() {
  int r, s, n;
  scanf("%d%d%d", &r, &s, &n);
  if (s > r) swap(r, s);

  for (int i = 0; i < r + 1; ++i)
    for (int j = 0; j < s + 1; ++j)
      for (int mask = 0; mask < (1 << s); ++mask)
        for (int k = 0; k < n + 1; ++k)
          for (int l = 0; l < 2; ++l)
            dp[i][j][mask][k][l] = INF;

  dp[0][0][0][0][0] = 0;

  for (int i = 0; i < r; ++i)
    for (int j = 0; j < s; ++j)
      for (int mask = 0; mask < (1 << s); ++mask)
        for (int l = 0; l < 2; ++l) {
          int nj = (j + 1) % s;
          int ni = i + (nj == 0);

          for (int k = 0; k <= n; ++k) {
            if (k != n) {
              int nmask = (mask >> 1) | (1 << (s - 1));
              int price = (mask & 1) + (l && j != 0);
              update(dp[ni][nj][nmask][k+1][1], dp[i][j][mask][k][l] + price);
            }
            update(dp[ni][nj][mask >> 1][k][0], dp[i][j][mask][k][l]);
          }
        }

  int ans = INF;
  for (int i = 0; i < (1 << s); ++i)
    for (int j = 0; j < 2; ++j) 
      ans = min(dp[r][0][i][n][j], ans);
  printf("%d\n", ans);
}

int main() {
  int t; scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    printf("Case #%d: ", i+1);
    solve();
  }
  return 0;
}

