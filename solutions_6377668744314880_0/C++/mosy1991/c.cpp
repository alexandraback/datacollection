#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

struct node {
	int x, y;
};

typedef long long LL;

int n;
node a[20];

LL cal(node p1, node p2, node p3) {
	return LL(p2.x - p1.x) * LL(p3.y - p1.y) - LL(p3.x - p1.x) * LL(p2.y - p1.y);
}

int main() {
	int T, cases = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) 
			scanf("%d%d", &a[i].x, &a[i].y);
		printf("Case #%d:\n", ++cases);
		if (n < 3) {
			for (int i = 0; i < n; i++) 
				printf("%d\n", 0);
			continue;
		}
		for (int i = 0; i < n; i++) {
			int ans = n;
			for (int j = 0; j < n; j++) 
				if (i != j) {
					int l = 0, r = 0;
					for (int k = 0; k < n; ++k) 
						if (k != i && k != j) {
							LL tmp = cal(a[i], a[j], a[k]);
							if (tmp > 0) ++l; else
								if (tmp < 0) ++r;
						}
					ans = min(ans, min(l, r));
				}
			printf("%d\n", ans);
		}
	}
	return 0;
}
