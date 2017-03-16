#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

typedef long long int lld;
typedef pair<int, int> pii;
typedef pair<pii, pii> line;

#define F first
#define S second

int seq[2000];
int cur[2000];
int ct[2000000];

int main()
{
  int i, j;
  int t, T;

  scanf("%d", &T);

  for (t = 1; t <= T; t++)
  {
    int b, n;
    scanf("%d %d", &b, &n);

    for (i = 0; i < b; i++)
      scanf("%d", &seq[i]);

    for (i = 0; i < b; i++)
      cur[i] = 0;

    for (i = 0; i < n; i++)
    {
      int fl = 1;
      for (j = 1; j < b; j++)
        if (cur[j] != cur[0])
          fl = 0;

      if (fl && i)
      {
        //printf("Capped at: %d\n", i);
        n %= i;
        if (n == 0)
          n = i;
        break;
      }

      int bs = 0;
      for (j = 1; j < b; j++)
        if (cur[j] < cur[bs])
          bs = j;

//      printf("Chose %d\n", bs);
      cur[bs] += seq[bs];
      ct[i] = bs + 1;
    }

    printf("Case #%d: %d\n", t, ct[n - 1]);
  }

  return 0;
}
