#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

const int MAXR = 16;
const int MAXC = 16;

int mat[MAXR][MAXC];

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int r, c, n;
bool ok(int x, int y) {
  return x >= 0 && x < r && y >= 0 && y < c;
}

int main() {
  int cases;
  scanf("%d", &cases);
  for (int T = 1; T <= cases; ++T) {
    scanf("%d %d %d", &r, &c, &n);
    int ans = INT_MAX;
    for (int i = 0; i < 1 << (r * c); ++i) {
      if (__builtin_popcount(i) != n) continue;
      for (int j = 0; j < r * c; ++j) {
        mat[j / c][j % c] = (i >> j) & 1;
      }
      int cnt = 0;
      for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
          if (mat[i][j] == 0) continue;
          for (int d = 0; d < 4; d += 3) {
            int ii = i + dx[d];
            int jj = j + dy[d];
            if (ok(ii, jj) && mat[ii][jj]) {
              ++cnt;
            }
          }
        }
      }
      ans = min(ans, cnt);
    }
    printf("Case #%d: %d\n", T, ans);
  }
}