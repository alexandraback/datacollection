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

int a[16][16];

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
		int res = 1000000000;
		int r, c, n;
		scanf("%d%d%d", &r, &c, &n);
		int tot = (r*c);
		FOR(i, 0, (1<<tot))
		{
			int cnt = 0;
			FOR(j, 0, tot)
			{
				cnt += ((i >> j) & 1);
			}
			if (cnt != n)
				continue;
			FOR(j, 0, tot)
			{
				int x = j / c;
				int y = j%c;
				if ((i >> j) & 1)
					a[x][y] = 1;
				else
					a[x][y] = 0;
			}
			int now = 0;
			FOR(j,0,r)
				FOR(k, 0, c)
				{
					if ((a[j][k] == 1) && (j + 1 < r) && (a[j + 1][k] == 1))
						now++;
					if ((a[j][k] == 1) && (k + 1 < c) && (a[j][k + 1] == 1))
						now++;
				}
			res = MIN(res, now);
		}
		printf("Case #%d: %d\n", testNumber, res);
		fprintf(stderr, "Case #%d done\n", testNumber);
	}

#ifdef Fcdkbear
	double end = clock();
	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
	return 0;
}