// -Wl,--stack,9001 
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz(x) ((int)((x).size()))
#define rep(i, N) for (int i = 0; i < N; ++i)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
typedef long long lint;
typedef vector<string> vs;
typedef vector<int> vi;
typedef pair<int, int> pii;

struct Point {
	lint x, y;
	Point(lint x = 0, lint y = 0) : x(x), y(y) {}
};

inline Point operator -(Point a, Point b) { return Point(a.x - b.x, a.y - b.y); }

bool cmp (Point a, Point b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw (Point a, Point b, Point c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw (Point a, Point b, Point c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull (vector<Point> &a) {
	if (a.size() <= 2)  return;
	sort (a.begin(), a.end(), &cmp);
	Point p1 = a[0],  p2 = a.back();
	vector<Point> up, down;
	up.push_back (p1);
	down.push_back (p1);
	for (size_t i=1; i<a.size(); ++i) {
		if (i==a.size()-1 || cw (p1, a[i], p2)) {
			while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
				up.pop_back();
			up.push_back (a[i]);
		}
		if (i==a.size()-1 || ccw (p1, a[i], p2)) {
			while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
				down.pop_back();
			down.push_back (a[i]);
		}
	}
	a.clear();
	for (size_t i=0; i<up.size(); ++i)
		a.push_back (up[i]);
	for (size_t i=down.size()-2; i>0; --i)
		a.push_back (down[i]);
}

inline lint Vect(Point a, Point b) { return a.x * b.y - a.y * b.x; }
inline lint Scal(Point a, Point b) { return a.x * b.x + a.y * b.y; }


bool InsideInSegm(Point p1, Point p2, Point p) {
	lint t = Vect(p2 - p1, p - p1);
	if (t != 0) return false;
	lint s1 = Scal(p2 - p1, p - p1);
	lint s2 = Scal(p1 - p2, p - p2);
	return s1 >= 0 && s2 >= 0;
}


bool testBit(lint use, int x) {
	return (use >> x) & 1;
}

void solve(int num) {
	printf("Case #%d:\n", num);
	int N;
	vector<Point> v;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		Point p;
		cin >> p.x >> p.y;
		v.pb(p);
	}

	for (int i = 0; i < N; ++i) {
		int ans = 1 << 30;
		for (int use = 0; use < (1 << N); ++use) {
			if (testBit(use, i)) {
				vector<Point> u;		
				int cnt = 0;		
				for (int j = 0; j < N; ++j) {
					if (testBit(use, j)) {
						u.pb(v[j]);
						++cnt;
					}
				}
				convex_hull(u);
				bool ok = false;
				for (int j = 0; j < sz(u); ++j) {
					int nj = j + 1;
					if (nj == sz(u)) nj = 0;
					if (InsideInSegm(u[j], u[nj], v[i])) {
					//if (u[j].x == v[i].x && u[j].y == v[i].y) {
						ok = true;
						break;
					}

				}
				if (ok) {
					ans = min(ans, N - cnt);
				}
			}
		}
		cout << ans << endl;
	}

	
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tst;
	cin >> tst;
	for (int i = 1; i <= tst; ++i) {
		solve(i);
	}
    return 0;
}
