#include <bits/stdc++.h>
using namespace std;

int dp[17][17][1 << 6], ans[17][17][17];

void update (int &x, int y) { if (y < x) x = y; }

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
	for (int i = 1; i <= t; ++i)
	{
		int n, m, k;
		cin >> n >> m >> k;
		if (n < m) swap(n, m);
		cout << "Case #" << i << ": " << ans[n][m][k] << endl;
	}
}
