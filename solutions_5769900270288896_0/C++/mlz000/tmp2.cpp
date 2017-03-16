#include <bits/stdc++.h>//brute force
using namespace std;
const int N = 30;
int a[N];
int main() {
	int n, m, k, T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; ++tt) {
		printf("Case #%d: ", tt);
		scanf("%d%d%d", &n, &m, &k);
		int sum = n * m;
		int ans = INT_MAX;
		for (int t = 0; t < (1 << sum); ++t) {
			memset(a, 0, sizeof(a));
			for (int i = 0; i < sum; ++i) 
				if ((t >> i & 1) != 0)	a[i] = 1;//mask
			int tmp = 0;
			for (int i = 0; i < sum; ++i) tmp += a[i];
			if (tmp != k) continue;
			tmp = 0;
			for (int i = 0; i < sum; ++i) {
				if (!a[i]) continue;
				int j = i - m;
				if (j >= 0 && a[j] == 1) ++tmp;
				j = i + m;
				if (j < sum && a[j] == 1) ++tmp;
				if (i % m != 0 && a[i - 1] == 1) ++tmp;
				if (i % m != m - 1 && a[i + 1] == 1) ++tmp;
			}
			ans = min(ans, tmp);
		}
		ans >>= 1;
		printf("%d\n", ans);
	}
	return 0;
}

