#include <bits/stdc++.h>
using namespace std;
struct Point {
	int x, y;
	double angle;
} P[3005], Q[3005];
int N;
bool cmp(Point a, Point b) {
	return a.angle < b.angle;
}
long long area2(Point &a, Point &b, Point &c) {
	return (long long)(b.x - a.x) * (c.y - a.y) - (long long)(c.x - a.x) * (b.y - a.y);
}
const double PI = 2 * acos(0);
int calc(int i) {
	int n = 0;
	for (int j = 0; j < N; ++j)
		if (i != j) Q[n++] = P[j];
	if (!n) return 0;
	bool line = true;
	for (int j = 0; j < n; ++j)
		if (area2(Q[j], Q[0], P[i])) line = false;
	if (line) return 0;
	for (int j = 0; j < n; ++j) {
		Q[j].angle = atan2(Q[j].y - P[i].y, Q[j].x - P[i].x);
		if (Q[j].y == P[i].y && Q[j].x < P[j].x) Q[j].angle = -PI;
	}
	sort(Q, Q + n, cmp);
	int pt = 1, ans = n;
	for (int j = 0; j < n; ++j) {
		int nex = (j + 1) % n;
		if (!area2(Q[j], P[i], Q[nex]) && abs(Q[j].angle - Q[nex].angle) < 0.5) {
			if (pt == nex) pt = (pt + 1) % n;
			continue; // Let next one test
		}
		while (area2(Q[j], P[i], Q[pt]) < 0) {
			pt = (pt + 1) % n;
		}
		int val = pt - j - 1;
		if (val < 0) val += n;
		ans = min(ans, val);
	}
	int ans2 = INT_MAX;
	for (int j = 0; j < n; ++j) {
		int v = 0;
		for (int k = 0; k < n; ++k)
			if (area2(Q[j], P[i], Q[k]) < 0) ++v;
		ans2 = min(ans2, v);
	}
	assert(ans2 == ans);
	return ans2;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) scanf("%d%d", &P[i].x, &P[i].y);
		printf("Case #%d:\n", cn);
		for (int i = 0; i < N; ++i) {
			printf("%d\n", calc(i));
		}
	}
}

