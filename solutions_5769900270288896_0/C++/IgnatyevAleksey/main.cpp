#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>

using namespace std;

#define mp make_pair
#define sqr(x) ((x) * (x))
#define all(a) a.begin(), a.end()

typedef long long int64;

const int INF = (int) 2e9;
const int64 INF64 = (int64) 1e18;
const double EPS = 1e-9;

vector<vector<bool> > used;
int n, m;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int cnt(int x, int y) {
	if (!used[x][y]) {
		return 0;
	}

	int res = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
			res += used[nx][ny];
		}
	}
	return res;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int tests;
	scanf("%d", &tests);

	for (int t = 0; t < tests; t++) {
		int N;
		scanf("%d%d%d", &n, &m, &N);

		int ans = INF;
		for (int mask = 0; mask < (1 << (n * m)); mask++) {
			used = vector<vector<bool> >(n, vector<bool>(m, 0));

			int c = 0;
			for (int i = 0; i < n * m; i++) {
				used[i / m][i % m] = (mask & (1 << i)) != 0;
				c += (mask & (1 << i)) != 0;
			}

			if (c != N) {
				continue;
			}

			int cur = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cur += cnt(i, j);
				}
			}

			ans = min(ans, cur / 2);
		}

		printf("case #%d: %d\n", t + 1, ans);
	}

	return 0;
}