#include <cstdio>

#define N 1024

int T, n, m, d[N];
long long t, a;

bool ok(long long x) {
	long long t = 0;
	for (int i = 0; i < n; ++i)
		t += 1 + x / d[i];
	return m > t;
}

long long find_time() {
	long long lo = -1, md, hi = (1ll << 50) - 1;
	while (lo + 1 < hi) {
		md = lo + hi >> 1;
		if (ok(md)) lo = md;
		else hi = md;
	}
	return hi;
}

int main() {
	scanf("%d", &T);
	for (int r = 1; r <= T; ++r) {
		printf("Case #%d: ", r);
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			scanf("%d", d + i);
		t = find_time();
		a = 0;
		for (int i = 0; i < n; ++i)
			a += 1 + t / d[i];
		a -= m;
		for (int i = n - 1; i >= 0; --i) {
			if (t % d[i] == 0) --a;
			if (a < 0) {
				printf("%d\n", i + 1);
				break;
			}
		}
	}
	return 0;
}
