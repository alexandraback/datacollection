#include <cstdio>
#include <algorithm>
using namespace std;

int T, a[2100], n;

int main() {
	scanf("%d", &T);
	for (int xx = 1; xx <= T; xx++) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		int ans1 = 0;
		for (int i = 1; i < n; i++)
			if (a[i] > a[i + 1]) ans1 += a[i] - a[i + 1];
		int ans2 = 2000000000;
		for (int r = 0; r <= 10000; r++) {
			bool ok = true;
			int tmp = 0;
			for (int i = 1; i < n; i++) {
				tmp += min(a[i], r);
				if (a[i] - r > a[i + 1]) ok = false;
				// tmp += min()
			}
			if (ok) {
				ans2 = min(ans2, tmp);
				break;
			}
		}
		printf("Case #%d: %d %d\n", xx, ans1, ans2);
	}
}
