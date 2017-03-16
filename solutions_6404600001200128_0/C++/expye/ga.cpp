#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int T;
int n, a[1001], ans1, ans2;
int main() {
	freopen("small.in", "r", stdin);
	freopen("small.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d", &n);
		ans1 = 0; ans2 = 0;
		for (int j = 1; j <= n; j++) scanf("%d", &a[j]);
		for (int j = 2; j <= n; j++) if (a[j] < a[j - 1]) ans1 += a[j - 1] - a[j];
		int ms = 0;
		for (int j = 2; j <= n; j++) if (a[j - 1] - a[j] > ms)
			ms = a[j - 1] - a[j];
		for (int j = 1; j < n; j++) if (a[j] <= ms) ans2 += a[j];
			else ans2 += ms;
		printf("Case #%d: %d %d\n", i, ans1, ans2);
	}
	return  0;
}
