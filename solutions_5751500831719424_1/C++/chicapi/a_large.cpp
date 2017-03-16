#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <inttypes.h>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define ST first
#define ND second
#define MP make_pair
#define PB push_back
#define POP pop_back

typedef long long LL;
typedef long double LD;
typedef double D;
typedef pair<int, int> PII;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int, int> MII;
typedef map<int, VI > MIVI;
typedef vector<pair<int, VI > > VPIVI;

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<=(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
#define ZERO(x) memset(x,0,sizeof(x))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a,b) ((a)>(b)?(a-b):(b-a))

#define MAXN 2

int main ()
{

    int T;
    cin >> T;
    REP(ttt, T) {
        int n;
        cin >> n;
        vector<queue<char> > q(101);
        REP(i, n) {
          string s;
          cin >> s;
          // q[i].clear();
          REP(j, s.size()) {
            q[i].push(s[j]);
          }
        }
        int op = 0;
        char lc = 0, c = 0;
        int qempty = 0;
        while (qempty < n) {
          int eq = 0, leq = 0;
          REP(i, n) {
            if (q[i].empty()) continue;
            if (!c) {
              c = q[i].front();
            }
            //cout << q[i].front() << " ";
            if (!lc && c == q[i].front()) {
              q[i].pop();
              if (q[i].empty()) qempty++;
              eq++;
            }
            else if (lc && lc == q[i].front()) {
              q[i].pop();
              if (q[i].empty()) qempty++;
              leq++;
            }
          }
          //cout << " lc: " << lc << " c: " << " eq: " << eq << " leq: " << leq << endl;
          if (!lc && eq < n) {
            cout << "Case #" << ttt+1 << ": Fegla Won" << endl;
            goto _end;
          }
          if (leq) {
            lc = c;
            op += MIN(leq, n - leq);
          } else if (!leq && !eq) {
            lc = 0;
            c = 0;
          } else {
            lc = c;
          }
        }
        cout << "Case #" << ttt+1 << ": " << op << endl;
_end: ;
    }
    return 0;
}
