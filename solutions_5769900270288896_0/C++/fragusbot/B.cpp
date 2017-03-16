#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>

using namespace std;

int n;
int m;
int k;
int a[25][25];

int go(int i, int j, int kk) {
  if (i == n) {
    if (kk != k) {
      return 123456;
    }
    int cnt = 0;
    for (int ii = 0; ii < n; ++ii) {
      for (int jj = 0; jj < m; ++jj) {
        if (a[ii][jj] == 0) {
          continue;
        }
        for (int di = -1; di <= 1; ++di) {
          for (int dj = -1; dj <= 1; ++dj) {
            if (abs(di) + abs(dj) != 1) {
              continue;
            }
            int ni = ii + di;
            int nj = jj + dj;
            if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
              if (a[ni][nj] == 1) {
                ++cnt;
              }
            }
          }
        }
      }
    }
    return cnt / 2;
  }
  int ni = (j == m - 1 ? i + 1 : i);
  int nj = (j == m - 1 ? 0 : j + 1);
  int res = 123456;
  if (kk < k) {
    a[i][j] = 1;
    res = min(res, go(ni, nj, kk + 1));
  }
  a[i][j] = 0;
  res = min(res, go(ni, nj, kk));
  return res;
}

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int cc = 1; cc <= tt; ++cc) {
    printf("Case #%d: ", cc);
    scanf("%d %d %d", &n, &m, &k);
    printf("%d\n", go(0, 0, 0));
  }
  return 0;
}
