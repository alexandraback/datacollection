#include <cassert>
#include <cstdio>

int main() {
  int tn;
  assert (scanf ("%d", &tn) == 1);
  for (int t = 1; t <= tn; t++) {
    int r, w, n;
    assert (scanf ("%d%d%d", &r, &w, &n) == 3);
    int ans1 = -1;
    if (r * w < 20) {
      ans1 = n * 4;
      for (int p = 0; p < (1 << (r * w)); p++) {
        int k = 0, res = 0;
        for (int i = 0; i < (r * w); i++) {
          if ((p & (1 << i)) == 0)
            continue;
          k++;
          if (i % r != (r - 1) && i + 1 < (r * w) && (p & (1 << (i + 1))) != 0)
            res++;
          if (i + r < (r * w) && (p & (1 << (i + r))) != 0)
            res++;
        }
        // fprintf (stderr, "p=%d, k=%d, res=%d\n", p, k, res);
        if (k == n && ans1 > res)
          ans1 = res;      }
    }
    printf ("Case #%d: %d\n", t, ans1);
  }
  return 0;
}

