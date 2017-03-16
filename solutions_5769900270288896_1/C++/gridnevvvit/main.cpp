#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <algorithm>
#include <bitset>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

#define forn(i, n) for(int i = 0; i< int(n); i++)
#define ford(i, n) for(int i = int(n) - 1; i >= 0; i--)
#define foreach(it, a) for(__typeof((a).begin()) it = a.begin(); it != a.end(); it++)

template<typename X> X abs(X a) { if (a < 0) return -a; return a; }
template<typename X> X sqr(X a) { return a * a; }
template<typename X> bool hasbit(X mask, int pos) { return (mask >> pos) & 1; }

#define sz(a) int((a).size())
#define all(a) (a).begin(),(a).end()
#define mp make_pair
#define pb push_back
#define ft first
#define sc second

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = 1000000000;
const ld EPS = 1e-9;
const ld PI = ld(3.1415926535897932384626433832795);

using namespace std;

int r, c, n;
inline bool read(){
  return (cin >> r >> c >> n);
}

inline int _solve(int tidx) {
  int dx[] = {0, 0, 1, -1};
  int dy[] = {1, -1, 0, 0};
  vector < int > bads;
  int nv = n;
  forn(i, r) {
    forn(j, c) {
      int cur = (i + j) & 1;
      if (cur == tidx) {
        int badcount = 0;
        forn(dir, 4) {
          int x = i + dx[dir];
          int y = j + dy[dir];
          if (x < 0 || y < 0 || x >= r || y >= c) continue;

          badcount++;
        }
        bads.pb(badcount);
      } else {
        nv--;
      }
    }
  }
  int ans = 0;
  sort(all(bads));
  reverse(all(bads));
  while (nv > 0) {
    int szt = sz(bads);
    ans += bads[szt - 1];
    bads.pop_back();
    nv--;
  }
  return ans;
}

inline void solve() {
  cout << min(_solve(1), _solve(0)) << endl;
}

int main() {
#ifdef gridnevvvit
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  int testcount;
  scanf("%d\n", &testcount);
  forn(test, testcount) {
    assert(read());
    cout << "Case #" << test + 1 << ": ";
    solve();
  }
}
