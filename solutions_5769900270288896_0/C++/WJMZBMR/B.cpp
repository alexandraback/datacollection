#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		int n, m, k;
		cin >> n >> m >> k;
		int tot = n * m;
		int ans = 10000;
		for (int mask = 0; mask < (1 << tot); ++mask) {
			if (__builtin_popcount(mask) == k) {
				int at[20][20];
				for (int r = 0; r < n; ++r) {
					for (int c = 0; c < m; ++c) {
						at[r][c] = mask >> (r * m + c) & 1;
					}
				}
				int cur = 0;
				for (int r = 0; r < n; ++r) {
					for (int c = 0; c < m; ++c) {
						if (r + 1 < n && at[r][c] + at[r + 1][c] == 2)
							++cur;
						if (c + 1 < m && at[r][c] + at[r][c + 1] == 2)
							++cur;
					}
				}
				ans = min(ans, cur);
			}
		}
		printf("Case #%d: %d\n", nc, ans);
	}
}
