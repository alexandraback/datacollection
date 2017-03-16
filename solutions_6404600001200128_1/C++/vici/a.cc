#include <bits/stdc++.h>
using namespace std;
int const N = 1010;
int a[N];
int n;

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large-ans.out", "w", stdout);
	int T, ca = 1;
	for (scanf("%d", &T); T--; ) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		int r = 0, mx = 0;
		for (int i = 1; i < n; ++i) {
			mx = max(mx, a[i - 1] - a[i]);
			r += max(0, a[i - 1] - a[i]);
		}
		int u = 0, s = 0;
		for (int i = 0; i < n - 1; ++i) {
			u += min(a[i], mx);
		}
		printf("Case #%d: %d %d\n", ca++, r, u);
	}
	return 0;
}

