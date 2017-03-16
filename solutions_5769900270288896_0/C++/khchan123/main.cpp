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

int solve(int R, int C, int N)
{
	int min = 1e8;
	int grid[16][16];
    std::string bitmask(N, '1'); // K leading 1's
    bitmask.resize(R*C, '0'); // N-K trailing 0's

	if (N == 0)
		return 0;

    do
	{
		debug("permuted: %s\n", bitmask.c_str());
		for (int r = 0; r < R; ++r)
		{
			for (int c = 0; c < C; ++c)
			{
				if (bitmask[r*C+c] == '1')
					grid[r][c] = 1;
				else
					grid[r][c] = 0;
				debug("%d ", grid[r][c]);
			}
			debug("\n");
		}

		int unhapiness = 0;
		for (int r = 0; r < R-1; ++r)
		{
			for (int c = 0; c < C; ++c)
			{
				if ((grid[r][c] == grid[r+1][c]) && (grid[r][c] == 1))
					unhapiness++;
			}
		}
		for (int r = 0; r < R; ++r)
		{
			for (int c = 0; c < C-1; ++c)
			{
				if ((grid[r][c] == grid[r][c+1]) && (grid[r][c] == 1))
					unhapiness++;
			}
		}
		debug("unhapiness: %d\n", unhapiness);
		min = MIN(min, unhapiness);
    } while (std::prev_permutation(bitmask.begin(), bitmask.end()));

	return min;
}

int main()
{
	int tt, T;
	int R, C, N;

	scanf("%d\n", &T);
	
	for (tt = 1; tt <= T; ++tt)
	{
		scanf("%d %d %d\n", &R, &C, &N);
		printf("Case #%d: %d\n", tt, solve(R, C, N));
	}
	return 0;
}
