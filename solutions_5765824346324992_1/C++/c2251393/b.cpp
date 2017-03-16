
// default code for competitive programming
// c2251393 ver 3.141 {{{

// Includes
#include <bits/stdc++.h>

// Defines
#define NAME(x) #x
#define SZ(c) (int)(c).size()
#define ALL(c) (c).begin(), (c).end()
#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define REP(i, s, e) for(int i = (s); i <= (e); i++)
#define REPD(i, s, e) for(int i = (s); i >= (e); i--)
#define DEBUG 1
#define fst first
#define snd second
 
using namespace std;

// Typedefs
typedef double real;
typedef long long ll;
typedef pair<ll, int> pli;
typedef tuple<ll, int> tli;
typedef pair<int, int> pii;
typedef tuple<int, int> tii;
typedef unsigned long long ull;

// Some common const.
const double EPS = -1e8;
const double Pi = acos(-1);
 
// Equal for double
bool inline equ(double a, double b)
{return fabs(a - b) < EPS;}

// }}}
// start ~~QAQ~~

const int MAXN = 1010;

int b;
ll n, in[MAXN];

const ll INF = 10000000000000000ll;

ll check(ll x)
{
  ll res = 0ll;
  REP(i, 1, b) res += ((x + in[i] - 1) / in[i]);
  return res;
}

ll oktime[MAXN];

int main()
{
  int tc;scanf("%d", &tc);
  REP(_, 1, tc)
  {printf("Case #%d: ", _);
    scanf("%d%lld", &b, &n);
    REP(i, 1, b) scanf("%lld", in+i);
    ll lb = 0ll, ub = INF, atime = 0ll, acnt = 0ll;
    while(lb <= ub)
    {
      ll mid = (lb + ub) / 2ll;
      ll cnt = check(mid);
      if(cnt < n)
      {
        atime = mid;
        acnt = cnt;
        lb = mid+1ll;
      }
      else ub = mid - 1ll;
    }
    REP(i, 1, b)
      oktime[i] = in[i] * ((atime + in[i] - 1ll) / in[i]);
    int id = 0;
    for(ll i = acnt+1ll; i <= n; i++)
    {
      int tid = 0;
      ll mnT = INF;
      REP(j, 1, b) if(oktime[j] < mnT)
      {
        mnT = oktime[j];
        tid = j;
      }
      oktime[tid] += in[tid];
      if(i == n)
      {
        id = tid;
        break ;
      }
    }
    printf("%d\n", id);
  }
}

