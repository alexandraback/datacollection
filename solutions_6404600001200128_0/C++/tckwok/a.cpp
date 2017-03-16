#include <cstdio>

#define N 1024

int T, n, d[N], ans1, ans2, t;

int main() {
	scanf("%d", &T);
	for (int r = 1; r <= T; ++r) {
		printf("Case #%d: ", r);
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", d + i);
		ans1 = ans2 = t = 0;
		for (int i = 1; i < n; ++i)
			if (d[i - 1] > d[i])
				ans1 += d[i - 1] - d[i];
		for (int i = 1; i < n; ++i)
			if (t < d[i - 1] - d[i])
				t = d[i - 1] - d[i];
		for (int i = 0; i < n - 1; ++i)
			ans2 += (d[i] > t ? t : d[i]);
		printf("%d %d\n", ans1, ans2);
	}
	return 0;
}
