#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <functional>
#include <string>

void solve();
int main()
{
	int t;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		printf("Case #%d: ", i + 1);
		solve();
		printf("\n");
	}
}

void solve()
{
	int n, m[10000],s[10000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &m[i]);
		if (i != 0)
		{
			s[i-1] = m[i] - m[i - 1];
		}
	}
	int sum1 = 0, sum2 = 0;
	int min = INT_MAX;
	for (int i = 0; i < n - 1; i++)
	{
		if (s[i] < 0)
		{
			sum1 += s[i];
			if (min > s[i])
				min = s[i];
		}
	}
	if (min < 0)
	{
		min = -min;
		for (int i = 0; i < n-1; i++)
		{
			if (m[i] < min)
			{
				sum2 += m[i];
			}
			else
			{
				sum2 += min;
			}
		}
	}
	printf("%d %d", -sum1, sum2);
}