#include <cstdio>

int v[2000];

int t, n;
int a, l, d;
int m1, m2;

int main()
{
  scanf("%d", &t);
  for (int tt = 1; tt <= t; ++tt)
  {
    printf("Case #%d: ", tt);

    scanf("%d", &n);
    m1 = 0;
    l = 0;
    d = 0;
    for (int i = 0; i < n; ++i)
    {
      scanf("%d", &a);
      if (a < l)
        m1 += l - a;
      if (l - a > d)
        d = l - a;
      l = a;

      v[i] = a;
    }

    m2 = 0;
    for (int i = 0; i < n - 1; ++i)
    {
      if (v[i] >= d)
        m2 += d;
      else
        m2 += v[i];
    }

    printf("%d %d\n", m1, m2);
  }

  return 0;
}
