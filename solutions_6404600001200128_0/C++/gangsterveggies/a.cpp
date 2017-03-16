#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

typedef long long int lld;
typedef pair<int, int> pii;
typedef pair<pii, pii> line;

#define F first
#define S second

int mu[1005];

int main()
{
  int i;
  int t, T;

  scanf("%d", &T);

  for (t = 1; t <= T; t++)
  {
    int n;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
      scanf("%d", &mu[i]);

    int ans1 = 0;
    for (i = 1; i < n; i++)
      if (mu[i] < mu[i - 1])
        ans1 += mu[i - 1] - mu[i];

    double rate = 0;
    for (i = 1; i < n; i++)
      if (mu[i - 1] > mu[i])
        rate = max(rate, (mu[i - 1] - mu[i]) / 10.0);

    int ans2 = 0;
    double tot = 0;
    for (i = 1; i < n; i++)
      tot += min(1.0 * mu[i - 1], rate * 10);

    ans2 = tot;

    printf("Case #%d: %d %d\n", t, ans1, ans2);
  }

  return 0;
}
