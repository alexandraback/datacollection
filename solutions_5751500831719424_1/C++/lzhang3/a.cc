#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

char s[200][200];

char a[200][200];
int  b[200][200];
int  c[200];

inline int iabs(const int x)
{
	if (x < 0) return -x;
	return x;
}

void solve()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%s", s[i]);
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	memset(c, 0, sizeof c);
	for (int i = 0; i < n; ++i)
	{
		char cur = s[i][0];
		a[i][0] = cur;
		int cnt = 1;
		for (int j = 0; s[i][j] != '\0'; ++j)
		{
			if (s[i][j] != cur)
			{
				cur = a[i][cnt] = s[i][j];
				++cnt;
			}
			++b[i][cnt-1];
		}
		c[i] = cnt;
	}

	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int j = 0; j < c[i]; ++j)
	// 		printf("(%c,%d) ", a[i][j], b[i][j]);
	// 	printf("\n");
	// }

	for (int i = 1; i < n; ++i)
		if (c[i-1] != c[i])
		{
			printf("Fegla Won\n");
			return;
		}

	for (int i = 0; i < c[0]; ++i)
		for (int j = 1; j < n; ++j)
			if (a[j-1][i] != a[j][i])
			{
				printf("Fegla Won\n");
				return;
			}

	int gsum = 0;
	for (int i = 0; i < c[0]; ++i)
	{
		int minval = 200, maxval = 0;
		for (int j = 0; j < n; ++j)
		{
			if (b[j][i] < minval) minval = b[j][i];
			if (b[j][i] > maxval) maxval = b[j][i];
		}
		//printf("(%d,%d) ", minval, maxval);
		int lsum = INT_MAX;
		for (int j = minval; j <= maxval; ++j)
		{
			int tsum = 0;
			for (int k = 0; k < n; ++k)
				tsum += iabs(j - b[k][i]);
			if (tsum < lsum)
				lsum = tsum;
		}
		gsum += lsum;
	}
	printf("%d\n", gsum);
}


int main(void)
{
	int t; scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
	{
		printf("Case #%d: ", i);
		solve();
	}
}