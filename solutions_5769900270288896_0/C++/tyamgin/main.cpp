#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:500000000") 
#include <functional>
#include <algorithm> 
#include <iostream> 
#include <string.h> 
#include <stdlib.h>
#include <limits.h>
#include <numeric>
#include <sstream> 
#include <fstream>
#include <ctype.h> 
#include <stdio.h> 
#include <bitset>
#include <vector> 
#include <string> 
#include <math.h> 
#include <time.h> 
#include <queue> 
#include <stack> 
#include <list>
#include <map> 
#include <set> 
#define Int long long 
#define INF 0x3F3F3F3F 
#define eps 1e-9
using namespace std;
typedef pair<int, int> pii;

#define N 17

int dp[N][1 << N][N];
int bitcount[1 << N];
map<vector<int>, int> cache;

int solve(int n, int m, int k)
{
	if (n > m)
		return solve(m, n, k);
	if (cache.count({ n, m, k }))
		return cache[{ n, m, k }];

	memset(dp, 63, sizeof(dp));
	dp[0][0][0] = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int mask = 0; mask < (1 << n); mask++)
		{
			for (int cn = 0; cn <= k; cn++)
			{
				if (cn < bitcount[mask])
					continue;

				auto &res = dp[i][mask][cn];
				for (int msk = 0; msk < (1 << n); msk++)
				{
					int cnt = bitcount[mask & msk];
					for (int j = 1; j < n; j++)
						cnt += (mask & (1 << j)) && (mask & (1 << (j - 1)));
					res = min(res, cnt + dp[i - 1][msk][cn - bitcount[mask]]);
				}
			}
		}
	}
	int res = INF;
	for (int mask = 0; mask < (1 << n); mask++)
		res = min(res, dp[m][mask][k]);
	return cache[{ n, m, k }] = res;
}

int main()
{
	bitcount[1] = 1;
	for (int i = 2; i < (1 << N); i++)
		bitcount[i] = bitcount[i / 2] + (i & 1);
	int tests;
	//int res = 0;
	//for (int n = 1; n <= 16; n++)
	//{
	//	for (int m = 1; m <= 16; m++)
	//	{
	//		for (int k = 0; k <= n*m; k++)
	//		{
	//			if (n*m <= 16)
	//			{
	//				res ^= solve(n, m, k);
	//			}
	//		}
	//	}
	//}
	//cout << res << endl;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
	{
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		printf("Case #%d: %d\n", test, solve(n, m, k));
	}
}

//
//#define N 1000009
//
//int d[N];
//char buf[22];
//
//Int Reverse(Int n)
//{
//	sprintf(buf, "%lld", n);
//	reverse(buf, buf + strlen(buf));
//	return atoll(buf);
//}
//
//Int greedy(Int n)
//{
//	Int cur = 1,
//		res = 1;
//	while (cur != n)
//	{
//		Int a = cur + 1,
//			b = Reverse(cur);
//		if (b <= n && b > cur)
//			cur = b;
//		else
//			cur = a;
//		res++;
//	}
//	return res;
//}
//
//int main()
//{
//	int tests;
//	Int n;
//	queue<int> q;
//	q.push(1);
//	memset(d, 63, sizeof(d));
//	d[1] = 1;
//	while (q.size())
//	{
//		int v = q.front();
//		q.pop();
//		vector<Int> nx = { v + 1, Reverse(v) };
//		for (auto to : nx)
//		{
//			if (to >= N)
//				continue;
//			if (d[to] == INF)
//			{
//				d[to] = d[v] + 1;
//				q.push(to);
//			}
//		}
//	}
//	cout << max_element(d + 10, d + 1000) - d << endl;
//	for (int i = 1; i < 100; i++)
//	{
//		if (greedy(i) != d[i])
//		{
//			cout << i << endl;
//			cout << greedy(i) << endl;
//			cout << d[i] << endl;
//			return 0;
//		}
//	}
//	puts("OK");
//
//	scanf("%d", &tests);
//	for (int test = 1; test <= tests; test++)
//	{
//		Int n;
//		scanf("%lld", &n);
//		printf("Case #%d: %d\n", test, d[n]);
//	}
//}