#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define int long long

const double eps = 1e-9;

struct point
{
	double x, y;
	point() { x = y = 0; }
	point(double xx, double yy) { x = xx, y = yy; }
	bool operator < (const point &nxt) const
	{
		if (fabs(x-nxt.x) < eps) return y < nxt.y;
		return x < nxt.x;
	}
	bool operator == (const point &nxt) const
	{
		return fabs(y-nxt.y) < eps and fabs(x-nxt.x) < eps;
	}
} p[20];

double signed_area(point a, point b, point c)
{
	double ret = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
	return ret / 2;
}

bool between(point &a, point &b, point &c)
{
	bool ret = true;
	ret &= (fabs(signed_area(a, b, c)) < eps);
	ret &= ((a.x - b.x) * (c.x - b.x) < eps);
	ret &= ((a.y - b.y) * (c.y - b.y) < eps);
	return ret;
}

vector <point> hull(vector<point> &p)
{
	sort(p.begin(), p.end());
	p.resize(unique(p.begin(), p.end()) - p.begin());

	int n = p.size(), nup = 0, ndn = 0, nret = 0;
	vector <point> up, dn, ret;
	for (int i = 0; i < n; i++)
	{
		while (nup > 1 and signed_area(up[nup-2], up[nup-1], p[i]) > -eps)
			up.pop_back(), nup--;
		while (ndn > 1 and signed_area(dn[ndn-2], dn[ndn-1], p[i]) < eps)
			dn.pop_back(), ndn--;
		up.push_back(p[i]), nup++;
		dn.push_back(p[i]), ndn++;
	}
	for (int i = nup-2; i >= 1; i--) dn.push_back(up[i]);

	ndn = dn.size();
	if (ndn <= 2) return dn;
	ret.push_back(dn[0]), ret.push_back(dn[1]), nret = 2;
	for (int i = 2; i < ndn; i++)
	{
		if (between(ret[nret-2], ret[nret-1], dn[i])) ret.pop_back(), nret--;
		ret.push_back(dn[i]), nret++;
	}
	if (nret >= 3 and between(ret.back(), ret[0], ret[1]))
		ret[0] = ret.back(), ret.pop_back(), nret--;
	return ret;
}

bool go(int id, int msk, int n)
{
	if (msk >> id & 1) return false;

	vector <point> rem;
	for (int i = 0; i < n; i++)
		if ((msk >> i & 1) == 0)
			rem.push_back(p[i]);

	rem = hull(rem);
	int sz = rem.size();
	for (int i = 0; i < sz; i++)
		if (between(rem[i], p[id], rem[(i + 1) % sz]))
			return true;
	return false;
}

#undef int
int main()
{
#define int long long
	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cerr << "Executing Case #" << tt << "\n";

		int n; cin >> n;
		for (int i = 0; i < n; i++)
			cin >> p[i].x >> p[i].y;

		cout << "Case #" << tt << ":\n";

		for (int i = 0; i < n; i++)
		{
			int ret = 123;
			for (int msk = 0; msk < 1 << n; msk++)
				if (go(i, msk, n))
					ret = min(ret, __builtin_popcountll(msk) + 0ll);
			cout << ret << "\n";
		}
	}
	return 0;
}