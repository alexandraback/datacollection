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
#include <utility>
#include <functional>
#include <bitset>
#include <deque>
#include <tuple>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef pair<int, int> pii;

#define FOR(i, x, y) for(ll i=x; i<=y; i++)
#define FORD(i, x, y) for (ll i = x; i >= y; --i)
#define REP(i, n) for(ll i=0; i<n; i++)
#define REPD(i, n) for(ll i = n - 1; i >= 0; --i) 

#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define UNIQ(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define SZ(c) (int)(c).size()
#define CONTAINS(s,obj) (s.find(obj)!=s.end())

#define CLEAR(x) memset(x,0,sizeof x)
#define COPY(from,to) memcpy(to, from, sizeof to)

#define sq(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define X first
#define Y second

const double eps = 1.0e-11;
const double pi = acos(-1.0);

void solve() {
  int n;
  cin >> n;
  string x;
  vector<string> g(n);
  vector<vector<int> > c(n);
  REP(i, n) {
    cin >> x;
    char last = '0';
    int cnt = 0;
    REP(j, SZ(x)) {
      if (x[j] != last) {        
        if (cnt) c[i].push_back(cnt), g[i].push_back(last);
        last = x[j];
        cnt = 1;
      }
      else ++cnt;
    }
    if (cnt) c[i].push_back(cnt), g[i].push_back(last);
  }

  SORT(g);
  if (g[0] != g[n - 1]) cout << "Fegla Won\n";
  else {
    int res = 0;
    REP(i, SZ(c[0])) {
      vector<int> t;      
      REP(j, n) {
        t.push_back(c[j][i]);
      }
      SORT(t);
      int pivot = t[n / 2];
      REP(j, n) {
        if (j < n / 2) res += pivot - t[j];
        else res += t[j]  - pivot;
      }
    }
    cout << res << endl;
  }
}

int main() {
  freopen("A-small-attempt0.in", "r", stdin);
  freopen("a.out", "w", stdout);
  int tests;
  scanf("%d", &tests);
  REP(i, tests) {
    printf("Case #%d: ", int(i + 1));
    solve();
  }
  return 0;
}