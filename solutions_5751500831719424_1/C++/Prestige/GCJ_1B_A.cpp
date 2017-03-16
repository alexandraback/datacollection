#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <complex>
#include <ctime>
#include <stack>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector< VI > VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
  
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define RREP(i, n) for(int i = (n) - 1; i >= 0; --i)
#define FOR(i, x, y) for(int i = (x); i <= (y); ++i)
#define RFOR(i, x, y) for(int i = (x); i >= (y); --i)
#define SZ(a) (ll)(a).size()
#define ALL(a) (a).begin(),(a).end()
#define SORT(a) sort(ALL(a)) 
#define CLEAR(x) memset(x, 0, sizeof x);
#define COPY(FROM, TO) memcpy(TO, FROM, sizeof TO);
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define pb push_back
#define mk make_pair
#define sqr(x) ((x)*(x))
#define X first
#define Y second
const long double pi=acos(-1.0);
const double EPS = 1E-9;
const int INF = 2 * (1e+9) + 1;
const int NMAX = 1000000;
const int MOD = (1e+9) + 7;

int n, m, t;
int main () {
  freopen ("A-large(1).in", "r", stdin);
  freopen ("A-large.out", "w", stdout);
  cin >> t;
  REP (test, t) {
    cin >> n;
    vector<string> arr(n), new_arr(n);
    VVI cnt(n);
    REP (i, n) cin >> arr[i];
    REP (i, n) {
      char prev = '#';
      REP (j, SZ(arr[i])) {
        if (arr[i][j] != prev) {
          new_arr[i] += arr[i][j], prev = arr[i][j];
          cnt[i].pb(1);
        } else cnt[i][SZ(cnt[i]) - 1]++;
      }
    }
    int minn = INF;
    REP (i, n) REP (j, n) if (new_arr[i] != new_arr[j]) minn = -1;
    if (minn == -1) {
      printf ("Case #%d: Fegla Won\n", test + 1);
      continue;
    }
    int cost = 0;
    REP (j, SZ(cnt[0])) {
      int min_cost = INF;
      REP (count, 101) {
        int cur = 0;
        REP (i, n) cur += abs(count - cnt[i][j]);
        min_cost = min (cur, min_cost);
      }
      cost += min_cost;
    }
    printf ("Case #%d: %d\n", test + 1, cost);
  }
}
/*
1
3
aaabbb
ab
aabb
*/