#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <climits>

using namespace std;

int test_case, r, c, n;
vector<int> v[2];

bool in_range(int x, int l, int r) {
	return x >= l && x <= r;
}

int main() {
	scanf("%d", &test_case);
	for (int case_cnt = 1; case_cnt <= test_case; ++case_cnt) {
		scanf("%d%d%d", &r, &c, &n);
		v[0] = vector<int>();
		v[1] = vector<int>();
		for (int i = 1; i <= r; ++i) {
			for (int j = 1; j <= c; ++j) {
				int tmp = 0;
				for (int dx = -1; dx <= 1; ++ dx) {
					for (int dy = -1; dy <= 1; ++dy) {
						tmp += abs(dx) + abs(dy) == 1 && in_range(i + dx, 1, r) && in_range(j + dy, 1, c);
					}
				}
				v[(i + j) % 2].push_back(tmp);
			}
		}
		int ans = INT_MAX;
		for (int k = 0; k < 2; ++k) {
			int tmp = 0;
			sort(v[k].begin(), v[k].end());
			for (int i = 0; i < n - (int) v[1 - k].size(); ++i) {
				tmp = tmp + v[k][i];
			}
			ans = min(ans, tmp);
		}
		printf("Case #%d: %d\n", case_cnt, ans);
	}
	return 0;
}
