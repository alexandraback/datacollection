#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define FN "A-small-attempt0"

int main()
{
  freopen(FN ".in","r",stdin);
  freopen(FN ".out","w",stdout);

  int tests;
  scanf("%d",&tests);
  for (int test = 1; test<=tests; test++)
  {
    int a[20];
    CLEAR(a);
    REP(it,2) {
      int r;
      scanf("%d",&r);
      --r;
      REP(i,4) REP(j,4)
      {
        int x;
        scanf("%d",&x);
        if (i == r)
          ++a[x];
      }
    }
    int cnt = 0;
    int res = -1;
    REP(i,20) if (a[i]==2)
    {
      ++cnt;
      res = i;
    }
    printf("Case #%d: ",test);
    if (cnt == 0)
      printf("Volunteer cheated!\n");
    else if (cnt == 1)
      printf("%d\n",res);
    else
      printf("Bad magician!\n");
  }
  return 0;
}
