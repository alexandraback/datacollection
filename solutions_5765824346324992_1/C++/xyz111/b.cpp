#include <cstdio>
#include <algorithm>
using namespace std;

int T, b, n, d[2000];

bool ok(long long x, long long y) {
	for (int i = 1; i <= b; i++)
		y = max(y - x / d[i] - 1, 0LL);
	return y == 0;
}

int main() {
	scanf("%d", &T);
	for (int xx = 1; xx <= T; xx++) {
		scanf("%d%d", &b, &n);
		for (int i = 1; i <= b; i++)
			scanf("%d", &d[i]);
		long long q = -1, h = 1e18, mid;
		while (q < h - 1) {
			mid = (q + h) / 2;
			if (ok(mid, n)) h = mid;
			else q = mid;
		}
		int t = 0;
		for (int i = 1; i <= b; i++)
			t += h / d[i] + 1;
		int l = t - n, ans = 0;
		for (int i = b; i; i--)
			if (h % d[i] == 0) {
				if (!l) ans = i;
				l--;
			}
		printf("Case #%d: %d\n", xx, ans);
	}
}
