#include <bits/stdc++.h>

using namespace std;

bool g[16][16];

int main() {
  freopen("B.in", "rt", stdin);
  freopen("B.out", "wt", stdout);
  int t; scanf("%d", &t);
  for(int test = 1; test <= t; ++test) {
    int r, c, n;
    scanf("%d %d %d", &r, &c, &n);
    int a = r * c;
    int ans = 1 << 30;
    for(int m = 0; m < (1 << a); ++m) {
      if(__builtin_popcount(m) != n) continue;
      memset(g, 0, sizeof g);
      for(int i = 0; i < a; ++i) {
        if((m >> i) & 1) {
          g[i / c][i % c] = 1;
        }
      }
      int res = 0;
      for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
          if(i + 1 < r && g[i][j] && g[i + 1][j]) res++;
          if(j + 1 < c && g[i][j] && g[i][j + 1]) res++;
        }
      }
      if(ans > res) {
        ans = res;
      }
    }
    printf("Case #%d: %d\n", test, ans);
  }
  return 0;
}
