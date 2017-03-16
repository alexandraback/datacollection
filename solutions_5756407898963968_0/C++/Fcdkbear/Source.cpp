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
#define PI 3.14159265358979
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned

int a[2][20];

int main()
{
#ifdef Fcdkbear
	freopen("in.txt", "r", stdin);
	freopen("out.txt","w",stdout);
	double beg = clock();
#else
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	FOR(it,0,t)
	{
		int r1;
		scanf("%d", &r1);
		r1--;
		MEMS(a, 0);
		FOR(i, 0, 4)
		{
			FOR(j, 0, 4)
			{
				int v;
				scanf("%d", &v);
				if (i == r1)
				{
					a[0][v - 1]++;
				}
			}
		}
		int r2;
		scanf("%d", &r2);
		r2--;
		FOR(i, 0, 4)
		{
			FOR(j, 0, 4)
			{
				int v;
				scanf("%d", &v);
				if (i == r2)
				{
					a[1][v - 1]++;
				}
			}
		}
		int last = -1;
		int cnt = 0;
		FOR(i, 0, 16)
		{
			if ((a[0][i] == 1) && (a[1][i] == 1))
			{
				last = i + 1;
				cnt++;
			}
		}
		printf("Case #%d: ", it + 1);
		if (cnt == 0)
			printf("Volunteer cheated!\n");
		else
		if (cnt == 1)
			printf("%d\n", last);
		else
			printf("Bad magician!\n");
	}

#ifdef Fcdkbear
	double end = clock();
	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
}