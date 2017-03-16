#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int T, n, a[10010];

int main()
{
	scanf("%d", &T);
	for (int ca = 1; ca <= T; ++ca) {
		memset(a, 0, sizeof(a));
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		int ans1 = 0, ans2 = 0, maxg = 0;
		for (int i = 1; i < n; ++i) {
			maxg = max(maxg, a[i] - a[i + 1]);
			if (a[i] > a[i + 1]) ans1 += a[i] - a[i + 1];
		}
		for (int i = 1; i < n; ++i)
			ans2 += min(a[i], maxg);
		printf("Case #%d: %d %d\n", ca, ans1, ans2);
	}
	return 0;
}
