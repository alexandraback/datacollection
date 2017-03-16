#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int calc(vector< vector<int> > &a, int x, int y)
{
	return a[x-1][y] + a[x][y-1] + a[x+1][y] + a[x][y+1];
}
int solve(int n, int m, int num, int flag)
{
	vector< vector<int> > a;
	for (int i = 0; i <= n + 1; i++)
	{
		vector< int > mm;
		for (int j = 0; j <= m+1; j++)
			mm.push_back(0);
		a.push_back(mm);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			if ((i+j) % 2 == flag)
			{
				a[i][j] = 1;
				num--;
			}
	}
	if (num <= 0) return 0;
	if (a[1][1] == 0 && num > 0)
	{
		num--;
		a[1][1] = 1;
		ans += 2;
	}
	if (a[1][m] == 0 && num > 0)
	{
		num--;
		a[1][m] = 1;
		ans += 2;
	}
	if (a[n][1] == 0 && num > 0)
	{
		num--;
		a[n][1] = 1;
		ans += 2;
	}
	if (a[n][m] == 0 && num > 0)
	{
		num--;
		a[n][m] = 1;
		ans += 2;
	}
	for (int i = 1; i <= n && num > 0; i++)
	{
		if (num > 0 && a[i][1] == 0)
		{
			num--;
			ans += calc(a, i, 1);
			a[i][1] = 1;
		}
		if (num > 0 && a[i][m] == 0)
		{
			num--;
			ans += calc(a, i, m);
			a[i][m] = 1;
		}
	}

	for (int i = 1; i <= m && num > 0; i++)
	{
		if (num > 0 && a[1][i] == 0)
		{
			num--;
			ans += calc(a, 1, i);
			a[1][i] = 1;
		}
		if (num > 0 && a[n][i] == 0)
		{
			num--;
			ans += calc(a, n, i);
			a[n][i] = 1;
		}
	}
	if (num <= 0) return ans;
	for (int i = 2; i <= n && num > 0; i++)
		for (int j = 2; j <= m && num > 0; j++)
			if (num > 0 && a[i][j] == 0)
			{
				num--;
				a[i][j] = 1;
				ans += calc(a, i, j);
			}
	return ans;

}
int solve2(int n, int m, int num, int flag)
{
	int a[30001] = {0};
	int al = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if ((i+j)%2 == flag)
			{
				int k = 4;
				if (i == 1 || j == 1 || i == n || j == m) k = 3;
				if (i == 1 && j == 1) k = 2;
				if (i == 1 && j == m) k = 2;
				if (i == n && j == 1) k = 2;
				if (i == n && j == m) k = 2;
				a[al++] = k;
			} else
				a[al++] = 0;
	sort(a, a+al);
	int ans = 0;
	for (int i = 0; i < num; i++) ans += a[i];
	return ans;
}
int f[30][30][5000] = {0};
int use(int k)
{
	int num = 0;
	while (k){
		if (k&1) num++;
		k >>= 1;
	}
	return num;
}
int cc(int i, int j)
{
	int ans = use(i&j);
	int flag = 0;
	while (j)
	{
		if (flag && (j&1)) ans++;
		if (j&1) flag = 1;
		else flag = 0;
		j >>= 1;
	}
	return ans;
}
int solve3(int n, int m, int num, int flag)
{
	for (int i = 0; i <= n; i++)
		for (int l = 0; l <= num + 3; l++)
		for (int j = 0; j <= (1<<(1+m)); j++)
			f[i][l][j] = 100000;
	f[0][0][0] = 0;
	int vm = (1<<(m)) - 1;
	for (int i = 0; i < n; i++)
		for (int l = 0; l <= num; l++)
			for (int j = 0; j <= vm; j++)
				for (int k = 0; k <= vm; k++)
					if (f[i][l][j] + cc(j, k) < f[i+1][l+use(k)][k])
						f[i+1][l+use(k)][k] = f[i][l][j] + cc(j,k);
	int ans = 1000;
	for (int j = 0; j <= vm; j++)
		ans = min(ans, f[n][num][j]);
	return ans;
}
int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int tot;
	scanf("%d", &tot);
	for (int tt = 1; tt <= tot; tt++)
	{
		
		int n, m, num;
		scanf("%d%d%d", &n, &m, &num);
		if (n < m)
		{
			int tmp = n; n = m; m = tmp;
		}
		int ans1 = solve3(n, m, num, 0);
		int ans2 = solve3(n, m, num, 1);
		printf("Case #%d: %d\n", tt, min(ans1, ans2));
	}
	return 0;
}

