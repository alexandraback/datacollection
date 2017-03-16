#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;

const double eps = 1e-10;
const int N = 3333;

inline double sqr(double x) {
	return x * x;
}

inline int sign(double x) {
	if (x < -eps) return -1;
	else if (x > eps) return 1;
	else return 0;
}

inline bool equal(double a, double b) {
	return a - eps < b && b < a + eps;
}

struct Point {
	double x, y;
	int id;
	Point (double _x = 0, double _y = 0) : x(_x), y(_y) {};
	double length() {
		return sqrt(sqr(x) + sqr(y));
	}
	Point operator + (const Point &p) const {
		return Point(x + p.x, y + p.y);
	}
	Point operator - (const Point &p) const {
		return Point(x - p.x, y - p.y);
	}
	inline bool operator < (const Point &p) const {
		if (!equal(x, p.x)) return x < p.x;
		else return y < p.y;
	}
} point[N], point0[N];

inline double det(const Point &p1, const Point &p2) {
	return p1.x * p2.y - p1.y * p2.x;
}

inline double cross(const Point &p1, const Point &p2, const Point &p3) {
	return det(p2 - p1, p3 - p1);
}

int n, n0;
vector<Point> vec;
int ans[N];

vector<Point> get_convex() {
	vector<Point> ret;
	int sz;
	ret.push_back(point[1]);
	ret.push_back(point[2]);
	sz = 2;
	for (int i = 3; i <= n; ++i) {
		while (sz > 1 && sign(cross(ret[sz - 2], ret[sz - 1], point[i])) <= 0) {
			--sz, ret.pop_back();
		}
		++sz, ret.push_back(point[i]);
	}
	int sz2;
	ret.push_back(point[n - 1]);
	sz2 = 2;
	++sz;
	for (int i = n - 2; i; --i) {
		while (sz2 > 1 && sign(cross(ret[sz - 2], ret[sz - 1], point[i])) <= 0) {
			--sz, --sz2, ret.pop_back();
		}
		++sz, ++sz2, ret.push_back(point[i]);
	}
	ret.pop_back();
	return ret;
}

bool check(int x) {
	for (int i = 0; i < (int)vec.size() - 1; ++i) {
		if (sign(cross(point0[x], vec[i], vec[i + 1])) == 0) return true;
	}
	if (sign(cross(point0[x], vec[0], vec[vec.size() - 1])) == 0) return true;
	else return false;
}

int solve(int x) {
	int ret = 10000;
	for (int msk = 0; msk < (1 << n0); ++msk) {
		if (msk & (1 << (x - 1))) continue;
		int t = __builtin_popcount(msk);
		if (t >= ret) continue;
		n = 0;
		for (int i = 1; i <= n0; ++i) {
			if (msk & (1 << (i - 1))) continue;
			point[++n] = point0[i];
		}
		if (n <= 2) {
			ret = min(ret, t);
			continue;
		}
		vec = get_convex();
		if (check(x)) {
			ret = min(ret, t);
		}
	}
	return ret;
}

bool cmp(const Point &p1, const Point &p2) {
	if (!equal(p1.x, p2.x)) return p1.x < p2.x;
	else return p1.y < p2.y;
}

int main() {
	freopen("C_.in", "r", stdin);
	freopen("C_.out", "w", stdout);
	int TT;
	scanf("%d", &TT);
	for (int T = 1; T <= TT; ++T) {
		printf("Case #%d:\n", T);
		scanf("%d", &n);
		n0 = n;
		for (int i = 1; i <= n; ++i) {
			scanf("%lf %lf", &point[i].x, &point[i].y);
			point[i].id = i;
			point0[i] = point[i];
		}
		sort(point0 + 1, point0 + n0 + 1, cmp);
		for (int i = 1; i <= n0; ++i) {
			ans[point0[i].id] = solve(i);
		}
		for (int i = 1; i <= n0; ++i) {
			printf("%d\n", ans[i]);
		}
fprintf(stderr, "solved %d\n", T);
	}
	return 0;
}
