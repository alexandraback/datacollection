#include <stdio.h>

int t, n, b, a[1020];
long long calc(long long x) {
	long long re = 0;
	for (int i = 0; i < b; i++) {
		re += (x + a[i] - 1) / a[i];
	}
	return re;
}

int main() {
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		scanf("%d%d", &b, &n);
		for (int i = 0; i < b; i++) {
			scanf("%d", &a[i]);
		}
		long long L = 0;
		long long R = 1LL << 60;
		while (L < R - 1) {
			long long M = (L + R) >> 1;
			if (calc(M) < n) {
				L = M;
			} else {
				R = M;
			}
		}
		n -= calc(L);
		int ans = 0;
		for (int i = 0; i < b; i++) {
			if (L % a[i] == 0 && n > 1) {
				n--;
			} else if (L % a[i] == 0) {
				ans = i;
				break;
			}
		}
		printf("Case #%d: %d\n", tt, ans + 1);
	}
	return 0;
}