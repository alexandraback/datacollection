#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif


int solveB(int r, int c, int n)
{
	int cntb = (r * c + 1) / 2;
	cntb = min(cntb, n);
	n -= cntb;

	int ans = 0;
	int cntA = (r * c) % 2 ? 0 : 2;
	cntA = min(n, cntA);
	ans += 2 * cntA;
	n -= cntA;

	int cntB = ( (r + c) * 2 - 4) / 2;
	cntB -= cntA;
	cntB = min(n, cntB);

	n -= cntB;
	ans += cntB * 3;

	ans += 4 * n;

	return ans;
}

int solveW(int r, int c, int n)
{
	int cntw = (r * c) / 2;
	cntw = min(cntw, n);
	n -= cntw;

	int ans = 0;
	int cntA = (r * c) % 2 ? 4 : 2;
	cntA = min(n, cntA);
	ans += cntA * 2;
	n -= cntA;

	
	int cntB = ( (r + c) * 2 - 4) / 2;
	cntB -= cntA;
	cntB = min(n, cntB);

	n -= cntB;
	ans += cntB * 3;

	ans += 4 * n;

	return ans;
}

void solve()
{
	int r, c, n;
	scanf("%d%d%d", &r, &c, &n);
	
	if (c < r)
		swap(c, r);

	if (r == 1)
	{
		int ans = 0;
		int b0 =  (c + 1) / 2;
		b0 = min(b0, n);
		n -= b0;
		if (n && c % 2 == 0)
		{
			n--;
			ans++;
		}
		ans += n * 2;
		printf("%d\n", ans);
		return;
	}

	int ans = min(solveB(r, c, n), solveW(r, c, n) );
	printf("%d\n", ans);
}

typedef long long int int64;

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		eprintf("Case %d .. %d\n", i + 1, t);
		printf("Case #%d: ", i + 1);
		solve();
	}
	

	return 0;
}
