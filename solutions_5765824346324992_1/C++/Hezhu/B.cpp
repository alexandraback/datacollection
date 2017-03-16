#include <cstdio>
#include <cstring>

int m[1000];
long long time[1000];

inline long long ceil(long long a, long long b)
{
	if (a % b == 0)
	{
		return a / b;
	}
	return a / b + 1;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int B, N;
		scanf("%d %d", &B, &N);
		for (int i = 0; i < B; ++i)
		{
			scanf("%d", &m[i]);
		}
		long long L = 0;
		long long R = 100000000000000;
		while (1)
		{
			if (R - L <= 1)
			{
				break;
			}
			long long M = (L + R) >> 1;
			long long turn = 0;
			for (int i = 0; i < B; ++i)
			{
				turn += ceil(M, m[i]);
			}
			if (turn < N)
			{
				L = M;
			}
			else
			{
				R = M;
			}
		}
		long long turn = 0;
		for (int i = 0; i < B; ++i)
		{
			turn += ceil(L, m[i]);
		}
		int last = -1;
		for (int i = 0; i < B; ++i)
		{
			time[i] = ceil(L, m[i]) * m[i];
		}
		for (int i = 0; i < N - turn; ++i)
		{
			long long mint = 1000000000000000;
			int mintindex = -1;
			for (int j = 0; j < B; ++j)
			{
				if (time[j] < mint)
				{
					mintindex = j;
					mint = time[j];
				}
			}
			time[mintindex] += m[mintindex];
			last = mintindex + 1;
		}
		printf("Case #%d: %d\n", kase, last);
	}
	return 0;
}
