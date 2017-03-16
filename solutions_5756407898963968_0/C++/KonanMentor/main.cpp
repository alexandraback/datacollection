#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <iterator>
#include <list>
#include <set>
#include <queue>
#include <numeric>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

typedef long long lli;
typedef long li;

const lli INFLL = LONG_LONG_MAX;
const li INF = LONG_MAX, N = 4;

bool p[N * N + 1];

void read ()
{
	li r;
	scanf("%ld", &r);
	r --;
	for (li y = 0; y < N; ++ y)
	{
		for (li x = 0; x < N; ++ x)
		{
			li a;
			scanf("%ld", &a);
			if (y != r) p[a] = 0;
		}
	}
}

void solve ()
{
	li tests;
	scanf("%ld", &tests);

	for (li t = 1; t <= tests; ++ t)
	{
		fill(p, p + N * N + 1, 1);
		read();
		read();
		li possible = 0;
		for (li x = 1; x <= N * N; ++ x)
		{
			possible += p[x];
		}
		printf("Case #%ld: ", t);
		switch (possible)
		{
			case 0:
				printf("Volunteer cheated!\n");
				break;
			case 1:
				for (li x = 1; x <= N * N; ++ x)
				{
					if (p[x]) printf("%ld\n", x);
				}
				break;
			default:
				printf("Bad magician!\n");
				break;
		}
	}
}

void init ()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int main()
{
	//init();
	solve();
	return 0;
}
