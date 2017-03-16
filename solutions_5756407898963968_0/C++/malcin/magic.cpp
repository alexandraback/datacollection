#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <numeric>
#include <cmath>
using namespace std;

typedef vector <int > VI;
typedef vector < VI > VVI;
typedef long long LL;
typedef vector < LL > VLL;
typedef vector < double > VD;
typedef vector < string > VS;
typedef pair<int,int> PII;
typedef vector <PII> VPII;
typedef istringstream ISS;

#define ALL(x) x.begin(),x.end()
#define REP(i,n) for (int i=0; i<(n); ++i)
#define FOR(var,pocz,koniec) for (int var=(pocz); var<=(koniec); ++var)
#define FORD(var,pocz,koniec) for (int var=(pocz); var>=(koniec); --var)
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define PB push_back
#define PF push_front
#define MP(a,b) make_pair(a,b)
#define ST first
#define ND second
#define SIZE(x) (int)x.size()


int main(){
  int te;
  scanf("%d", &te);
  FOR(ii, 1, te) {
    int x[17], t[4][4], s;
    REP(i, 17) x[i] = 0;
    REP(z,2){
      scanf("%d", &s);
      REP(a, 4) REP(b, 4) scanf("%d", &t[a][b]);
      REP(b, 4) x[t[s-1][b]]++;
    }
    int res = 0;
    FOR(i, 1, 16){
      if (x[i] == 2){
        if (res == 0) res = i;
        else res = -i;
      }
    }
    if (res > 0) {
      printf("Case #%d: %d\n", ii, res);
    } else if (res == 0) {
      printf("Case #%d: Volunteer cheated!\n", ii);
    } else {
      printf("Case #%d: Bad magician!\n", ii);
    }
  }
	return 0;
}
