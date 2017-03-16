#include <bits/stdc++.h>

using namespace std;

const int N = 1000 +10;

int a[N];

int main() {
	int t;
	scanf("%d", &t);
	for(int kase = 1; kase <= t; kase++) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++)	scanf("%d", a+i);
		int x = 0, y = 0;
		for(int i = 0; i < n-1; i++) {
			x += max(0, a[i]-a[i+1]);
			y = max(y, a[i]-a[i+1]);
		}
		int ans1 = x, ans2 = 0;
		for(int i = 0; i < n-1; i++)	ans2 += min(a[i], y);

		printf("Case #%d: %d %d\n", kase, ans1, ans2);
	}

	return 0;
}
