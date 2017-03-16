#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define in_str(b) scanf("%s",(b))
#define in_int1(a) scanf("%d",&(a))
#define in_int2(a,b) scanf("%d%d",&(a),&(b))
#define in_int3(a,b,c) scanf("%d%d%d",&(a),&(b),&(c))
#define in_int4(a,b,c,d) scanf("%d%d%d%d",&(a),&(b),&(c),&(d))
#define so(a) sort((a).begin(), (a).end())
#define rso(a) sort((a).rbegin(), (a).rend())
#define mp(a,b) make_pair(a,b)
#define MOD 1000000007
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 2000000000

//bool mas[10010][10010];
bool mas[20][20];

void Solve()
{
	int i, j, k, n, m;

	int tests;
	in_int1(tests);
	for (int test = 1; test <= tests; test++)
	{
		printf("Case #%d: ", test);
		int r, c;
		in_int3(r, c, n);
		memset(mas, 0, sizeof(mas));
		int m = r*c;
		int res = 0;
		int best = 10000000;
		for (i = 0; i < (1 << m); i++)
		{
			for (j = 0; j < m; j++)
			{
				mas[1 + (j / c)][1 + j%c] = (i&(1 << j)) != 0;
			}
			int cnt = 0;
			res = 0;
			for (j = 1; j <= r; j++)
			{
				for (k = 1; k <= c; k++)
				{
					if (mas[j][k])
					{
						cnt++;
						if (mas[j][k + 1]) res++;
						if (mas[j + 1][k]) res++;
					}
				}
			}
			if (cnt == n) best = min(best, res);
		}
		res = best;

/*		int p2 = 0, p3 = 0, p4 = 0;
		for (i = 1; i <= r; i ++)
		{
			for (j = 1; j <= c; j++)
			{
				if ((i + j) % 2 == 0)
				{
					mas[i][j] = 1;
					n--;
				}
				else if ((i == 1 || i == r) && (j == 1 || j == c)) p2++;
				else if (i == 1 || i == r || j == 1 || j == c) p3++;
				else p4++;
			}
		}

		int res = 0;
		if (n > 0)
		{
			m = min(n, p2);
			res += m*2;
			n -= m;
		}
		if (n > 0)
		{
			m = min(n, p3);
			res += m*3;
			n -= m;
		}
		if (n > 0)
		{
			m = min(n, p4);
			res += m*4;
			n -= m;
		}
*/
		printf("%d\n", res);
	}
}

int main()
{
#ifdef __LOCAL_RUN__
	#define _MAX_BUF_SIZE 32
	int _i = 0;
	char *_buf = new char[_MAX_BUF_SIZE];

	FILE *res_output = freopen("output.txt", "wt", stdout);
	while (true)
	{
		string _suffix = string(itoa(_i, _buf, 10)) + string(".txt");
		FILE *res_input = freopen((string("input-") + _suffix).c_str(), "rt", stdin);
		if (!res_input)
		{
			// the end
			break;
		}
		if (_i) printf("\n\n");
		printf("==== Case #%d =====\n", _i);
		Solve();
		_i++;
	}
#else
	Solve();
#endif
	return 0;
}