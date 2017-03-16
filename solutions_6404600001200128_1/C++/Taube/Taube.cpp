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

int n, t, j, i, h, k, q1, q2, q, cur, l, pos, m, ans, a[100500], mx;
int ans1, ans2;

void solve()
{
	scanf ("%d", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		scanf ("%d", &n);
		for (j = 1; j <= n; j++)
		{
			scanf ("%d", &a[j]);
		}
		ans1 = ans2 = mx = 0;
		for (j = 2; j <= n; j++)
		{
			if (a[j] < a[j - 1])
			{
				ans1 += a[j - 1] - a[j];
				mx = max(mx, a[j - 1] - a[j]);
			}
		}
		/*if (mx % 10 != 0)
		{
			mx += 10 - mx % 10;
		}*/
		for (j = 2; j <= n; j++)
		{
			ans2 += min(a[j - 1], mx);
		}
		printf ("Case #%d: %d %d\n", tt, ans1, ans2);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("A-large.in", "r", stdin); freopen("output.txt", "w", stdout);
	srand(333);
	solve();
	return 0;
}