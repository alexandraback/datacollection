#include <cstdio>
#include <cstring>

int m[5];
int time[5];

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b)
{
	int g = gcd(a, b);
	return a / g * b;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int B, N;
		scanf("%d %d", &B, &N);
		int g = 1;
		for (int i = 0; i < B; ++i)
		{
			scanf("%d", &m[i]);
			g = lcm(g, m[i]);
		}
		int turn = 0;
		for (int i = 0; i < B; ++i)
		{
			turn += g / m[i];
		}
		N = (N - 1) % turn + 1;
		memset(time, 0, sizeof time);
		int last = 1;
		for (int i = 0; i < N; ++i)
		{
			int mintime = 1999999999;
			int mintimeindex = -1;
			for (int j = 0; j < B; ++j)
			{
				if (time[j] < mintime)
				{
					mintime = time[j];
					mintimeindex = j;
				}
			}
			time[mintimeindex] += m[mintimeindex];
			last = mintimeindex + 1;
		}
		printf("Case #%d: %d\n", kase, last);
	}
	return 0;
}
