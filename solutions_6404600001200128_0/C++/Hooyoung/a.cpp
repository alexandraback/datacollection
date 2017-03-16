#include <cstdio>

int M[1001];
int main()
{
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    int N;
    scanf("%d", &N);
    int last = 0, a = 0;
    for (int i = 0; i < N; ++i) {
      scanf("%d", &M[i]);
      if (M[i] < last) {
        a += last - M[i];
      }
      last = M[i];
    }
    int b = 10000 * 1001;
    for (int rate = 0; rate <= 10000; ++rate) {
      int bb = 0;
      for (int i = 1; i < N; ++i) {
        if (M[i] < M[i-1] - rate)
          goto bad;
        if (M[i-1] < rate)
          bb += M[i-1];
        else
          bb += rate;
      }
      if (bb < b)
        b = bb;
bad:;
    }
    printf("Case #%d: %d %d\n", t, a, b);
  }
  return 0;
}
