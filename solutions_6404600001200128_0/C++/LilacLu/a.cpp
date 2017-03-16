#include <cstdio>

#define small

int T, n, x[1005];

int eatOne() {
	int ret = 0;
	for (int i = 1; i < n; ++i)
		if (x[i] < x[i - 1])
			ret += x[i - 1] - x[i];
	return ret;
}

int eatTwo() {
	int ret = 0, eatPerTenSec = 0;
	for (int i = 1; i < n; ++i) 
		if (x[i - 1] - x[i] > eatPerTenSec)
			eatPerTenSec = x[i - 1] - x[i];
	for (int i = 0; i < n - 1; ++i)
		ret += (x[i] >= eatPerTenSec ? eatPerTenSec : x[i]);
	return ret;
}

int main()
{
#ifdef small
  freopen("A-small.in", "r", stdin);
  freopen("A-small.out", "w", stdout);
#endif
#ifdef large
  freopen("A-large.in", "r", stdin);
  freopen("A-large.out", "w", stdout);
#endif
	scanf("%d", &T);
	for (int Case = 1; Case <= T; ++Case) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &x[i]);
		printf("Case #%d: %d %d\n", Case, eatOne(), eatTwo());
	}
	return 0;
}
