#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 1010;
int m[MAX_N], b, n;

lint calc(lint x) {
	lint res = 0;
	for (int i = 0; i < b; i++) {
		res += (x + m[i]) / m[i];
	}
	return res;
}

int gao() {
	lint low = 0, high = 100000000000000000LL;
	while (low <= high) {
		lint mid = low + high >> 1;
		if (calc(mid) < (lint)n) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	lint tims = low;
	int cnt = n - calc(low - 1);
	for (int i = 0; i < b; i++) {
		if (tims % m[i] == 0) {
			--cnt;
			if (cnt == 0) {
				return i + 1;
			}
		}
	}
	assert(false);
}

int main() {
#ifdef _SHANGKE_
	time_t _t1 = clock();
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
#endif
	int n_case = 0;
	scanf("%d", &n_case);
	for (int ca = 1; ca <= n_case; ca++) {
		scanf("%d%d", &b, &n);
		for (int i = 0; i < b; i++) {
			scanf("%d", m + i);
		}
		int ans = gao();
		printf("Case #%d: %d\n", ca, ans);
	}
#ifdef _SHANGKE_
	fprintf(stderr, "%.3lf s\n", 1.0 * (clock() - _t1) / CLOCKS_PER_SEC);
#endif
	return 0;
}
