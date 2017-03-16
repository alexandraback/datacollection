#include <bits/stdc++.h>
using namespace std;
int const N = 101;
typedef __int64 ll;

struct Point {
    ll x, y;
    friend bool operator < (Point a, Point b) {
        if (a.y == b.y) return a.x < b.x;
        else return a.y < b.y;
    }
} p0[N], p[N], res[N];

ll Xmul(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

ll Xmul(Point b, Point c) {
    return b.x * c.y - c.x * b.y;
}
int Graham(Point pnt[], int n, Point res[]) {
    int i, j, top = 1;
    sort(pnt, pnt + n);
    pnt[n] = pnt[0];
    if (n == 0) return 0; res[0] = pnt[0];
    if (n == 1) return 1; res[1] = pnt[1];
    if (n == 2) return 2; res[2] = pnt[2];
    for (i = 2; i < n; ++i) {
        while (top && Xmul(res[top - 1], res[top], pnt[i]) <= 0) --top;
        res[++top] = pnt[i];
    }
    j = top;
    res[++top] = pnt[n - 2];
    for (i = n - 3; i >= 0; --i) {
        while (top != j && Xmul(res[top - 1], res[top], pnt[i]) <= 0) --top;
        res[++top] = pnt[i];
    }
    res[top] = res[0];
    return top;
}

ll xmul(Point a, Point b, Point c)  { 
	return (b.x - a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}

bool isPointOnSegment(Point p, Point p1, Point p2) {
  if(Xmul(p1, p2, p) != 0) return false ;
  if((p.x > p1.x && p.x > p2.x) || (p.x < p1.x && p.x < p2.x)) return false;
  if((p.y > p1.y && p.y > p2.y) || (p.y < p1.y && p.y < p2.y)) return false;
  return true;   
}
int ans[N];

int main() {
		freopen("C-small-attempt1.in", "r", stdin);
	//freopen("B-large.in", "r", stdin);
	freopen("C-small-ans.out", "w", stdout);
	int T, n, ca = 1;
	for (scanf("%d", &T); T--; ) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%I64d %I64d", &p0[i].x, &p0[i].y);
		}
		memset(ans, 0x3f, sizeof ans);
		p0[n].x = p0[0].x, p0[n].y = p0[0].y;
		int m = 1 << n;
		for (int i = 0; i < m; ++i) {
			int t = 0;
			for (int j = 0; j < n; ++j) {
				if (i >> j & 1) {
					p[t].x = p0[j].x;
					p[t].y = p0[j].y;
					++t;
				}
			}
			p[t].x = p[0].x, p[t].y = p[0].y;
			int g = Graham(p, t, res);
			for (int j = 0; j < n; ++j) if (i >> j & 1) {
				for (int k = 1; k <= g; ++k) {
					if (isPointOnSegment(p0[j], res[k - 1], res[k])) {
						ans[j] = min(ans[j], n - t);
					}
				}
			}
		}
		printf("Case #%d:\n", ca++);
		for (int i = 0; i < n; ++i) {
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}


