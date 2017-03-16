#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int dx[] = {-1, 0, 0, 1};
int dy[] = { 0,-1, 1, 0};
int n, r, c;

bool isValid(int x, int y) {
	return 0 <= x && x < r && 0 <= y && y < c;
}

int calcA() {
	int n = ::n;
	vector < vector < int > > a(r, vector < int > (c, 0));
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if ((i + j) % 2 == 0 && n > 0) {
				a[i][j] = 1;
				--n;
			}
		}
	}
	vector < int > cnt(5);
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (a[i][j] == 1) {
				continue;
			}
			int score = 0;
			for (int t = 0; t < 4; ++t) {
				int ni = i + dx[t];
				int nj = j + dy[t];
				if (!isValid(ni, nj)) {
					continue;
				}
				if (a[ni][nj] == 1) {
					++score;
				}
			}
			++cnt[score];
		}
	}

	int res = 0;
	for (int i = 0; i <= 4; ++i) {
		int t = min(cnt[i], n);
		res += i * t;
		n -= t;
	}
	return res;
}

int calcB() {
	int n = ::n;
	vector < vector < int > > a(r, vector < int > (c, 0));
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if ((i + j) % 2 == 1 && n > 0) {
				a[i][j] = 1;
				--n;
			}
		}
	}
	vector < int > cnt(5);
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (a[i][j] == 1) {
				continue;
			}
			int score = 0;
			for (int t = 0; t < 4; ++t) {
				int ni = i + dx[t];
				int nj = j + dy[t];
				if (!isValid(ni, nj)) {
					continue;
				}
				if (a[ni][nj] == 1) {
					++score;
				}
			}
			++cnt[score];
		}
	}

	int res = 0;
	for (int i = 0; i <= 4; ++i) {
		int t = min(cnt[i], n);
		res += i * t;
		n -= t;
	}
	return res;
}

void solve2(int test) {
	cin >> r >> c >> n;
	printf("Case #%d: %d\n", test, min(calcA(), calcB()));
}

void solve(int test) {
	cin >> r >> c >> n;
	int res = 1000000000;
	vector < vector < int > > a(r, vector < int > (c, 0));
	for (int mask = 0; mask < (1 << (r * c)); ++mask) {
		int cnt = 0;
		for (int i = 0; i < r * c; ++i) {
			if (mask & (1 << i)) {
				a[i / c][i % c] = 1;
				++cnt;
			} else {
				a[i / c][i % c] = 0;
			}
		}
		if (cnt != n) {
			continue;
		}

		int score = 0;
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				if (a[i][j] == 0) {
					continue;
				}
				for (int t = 0; t < 4; ++t) {
					int ni = i + dx[t];
					int nj = j + dy[t];
					if (!isValid(ni, nj)) {
						continue;
					}
					if (a[ni][nj] == 1) {
						++score;
					}
				}
			}
		}
		res = min(res, score / 2);
	}
	printf("Case #%d: %d\n", test, res);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	scanf("%d", &tests);
	for (int i = 0; i < tests; ++i) {
		solve2(i + 1);
		cerr << (i + 1) << endl;
	}
	cerr << "Time: " << clock() << endl;
	return 0;
}