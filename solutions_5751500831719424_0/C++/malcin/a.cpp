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

char s[110][2000];
int p[110];

int main(){
  int te; scanf("%d", &te);
  FOR(ii,1,te){
    printf("Case #%d: ", ii);
    int n; scanf("%d", &n);
    REP(i,n) scanf("%s",&s[i][0]);
    REP(i,n) p[i] = 0;
    int res = 0;
    while(res >= 0){
      char c = s[0][p[0]];
      REP(i,n){
        if (s[i][p[i]] != c){
          res = -1;
          break;
        }
      }
      if (res < 0 || !c) break;
      vector<int> v;
      REP(i, n){
        int x = 0;
        while (s[i][p[i]] == c) { p[i]++; x++; }
        v.PB(x);
      }
      sort(ALL(v));
      int med = v[n/2];
      FOREACH(it, v){
        if (*it < med) res += med - *it;
        else res += *it - med;
      }
    }
    if (res < 0) printf ("Fegla Won\n");
    else printf("%d\n", res);
  }
	return 0;
}
