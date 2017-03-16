#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3fffffff

using namespace std;

char a[20][20];
int r, c, n;
int ans;

void dfs(int stp, int x, int y)
{
	int i, j, k;
	if (stp == n) // placed all
	{
		int res = 0;
		for (i = 0; i < r; i++)
			for (j = 0; j < c-1; j++)
				if (a[i][j] && a[i][j+1])
					res++;
		for (i = 0; i < r-1; i++)
			for (j = 0; j < c; j++)
				if (a[i][j] && a[i+1][j])
					res++;
		ans = min(ans, res);
		return ;
	}
	if (x == -1 && y == -1)
	{
		a[0][0] = 1;
		dfs(stp+1, 0, 0);
		a[0][0] = 0;
		dfs(stp, 0, 0);
	}
	else
	{
		int nx = x, ny = y + 1;
		if (ny >= c)
		{
			ny = 0;
			nx++;
		}
		if (nx < r)
		{
			a[nx][ny] = 1;
			dfs(stp+1, nx, ny);
			a[nx][ny] = 0;
			dfs(stp, nx, ny);
		}
	}
}

int main()
{
	int i, j, t;
	scanf("%d", &t);
	for (int cases = 1; cases <= t; cases++)
	{
		scanf("%d%d%d", &r, &c, &n);
		ans = INF;
		memset(a, 0, sizeof(a));
		dfs(0, -1, -1);
		printf("Case #%d: %d\n", cases, ans);
	}
	return 0;
}
