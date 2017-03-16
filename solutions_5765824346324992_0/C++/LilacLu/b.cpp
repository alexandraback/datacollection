#include <cstdio>

#define small

int T, b, n, m[1005];

bool isAns(const long long& x) {
	long long tot = 0;
	for (int i = 0; i < b; ++i)
		tot += x / m[i] + 1;
	return tot >= n;
}

int binarySearch() {
	long long bot = 0, top = n * 100000LL, mid;
	while (bot + 1 < top) {
		mid = (bot + top) >> 1;
		if (isAns(mid))
			top = mid;
		else
			bot = mid + 1;
	}
	long long ans;
	if (isAns(top))
		ans = top;
	if (isAns(bot))
		ans = bot;
	for (int i = 0; i < b; ++i)
		n -= ans / m[i] + (ans % m[i] ? 1 : 0);
	for (int i = 0; i < b; ++i)
		if (ans % m[i] == 0 && (--n == 0))
			return i + 1;
}

int main()
{
#ifdef small
  freopen("B-small.in", "r", stdin);
  freopen("B-small.out", "w", stdout);
#endif
#ifdef large
  freopen("B-large.in", "r", stdin);
  freopen("B-large.out", "w", stdout);
#endif
	scanf("%d", &T);
	for (int Case = 1; Case <= T; ++Case) {
		scanf("%d %d", &b, &n);
		for (int i = 0; i < b; ++i)
			scanf("%d", &m[i]);
		printf("Case #%d: %d\n", Case, binarySearch());
	}
	return 0;
}
