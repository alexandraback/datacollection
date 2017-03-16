#pragma comment (linker,"/STACK:256000000")
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <cassert>
#include <string>
using namespace std;

#define INF 1000000000
#define lint long long
#define pb push_back
#define MOD 1000000007
#define mp make_pair

int ans;
int d[20][20];

void solve(int a, int b, int r, int c, int n, int f)
{
	if (a == r + 1 && b == 1)
	{
		if (n == 0)
			ans = min(ans, f);
		return;
	}
	if (n)
	{
		d[a][b] = 1;
		int na = a;
		int nb = b + 1;
		if (nb > c)
		{
			nb = 1;
			++na;
		}
		int nf = f + d[a][b - 1] + d[a - 1][b];
		solve(na, nb, r, c, n - 1, nf);
	}
	d[a][b] = 0;
	int na = a;
	int nb = b + 1;
	if (nb > c)
	{
		nb = 1;
		++na;
	}
	solve(na, nb, r, c, n, f);
}
int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tc, T=1;
	scanf("%d", &tc);
	while (tc--)
	{
		int r, c, n;
		scanf("%d %d %d", &r, &c, &n);

		ans = INF;
		solve(1, 1, r, c, n, 0);
		printf("Case #%d: %d\n", T++, ans);
	}
	return 0;
}