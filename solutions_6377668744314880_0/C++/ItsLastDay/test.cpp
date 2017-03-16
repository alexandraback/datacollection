#include <bits/stdc++.h>
using namespace std;
#define DBG(x) cout << #x << " = " << x << endl;
/*
Compile:
    -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wcast-qual -Wcast-align -fwhole-program -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -lmcheck -fsanitize=address 

Check for memory usage:
    valgrind --tool=massif
 */

// Convex hull from http://e-maxx.ru/algo/convex_hull_graham
struct pt {
	long long x, y;
        pt() {}
        bool operator==(const pt &other) const
        {
            return x == other.x and y == other.y;
        }
};

bool cmp (pt a, pt b) {
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

inline long long area (pt a, pt b, pt c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
 
inline bool intersect_1 (long long a, long long b, long long c, long long d) {
	if (a > b)  swap (a, b);
	if (c > d)  swap (c, d);
	return max(a,c) <= min(b,d);
}
 
bool f(long long x, long long y)
{
    if(x == 0 or y == 0)
        return true;
    return (x < 0) ^ (y < 0);
}

bool intersect (pt a, pt b, pt c, pt d) {
	bool t1 = intersect_1 (a.x, b.x, c.x, d.x)
		&& intersect_1 (a.y, b.y, c.y, d.y);
        t1 &= f(area(a, b, c), area(a, b, d));
        t1 &= f(area(c, d, a), area(c, d, b));
        return t1;
}

void convex_hull (vector<pt> & a) {
	if (a.size() <= 1)  return;
	sort (a.begin(), a.end(), &cmp);
	pt p1 = a[0],  p2 = a.back();
	vector<pt> up, down;
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
// end convex hull.

typedef long long coord_t;
typedef long long coord2_t;
// convex hull from wikipedia
struct Point {
	coord_t x, y;
        Point() {};
 
	bool operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}

        operator pt() {
            pt ret;
            ret.x = x;
            ret.y = y;
            return ret;
        }
};
 
// 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross product.
// Returns a positive value, if OAB makes a counter-clockwise turn,
// negative for clockwise turn, and zero if the points are collinear.
coord2_t cross(const Point &O, const Point &A, const Point &B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
 
// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
vector<Point> convex_hull(vector<Point> P)
{
	int n = P.size(), k = 0;
	vector<Point> H(2*n);
 
	// Sort points lexicographically
	sort(P.begin(), P.end());
 
	// Build lower hull
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
 
	// Build upper hull
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
 
	H.resize(k);
	return H;
}
//end convex hull.

int n, x[16], y[16];
pt points[16];
Point pnts[16];
int dp[16];

void print_points(vector<pt> &a)
{
    for(const auto &u: a) {
        cout << "(" << u.x << ", " << u.y << ") ";
    }
    if(a.size())
        cout << endl;
}

void solve()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        points[i].x = x[i];
        points[i].y = y[i];
        pnts[i].x = x[i];
        pnts[i].y = y[i];

        dp[i] = 123;
    }

    for(int i = 0; i < (1 << n); i++) {
        vector<Point> cur;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                cur.push_back(pnts[j]);
            }
        }

//      cout << i << endl;
//        print_points(cur);
        cur = convex_hull(cur);
//        print_points(cur);
        for(int j = 0; j < n; j++)
            for(int k = 0; k < cur.size(); k++) {
                if(intersect(cur[k], cur[(k + 1) % cur.size()], points[j], points[j]))
                    dp[j] = min(dp[j], n - __builtin_popcount(i));
            }
    }
        
    for(int i = 0; i < n; i++)
        cout << dp[i] << endl;
}

int main()
{
    int t;
    cin >> t;
    for(int test = 1; test <= t; test++) {
        cout << "Case #" << test << ":" << endl;
        solve();
    }
    return 0;
}

