#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int n, a[1100], x, y;

int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int cas; scanf("%d", &cas);
	for (int t = 1; t <= cas; t++) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		printf("Case #%d: ", t);
		x = 0; y = 0;
		for (int i = 1; i < n; i++) {
			x += max(0, a[i-1] - a[i]);
			if (a[i] < a[i-1]) y = max(y, a[i-1] - a[i]);
		}
		printf("%d ", x);
		x = 0;
		for (int i = 1; i < n; i++) {
			x += min(a[i-1], y);
		}
		printf("%d\n", x);
	}
	return 0;
}
