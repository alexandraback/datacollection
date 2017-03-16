#include <bits/stdc++.h>

using namespace std;

int w[100][100];

int main()
{
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		int R, C, N;
		scanf("%d%d%d", &R, &C, &N);
		int ans = 1000000;
		for (int i = 0; i < (1 << (R * C)); i++) {
			if (__builtin_popcount(i) != N) continue;
			memset(w, 0, sizeof(w));
			for (int x = 0; x < R; x++) {
				for (int y = 0; y < C; y++) {
					int k = x * C + y;
					if (i & (1 << k)) {
						w[x][y] = 1;
					}
				}
			}
			int delta = 0;
			for (int x = 0; x < R; x++) {
				for (int y = 0; y < C; y++) {
					if (w[x][y] == 0) continue;
					delta += w[x + 1][y] + w[x][y + 1];
				}
			}
			ans = min(ans, delta);
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}
