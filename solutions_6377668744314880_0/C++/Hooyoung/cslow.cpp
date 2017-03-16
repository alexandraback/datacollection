#include <cstdio>

long x[3000], y[3000];

int best(int i, int N)
{
  if (N == 1) { return 0; }
  int out = N;
  for (int j = 0; j < N; ++j) {
    if (j == i) continue;
    int hi = 0, lo = 0;
    for (int k = 0; k < N; ++k) {
      long det = (x[i]-x[k])*(y[j]-y[k]) - (x[j]-x[k])*(y[i]-y[k]);
      if (det > 0L)
        ++hi;
      else if (det < 0L)
        ++lo;
    }
    if (hi < out)
      out = hi;
    if (lo < out)
      out = lo;
  }
  return out;
}
int main()
{
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
      int xt, yt;
      scanf("%d%d", &xt, &yt);
      x[i] = xt;
      y[i] = yt;
    }
    printf("Case #%d:\n", t);
    for (int i = 0; i < N; ++i) {
      printf("%d\n", best(i, N));
    }
  }
  return 0;
}
