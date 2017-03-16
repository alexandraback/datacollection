#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <cmath>
#include <queue>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

ll m[1002];
int b;
ll n;

ll cnt(ll t)
{
  if (t < 0)
    return 0;
  ll res = 0;
  for (int i = 0; i < b; ++i)
  {
    res += t / m[i];
  }
  return res + b;
}

int main()
{
  std::ios::sync_with_stdio(false);
  freopen("B-large.in", "r", stdin);
  freopen("Bresultcpp.txt", "w", stdout);
  int T;
  scanf("%d", &T);

  for (int i = 0; i < T; ++i)
  {
    scanf("%d%lld", &b, &n);
    for (int i = 0; i < b; ++i)
    {
      scanf("%lld", &m[i]);
    }

    ll mn = m[0];
    for (int i = 0; i < b; ++i)
      mn = std::min(mn, m[i]);
    ll l = 0;
    ll r = mn * n + 1;
    while (l < r)
    {
      ll mid = l + ((r - l) / 2);
      ll val = cnt(mid);
      if (val < n)
        l = mid + 1;
      else
        r = mid;
    }

    if (cnt(r) < n || cnt(r-1) >= n)
    {
      std::cerr << "FUUCK " << i + 1 << std::endl;
    }

    n -= cnt(r-1);
    int pos = 0;
    for (int i = 0; i < b; ++i)
    {
      if (r % m[i] == 0)
        --n;
      if (n == 0)
      {
        pos = i + 1;
        break;
      }
    }

    printf("Case #%d: %d", i + 1, pos);

    printf("\n");
  }

  fclose(stdin);
  fclose(stdout);

  return 0;
}