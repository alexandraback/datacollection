#include <bits/stdc++.h>
using namespace std;
const int mn = 5000;

struct point {
	double x, y;
}b[mn], a[mn];

const double pi = acos(-1.0), eps = 1e-5;

int N, n, cn, st[mn];
inline bool cmp(const point &a, const point &b) {
	if (a.y != b.y) return a.y < b.y; return a.x < b.x;
}
inline int dblcmp(const double &d) {
	if (abs(d) < eps) return 0; return d < 0 ? -1 : 1;
}
inline double cross(const point &a, const point &b, const point &c) {
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}
inline double dis(const point &a, const point &b) {
	double dx = a.x - b.x, dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
} // get the convex hull
void graham_scan() {
	sort(a, a + n, cmp);
	cn = -1;
	st[++cn] = 0;
	st[++cn] = 1;
	for (int i = 2; i < n; i++) {
		while (cn>0 && dblcmp(cross(a[st[cn-1]],a[st[cn]],a[i]))<=0) cn--;
		st[++cn] = i;
	}
	int newtop = cn;
	for (int i = n - 2; i >= 0; i--) {
		while (cn>newtop && dblcmp(cross(a[st[cn-1]],a[st[cn]],a[i]))<=0) cn--;
		st[++cn] = i;
	}
}

int ans[mn];

int main() {
	int Tc;
	scanf("%d", &Tc);
	for (int Tn = 1; Tn <= Tc; ++Tn) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) {
			scanf("%lf%lf", &b[i].x, &b[i].y);
		}

		for (int i = 0; i < N; ++i) {
			ans[i] = max(0, N - 3);
			for (int j = (1 << N) - 1; j >= 0; --j) {
				n = 0;
				for (int k = 0; k < N; ++k)
					if (j & (1<<k)) {
						a[n++] = b[k];
					}
				graham_scan();
				for (int k = 0; k < cn; ++k) {
					int c = dblcmp(cross(a[st[k]],a[st[k+1]],b[i]));
					if (c == 0) {
						ans[i] = min(N - n, ans[i]);
						break;
					}
				}
			}

		}

		printf("Case #%d:\n", Tn);
		for (int i = 0; i < N; ++i)
			printf("%d\n",ans[i]);
	}
	return 0;
}
