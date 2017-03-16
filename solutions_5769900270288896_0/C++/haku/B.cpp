#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <list>
#include <iterator>
#include <functional>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pnt;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define FILE ""

const int INF = 1000 * 1000 * 1000 + 5;
const int MOD = 1000 * 1000 * 1000 + 7;
const ld EPS = 1e-9;



int main() {
#ifdef HOME
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  //freopen(FILE ".in", "r", stdin);
  //freopen(FILE ".out", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  int ts;
  cin >> ts;
  for (int ti = 0; ti < ts; ++ti) {
    int n, m, k;
    cin >> n >> m >> k;
    int ans = INF;
    for (int x = 0; x < (1 << (n * m)); ++x) {
      if (__builtin_popcount(x) == k) {
        bool a[16][16];
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < m; ++j) {
            a[i][j] = (x >> (m * i + j)) & 1;
          }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < m; ++j) {
            if (i + 1 < n) {
              res += a[i][j] && a[i + 1][j];
            }
            if (j + 1 < m) {
              res += a[i][j] && a[i][j + 1];
            }
          }
        }
        ans = min(ans, res);
      }
    }
    cout << "Case #" << ti + 1 << ": " << ans << "\n";
  }
  return 0;
}
