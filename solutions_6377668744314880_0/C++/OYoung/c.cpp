#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

struct point {
	int x, y;
};

int n, ans, x, y;
point a[20];

int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int cas; scanf("%d", &cas);
	for (int t = 1; t <= cas; t++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d%d", &a[i].x, &a[i].y);
		printf("Case #%d:\n", t);
		if (n < 3) {
			for (int i = 0; i < n; i++) puts("0");
			continue;
		}
		long long ax, ay, bx, by, c;
		for (int i = 0; i < n; i++) {
			ans = n;
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				x = y = 0;
				ax = a[j].x - a[i].x; ay = a[j].y - a[i].y;
				for (int k = 0; k < n; k++) {
					if (k == i) continue;
					if (k == j) continue;
					bx = a[k].x - a[i].x; by = a[k].y - a[i].y;
					c = ax * by - bx * ay;
					if (c == 0) continue;
					if (c > 0) ++x; else ++y;
				}
				ans = min(ans, min(x, y));
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
