#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <deque>
#include <cassert>

using namespace std;

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
#define sz(s) (int(s.size()))
#define fname "a"
#define ms(a,x) memset(a, x, sizeof(a))
#define forit(it,s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); ++it)
#define MAXN 3003

#define sqr(x) ((x) * (x))

const double inf = 1e20, eps = 1e-12;

struct Point 
{
	int x, y;
	int id;
	void read() 
	{
		scanf("%d%d", &x, &y);
	}
	double r() 
	{
		return sqrt(x*x+y*y);
	}
	void print() 
	{
		printf("%d %d\n", x, y);
	}
	bool operator<(const Point& r) const 
	{
		if (x < r.x) return 1;
		if (x > r.x) return 0;
		return y < r.y;
	}
	Point operator-(Point& r) 
	{
		Point res = {x - r.x, y - r.y};
		res.id = id;
		return res;
	}
	double slope() 
	{
		if (x == 0 && y == 0) return -inf;
		if (x == 0) return inf;
		return double(y) / x;
	}
	ll operator*(const Point& r) 
	{
		return 1LL * x * r.y - 1LL * y * r.x;
	}
	double dist_to(Point& r) 
	{
		return sqrt(sqr(x-r.x)+sqr(y-r.y));
	}
};

Point O;
bool BY_SLOPE(Point l, Point r) {
/*	if (l * r == 0)
		return l.dist_to(O) < r.dist_to(O);
	return l * r < 0;*/
	double ls = (l-O).slope(),  rs = (r-O).slope();
	if (ls < rs) return 1;
	if (ls > rs) return 0;
	return l.dist_to(O) < r.dist_to(O);
}

int n;
Point a[MAXN];
Point b[MAXN];

int convex_hull(Point *p, int N, int pos)
{	
	int ans = 0;
	sort(p, p + N);
	O = p[0];
	for (int i = 0; i < N; ++i)
		p[i] = p[i] - O;
/*	for (int i = 1; i < N; ++i)
		if (p[i].id != pos && (abs(p[i].slope() - (b[pos] - O).slope()) < eps))
		{
//			cout << "same" << endl;
//			p[i].print();
			swap(p[i], p[N - 1]);
			--N;
		}*/
	if (N <= 2) return ans;

	sort(p + 1, p + N, BY_SLOPE);
	if (pos == 3)
	for (int i = 0; i < N; ++i)
	{
		cout << i << " ,slope " << p[i].slope() << " , aaa = " << p[i].slope() - (b[pos] - O).slope() << ' '<< p[i].id  << endl;
		p[i].print();
	}

	vector<Point> hull;
	for (int i = 0; i < N ; i ++) {
		if (i < 3) hull.push_back(p[i]);
		else {
			int sz = hull.size();
			int t = 0;
			while (sz >= 2 && (p[i] - hull[sz-2])*(hull[sz-1]-hull[sz-2]) > 0)
			{
				if (hull.back().id == pos)
				{
					t = 1;
					break;
				}
				hull.pop_back();
				sz--;
			}
			if (t == 0)
				hull.push_back(p[i]);
			else
			{
				cout << "deletion" << endl;
				cout << hull.back().id << endl;
				hull[sz(hull) - 2].print();
				hull.back().print();
				p[i].print();
				cout << pos << ' '<< p[i].id << endl;
				++ans;
			}
		}
	}

	return min(res, ans);
}

inline void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		a[i].read();
		a[i].id = i;
		b[i] = a[i];
	}
	puts("");
	for (int i = 0; i < n; ++i)
	{
		printf("%d\n", convex_hull(a, n, i));
		for (int j = 0; j < n; ++j)
			a[j] = b[j];
	}
}

int main()
{
	#ifdef LOCAL
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	#endif

	int tt;
	scanf("%d", &tt);
	for (int t = 0; t < tt; ++t)
	{
		printf("Case #%d: ", t + 1);
		solve();
	}
	return 0;
}
