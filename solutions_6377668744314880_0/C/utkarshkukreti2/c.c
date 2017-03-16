#include <stdio.h>
#include <stdlib.h>

#define Fi(n) for(int i = 0; i < (n); i++)
#define Fj(n) for(int j = 0; j < (n); j++)
#define Fk(n) for(int k = 0; k < (n); k++)
#define P printf
#define S scanf

typedef long long LL;

enum Side { Left, Right, On };

enum Side which_side(LL ax, LL ay, LL bx, LL by, LL cx, LL cy) {
  LL tmp = (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);
  if(tmp == 0) return On;
  else if (tmp > 0) return Left;
  else return Right;
}

int main() {
  int T;
  S("%d", &T);
  for(int t = 1; t <= T; t++) {
    int n, xs[3003], ys[3003];
    S("%d", &n);
    Fi(n) S("%d %d", &xs[i], &ys[i]);

    P("Case #%d:\n", t);
    Fi(n) {
      int best = 1 << 30;
      Fj(n) {
        if(j == i) continue;
        int left_count = 0, right_count = 0;
        Fk(n) {
          if(k == i) continue;
          switch(which_side(xs[i], ys[i], xs[j], ys[j], xs[k], ys[k])) {
          case Left: left_count++; break;
          case Right: right_count++; break;
          case On: break;
          }
        }
        if(left_count < best) best = left_count;
        if(right_count < best) best = right_count;
      }
      P("%d\n", best);
    }

  }
  return 0;
}
