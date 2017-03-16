#pragma comment(linker, "/STACK:134217728")

#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <complex>
#include <memory.h>
#include <time.h>

using namespace std;

typedef long long LL;

int n, t, r, c;

bool bound(int x, int y)
{
	return x >= 0 && y >= 0 && x < r && y < c;
}

int a[16][16];

int go(int x, int y, int k)
{
	if (x == r)
		return k == 0 ? 0 : (int)1e9;
	if (y == c)
		return go(x + 1, 0, k);
	int res = go(x, y + 1, k);
	a[x][y] = 1;
	if (k > 0)
		res = min(res, go(x, y + 1, k - 1) + (x == 0 ? 0 : a[x - 1][y]) + (y == 0 ? 0 : a[x][y - 1]));
	a[x][y] = 0;
	return res;
}

int main()
{
	freopen("B-small-attempt0 (5).in", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);

	for(int it = 1; it <= t; ++it)
	{
		scanf("%d%d%d", &r, &c, &n);
		printf("Case #%d: %d\n", it, go(0, 0, n));
	}
	return 0;
}