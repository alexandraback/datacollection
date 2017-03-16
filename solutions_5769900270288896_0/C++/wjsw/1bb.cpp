#include <stdio.h>

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; ++tt) {
		int r, c, n;
		scanf("%d%d%d", &r, &c, &n);
		n = r * c - n;
		int m = 2 * r * c - c - r;
		int rr;
		if (n >= c * r / 2) {
			rr = 0;
		} else if ((n + 2 >= c*r/2) && (r % 2 == 0 || c * 2 == 0)) {
			rr = (c*r/2 - n)*2;
		} else {
			int x = ((r - 2) * (c - 2) + 1) / 2;
			if (n <= x) {
				rr = m - 4 * n;
			} else {
				m -= 4 * x;
				n -= x;
				rr = m - 3 * n;
			}
		}
		printf("Case #%d: %d\n", tt, rr);
	}
}
