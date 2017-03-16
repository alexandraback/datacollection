#include <cstdio>

int N, My;
int M[100000];

int Work()
{
	scanf("%d%d", &N, &My); 
	for (int i = 0; i < N; i ++)
		scanf("%d", &M[i]);
	long long L = 0, R = 1000000000000000LL, Ans = -1;
	while (L <= R)
	{
		long long Mid = (L + R) >> 1;
		//printf("%lld %lld %lld\n", L, R, Mid);
		long long Count = 0;
		for (int i = 0; i < N; i ++)
			Count += (Mid / (long long) M[i]) + 1LL;
		if (Count >= My)
		{
			Ans = Mid;
			R = Mid - 1;
		}
		else
			L = Mid + 1;
	} 
	long long Before = 0;
	for (int i = 0; i < N; i ++)
		if (Ans >= 1)
			Before += ((Ans - 1) / M[i]) + 1;
	for (int i = 0; i < N; i ++)
		if (Ans % M[i] == 0)
		{
			Before ++;
			if (Before == My)
				return i + 1;
		}
	return -1;
}

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int Cases;
	scanf("%d", &Cases);
	for (int Case = 1; Case <= Cases; Case ++)
	{
		printf("Case #%d: %d\n", Case, Work());
	}
	return 0;
}
