#include "stdio.h"
#include "string.h"
#include "math.h"
#include "set"
#include "algorithm"
#include <gmpxx.h>

using namespace std;

/**************** debug ***************/
//#define DBG 1
#ifdef DBG
#define chkpoint(...) { fprintf(stderr, "[%s:%d]", __func__, __LINE__);fprintf(stderr, __VA_ARGS__); };
#define debug(...) { fprintf(stderr, __VA_ARGS__); };
#else
#define chkpoint(...) 
#define debug(...) 
#endif
/**************** debug ***************/

/**************** Useful macro ***************/
#define MIN(a, b) (((a)<(b))?(a):(b))
#define MAX(a, b) (((a)>(b))?(a):(b))
#define SET_MIN(a, b) a = MIN(a, b)
#define SET_MAX(a, b) a = MAX(a, b)
#define MPZ2STR(x) (x.get_str(10).c_str())
/**************** Useful macro ***************/
void solve(int a[4], int b[4])
{
	int match = 0;
	int last_match = 0;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (a[i] == b[j])
			{
				last_match = a[i];
				match++;
			}
		}
	}
	if (match > 1)
		printf("Bad magician!\n");
	else if (match == 0)
		printf("Volunteer cheated!\n");
	else
		printf("%d\n", last_match);
	return;
}

int main()
{
	int tt, T;

	scanf("%d\n", &T);
	
	for (tt = 1; tt <= T; ++tt)
	{
		int x, y, a[4][4], b[4][4];
		scanf("%d\n", &x);
		for (int i = 0; i < 4; ++i)
			scanf("%d %d %d %d\n", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
		scanf("%d\n", &y);
		for (int i = 0; i < 4; ++i)
			scanf("%d %d %d %d\n", &b[i][0], &b[i][1], &b[i][2], &b[i][3]);
		printf("Case #%d: ", tt);
		solve(a[x-1], b[y-1]);
	}
	return 0;
}
