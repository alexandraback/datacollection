#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <functional>
using namespace std;

#pragma comment(linker,"/STACK:100000000")

int solve(int n, int base, int corner, int sides, int inner, int sub)
{
	if (n <= base)
		return 0;
	if (n <= base + corner)
		return (n - base)*(2 - sub);
	if (n <= base + corner + sides)
		return (n - base - corner)*(3 - sub) + corner*(2 - sub);
	return (n - base - corner - sides)*4 + sides*3 + corner*2;
}

void solve(int t)
{
	int r, c, n;
	scanf("%d%d%d", &r, &c, &n);
	int corner1 = 0, corner2 = 0;
	int sides1 = 0, sides2 = 0;
	int inner1 = 0, inner2 = 0;
	int base1 = 0, base2 = 0;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if ((i == 0 || i == r - 1) && (j == 0 || j == c - 1))
			{
				if ((i + j) % 2 == 0)
					corner1++;
				else
					corner2++;
			}
			else if (i == 0 || i == r - 1 || j == 0 || j == c - 1)
			{
				if ((i + j) % 2 == 0)
					sides1++;
				else
					sides2++;
			}
			else
			{
				if ((i + j) % 2 == 0)
					inner1++;
				else
					inner2++;
			}
			if ((i + j) % 2 == 0)
				base2++;
			else
				base1++;
		}
	}
//	printf("%d %d %d %d\n", base1, corner1, sides1, inner1);
//	printf("%d %d %d %d\n", base2, corner2, sides2, inner2);
	int ans = min(solve(n, base1, corner1, sides1, inner1, (r == 1 || c == 1)), solve(n, base2, corner2, sides2, inner2, (r == 1 || c == 1)));
	printf("Case #%d: %d\n", t, ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		solve(i + 1);
	}
	return 0;
}