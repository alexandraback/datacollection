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

int m, t, y, l, g, q, q0, n, q1, q2, cnt, res, k, j, i, h, a1[101], a2[102], ans;
string s1, s2, f1, f2;
char buf[1000];

bool check (string s1, string s2)
{
	if (s1.sz != s2.sz)
	{
		return 0;
	}
	for (int i = 0; i < int(s1.sz); i++)
	{
		if (s1[i] != s2[i])
		{
			return 0;
		}
	}
	//printf ("%s - %s\n", s1.c_str(), s2.c_str());
	return 1;
}

inline void solve()
{
	memset(a1, 0, sizeof(a1));
	f1 = s1[0];
	q1 = a1[1] = 1;
	for (i = 1; i < int(s1.sz); i++)
	{
		if (s1[i] == s1[i - 1])
		{
			a1[q1]++;
		}
		else
		{
			f1 += s1[i];
			a1[++q1] = 1;
		}
	}
	memset(a2, 0, sizeof(a2));
	f2 = s2[0];
	q2 = a2[1] = 1;
	for (i = 1; i < int(s2.sz); i++)
	{
		if (s2[i] == s2[i - 1])
		{
			a2[q2]++;
		}
		else
		{
			f2 += s2[i];
			a2[++q2] = 1;
		}
	}
	if (check(f1, f2))
	{
		ans = 0;
		for (i = 1; i <= q1; i++)
		{
			ans += abs(a1[i] - a2[i]);
		}
		printf ("Case #%d: %d\n", j, ans);
	}
	else
	{
		printf ("Case #%d: Fegla Won\n", j);
	}
}

inline void init()
{
    scanf ("%d", &t);
	for (j = 1; j <= t; j++)
	{
		scanf ("%d", &n);
		scanf ("%s", &buf);
		s1 = buf;
		scanf ("%s", &buf);
		s2 = buf;
		solve();
	}
}

inline void answer()
{
    
}

int main()
{
    freopen ("A-small-attempt1.in","r",stdin); freopen ("output.txt","w",stdout);
    //freopen ("olympiad.in","r",stdin); freopen ("olympiad.out","w",stdout);
    init();
    answer();
    return 0;
}