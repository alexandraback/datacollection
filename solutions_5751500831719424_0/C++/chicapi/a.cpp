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
        char al[MAXN][210];
        string s, t;
        cin >> s >> t;
        int maxlen = MAX(t.size(), s.size());
        int i = 0, j = 0, k = 0;
        int op = 0;
        while (i < s.size() || j < t.size()) {
          if (i < s.size() && j < t.size() && s[i] == t[j]) {
            al[0][k] = s[i];
            al[1][k] = t[j];
            i++; j++;
          } else {
            if (i > 0 && i < s.size() && s[i-1] == s[i]) {
              al[0][k] = s[i];
              i++;
              al[1][k] = '0';
              op++;
            } else if (j > 0 && j < t.size() && t[j-1] == t[j]) {
              al[1][k] = t[j];
              j++;
              al[0][k] = '0';
              op++;
            } else {
              cout << "Case #" << ttt+1 << ": Fegla Won" << endl;
              goto _end;
            }
          }
          k++;
        }

        cout << "Case #" << ttt+1 << ": " << op << endl;
_end: ;
    }
    return 0;
}
