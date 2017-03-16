/*************************************************************************
    > File Name: C.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年04月18日 星期六 11时02分00秒
 ************************************************************************/

#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <bitset>
#include <set>
#include <vector>

using namespace std;

const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;
typedef long long LL;
typedef pair <int, int> PLL;

const int N = 3300;
struct POINT
{
	LL x, y;
}point[N];

LL ans[N];

void solve(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			LL x = point[j].y - point[i].y;
			LL y = point[i].x - point[j].x;
			LL z = point[j].x * point[i].y - point[j].y * point[i].x;
			LL res1 = 0, res2 = 0;
			for (int k = 1; k <= n; ++k)
			{
				LL ret = x * point[k].x + z + y * point[k].y;
				if (ret == 0)
				{
					continue;
				}
				if (ret > 0)
				{
					++res1;
				}
				else
				{
					++res2;
				}
			}
			ans[i] = min(ans[i], min(res1, res2));
			ans[j] = min(ans[j], min(res1, res2));
		}
		cout << ans[i] << endl;
	}
}

int main()
{
//	freopen("C-small-attempt0.in", "r", stdin);
//	freopen("out.out", "w", stdout);
	int t;
	int icase = 1;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			cin >> point[i].x >> point[i].y;
			if (n == 1)
			{
				ans[i] = 0;
			}
			else
			{
				ans[i] = n;
			}
		}
		cout << "Case #" << icase++ << ":" << endl;
		solve(n);
	}
	return 0;
}
