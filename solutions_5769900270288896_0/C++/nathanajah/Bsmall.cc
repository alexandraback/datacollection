#include <bits/stdc++.h>
using namespace std;

int score(int mask, int n, int m) {
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i < n - 1) {
        int idx1 = m * i + j;
        int idx2 = m * (i+1) + j;
        if (((mask & (1<<idx1)) != 0) && ((mask & (1<<idx2)) != 0)) {
          res++;
        }
      }
      if (j < m - 1) {
        int idx1 = m * i + j;
        int idx2 = m * i + j + 1;
        if (((mask & (1<<idx1)) != 0) && ((mask & (1<<idx2)) != 0)) {
          res++;
        }
      }
    }
  }
  return res;
}
int main() {
  int t, n, m, k;
  scanf("%d", &t);
  int cs =0;
  while (t--) {
    scanf("%d %d %d", &n, &m, &k);
    ++cs;
    int res = 1000000000;
    for (int i = 0; i < (1 <<(n*m)); i++) {
      if (__builtin_popcount(i) == k) {
        res = min(res, score(i, n, m));
      }
    }
    printf("Case #%d: %d\n", cs, res);
  }
}
