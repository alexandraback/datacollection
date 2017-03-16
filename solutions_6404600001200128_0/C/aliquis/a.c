#include <stdio.h>

void solve(void)
{
  unsigned int N;
  unsigned int i;
  int ms[1000];
  int a = 0, b = 0;
  int last = 0, max_drop = 0;
  scanf("%u", &N);
  for (i = 0; i < N; ++i) {
    int drop;
    scanf("%d", ms+i);
    drop = last - ms[i];
    if (drop < 0)
      drop = 0;
    if (max_drop < drop)
      max_drop = drop;
    a += drop;
    last = ms[i];
  }
  for (i = 0; i < N - 1; ++i) {
    if (ms[i] < max_drop)
      b += ms[i];
    else
      b += max_drop;
  }
  printf("%d %d\n", a, b);
}

int main(void)
{
  unsigned int T;
  unsigned int casenr;
  scanf("%u", &T);
  for (casenr = 1; casenr <= T; ++casenr) {
    printf("Case #%u: ", casenr);
    solve();
  }
  return 0;
}
