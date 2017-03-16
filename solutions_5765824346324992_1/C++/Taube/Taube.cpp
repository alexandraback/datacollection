#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <utility>
#include <algorithm>
#include <memory.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <complex>

using namespace std;

#define pb push_back
#define pii pair<int, int>
#define pdi pair<double, int>
#define pdii pair<pdi, int>
#define pll pair<ll, ll>
#define pli pair<ll, int>
#define psi pair<string, int>
#define vi vector<int>
#define inf 2000000000
//#define mod1 1000333
//#define mod 1000000123
#define y1 uhgeg
#define lim 31700
#define eps 1e-9
#define prime1 31
#define prime2 41

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> comp;

int n, t, j, i, h, k, cur, l, pos, m, ans, a[100500], mx;
ll q1, q2, q, c, c1, c2;

void solve()
{
	scanf ("%d", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		scanf ("%d%d", &n, &k);
		for (j = 1; j <= n; j++)
		{
			scanf ("%d", &a[j]);
		}
		if (k <= n)
		{
			ans = k;
		}
		else
		{
			q1 = 1;
			q2 = 1000000000000000;
			while (q1 < q2)
			{
				q = (q1 + q2) >> 1;
				c = n;
				for (j = 1; j <= n; j++)
				{
					c += q / a[j];
				}
				if (c >= k)
				{
					q2 = q;
				}
				else
				{
					q1 = q + 1;
				}
			}
			q1 = q2 - 1LL;
			c1 = c2 = n;
			for (j = 1; j <= n; j++)
			{
				c1 += q1 / a[j];
				c2 += q2 / a[j];
			}
			for (j = 1; j <= n; j++)
			{
				if (!(q2 % a[j]))
				{
					c1++;
					if (c1 == k)
					{
						ans = j;
						break;
					}
				}
			}
		}
		printf ("Case #%d: %d\n", tt, ans);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("B-large.in", "r", stdin); freopen("output.txt", "w", stdout);
	srand(333);
	solve();
	return 0;
}