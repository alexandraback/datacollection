/*************************************************************************
    > File Name: A.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年04月18日 星期六 08时40分24秒
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

vector <int> mush;

int main()
{
	int icase = 1;
	int t;
//	freopen("A-small-attempt0.in", "r", stdin);
//	freopen("out.out", "w", stdout);
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		int u;
		mush.clear();
		int maxs = 0;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &u);
			mush.push_back(u);
		}
		int ans1 = 0, ans2 = 0;
		for (int i = 1; i < n; ++i)
		{
			if (mush[i] < mush[i - 1])
			{
				ans1 += mush[i - 1] - mush[i];
				maxs = max(maxs, mush[i - 1] - mush[i]);
			}
		}
		for (int i = 0; i < n - 1; ++i)
		{
			if (maxs < mush[i])
			{
				ans2 += maxs;
			}
			else
			{
				ans2 += mush[i];
			}
		}
		printf("Case #%d: %d %d\n", icase++, ans1, ans2);

	}
	return 0;
}
