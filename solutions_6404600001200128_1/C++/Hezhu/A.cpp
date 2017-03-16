#include <cstdio>

int a[1000];

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &a[i]);
		}
		long long ans1 = 0;
		int maxa = 0;
		for (int i = 1; i < N; ++i)
		{
			if (a[i] < a[i - 1])
			{
				ans1 += a[i - 1] - a[i];
			}
			if (a[i - 1] - a[i] > maxa)
			{
				maxa = a[i - 1] - a[i];
			}
		}
		long long ans2 = 0;
		for (int i = 1; i < N; ++i)
		{
			if (a[i - 1] < maxa)
			{
				ans2 += a[i - 1];
			}
			else
			{
				ans2 += maxa;
			}
		}
		printf("Case #%d: %lld %lld\n", kase, ans1, ans2);
	}
	return 0;
}
