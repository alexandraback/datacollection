#include <cstdio>

const int N = 1000 + 10;

int n, a[N];

int main()
{
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		long long A = 0, B = 0, maxp = 0;
		for(int i = 1; i < n; i++)
		{
			if(a[i] > a[i+1]) A += a[i] - a[i+1];
			if(a[i] - a[i+1] > maxp) maxp = a[i] - a[i+1];
		}
		for(int i = 1; i < n; i++)
		{
			if(a[i] <= maxp) B += a[i];
			else B += maxp;
		}
		printf("Case #%d: %lld %lld\n", cas, A, B);
	}
	return 0;
}
