#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <cassert>

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, a, b) for(int i = (a); i <=(b); ++i)
#define REPD(i, a, b) for(int i = (a); i >=(b); --i)
#define TR(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define RESET(a, v) memset(a, (v), sizeof(a))
#define SZ(a) (int(a.size()))
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
#define LL long long
#define LD long double
#define II pair<int, int>
#define X first
#define Y second
#define VI vector<int>
#define VII vector<II>
#define endl '\n'

using namespace std;

int nTest, n, R, C;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  //freopen("small.in", "r", stdin);
  freopen("B-small-attempt1.in", "r", stdin);
  freopen("B-small-attempt1.out", "w", stdout);
  cin >> nTest;
  REP(test, 1, nTest) {
    cin >> R >> C >> n;
    int ans = 1000000;
    #define index(i, j) ((i) * C + (j))
    FOR(mask, 0, 1 << (R * C))
    if (__builtin_popcount(mask) == n) {
      int now = 0;
      FOR(i, 0, R) FOR(j, 0, C)
      if (mask & (1 << index(i, j))) {
        now += i + 1 < R && (mask & (1 << (index(i + 1, j))));
        now += j + 1 < C && (mask & (1 << (index(i, j + 1))));
      }
      ans = min(ans, now);
    }
    cout << "Case #" << test << ": " << ans << endl;
  }
  return 0;
}
