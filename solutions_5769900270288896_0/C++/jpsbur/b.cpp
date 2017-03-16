#include <cstdio>
#include <cassert>

int main () {
  int nt;
  assert (scanf ("%d", &nt) == 1);
  for (int tt = 1; tt <= nt; ++tt) {
    int r, c, n;
    assert (scanf ("%d%d%d", &r, &c, &n) == 3);
    int res = r * c * 4;
    for (int i = 0; i < (1 << (r * c)); ++i) {
      int cnt = 0, cc = 0;
      for (int j = 0; j < r; ++j) {
        for (int k = 0; k < c; ++k) {
          if ((i >> (j * c + k)) & 1) {
            ++cnt;
            if (j < r - 1 && ((i >> ((j + 1) * c + k)) & 1)) {
              ++cc;
            }
            if (k < c - 1 && ((i >> (j * c + k + 1)) & 1)) {
              ++cc;
            }
          }
        }
      }
      if (cnt == n && cc < res) {
        res = cc;
      }
    }
    printf ("Case #%d: %d\n", tt, res);
  }
  return 0;
}
