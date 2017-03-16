#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

#define foreach(e,x) for(__typeof((x).begin()) e=(x).begin(); e!=(x).end(); ++e)

const int INF = 1000000;

int r, c, n;
int ans;
int vis[20][20];

void dfs(int x, int y, int cnt, int cur)
{
	if (cnt == 0) {
		ans = min(ans, cur);
		return;
	}
	if (x == r) {
		return;
	}
	int nx = x, ny = y + 1;
	if (ny == c) {
		ny = 0;
		nx ++;
	}
	vis[x][y] = 0;
	dfs(nx, ny, cnt, cur);
	vis[x][y] = 1;
	if (x && vis[x - 1][y]) ++ cur;
	if (y && vis[x][y - 1]) ++ cur;
	dfs(nx, ny, cnt - 1, cur);
}

void solve()
{
	cin >> r >> c >> n;
	ans = INF;
	memset(vis, 0, sizeof vis);
	dfs(0, 0, n, 0);
	cout << ans << endl;
}

int main()
{
	//freopen("B-small-attempt0.in", "r", stdin); freopen("B-small-attempt0.out", "w", stdout);
	freopen("B-small-attempt1.in", "r", stdin); freopen("B-small-attempt1.out", "w", stdout);
	//froepen("B-large.in", "r", stdin); freopen("B-large.out", stdout);
	int test_case;
	cin >> test_case;
	for(int i = 0; i < test_case; ++ i) {
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}
