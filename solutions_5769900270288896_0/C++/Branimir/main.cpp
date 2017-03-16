#include <bits/stdc++.h>

using namespace std;

struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
bool grid[20][20];
int r, c, n;
int solve() {
  int ans = 0;
  for (int i = 0; i < r; i++)
    for (int j = 1; j < c; j++)
      if (grid[i][j - 1] && grid[i][j])
	ans++;
  for (int j = 0; j < c; j++)
    for (int i = 1; i < r; i++)
      if (grid[i - 1][j] && grid[i][j])
	ans++;
  return ans;
}
int main() {
  int t;
  scanf("%d", &t);
  for (int caso = 1; caso <= t; caso++) {

    scanf("%d %d %d", &r, &c, &n);
    int ans = INT_MAX;
    int rc = r * c;
    for (int mask = 0; mask  < (1 << rc); mask++)
      if (__builtin_popcount(mask) == n) {
	int pos = 0;
	for (int i = 0; i < r; i++)
	  for (int j = 0; j < c; j++) {
	    grid[i][j] = (1 << pos) & mask;
	    pos++;
	  }
	ans = min(ans, solve());
      }
    printf("Case #%d: %d\n", caso, ans);
  }
  return 0;
}
