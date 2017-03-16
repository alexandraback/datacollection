#include <cstdio>
#include <algorithm>

int a[1000];

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t)
	{
		int rate = 0;

		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);

			rate = std::max(rate, a[i - 1] - a[i]);
		}

		int ans1 = 0;
		for (int i = 1; i < n; ++i)
		{
			ans1 += std::max(a[i - 1] - a[i], 0);
		}

		int ans2 = 0;
		for (int i = 0; i < n - 1; ++i)
		{
			ans2 += std::min(a[i], rate);
		}

		printf("Case #%d: %d %d\n", t, ans1, ans2);
	}

	return 0;
}
