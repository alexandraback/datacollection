#include <assert.h>
#include <memory.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define pb push_back
#define INF 1011111111
#define FOR(i, a, b) for (int _n(b), i(a); i < _n; i++)
#define rep(i, n) FOR(i, 0, n)
#define CL(a, v) memset((a), (v), sizeof(a))
#define mp make_pair
#define X first
#define Y second
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> pii;

/*** TEMPLATE CODE ENDS HERE */

int main() {
#ifdef LOCAL_HOST
  freopen("A-large.in", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  cout.sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;

  FOR(tt, 1, T + 1) {
    cout << "Case #" << tt << ": ";
    int n;
    cin >> n;
    VI p(n);
    rep(i, n) cin >> p[i];
    int M = *max_element(all(p));
    for (; M > 0; --M) {
      VI idx;
      rep(i, n) if (p[i] == M) {
        idx.pb(i);
        p[i]--;
      }
      int k = 0;
      if (idx.size() & 1) {
        cout << char('A' + idx[k++]) << " ";
      }
      while (k < (int)idx.size()) {
        cout << char('A' + idx[k++]);
        cout << char('A' + idx[k++]) << " ";
      }
    }
    cout << endl;
  }

  return 0;
}
