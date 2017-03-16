#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <bitset>

using namespace std;

#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define PI 3.1415926535897
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned

int cnt[5];

int main()
{
#ifdef Fcdkbear
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	double beg = clock();
#else
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif


	int tests;
	scanf("%d", &tests);
	FOR(testNumber, 1, tests + 1)
	{
		int n, r, c;
		scanf("%d%d%d", &r, &c, &n);
		int N = n;
		MEMS(cnt, 0);
		FOR(i, 0, r)
		{
			FOR(j, 0, c)
			{
				if ((i & 1) == (j & 1))
				{
					if (n > 0)
					{
						n--;
					}
				}
				else
				{
					int now = 0;
					if (i) now++;
					if (i + 1 < r) now++;
					if (j) now++;
					if (j + 1 < c) now++;
					cnt[now]++;
				}
			}
		}
		int res1 = 0;
		FOR(i, 0, 5)
		{
			int v = MIN(n, cnt[i]);
			res1 += v*i;
			n -= v;
		}
		n = N;
		MEMS(cnt, 0);
		FOR(i, 0, r)
		{
			FOR(j, 0, c)
			{
				if ((i & 1) != (j & 1))
				{
					if (n > 0)
					{
						n--;
					}
				}
				else
				{
					int now = 0;
					if (i) now++;
					if (i + 1 < r) now++;
					if (j) now++;
					if (j + 1 < c) now++;
					cnt[now]++;
				}
			}
		}
		int res2 = 0;
		FOR(i, 0, 5)
		{
			int v = MIN(n, cnt[i]);
			res2 += v*i;
			n -= v;
		}
		int res = MIN(res1, res2);
		printf("Case #%d: %lld\n", testNumber, res);
		fprintf(stderr, "Case #%d done\n", testNumber);
	}

#ifdef Fcdkbear
	double end = clock();
	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
	return 0;
}