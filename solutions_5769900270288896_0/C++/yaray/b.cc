#include <algorithm>
#include <cstdio>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define REP1(i, n) for (int i = 1; i <= (n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

typedef long long ll;

int ri()
{
  int x;
  scanf("%d", &x);
  return x;
}

ll rl()
{
  ll x;
  scanf("%lld", &x);
  return x;
}

const int N = 1000000;
int s[N+1];

int main()
{
  int cases = ri();
  REP1(cc, cases) {
    int r = ri(), c = ri(), n = ri(), m = r*c, ans = m*2;
    REP(mask, 1 << m) {
      int s = 0, pop = 0;
      REP(i, m)
        if (mask & 1 << i) {
          pop++;
          if (i%c+1 < c && mask & 1 << i+1)
            s++;
          if (i+c < m && mask & 1 << i+c)
            s++;
        }
      if (pop == n)
        ans = min(ans, s);
    }
    printf("Case #%d: %d\n", cc, ans);
  }
}
