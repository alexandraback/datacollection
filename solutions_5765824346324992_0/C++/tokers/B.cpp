/*************************************************************************
    > File Name: B.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年04月18日 星期六 09时38分54秒
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
typedef pair <LL, int> PLL;

static const int N = 1010;
int arr[N];
vector <PLL> qu;

int main()
{
	int t;
//	freopen("B-small-attempt1.in", "r", stdin);
//	freopen("out.out", "w", stdout);
	scanf("%d", &t);
	int icase = 1;
	while (t--)
	{
		int m;
		LL n;
		LL l = -1, r = (1LL << 51);
		scanf("%d%lld", &m, &n);
		for (int i = 1; i <= m; ++i)
		{
			scanf("%d", &arr[i]);
		}
		LL mid;
		int ans = -1;
		while (l + 1 < r)
		{
			mid = (l + r) >> 1;
			LL cnt = 0, all = 0;
			LL x = mid;
			for (int i = 1; i <= m; ++i)
			{
				if (x)
				{
					all += (x - 1) / arr[i] + 1;
				}
				cnt += (x % arr[i] == 0);
			}
			if (cnt && all < n && n <= all + cnt)
			{
				n -= all;
				for (int i = 1; i <= m; ++i)
				{
					if (x % arr[i] == 0)
					{
						--n;
						if (n == 0)
						{
							ans = i;
							break;
						}
					}
				}
			}
			if (ans != -1)
			{
				break;
			}
			if (n <= all)
			{
				r = mid;
			}
			else
			{
				l = mid;
			}
		}
		printf("Case #%d: %d\n", icase++, ans);
	}
	return 0;
}
