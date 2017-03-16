// Problem C. Logging
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
	double	x, y;
	int i;
} point;

const double EPS = 1E-6;

double dist(const point a, const point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int convex_hull_cmp(const void *a, const void *b)
{
	const point *p1 = (const point *) a;
	const point *p2 = (const point *) b;
	if (fabs(p1->x - p2->x) < EPS) return p1->y < p2->y ? -1 : 1;
	return p1->x < p2->x ? -1 : 1;
}

int convex_hull_better(point p1, point p2, point p3)
{
	double sg = (p2.x - p1.x) * (p3.y - p2.y) - (p2.y - p1.y) * (p3.x - p2.x);
	if (fabs(sg) < EPS)
		return (dist(p1, p3) > dist(p1, p2)) ? 1 : 0;
	return sg < 0 ? 1 : 0;
}

int convex_hull(point *p, int n, point *h)
{
	int i, k = 0;

	qsort(p, n, sizeof(p[0]), convex_hull_cmp);

	for (i = 0; i < n; i++) {
		if (i > 0 && dist(p[i], p[i - 1]) < EPS) continue;
		while (k > 1 && convex_hull_better(h[k - 2], h[k - 1], p[i]))
			k--;
		h[k++] = p[i];
	}
	for (i = n - 2; i >= 0; i--) {
		if (i < n - 1 && dist(p[i], p[i + 1]) < EPS) continue;
		while (k > 1 && convex_hull_better(h[k - 2], h[k - 1], p[i]))
			k--;
		h[k++] = p[i];
	}

	return k - 1;
}

double area(const point &a, const point &b, const point &c)
{
	return fabs((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x)) * 0.5;
}

int main(int argc, char *argv[])
{
	int T;
	scanf("%d\n", &T);
	for (int ti = 1; ti <= T; ti++) {
		int n;
		static point p[6000], q[6000], h[6000];
		static int ans[6000];
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lf %lf", &p[i].x, &p[i].y);
			ans[i] = n;
		}

		for (int k = 0; k < (1 << n); k++) {
			int r = 0;
			for (int j = 0; j < n; j++)
				if ((k & (1 << j)) == 0) r++;
			if (r == 0) continue;
			int m = 0;
			for (int j = 0; j < n; j++)
				if ((k & (1 << j)) == 0) {
					q[m] = p[j];
					q[m].i = j;
					m++;
				}
			int c = n - r;
			if (m > 3) {
				int t = convex_hull(q, m, h);
				for (int i = 0; i < t; i++) {
					for (int j = 0; j < m; j++) {
						double ta = area(q[j], h[i], h[(i + 1) % t]);
						if (ta < EPS) {
							int ii = q[j].i;
							if (ans[ii] > c) ans[ii] = c;
						}
					}
				}
			} else {
				for (int i = 0; i < m; i++) {
					int ii = q[i].i;
					if (ans[ii] > c) ans[ii] = c;
				}
			}
		}

		printf("Case #%d:\n", ti);
		for (int i = 0; i < n; i++) printf("%d\n", ans[i]);
	}
	return 0;
}
