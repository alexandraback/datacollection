#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <utility>
#include <ctime>
#include <memory.h>
#include <cctype>
#include <cstdlib>

using namespace std;

#pragma comment (linker, "/STACK:64000000")

#define y0 qwe
#define y1 asd
#define sz size()
#define pb push_back
#define fors(w,s) for(map <int, int> :: iterator w = s.begin(); w != s.end(); w++)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ull unsigned long long
#define vi vector <int>
#define vvi vector <vi>
#define inf 2000000000
#define mod 1000000007
#define ll long long
#define maxint 2139062143 //2147483647
#define maxll 9223372036854775807
#define fi first
#define se second
#define eps 1e-9
#define doubleinf 1000000000000000.0

int m, t, y, l, g, q[101], q0, n, q1, q2, cnt, res, k, j, i, h, a[101][101], ans, z[101], sum;
string s[101], f[101];
char buf[1000];

inline void solve()
{
	for (h = 1; h <= n; h++)
	{
		memset(a[h], 0, sizeof(s[h].sz * sizeof(int)));
		f[h] = s[h][0];
		q[h] = a[h][1] = 1;
		for (i = 1; i < int(s[h].sz); i++)
		{
			if (s[h][i] != s[h][i - 1])
			{
				a[h][++q[h]] = 1;
				f[h] += s[h][i];
			}
			else
			{
				a[h][q[h]]++;
			}
		}
	}
	for (h = 2; h <= n; h++)
	{
		if (f[h] != f[h - 1])
		{
			printf ("Case #%d: Fegla Won\n", j);
			return;
		}
	}
	q0 = q[1];
	ans = 0;
	for (i = 1; i <= q0; i++)
	{
		res = maxint;
		sum = 0;
		for (h = 1; h <= n; h++)
		{
			sum += z[h] = a[h][i];
		}
		sort (z + 1, z + n + 1);
		for (h = 1; h <= n; h++)
		{
			sum -= (n - h + 1) * (z[h] - z[h - 1]);
			sum += (h - 1) * (z[h] - z[h - 1]);
			res = min(sum, res);
		}
		ans += res;
	}
	printf ("Case #%d: %d\n", j, ans);
}

inline void init()
{
    scanf ("%d", &t);
	for (j = 1; j <= t; j++)
	{
		scanf ("%d", &n);
		for (h = 1; h <= n; h++)
		{
			scanf ("%s", &buf);
			s[h] = buf;
		}
		solve();
	}
}

inline void answer()
{
    
}

int main()
{
    freopen ("A-large.in","r",stdin); freopen ("output.txt","w",stdout);
    //freopen ("olympiad.in","r",stdin); freopen ("olympiad.out","w",stdout);
    init();
    answer();
    return 0;
}