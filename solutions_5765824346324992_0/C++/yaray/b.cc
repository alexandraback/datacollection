#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define REP1(i, n) for (int i = 1; i <= (n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long ll;

int ri()
{
  int x;
  scanf("%d", &x);
  return x;
}

const int M = 1000;
ll a[M];
pair<ll, int> b[M];

ll gcd(ll x, ll y)
{
  ll d;
  while (y)
    d = x%y, x = y, y = d;
  return x;
}

int bisect(int m, ll n, ll lcm)
{
  ll lo = 0, hi = lcm, c, cc;
  while (lo < hi) {
    ll mi = (lo+hi)>>1;
    c = 0;
    REP(i, m)
      c += mi/a[i]+!!(mi%a[i]);
    if (c < n)
      lo = mi+1;
    else
      hi = mi;
  }
  lo--;
  REP(i, m)
    n -= lo/a[i]+!!(lo%a[i]);
  REP(i, m)
    if (! (lo%a[i]) && !--n)
      return i;
  REP(i, m)
    b[i] = make_pair(lo%a[i], i);
  sort(b, b+m);
  return b[n].se+1;
}

int main()
{
  int cases = ri();
  REP1(cc, cases) {
    int m = ri(), n = ri();
    ll lcm = 1, unit = 0;
    REP(i, m) a[i] = ri(), lcm = lcm*(a[i]/gcd(a[i], lcm));
    REP(i, m) unit += lcm/a[i];
    n %= unit;
    if (! n) n = unit;
    printf("Case #%d: %d\n", cc, bisect(m, n, lcm) + 1);
  }
}
