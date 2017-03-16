#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <climits>
#include <complex>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define FOREACH(i, n) for (__typeof((n).begin()) i = (n).begin(); i != (n).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(v) ((int)v.size())

#define pb push_back
#define mp make_pair

const double EPS = 1e-8;
const double INF = 1e12;

typedef complex<double> P;
typedef P Point;
namespace std {
    bool operator < (const P& a, const P& b) {
        return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
    }
}
double cross(const P& a, const P& b) {
    return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
    return real(conj(a)*b);
}

struct L : public vector<P> {
    L(const P &a, const P &b) {
        push_back(a); push_back(b);
    }
};

typedef vector<P> G;

struct C {
    P p; double r;
    C(const P &p, double r) : p(p), r(r) { }
};

int ccw(P a, P b, P c) {
    b -= a; c -= a;
    if (cross(b, c) > 0)   return +1;       // counter clockwise
    if (cross(b, c) < 0)   return -1;       // clockwise
    if (dot(b, c) < 0)     return +2;       // c--a--b on line
    if (norm(b) < norm(c)) return -2;       // a--b--c on line
    return 0;
}

vector<Point> convex_hull(vector<Point> ps) {
	int n = ps.size(), k = 0;
	sort(ps.begin(), ps.end());
	vector<Point> ch(2 * n);
	for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
		while (k >= 2 && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) --k;
	for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--]) // upper-hull
		while (k >= t && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) --k;
	ch.resize(k - 1);
	return ch;
}


typedef vector<P> Polygon;

/// 中は2, 外は0, 境界は1
int convex_contains(const Polygon &poly, const Point &p) {
	// 頂点は個別に判定
	for (auto p2 : poly) {
		if (fabs(p2.real() - p.real()) < EPS && fabs(p2.imag() - p.imag()) < EPS) return 1;
	}

	const int n = poly.size();
	Point g = (poly[0] + poly[n / 3] + poly[2 * n / 3]) / 3.0; // inner-Point
	int a = 0, b = n;
	while (a + 1 < b) { // invariant: c is in fan g-poly[a]-poly[b]
		int c = (a + b) / 2;
		if (cross(poly[a] - g, poly[c] - g) > 0) { // angle < 180 deg
			if (cross(poly[a] - g, p - g) > 0 && cross(poly[c] - g, p - g) < 0) b = c;
			else                                                  a = c;
		}
		else {
			if (cross(poly[a] - g, p - g) < 0 && cross(poly[c] - g, p - g) > 0) a = c;
			else                                                  b = c;
		}
	}
	b %= n;
	if (cross(poly[a] - p, poly[b] - p) < 0) return 0;
	if (cross(poly[a] - p, poly[b] - p) > 0) return 2;
	return 1;
}


#define curr(P, i) P[(i) % P.size()]
#define next(P, i) P[(i+1) % P.size()]
#define prev(P, i) P[(i+P.size()-1) % P.size()]
bool isconvex(const Polygon &p) {
    for (int i = 0; i < p.size(); ++i)
        if (ccw(prev(p, i), curr(p, i), next(p, i)) > 0) return false;
    return true;
}

vector<Point> new_points(vector<Point>& points, int i) {
    vector<Point> ret;
    REP(n, SIZE(points)) {
        if (n == i) continue;
        ret.pb(points[n]);
    }
    return ret;
}

int bitcount(int j) {
    int ret = 0;
    while(j) {
        if (j % 2) ++ret;
        j /= 2;
    }
    return ret;
}

void solve() {
    int N;
    vector<Point> points;
    cin >> N;
    REP(n, N) {
        int X, Y;
        cin >> X >> Y;
        points.pb( P(X, Y) );
    }

	if (N <= 3) {
		REP(n, N) {
			cout << 0 << endl;
		}
		return;
	}


    REP(i, N) {
        Point interest = points[i];
        auto points_wo_one = new_points(points, i);
        int ret = 10000;
        
        // brute force
        REP(j, (1 << (N-1))) {
            int point_num = bitcount(j);
            if (point_num < 2) continue;

			if (point_num == 2) {
				ret = min(ret, N - 3);
				continue;
			}

            // 凸包作る
            vector<Point> selected_points;
            REP(k, N-1) {
                if (j & (1 << k)) {
                    selected_points.pb( points_wo_one[k] );
                }
            }
			selected_points.pb(interest);
            Polygon poly = convex_hull(selected_points);



            // 内外判定
            if (convex_contains(poly, interest) == 1) {
                int need_cut = N - (point_num + 1);
                ret = min(ret, need_cut);
            }
        }

        cout << ret << endl;
    }
}

int main(void)
{
    int TEST_NUM;
    cin >> TEST_NUM;

    for(int test = 0; test < TEST_NUM; ++test){
        cout << "Case #" << (test+1) << ":" << endl;
        solve();
    }

    return 0;
}
