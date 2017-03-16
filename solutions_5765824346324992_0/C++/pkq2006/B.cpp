#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cctype>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <bitset>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef long double ld;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(X) ((int)((X).size()))

const int int_inf = 0x3f3f3f3f;
const ll ll_inf = 0x3f3f3f3f3f3f3f3fll;
const double pi = acos(-1.0);
const double eps = 1e-8;

template <class T>
inline T abs(const T x)
{
	return x < 0 ? -x : x;
}

template <class T>
inline void get_min(T &a, T b)
{
	if (a > b)
		a = b;
}

template <class T>
inline void get_max(T &a, T b)
{
	if (a < b)
		a = b;
}

template <class T>
inline void fix(T &a, T mo)
{
	while (a >= mo)
		a -= mo;
	while (a < 0)
		a += mo;
}

template <class T>
inline void inc(T &a, T b, T mo)
{
	a += b;
	fix(a, mo);
}

template <class T>
inline void dec(T &a, T b, T mo)
{
	a -= b;
	fix(a, mo);
}

template <class T>
inline T sqr(T x)
{
	return x * x;
}

template <class T>
inline int sgn(T x)
{
	if (x > eps)
		return 1;
	if (x < -eps)
		return -1;
	return 0;
}

template <class T>
inline void read_int(T &x)
{
	x = 0;
	char ch;
	bool flag = 0;
	while (ch = getchar(), !isdigit(ch) && ch != '-');
	if (ch == '-')
		flag = 1;
	else
		x = ch - '0';
	while (ch = getchar(), isdigit(ch))
		x = (x << 3) + x + x + ch - '0';
	if (flag)
		x = -x;
}

#define maxn 100010

int n;
ll a[maxn];

inline ll check(ll mid)
{
	ll ans = 0;
	for (int i = 1; i <= n; i ++)
		ans += mid / a[i] + 1;
	return ans;
}

int main()
{
	int T;
	read_int(T);
	for (int Case = 1; Case <= T; Case ++)
	{
		printf("Case #%d: ", Case);
		int m;
		read_int(n);
		read_int(m);
		for (int i = 1; i <= n; i ++)
			read_int(a[i]);
		ll l = 0, r = (ll)int_inf << 5;
		while (l < r)
		{
			ll mid = (l + r) >> 1;
			ll now_cnt = check(mid);
			if (now_cnt >= m)
				r = mid;
			else
				l = mid + 1;
		}
		int rest = m - check(l - 1);
		for (int i = 1; i <= n; i ++)
		{
			if (l % a[i] == 0)
				rest --;
			if (!rest)
			{
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}

