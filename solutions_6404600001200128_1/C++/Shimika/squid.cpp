#include <stdio.h>
#define min2(x, y) ((x) < (y) ? (x) : (y))
int x, a[1005];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tt;
	scanf("%d", &tt);
	for (int t = 1; t <= tt; t++) {
		scanf("%d", &x);
		for (int i = 1; i <= x; i++) {
			scanf("%d", &a[i]);
		}

		int s1 = 0, s2 = 100000000;
		int mn = 0, mx = 100000000;

		for (int i = 2; i <= x; i++) {
			if (a[i - 1] > a[i]) {
				s1 += a[i - 1] - a[i];
				if (mn < a[i - 1] - a[i]) {
					mn = a[i - 1] - a[i];
				}
				if (mx > a[i - 1] - a[i]) {
					mx = a[i - 1] - a[i];
				}
			}
		}

		for (int tl = mn; tl <= 20000; tl++) {
			int s = 0;
			for (int i = 1; i < x; i++) {
				s += min2(a[i], tl);
			}

			if (s2 > s) {
				s2 = s;
			}
		}

		printf("Case #%d: %d %d\n", t, s1, s2);
	}
}