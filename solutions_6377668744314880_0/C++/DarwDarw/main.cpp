#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void solve()
{
	int n;
	int x[3001], y[3001];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &x[i], &y[i]);
	if (n == 1) 
	{
		printf("0\n");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		int ans = n;
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;
			int above = 0;
			int below = 0;
			for (int k = 0; k < n; k++)
			{
				if (i == k ||  j == k) continue;
				if ((long long)(x[k] - x[i]) * (y[k] - y[j]) - (long long)(x[k] - x[j]) * (y[k] - y[i]) > 0) above++;
				if ((long long)(x[k] - x[i]) * (y[k] - y[j]) - (long long)(x[k] - x[j]) * (y[k] - y[i]) < 0) below++;
			}
			ans = min(ans, min(above, below));
		}
		printf("%d\n", ans);
	}
}

int main()
{
	freopen("c-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		printf("Case #%d:\n", i + 1);
		solve();
	} 
}