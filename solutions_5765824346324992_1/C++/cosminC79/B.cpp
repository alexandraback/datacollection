#include <cstdio>
#define NMAX 1505
#define ll long long
int tests, n, m, A[NMAX];

inline int ok(ll val)
{
	ll res = 0;
	for (int i = 1; i <= n; i++)
		res += val / A[i] + 1;
	return res >= m;
}

ll cbin()
{
	ll step = (1LL << 60);
	ll i;
	for (i = -1; step; step >>= 1)
		if (!ok(i + step))
			i += step;
	return ++i;
}

int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	
	scanf("%d", &tests);
	for (int test_no = 1; test_no <= tests; test_no++)
	{
		printf("Case #%d: ", test_no);
		
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%d", &A[i]);
			
		ll t = cbin();
		
		int done_bf = 0;
		if (t > 0)
		{
			for (int i = 1; i <= n; i++)
				done_bf += (t - 1) / A[i] + 1;
		}
		
		int curr = m - done_bf;
		for (int i = 1; i <= n; i++)
			if (t % A[i] == 0)
			{
				curr--;
				if (curr == 0)
				{
					printf("%d\n", i);
					break ;
				}
			}
	}
	return 0;
}
