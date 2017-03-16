#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <cstdio>
#include <functional>

#pragma warning(disable : 4996)

using namespace std;

typedef unsigned long long ull;

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	size_t __; cin >> __;
	for (size_t _ = 0; _ < __; ++_) {
		size_t r, c, n; cin >> r >> c >> n;
		vector<vector<bool>> v(r, vector<bool>(c));
		size_t mx = numeric_limits<size_t>::max();
		auto score = [&]() {
			size_t s = 0, m = 0;
			for (size_t i = 0; i < r; ++i) {
				for (size_t j = 0; j < c; ++j) {
					if (!v[i][j])
						continue;
					++m;
					if (i + 1 < r && v[i + 1][j])
						++s;
					if (j + 1 < c && v[i][j + 1])
						++s;
				}
			}
			if (m == n)
				mx = min(mx, s);
		};
		function<void(size_t, size_t, bool)> dfs;
		dfs = [&](size_t i, size_t j, bool b) {
			v[i][j] = b;
			if (i + 1 == r && j + 1 == c)
				score();
			else if (j + 1 == c) {
				dfs(i + 1, 0, true);
				dfs(i + 1, 0, false);
			}
			else {
				dfs(i, j + 1, true);
				dfs(i, j + 1, false);
			}
			v[i][j] = false;
		};
		dfs(0, 0, true);
		dfs(0, 0, false);
		cout << "Case #" << (_ + 1) << ": " << mx << endl;
	}
	return 0;
}