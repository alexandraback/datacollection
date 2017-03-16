#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <set>
using namespace std;

int a[20][20], r, c, n;
int ans;

void check()
{
	int tmp = 0;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			if (a[i][j])
		{
			if (i < r-1 && a[i+1][j]) ++tmp;
			if (j < c-1 && a[i][j+1]) ++tmp;
		}
	if (ans > tmp)
		ans = tmp;
}

void doit(int x, int y, int k)
{
	if (k == n)
		check();
	++y;
	if (y == c)
	{
		y = 0;
		++x;
		if (x == r)
			return;
	}
	doit(x,y,k);
	++k;
	a[x][y] = 1;
	doit(x,y,k);
	a[x][y] = 0;
}

void solve()
{
	scanf("%d%d%d", &r, &c, &n);
	ans = 10000;
	memset(a, 0, sizeof(a));
	doit(0, -1, 0);
	printf("%d\n", ans);
}

int main()
{
	freopen("a.txt", "r", stdin);
	freopen("b.out", "w", stdout);
	int times;
	scanf("%d", &times);
	for (int i = 1; i <= times; ++i)
	{
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}