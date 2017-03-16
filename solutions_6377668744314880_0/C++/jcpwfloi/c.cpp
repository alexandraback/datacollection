#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int const N = 1e4;

double const eps = 1e-3;

struct Point {
	int x, y;
	Point() : x(0), y(0) {}
	Point(int x, int y) : x(x), y(y) {}
	Point operator + (Point p) {
		return Point(x + p.x, y + p.y);
	}
	Point operator - (Point p) {
		return Point(x - p.x, y - p.y);
	}
	double operator * (Point p) {
		return x * p.y - y * p.x;
	}
	double operator / (Point p) {
		return x * p.x + y * p.y;
	}
	void read() {
		scanf("%d%d", &x, &y);
	}
} pp[N], p[N];

int T, n;

inline double arg(Point p) {
	return atan2(p.y, p.x);
}

inline bool comp(Point p1, Point p2) {
	return arg(p1 - p[1]) < arg(p2 - p[1]);
}

inline bool theta(int r, int l) {
	Point p1 = p[r] - p[1], p2 = p[l] - p[1];
	return p1 * p2 <= -eps;
}

int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; ++ t) {
		scanf("%d", &n);
		printf("Case #%d:\n", t);
		for (int i = 1; i <= n; ++ i) pp[i].read();
		for (int i = 1; i <= n; ++ i) {
			int ans = 2147483647;
			for (int j = 1; j <= n; ++ j) p[j] = pp[j];
			swap(p[1], p[i]);
			sort(p + 2, p + n + 1, comp);
			int l = 2, r = 2, nex;
			for (nex = (r != n ? r + 1 : 2); theta(nex, l); r = nex, nex = (r != n ? r + 1 : 2)) ;
			ans = min(ans, r >= l ? r - l : l - 2 + n - r + 1);
			for (; l <= n; ++ l) {
				for (nex = (r != n ? r + 1 : 2); theta(nex, l); r = nex, nex = (r != n ? r + 1 : 2)) ;
				ans = min(ans, r >= l ? r - l : l - 2 + n - r + 1);
			}
			printf("%d\n", ans);
		}
	}
    return 0;
}

