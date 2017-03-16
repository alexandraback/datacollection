#include <stdio.h>

#define min(a,b) ((a) < (b)? (a) : (b))
#define max(a,b) ((a) < (b)? (b) : (a))

int buf[1001];

int main(void) {
  int T;
  scanf("%d", &T);

  for (int t = 1; t <= T; t++) {
    int va = 0,
        vb = 0;
    int maxdelta = 0;

    int n, x, y;
    scanf("%d %d", &n, &x);
    buf[0] = x;
    for (int i = 1; i < n; i++) {
      scanf("%d", &y);
      buf[i] = y;
      va += max(x - y, 0);
      if (x - y > maxdelta) maxdelta = x - y;
      x = y;
    }

    int plate = buf[0],
        count = 0;
    for (int i = 1; i < n; i++) {
      count += min(plate, maxdelta);
      plate = buf[i];
    }
    vb = count;

    printf("Case #%d: %d %d\n", t, va, vb);
  }
}
