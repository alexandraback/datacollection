#include <cstdio>
#include <algorithm>
using namespace std;

#define N 4096

struct P {
	long long x, y;
	P() {}
	P(long long x, long long y) : x(x), y(y) {}
	P operator-(const P p) const {
		return P(x - p.x, y - p.y);
	}
	long long operator^(P p) {
		return x*p.y - y*p.x;
	}
};

int T, n, ans, t, c[N], a, b;
P p[N], q[N];

bool cmp(int a, int b) {
	if (q[b].x > 0 && q[b].y == 0) return 0;
	if (q[a].x > 0 && q[a].y == 0) return 1;
	if (q[b].y > 0 && q[a].y <= 0) return 0;
	if (q[a].y > 0 && q[b].y <= 0) return 1;
	return (q[a]^q[b]) > 0;
}

int main() {
	scanf("%d", &T);
	for (int r = 1; r <= T; ++r) {
		printf("Case #%d:\n", r);
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%lld%lld", &p[i].x, &p[i].y);
		--n;
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= n; ++j)
				if (j != i)
					q[j - (j > i)] = p[j] - p[i];
			for (int j = 0; j < n; ++j)
				c[j] = j;
			sort(c, c + n, cmp);
			for (int j = 0; j < n; ++j)
				c[n + j] = c[j];
			a = -1;
			b = 0;
			ans = n;
			while (++a < n) {
				if (b == a) ++b;
				while (b < n + a && (q[c[a]]^q[c[b]]) >= 0) ++b;
				if (n + a - b < ans)
					ans = n + a - b;
				if (ans == 0) break;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
