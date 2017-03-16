#define _CRT_SECURE_NO_WARNINGS
#pragma comment (linker,"/STACK:256000000")
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <cassert>
#include <string>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <iomanip>
using namespace std;

#define INF 1000000001
#define lint long long
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define eps 0.0000001

int p[50];
int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tc, T = 1;
	scanf("%d", &tc);

	while (tc--)
	{
		printf("Case #%d: ", T++);
		int n;
		scanf("%d", &n);

		int ss = 0;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &p[i]);
			ss += p[i];
		}

		while (ss)
		{
			if (ss % 2 == 0)
			{
				int mx1 = -1, mx2 = -1, ind1 = -1, ind2 = -1;
				for (int i = 1; i <= n; ++i)
				{
					if (p[i] >= mx1)
					{
						mx2 = mx1;
						ind2 = ind1;
						mx1 = p[i];
						ind1 = i;
					}
					else
					{
						if (p[i] > mx2)
						{
							mx2 = p[i];
							ind2 = i;
						}
					}
				}

				if (mx1 == mx2)
				{
					--p[ind1];
					--p[ind2];

					printf("%c%c ", char('A' + ind1 - 1), char('A' + ind2 - 1));
					ss -= 2;
				}
				else
				{
					p[ind1] -= 2;
					printf("%c%c ", char('A' + ind1 - 1), char('A' + ind1 - 1));
					ss -= 2;
				}
			}
			else
			{
				int mx = -1, ind = -1;
				for (int i = 1; i <= n; ++i)
				{
					if (p[i] > mx)
					{
						mx = p[i];
						ind = i;
					}
				}

				printf("%c ", char('A' + ind - 1));
				--p[ind];
				--ss;
			}

			for (int i = 1; i <= n; ++i)
			{
				assert(p[i] <= ss / 2);
			}
		}
		printf("\n");
	}
	return 0;
}