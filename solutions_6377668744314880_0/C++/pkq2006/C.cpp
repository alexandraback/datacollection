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

class Point
{
	public:
		ll x, y;
		Point(const ll &x = 0, const ll &y = 0) {
			this->x = x;
			this->y = y;
		}
};

inline bool operator < (const Point &a, const Point &b)
{
	if (a.x != b.x)
		return a.x < b.x;
	return a.y < b.y;
}

inline Point operator - (const Point &a, const Point &b)
{
	return Point(a.x - b.x, a.y - b.y);
}

inline bool operator == (const Point &a, const Point &b)
{
	return a.x == b.x && a.y == b.y;
}

#define maxn 100100

int n;
Point a[maxn];

inline ll det(const Point &a, const Point &b)
{
	return a.x * b.y - a.y * b.x;
}

int main()
{
	int T;
	read_int(T);
	for (int Case = 1; Case <= T; Case ++)
	{
		printf("Case #%d: \n", Case);
		int n;
		read_int(n);
		for (int i = 1; i <= n; i ++)
			scanf("%lld%lld", &a[i].x, &a[i].y);
		for (int pivot = 1; pivot <= n; pivot ++)
		{
			vector <pair<double, Point> > data;
			for (int i = 1; i <= n; i ++)
			{
				if (i == pivot)
					continue;
				data.pb(mp(atan2(a[i].y - a[pivot].y, a[i].x - a[pivot].x), a[i]));
			}
			sort(data.begin(), data.end());
			vector <Point> now;
			for (int i = 0; i < sz(data); i ++)
				now.pb(data[i].y);
			for (int i = 0; i < sz(data); i ++)
				now.pb(data[i].y);
			int now_ans = 0;
			for (int l = 0, r = 0; l < sz(now); ++l)
			{
				for (; r < sz(now) && det(now[l] - a[pivot], now[r] - a[pivot]) >= 0; r ++);
				get_max(now_ans, r - l);
			}
			printf("%d\n", max(n - now_ans - 1, 0));
		}

	}
	return 0;
}

