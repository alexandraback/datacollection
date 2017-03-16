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

int getAns(int r, int c, int n)
{
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
			if (res < ans) {
				ans = res;
				/*for (int j = 0; j < r; j++)
				{
					for (int k = 0; k < c; k++)
					{
						if ((i & (1 << (j * c + k))))
							printf("%d %d\n", j, k);
					}
				}
				res = 0;
				for (int j = 0; j < r; j++)
				{
					for (int k = 0; k < c; k++)
					{
						if (j != r - 1 && (i & (1 << (j * c + k))) && (i & (1 << ((j + 1) * c + k))))
							res++;
						if (k + 1 < c && (i & (1 << (j * c + k))) && (i & (1 << (j * c + k + 1))))
							res++;
					}
				}*/
			}
			//ans = min(ans, res);
		}
	}
	return ans;
}

vector<vector<int> > ve;

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		int r, c, n, nn;
		scanf("%d%d%d", &r, &c, &n);

		if (r > c)
			swap(r, c);
		nn = n;
		//int ans1 = getAns(r, c, n);

		int ans2 = 0, ans3 = 0;

		if (r == 1)
		{
			int zero = c - c / 2, one = (c % 2 == 0), two = c - zero - one;
			n -= zero;
			if (n > 0)
				ans2 += 1 * min(n, one), n -= one;
			if (n > 0)
				ans2 += 2 * min(n, two), n -= two;

			n = nn;
			zero = c / 2, one = (c % 2 == 0) * 1 + (c % 2 == 1) * 2, two = c - zero - one;
			n -= zero;
			if (n > 0)
				ans3 += 1 * min(n, one), n -= one;
			if (n > 0)
				ans3 += 2 * min(n, two), n -= two;
		}
		else
		{
			int zero = r * c - (r * c) / 2,
				four = max(0, r - 2) * max(0, c - 2) / 2,
				two = (r % 2 == 0 || c % 2 == 0) * 2,
				three = r * c - zero - two - four;
			n -= zero;
			if (n > 0)
				ans2 += 2 * min(two, n), n -= two;
			if (n > 0)
				ans2 += 3 * min(three, n), n -= three;
			if (n > 0)
				ans2 += 4 * min(four, n), n -= four;

			n = nn;
			zero = (r * c) / 2;
			four = max(0, r - 2) * max(0, c - 2) - max(0, r - 2) * max(0, c - 2) / 2;
			two = 4 - two;
			three = r * c - zero - two - four;
			n -= zero;
			if (n > 0)
				ans3 += 2 * min(two, n), n -= two;
			if (n > 0)
				ans3 += 3 * min(three, n), n -= three;
			if (n > 0)
				ans3 += 4 * min(four, n), n -= four;
		}
		/*if (min(ans2, ans3) != ans1)
			printf("%d %d %d: %d %d\n", r, c, nn, ans1 ,min(ans2, ans3));*/
		printf("Case #%d: %d\n", tt + 1, min(ans2, ans3));
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