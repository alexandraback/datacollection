#include <stdio.h>

int min(const int & a, const int & b) {
	return a < b ? a : b;
}

int main() {
	int cases;
	scanf("%d", &cases);
	for (int cas = 1; cas <= cases; cas++) {
		int n, a[1000], biggest_decreasing_interval = 0, sol1 = 0;
		scanf("%d", &n);
		scanf("%d", &a[0]);

		for (int i = 1; i < n; i++) {
			scanf("%d", &a[i]);
			int diff = a[i - 1] - a[i];
			if (diff > 0) {
				sol1 += diff;
			}
			if (diff > biggest_decreasing_interval)
				biggest_decreasing_interval = diff;
		}

		int sol2 = 0;
		for (int i = 0; i < n-1; i++) {
			sol2 += min(a[i], biggest_decreasing_interval);
		}

		printf("Case #%d: %d %d\n", cas, sol1, sol2);
	}
	return 0;
}
