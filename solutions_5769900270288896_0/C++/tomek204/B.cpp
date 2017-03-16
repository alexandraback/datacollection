#include <bits/stdc++.h>

using namespace std;

int r, c, n;

bool room[17][17];

int check(int bm) {
	for (int i = 0; i < r*c; i++) {
		room[i/c][i%c] = (bm&(1<<i)) > 0;
	}
	int ret = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (i > 0 && room[i][j] && room[i-1][j]) ++ret;
			if (j > 0 && room[i][j] && room[i][j-1]) ++ret;
		}
	}
	return ret;
}

int solve() {
	int ret = 10000;
	scanf("%d%d%d", &r, &c, &n);
	for (int bitmask = 0; bitmask < (1<<(r*c)); bitmask++) if (__builtin_popcount(bitmask) == n) {
		ret = min(ret, check(bitmask));
	}
	return ret;
}

int main() {
	int t; scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: %d\n", i, solve());
	}
	return 0;
}