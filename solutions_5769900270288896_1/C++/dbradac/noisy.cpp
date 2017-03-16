#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
  int tt;

  scanf("%d", &tt);

  for (int i=1; i<=tt; i++) {
    int r, c, n, rje=0, pocn;
    scanf("%d%d%d", &r, &c, &n); pocn = n;
  
    if (r > c)
      swap(r, c);

    if (r == 1) {
      printf("Case #%d: %d\n", i, max(0, c - 1 - 2 * (c - n)));
      continue;
    }

    n -= (r * c + 1) / 2;
    if (n > 0) {
      if (!((r * c) % 2)) {
        rje += min(2 * n, 4);
        n -= 2;
      }
      if (n > 0) {
        if (!((r * c) % 2)) {
          rje += min(3 * (r + c - 4), 3 * n);
          n -= r + c - 4;
        }
        else {
          rje += min(3 * (r + c - 2), r * n);
          n -= r + c - 2;
        }
      }
      if (n > 0)
        rje += 4 * n;
    }
  
    int rez = rje;
    rje = 0;
    n = pocn;
  
    if ((r * c) % 2) {
      n -= (r * c) / 2;
      if (n > 0) {
        rje += min(2 * n, 8);
        n -= 4;
      }
      if (n > 0) {
        rje += min(3 * (r + c - 6), n * 3);
        n -= r + c - 6;
      }
      if (n > 0)
        rje += 4 * n;

      rez = min(rez, rje);
    }

    printf("Case #%d: %d\n", i, rez);
  }

  return 0;
}
