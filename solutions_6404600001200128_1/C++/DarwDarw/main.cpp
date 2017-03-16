#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;
int m[1001];

int solve1()
{
	int ans = 0;
	for (int i = 1; i < n; i++)
	{
		if (m[i] < m[i-1]) ans += m[i-1]-m[i];
	}
	return ans;
}

int solve2()
{
	int rate = 0;
	int ans = 0;
	for (int i = 1; i < n; i++)
	{
		if (m[i] <= m[i-1])
		{
			rate = max(m[i-1] - m[i], rate);
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		ans += min(m[i], rate);
	}
	return ans;
}

int main()
{
	freopen("a-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &m[j]);
		}
		printf("Case #%d: %d", i + 1, solve1());
		printf(" %d\n", solve2());
	}
}