#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int r, c, n;
bool g[18][18];
int dx[] = { 0, 1 }, dy[] = { 1, 0 };

int calc(int i, int j, int w) {
	if (w == n) {
		int bad = 0;
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				if (g[i][j])
					for (int k = 0; k < 2; ++k) {
						int x = i + dx[k];
						int y = j + dy[k];
						if (x < r && j < c && g[x][y])
							++bad;
					}
		return bad;
	}
	if (i == r)
		return 2e9;
	int res = 2e9;
	if (j == c - 1)
		res = min(res, calc(i + 1, 0, w));
	else
		res = min(res, calc(i, j + 1, w));
	g[i][j] = 1;
	if (j == c - 1)
		res = min(res, calc(i + 1, 0, w + 1));
	else
		res = min(res, calc(i, j + 1, w + 1));
	g[i][j] = 0;
	return res;
}

int main(int argc, char **argv) {
//	freopen("B-small-attempt0.in", "r", stdin);
//	freopen("res.txt", "w", stdout);
	int t, k = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &r, &c, &n);
		printf("Case #%d: %d\n", k++, calc(0, 0, 0));
	}
	return 0;
}
