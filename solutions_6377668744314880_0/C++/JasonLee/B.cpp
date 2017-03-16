//============================================================================
// Name        : B.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#define MAXN 10010
using namespace std;
const double eps = 1e-6;
int dcmp(double x) {
	if (fabs(x) < eps)
		return 0;
	return x < 0 ? -1 : 1;
}
struct Point {
	double x, y;
	Point() {
	}
	Point(double x, double y) :
			x(x), y(y) {
	}
	bool operator==(const Point& rhs) const {
		return dcmp(x - rhs.x) == 0 && dcmp(y - rhs.y) == 0;
	}
	bool operator<(const Point& rhs) const {
		return dcmp(x - rhs.x) < 0
				|| (dcmp(x - rhs.x) == 0 && dcmp(y - rhs.y) < 0);
	}
};
typedef Point Vector;
Vector operator-(Point A, Point B) {
	return Vector(A.x - B.x, A.y - B.y);
}
double Cross(Vector A, Vector B) {
	return A.x * B.y - A.y * B.x;
}
int ConvexHull(Point *p, int n, Point *ch) //求凸包
		{
	sort(p, p + n);
	n = unique(p, p + n) - p;
	int m = 0;
	for (int i = 0; i < n; i++) {
		while (m > 1 && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) < 0)
			m--;
		ch[m++] = p[i];
	}
	int k = m;
	for (int i = n - 2; i >= 0; i--) {
		while (m > k && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) < 0)
			m--;
		ch[m++] = p[i];
	}
	if (n > 1)
		m--;
	return m;
}
Point p[MAXN], ch[MAXN], tmp[MAXN];
int gao(int n, int idx, int status) {
	int m = 0;
	for (int i = 0; i < n; i++) {
		if (status & (1 << i)) {
			tmp[m++] = p[i];
		}
	}
	int ans = ConvexHull(tmp, m, ch);
	for (int i = 0; i < ans; i++) {
		if (dcmp(ch[i].x - p[idx].x) == 0 && dcmp(ch[i].y - p[idx].y) == 0) {
			return ans;
		}
	}
	return -1;
}
Point in[MAXN];
bool is(Point pt, int n) {
	for (int i = 0; i < n; i++) {
		if (dcmp(pt.x - in[i].x) == 0 && dcmp(pt.y - in[i].y) == 0) {
			return true;
		}
	}
	return false;
}
Point tp[MAXN];
int f(int n) {
	int ans = 0;
	while (n) {
		ans += n & 1;
		n >>= 1;
	}
	return ans;
}
int main() {
	int T;
	int ca = 1;
	freopen("C.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> p[i].x >> p[i].y;
			tp[i] = p[i];
		}
		int total = ConvexHull(tp, n, in);
//		cout << "total: " << total << endl;
//		for (int i = 0; i < total; i++) {
//			cout << in[i].x << " " << in[i].y << endl;
//		}
		printf("Case #%d:\n", ca++);
		for (int i = 0; i < n; i++) {
			int ans = 0;
			if (!is(p[i], total)) {
				ans = 100000;
				for (int j = 0; j < (1 << n); j++) {
					if (j & (1 << i)) {
						int r = gao(n, i, j);
						if (r < 0) {
							continue;
						}
						ans = min(ans, n - f(j));
					}
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}
