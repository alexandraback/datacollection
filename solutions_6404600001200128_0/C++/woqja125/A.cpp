#include<stdio.h>
#pragma warning(disable:4996)
int a[1001];
void solve()
{
	int n, i, s=0, s1=0, m=0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)scanf("%d", a + i);
	for (i = 2; i <= n; i++)
	{
		if (a[i - 1] > a[i])
		{
			s += a[i - 1] - a[i];
			if (a[i - 1] - a[i] > m) m = a[i - 1] - a[i];
		}
	}
	for (i = 1; i < n; i++)
	{
		if (a[i] < m) s1 += a[i];
		else s1 += m;
	}
	printf("%d %d\n", s, s1);
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}