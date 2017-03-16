#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <queue>
#include <deque>
#include <functional>
#include <climits>
#include <cassert>
#include <list>

#define mp make_pair
#define mt(a, b, c) mp(a, mp(b, c))
#define ABS(a) (((a) > 0) ? (a) : (-(a)))
#define ZERO(x) memset((x), 0, sizeof(x))
#define NEGATE(x) memset((x), 255, sizeof(x))

using namespace std;
typedef long long ll;

bool a[20][20];

int main()
{
#ifdef XXX
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int tests;
	scanf("%d", &tests);

	for (int q = 0; q < tests; q++)
	{
		ZERO(a);
		int r, c;
		scanf("%d %d", &r, &c);
		int n;
		scanf("%d", &n);

		int ans = 2e9;

		for (int mask = 0; mask < (1 << (r * c)); mask++)
		{
			for (int j = 0; j < (r * c); j++)
			{
				int cur_row = j / c;
				int cur_column = j - cur_row * c;
				a[cur_row][cur_column] = ((mask >> j) & 1);
			}

			int total_sum = 0;
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
				{
					if (a[i][j] == 1) total_sum++;
				}
			}

			if (total_sum != n) continue;

			int unhappiness = 0;
			
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
				{
					if (a[i][j] == 1 && a[i + 1][j] == 1) unhappiness++;
					if (a[i][j] == 1 && a[i][j + 1] == 1) unhappiness++;
				}
			}

			ans = min(ans, unhappiness);
		}

		if (ans != 2e9)
			printf("Case #%d: %d\n", q + 1, ans);
		else
			printf("Case #%d: %d\n", q + 1, 0);
	}


	return 0;
}