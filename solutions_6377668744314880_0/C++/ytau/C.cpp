#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 10005

struct point { int i, ans; long long x, y; };
long long xmult(point p1, point p2, point p0) { return (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y); }


int T, N;
point points[MAXN];

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) {
			scanf("%lld%lld", &points[i].x, &points[i].y);
			points[i].i = i;
			points[i].ans = max(0, N - 3);
		}
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				if (i == j) continue;
				int t1 = 0, t2 = 0;
				for (int k = 0; k < N; ++k) {
					if (k == i || k == j) continue;
					long long tmp = xmult(points[i], points[j], points[k]);
					if (tmp > 0) t1++;
					else if (tmp < 0) t2++;
				}
				points[i].ans = min(points[i].ans, min(t1, t2));
				points[j].ans = min(points[j].ans, min(t1, t2));
			}
		}
		printf("Case #%d:\n", tc);
		for (int i = 0; i < N; ++i) {
			printf("%d\n", points[i].ans);
		}
	}
	return 0;
}

