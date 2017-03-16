
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

int n, in[MAXN];

int solve1()
{
  int res = 0;
  REP(i, 2, n)
    res += max(0, in[i-1] - in[i]);
  return res;
}

const int INF = 100000000;

int solve2()
{
  int res = 0;
  int mxRat = 0;
  REP(i, 2, n)
    mxRat = max(mxRat, in[i-1] - in[i]);
  REP(i, 1, n-1)
  {
    res += min(mxRat, in[i]);
  }
  return res;
}

int main()
{
  int tc;scanf("%d", &tc);
  REP(_, 1, tc)
  {printf("Case #%d: ", _);
    scanf("%d", &n);
    REP(i, 1, n) scanf("%d", in+i);
    int a1 = solve1();
    int a2 = solve2();
    printf("%d %d\n", a1, a2);
  }
}
