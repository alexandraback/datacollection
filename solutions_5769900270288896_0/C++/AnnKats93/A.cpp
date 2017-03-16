#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <ctime>
#include <cstdlib>
#include <map>
#include <queue>

using namespace std;


int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		int r, c, n;
		scanf("%d%d%d", &r, &c, &n);
		int rc = r * c;
		int ans = 100000000;
		for (int i = 0; i < (1 << rc); i++)
		{
			int cnt = 0;
			for (int j = 0; j < rc; j++) {
				if (i & (1 << j))
					cnt++;
			}
			if (cnt == n)
			{
				int res = 0;
				for (int j = 0; j < r; j++)
				{
					for (int k = 0; k < c; k++)
					{
						if (j != r - 1 && (i & (1 << (j * c + k))) && (i & (1 << ((j + 1) * c + k))))
							res++;
						if (k + 1 < c && (i & (1 << (j * c + k))) && (i & (1 << (j * c + k + 1))))
							res++;
					}
				}
				ans = min(ans, res);
			}
		}
		printf("Case #%d: %d\n", tt + 1, ans);
	}

	return 0;
}



/*
int dp[1000005];

int rev(int x)
{
	int ans = 0;
	while (x > 0)
		ans *= 10, ans += x % 10, x /= 10;
	return ans;
}

int main()
{
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("a.out", "w", stdout);
	dp[1] = 1;
	for (int i = 2; i <= 1000000; i++)
	{
		int re = rev(i);
		if (re < i && (i % 10 != 0))
			dp[i] = min(dp[i - 1], dp[re]) + 1;
		else
			dp[i] = dp[i - 1] + 1;
	}

	int t;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		int n;
		scanf("%d", &n);
		printf("Case #%d: %d\n", tt + 1, dp[n]);
	}


	return 0;
}
*/