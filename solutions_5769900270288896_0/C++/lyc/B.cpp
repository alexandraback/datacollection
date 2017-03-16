#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
bool g[20][20];
int r, c, n, ans[20][20][20];
int t;

int calc() {
	int ret = 0;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j + 1 < c; ++j)
			ret += g[i][j] && g[i][j + 1];
	for (int i = 0; i + 1 < r; ++i)
		for (int j = 0; j < c; ++j)
			ret += g[i][j] && g[i + 1][j];
	return ret;
}

void init() {
	memset(ans, 0x3f, sizeof(ans));
	for (r = 1; r <= 16; ++r)
		for (c = 1; c <= 16; ++c)
			if (r * c <= 16)
				for (int k = 0; k < (1 << (r * c)); ++k) {
					int x = 0;
					for (int i = 0; i < r * c; ++i) {
						g[i / c][i % c] = k & (1 << i);
						x += (k & (1 << i)) > 0;
					}
					ans[r][c][x] = min(ans[r][c][x], calc());
				}
}

int main()
{
	init();
	scanf("%d", &t);
	for (int ca = 1; ca <= t; ++ca) {
		scanf("%d%d%d", &r, &c, &n);
		printf("Case #%d: %d\n", ca, ans[r][c][n]);
	}
	return 0;
}
