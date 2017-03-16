#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int n, r, c;
bool ar[20][20];

bool good(int x, int y)
{
	return x >= 0 && x < r && y >= 0 && y < c;
}

int check()
{
	int res = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			res += good(i, j + 1) && ar[i][j] && ar[i][j + 1];
			res += good(i + 1, j) && ar[i][j] && ar[i + 1][j];
		}
	}
	return res;
}

int solve()
{
	int m = r * c;
	int res = 1e9;
	for (int i = 0; i < (1 << m); i++)
	{
		int cnt = 0;
		for (int j = 0; j < m; j++)
		{
			ar[j / c][j % c] = (i & (1 << j));
			cnt += ar[j / c][j % c];
		}
		if (cnt == n)
		{
			res = min(res, check());
		}
	}
	return res;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	for (int q = 0; q < t; q++)
	{
		scanf("%d%d%d", &r, &c, &n);
		printf("Case #%d: %d\n", q + 1, solve());
	}
	return 0;
}