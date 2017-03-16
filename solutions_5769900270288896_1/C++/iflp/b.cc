#include <bits/stdc++.h>
using namespace std;

int dp[17][17][1 << 6], ans[17][17][17];

void update (int &x, int y) { if (y < x) x = y; }

int calc2 (int n, int m, int k)
{
	if (k * 2 <= n * m) return 0;
	if (n % 2) swap(n, m);
	if (n % 2)
	{
		if (n == 1 && m == 1) return 0;
		if (n == 1)
		{
			int gres = 0;
			// cond. 1
			int rst = k - (n * m / 2);
			int res = 1 * min(rst, 2);
			if (rst <= 2) return res;
			rst -= 2;
			gres = res + 2 * rst;
			// cond. 2
			rst = k - (n * m / 2) + 1;
			gres = min(gres, res + 2 * rst);
			return gres;
		}
		else
		{
			int gres = 0;
			// cond. 1
			int rst = k - (n * m / 2);
			int res = 2 * min(rst, 4);
			if (rst <= 4) return res;
			rst -= 4;
			res += 3 * min(rst, 2 * (n + m - 2) - 4);
			if (rst <= 2 * (n + m - 2) - 4) return res;
			rst -= 2 * (n + m - 2) - 4;
			gres = res + 4 * rst;
			// cond. 2
			rst = k - (n * m / 2) + 1;
			res = 3 * min(rst, 2 * (n + m - 2));
			if (rst <= 2 * (n + m - 2)) return res;
			rst -= 2 * (n + m - 2);
			gres = min(gres, res + 4 * rst);
			return gres;
		}
		return 0;
	}
	else
	{
		int rst = k - (n * m / 2);
		if (rst <= 2) return 2 * rst;
		rst -= 2;
		int res = 4 + 3 * min(rst, 2 * (n + m - 2) - 2);
		if (rst <= 2 * (n + m - 2) - 2) return res;
		rst -= 2 * (n + m - 2) - 2;
		return res + 4 * rst;
	}
}


void init (int n, int m)
{
	if (n < m) swap(n, m);
	memset(dp, 0x3f, sizeof dp);
	dp[0][0][0] = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0, je = 1 << m; j < je; ++j)
		{
			for (int k = 0, ke = 1 << m; k < ke; ++k)
			{
				for (int l = 0; l + __builtin_popcount(k) <= n * m; ++l)
				{
					update(dp[i + 1][l + __builtin_popcount(k)][k],
						   dp[i][l][j] + __builtin_popcount(k & j) +
						   __builtin_popcount(k & (k >> 1)));
				}
			}
		}
	}
	ans[n][m][0] = 0;
	for (int i = 1; i <= n * m; ++i)
		for (int k = 0; k < (1 << m); ++k)
			update(ans[n][m][i], dp[n][i][k]);
}

int main ()
{
	memset(ans, 0x3f, sizeof ans);
	for (int i = 1; i <= 16; ++i)
		for (int j = 1; j * i <= 16 && j <= i; ++j)
			init(i, j);
	int t;
	cin >> t;
	for (int i = 1; i <= 16; ++i)
		for (int j = 1; j * i <= 16 && j <= i; ++j)
		{
			for (int k = 1; k <= i * j; ++k)
			{
				if (calc2(i, j, k) != ans[i][j][k])
				{
				}
			}
		}
	for (int i = 1; i <= t; ++i)
	{
		int n, m, k;
		cin >> n >> m >> k;
		if (n < m) swap(n, m);
		cout << "Case #" << i << ": " << calc2(n, m, k) << endl;
	}
}
