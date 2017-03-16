#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int tab[20][20];

int ans = 10000;
int r, c, n;

void dfs(int x, int y)
{
	if (x > r)
	{
		int cnt = 0;
		int cur = 0;
		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				cnt += tab[i][j];
				if (tab[i][j])
				{
					cur += (tab[i][j] == tab[i][j + 1]);
					cur += (tab[i][j] == tab[i][j - 1]);
					cur += (tab[i][j] == tab[i - 1][j]);
					cur += (tab[i][j] == tab[i + 1][j]);
				}
			}
		}
		if (cnt == n)
		{
			ans = min(ans, cur);
		}
		return;
	}
	tab[x][y] = 1;
	if (y == c)
	{
		dfs(x + 1, 1);
	}
	else
	{
		dfs(x, y + 1);
	}
	tab[x][y] = 0;
	if (y == c)
	{
		dfs(x + 1, 1);
	}
	else
	{
		dfs(x, y + 1);
	}
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		for (int j = 1; j < 20; j++)
		{
			for (int tj = 1; tj < 20; tj++)
			{
				tab[j][tj] = 0;
			}
		}
		cin >> r >> c >> n;
		ans = (int)1e9;
		dfs(1, 1);
		cout << "Case #" << i << ": " << ans / 2 << endl;
	}

	return 0;
}