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
		int n, m, k, ans = 1 << 20;
		cin >> n >> m >> k;
		vector<vector<int> > map(n, vector<int>(m, 0));
		for (int pick = 0; pick < 2; ++pick) {
			int cnt = 0;
			for (int r = 0; r < n; ++r) {
				for (int c = 0; c < m; ++c) {
					if ((r + c) % 2 == pick)
						++cnt, map[r][c] = 1;
				}
			}
			int need = k - cnt;
			if (need < 0)
				need = 0;
			vector<int> adjs;
			for (int r = 0; r < n; ++r) {
				for (int c = 0; c < m; ++c) {
					if ((r + c) % 2 != pick) {
						int adj = 0;
						if (r > 0)
							++adj;
						if (c > 0)
							++adj;
						if (r + 1 < n)
							++adj;
						if (c + 1 < m)
							++adj;
						adjs.push_back(adj);
					}
				}
			}
			sort(adjs.begin(), adjs.end());
			int cur = 0;
			for (int i = 0; i < need; ++i) {
				cur += adjs[i];
			}
			ans = min(ans, cur);
		}
		printf("Case #%d: %d\n", nc, ans);
	}
}

