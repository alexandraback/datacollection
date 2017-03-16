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

int usd[20][20];

inline void solve() {
  int total = r * c;
  int dx[] = {-1, 0};
  int dy[] = {0, -1};
  int ans = INF;
  int cp = 0;
  forn(mask, 1 << total) {
    cp++;
    int id = 0;
    int tans = 0;
    int bitcount = 0;
    forn(i, r) {
      forn(j, c) {
        if (hasbit(mask, id)) {
          usd[i][j] = cp;
          if (i > 0) tans += (usd[i - 1][j] == cp);
          if (j > 0) tans += (usd[i][j - 1] == cp);
          bitcount++;
        }
        id++;
      }
    }
    if (bitcount == n) ans = min(ans, tans);
  }
  cout << ans << endl;
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
