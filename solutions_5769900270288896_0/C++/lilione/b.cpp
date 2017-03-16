#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<ctime>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<cassert>
#include<bitset>

using namespace std;

const int lim = 20, inf = 2e9;

bool use[lim][lim];
int r, c, n;
int u[4] = {-1, 0, 0, 1};
int v[4] = {0, -1, 1, 0};
int ans;

bool check(int i, int j) {
	return (i >= 1 && i <= r && j >= 1 && j <= c && use[i][j]);
}

void dfs(int x, int y, int z) {
	if (y > c) {
		x++;
		y = 1;
	}
	if (x > r) {
		if (z == 0) {
			int now = 0;
			for (int i = 1; i <= r; i++) {
				for (int j = 1; j <= c; j++) if (use[i][j]) {
					for (int k = 0; k < 4; k++) if (check(i + u[k], j + v[k])) now++;
				}
			}
			ans = min(ans, now / 2);
		}
		return;
	}
	dfs(x, y + 1, z);
	if (z) {
		use[x][y] = 1;
		dfs(x, y + 1, z - 1);
		use[x][y] = 0;
	}
}

int main() {
	freopen("b.out", "w", stdout);
	int TT;
	scanf("%d", &TT);
	for (int s = 1; s <= TT; s++) {
		scanf("%d%d%d", &r, &c, &n);
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) use[i][j] = 0;
		}
		ans = inf;
		dfs(1, 1, n);
		printf("Case #%d: %d\n", s, ans);
	}
	return 0;
}

