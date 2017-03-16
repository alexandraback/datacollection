// Problem B. Haircut
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
	int T;
	scanf("%d\n", &T);
	for (int ti = 1; ti <= T; ti++) {
		int m, n, ans = 0;
		static int a[1024];
		scanf("%d %d", &m, &n);
		for (int i = 0; i < m; i++) scanf("%d", &a[i]);

		long long lo = 0, hi = 100000000000000L, mi;
		while (lo < hi) {
			mi = lo + (hi - lo) / 2;
			long long c = m;
			for (int i = 0; i < m; i++)
				c += mi / a[i];
			if (c < n) lo = mi + 1;
			else hi = mi;
		}

		if (lo > 0) {
			int t = m;
			for (int i = 0; i < m; i++)
				t += (lo - 1) / a[i];
			for (int i = 0; i < m; i++) {
				if (lo % a[i] == 0) t++;
				if (t >= n) {
					ans = i + 1;
					break;
				}
			}
		} else {
			ans = n;
		}

		printf("Case #%d: %d\n", ti, ans);
	}
	return 0;
}
