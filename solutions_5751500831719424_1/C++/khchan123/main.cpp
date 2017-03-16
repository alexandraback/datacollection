#include "limits.h"
#include "stdio.h"
#include "string.h"
#include "math.h"
#include "set"
#include "algorithm"
#include "iostream"
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
string s[128];
int N;
int times;

void solve()
{
	times = 0;
	for (int n = 0; n < N; ++n)
		debug("s[%d] %s\n", n, s[n].c_str());

	int c[128] = {0};
	while (1)
	{
		char ch = s[0][c[0]];
		debug("ch = %c\n", ch);
		if (ch == '\0')
		{
			for (int n = 0; n < N; ++n)
			{
				if (c[n] < s[n].size())
				{
					times = -1;
					return;
				}

			}
			return;
		}
		int repeated[128] = {0};
		for (int n = 0; n < N; ++n)
		{
			while (1)
			{
				if (c[n] >= s[n].size())
				{
					break;
				}
				if (s[n][c[n]] == ch)
				{
					repeated[n]++;
					c[n]++;
					continue;
				}
				else
					break;
			}
			debug("repeated[%d] = %d\n", n, repeated[n]);
			if (repeated[n] == 0)
			{
				times = -1;
				return;
			}
		}

		int min = *std::min_element(repeated, repeated + N);
		int max = *std::max_element(repeated, repeated + N);

		debug("min = %d , max = %d\n", min, max);
		if (min == max)
			continue;

		int A = INT_MAX;
		for (int t = min ; t <= max; ++t)
		{
			int a = 0;
			for (int n = 0; n < N; ++n)
				a += abs(repeated[n]-t);
			if (a < A)
				A = a;
		}
		times += A;
	}
}

int main()
{
	int tt, T;

	scanf("%d\n", &T);
	
	for (tt = 1; tt <= T; ++tt)
	{
		scanf("%d\n", &N);
		for (int n = 0; n < N; ++n)
			cin >> s[n];
		solve();
		if (times >= 0)
			printf("Case #%d: %d\n", tt, times);
		else
			printf("Case #%d: Fegla Won\n", tt);
	}
	return 0;
}
