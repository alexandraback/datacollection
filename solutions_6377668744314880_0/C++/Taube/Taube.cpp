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

struct point
{
	int x, y, num;
	bool cut, in_h;
	bool operator < (const point p) const
	{
		if (x != p.x)
		{
			return x < p.x;
		}
		else
		{
			return y < p.y;
		}
	}
};

int n, t, j, i, h, k, cur, l, pos, m, ans[100500], a[100500], mx, cnt, q1, q2;
point p[100500];
vector<int> up, down;

bool cw(point p1, point p2, point p3)
{
	return (ll)(p2.x - p1.x) * (ll)(p3.y - p1.y) - (ll)(p2.y - p1.y) * (ll)(p3.x - p1.x) < 0;
}

bool ccw(point p1, point p2, point p3)
{
	return (ll)(p2.x - p1.x) * (ll)(p3.y - p1.y) - (ll)(p2.y - p1.y) * (ll)(p3.x - p1.x) > 0;
}

void rec(int step)
{
	if (step > n)
	{
		if (!cnt)
		{
			return;
		}
		int j, i;
		for (q1 = 1; p[q1].cut; q1++);
		for (q2 = n; p[q2].cut; q2--);
		up.clear();
		up.pb(q1);
		down.clear();
		down.pb(q1);
		for (j = q1 + 1; j <= q2; j++)
		{
			if (p[j].cut)
			{
				continue;
			}
			if (cw(p[q1], p[j], p[q2]) || j == q2)
			{
				while (up.size() >= 2 && !cw(p[up[up.size() - 2]], p[up[up.size() - 1]], p[j]))
				{
					up.pop_back();
				}
				up.pb(j);
			}
			if (ccw(p[q1], p[j], p[q2]) || j == q2)
			{
				while (down.size() >= 2 && !ccw(p[down[down.size() - 2]], p[down[down.size() - 1]], p[j]))
				{
					down.pop_back();
				}
				down.pb(j);
			}
		}
		for (j = 0; j < up.size(); j++)
		{
			p[up[j]].in_h = 1;
		}
		for (j = 0; j < down.size(); j++)
		{
			p[down[j]].in_h = 1;
		}
		for (i = 1; i <= n; i++)
		{
			if (p[i].cut)
			{
				continue;
			}
			for (j = 0; j + 1 < up.size(); j++)
			{
				if (!cw(p[up[j]], p[i], p[up[j + 1]]) && !ccw(p[up[j]], p[i], p[up[j + 1]]))
				{
					p[i].in_h = 1;
				}
			}
			for (j = 0; j + 1 < down.size(); j++)
			{
				if (!cw(p[down[j]], p[i], p[down[j + 1]]) && !ccw(p[down[j]], p[i], p[down[j + 1]]))
				{
					p[i].in_h = 1;
				}
			}
		}
		for (j = 1; j <= n; j++)
		{
			if (p[j].cut)
			{
				continue;
			}
			if (p[j].in_h)
			{
				ans[p[j].num] = min(ans[p[j].num], n - cnt);
				p[j].in_h = 0;
			}
		}
	}
	else
	{
		cnt++;
		p[step].cut = 0;
		rec(step + 1);
		cnt--;
		p[step].cut = 1;
		rec(step + 1);
	}
}

void solve()
{
	scanf ("%d", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		scanf ("%d", &n);
		for (j = 1; j <= n; j++)
		{
			scanf ("%d%d", &p[j].x, &p[j].y);
			p[j].num = j;
			ans[j] = inf;
		}
		sort (p + 1, p + n + 1);
		rec(1);
		printf ("Case #%d:\n", tt);
		for (j = 1; j <= n; j++)
		{
			printf ("%d\n", ans[j]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("C-small-attempt0.in", "r", stdin); freopen("output.txt", "w", stdout);
	srand(333);
	solve();
	return 0;
}