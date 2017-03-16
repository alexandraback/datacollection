#include <set>
#include <bitset>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <climits>
#include <cstring>
#include <ctime>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <sstream>
#define MID(x,y) ( ( x + y ) >> 1 )
#define L(x) ( x << 1 )
#define R(x) ( x << 1 | 1 )
#define REP(i,t) for(int i=0; i<(t); i++)
#define FOR(i,s,t) for(int i=(s); i<(t); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define FORL(i,s,t) for(L i=(s); i<(t); i++)
#define BUG puts("here!!!")
#define STOP system("pause")
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)
#define EPS 1e-11
#define EQ(a, b) (fabs((a) - (b)) <= EPS)
#define POS(a) ((a) >= EPS)
#define NEG(a) ((a) <= -EPS)
#define BG(a, b) ((a) - (b) >= EPS)
#define LS(a, b) ((b) - (a) >= EPS)
#define CLR(a, x) memset( a, x, sizeof( a ) )
#define PI (atan(1.0) * 4)
#define SQ(x) ((x) * (x))
#define DIST(x1, y1, x2, y2) (sqrt(SQ((x1) - (x2)) + SQ((y1) - (y2))))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define setmin(a, b) (a = min(a, b))
#define setmax(a, b) (a = max(a, b))
#define LOG2(x) (log(x) / log(2))
#define XX first.first
#define XY first.second
#define YX second.first
#define YY second.second

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;
typedef pair<double, double> Pd;
typedef pair<int, int> Pi;
typedef pair<LL, LL> Pl;

string s[101];
int main()
{
  int t;
  cin >> t;
  FOR(p, 1, t + 1) {
    int n;
    vector<int> v[101];
    cin >> n;
    REP(i, n) cin >> s[i];
    string last = "";
    int bad = 0;
    REP(i, n) {
      string x = "";
      char prev = ' ';
      int cnt = 0;
      REP(j, s[i].length()) {
        if (prev != s[i][j]) {
          x += s[i][j];
          if (cnt) {
            v[i].pb(cnt);
            cnt = 0;
          }
        }
        prev = s[i][j];
        cnt++;
      }
      if (cnt) v[i].pb(cnt);
      if (i > 0 && x != last) {
        bad = 1;
        break;
      }
      last = x;
    }
    if (bad) {
      cout << "Case #" << p << ": Fegla Won";
    } else {
      int ans = 0;
      REP(i, v[0].size()) {
        int best = 100000000;
        FOR(j, 1, 101) {
          int total = 0;
          REP(k, n) total += abs(v[k][i] - j);
          best = min(best, total);
        }
        ans += best;
      }
      cout << "Case #" << p << ": " << ans;
    }
    cout << endl;
  }
  return 0;
}

