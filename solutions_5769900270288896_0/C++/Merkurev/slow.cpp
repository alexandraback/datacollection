#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

/*
const int maxn = 17;
int dp[maxn][maxn][1 << maxn][maxn * maxn];

void solve()
{
	int r, c, n;
	scanf("%d%d%d", &r, &c, &n);
	dp[0][0][0][0] = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			for (int mask = 0; mask < (1 << c); mask++)
				for (int cnt = 0; cnt < n; cnt++)
				{
					int curdp = dp[i][j][mask][cnt];
					if (curdp == -1)
						continue;
					for (int cur = 0; cur < 1; cur++)
					{
							
					}
				}
}
*/

const int maxn = 17;
int f[maxn][maxn];

void solve()
{
	int r, c, n;
	scanf("%d%d%d", &r, &c, &n);
	
	int ans = 4 * n;
	for (int mask = 0; mask < (1 << (r * c) ); mask++)
	{
		memset(f, 0, sizeof f);
		int cnt = 0;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
			{
				int cur = ( (mask >> (i * c + j) ) & 1);
				cnt += cur;
				f[i][j] = cur;
			}
		int cans = 0;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
			{
				if (f[i][j] && f[i + 1][j] )
					cans++;
				if (f[i][j] && f[i][j + 1] )
					cans++;
			}
		if (cnt == n)
			ans = min(ans, cans);
	}
	printf("%d\n", ans);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("answer.txt", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		eprintf("Case %d .. %d\n", i, t);
		printf("Case #%d: ", i);
		solve();
	}
	

	return 0;
}
