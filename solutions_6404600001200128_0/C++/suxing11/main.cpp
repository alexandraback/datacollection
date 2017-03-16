#include <stdio.h>


int n;
int a[1010];


int gao1()
{
	int ans = 0, i;
	for (i = 1; i < n; i++)
		if (a[i] < a[i-1]) ans += a[i-1] - a[i];
	return ans;
}


int max(int a, int b){return a>b?a:b;}


int gao2()
{
	int rate = 0;
	int i;
	int ans = 0;
	for (i = 1; i < n; i++) if (a[i] < a[i-1])
		rate = max(rate, a[i-1] - a[i]);
	
	for (i = 0; i < n-1; i++)
	{
		if (a[i] >= rate)
			ans += rate;
		else
			ans += a[i];
	}
	return ans;
}


int main()
{
	int T, cas, i;
	freopen ("A-small-attempt0.in", "r", stdin);
	freopen ("out.txt", "w", stdout);
	scanf ("%d", &T);
	for (cas = 1; cas <= T; cas++)
	{
		scanf ("%d", &n);
		for (i = 0; i < n; i++)
			scanf ("%d", &a[i]);
		printf ("Case #%d: %d %d\n", cas, gao1(), gao2());
	}
	return 0;
}
