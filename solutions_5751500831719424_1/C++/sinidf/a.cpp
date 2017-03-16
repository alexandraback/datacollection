#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#include <map>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
typedef long long ll;

const int MAX_N = 111;
char s[MAX_N][MAX_N], b[MAX_N][MAX_N];
int n, a[MAX_N], beg[MAX_N];

void dist(char *a, char *b)
{
	char last = 0;
	while (*a)
	{
		if (*a == last)
		{
			a++;
			continue;
		}
		else
		{
			*b = *a;
			last = *a;
			b++;
			a++;
		}
	}
	*b = 0;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int ca = 1; ca <= T; ca++)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%s", s[i]);
			dist(s[i], b[i]);
		}
		bool ok = true;
		for (int i = 0; i < n - 1; i++)
		{
			if (strcmp(b[i], b[i + 1]))
			{
				ok = false;
			}
		}
		if (!ok)
		{
			printf("Case #%d: Fegla Won\n", ca);
			continue;
		}
		int m = strlen(b[0]);
		int ans = 0;
		fill(beg, beg + n, 0);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int tt = beg[j];
				while (s[j][tt] == b[0][i])
				{
					tt++;
				}
				a[j] = tt - beg[j];
				beg[j] = tt;
			}
			sort(a, a + n);
			for (int j = 0; j < n; j++)
			{
				ans += abs(a[j] - a[n / 2]);
			}
		}
		printf("Case #%d: %d\n", ca, ans);
	}
	return 0;
}
