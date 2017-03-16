#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <list>
#include <stack>
#include <tuple>
#include <utility>
#include <complex>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <typeinfo>
using namespace std;

typedef long long lint;
typedef pair<int,int> pii;
typedef pair<lint,lint> pll;

#define REP(i,n) for(int i=0; i<(n); i++)
#define REPA(i,s,e) for(int i=(s); i<=(e); i++)
#define REPD(i,s,e) for(int i=(s); i>=(e); i--)
#define ALL(a) (a).begin(), (a).end()

#define PRT(a) cerr << #a << " = " << (a) << endl
#define PRT2(a, b) cerr << #a << " = " << (a) << ", " << #b << " = " << (b) << endl
#define PRT3(a, b, c) cerr << #a << " = " << (a) << ", " << #b << " = " << (b) << ", " << #c << " = " << (c) <<  endl
template <class Ty> void print_all(Ty b, Ty e) {
	cout << "[ ";
	for(Ty p=b; p!=e; ++p) {
		cout << (*p) << ", ";
	}
	cout << " ]" << endl;
}

// geometry library start

const double EPS = 1.0e-10;
const double PI = 4.0 * atan(1.0);
int sign(double r) { return r < -EPS ? -1 : r > EPS ? 1 : 0; }

class P {
public:
    double x, y;
    P() {}
    P(int x_, int y_) : x(x_), y(y_) {}
    P(double x_, double y_) : x(x_), y(y_) {}
    P(const P& p) : x(p.x), y(p.y) {}
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator-() const { return P(-x, -y); }
    P operator*(double s) const { return P(x*s, y*s); }
    P operator/(double s) const { return P(x / s, y / s); }
    P& operator=(const P& p) { x = p.x; y = p.y; return (*this); }
    double dot(P p) const { return x*p.x + y*p.y; }
    double det(P p) const { return x*p.y - y*p.x; }
    double norm() const { return sqrt(x*x + y*y); }
    double norm2() const { return x*x + y*y; }
    P proj(const P& p) const { double k = det(p) / norm2(); return P(x*k, y*k); }
};

bool operator<(P p, P q) {
    if (sign(p.x - q.x) != 0) return p.x < q.x;
    return p.y < q.y;
}

bool operator>(P p, P q) {
    if (sign(p.x - q.x) != 0) return p.x > q.x;
    return p.y > q.y;
}


double tri(P a, P b, P c) { return (b - a).det(c - a); }

class L {
public:
    P s, t;
    L() {}
    L(P s_, P t_) : s(s_), t(t_) {}
    L(const L& l) : s(l.s), t(l.t) {}
    L& operator=(const L& l) { s = l.s; t = l.t; return (*this); }
    double length() { return (s - t).norm(); }
    P vec() const { return t - s; }
    P proj(const P& p) { return s + vec().proj(p - s); }
    int iLL(const L& l) const {
        if (sign(vec().det(l.vec()))) return 1;
        if (sign(vec().det(l.s - s))) return 0;
        return -1;
    }
    bool iLS(const L& l) const { return sign(tri(s, t, l.s)) * sign(tri(s, t, l.t)) <= 0; }
    bool iSS(const L& l) const { return iLS(l) && l.iLS(*this); }
    P pLL(const L& l) const { return s + vec() * (l.s - s).det(l.vec()) / vec().det(l.vec()); }
    double dLP(const P& p) const { return abs(tri(s, t, p)) / vec().norm(); }
    double dSP(const P& p) const {
        if (sign(vec().dot(p - s)) <= 0) return (p - s).norm();
        if (sign(vec().dot(p - t)) >= 0) return (p - t).norm();
        return dLP(p);
    }
};

class C {
public:
    P p;
    double r;
    C() {}
    C(P p_, double r_) : p(p_), r(r_) {}
    C(const C& c) : p(c.p), r(c.r) {}
    C& operator=(const C& c) { p = c.p; r = c.r; return (*this); }
};

int ccw(P a, P b, P c) {
    b = b - a;
    c = c - a;
    if (sign(b.det(c)) > 0)    return  1;  // counter clockwise
    if (sign(b.det(c)) < 0)    return -1;  // clockwise
    if (sign(b.dot(c)) < 0)    return  2;  // c-a-b on line
    if (b.norm2() < c.norm2()) return -2;  // a-b-c on line
    return 0;
}

// geometry library end

// convex hull functions start

bool check_new(vector<P>& v, P p) {
    int nv = v.size();
    if (nv < 2) return true;

    return sign((p - v[nv - 1]).det(v[nv - 2] - v[nv - 1])) <= 0;
}

void convex_hull(vector<P>& hull, vector<P>& points) {
    if (points.size() <= 2) {
        hull = vector<P>(points.size());
        copy(points.begin(), points.end(), hull.begin());
        return;
    }

    sort(points.begin(), points.end());
    int np = points.size();

    vector<P> upper;
    upper.push_back(points[0]);
    upper.push_back(points[1]);
    for (int i = 2; i<np; i++) {
        while (!check_new(upper, points[i])) {
            upper.pop_back();
        }
        upper.push_back(points[i]);
    }

    vector<P> lower;
    lower.push_back(points[np - 1]);
    lower.push_back(points[np - 2]);
    for (int i = np - 3; i >= 0; i--) {
        while (!check_new(lower, points[i])) {
            lower.pop_back();
        }
        lower.push_back(points[i]);
    }

    hull = vector<P>();
    for (int i = 0; i<upper.size() - 1; i++) {
        hull.push_back(upper[i]);
    }
    for (int i = 0; i<lower.size() - 1; i++) {
        hull.push_back(lower[i]);
    }
}

// convex hull functions end

// -----------------------------------------------------------------------------
// Code starts 
// -----------------------------------------------------------------------------

int n;
P p[3011];

int bits(int n) {
    int ret = 0;
    while (n != 0) {
        ret += (n & 0x01);
        n >>= 1;
    }
}

void solve() {
    int x, y;
    cin >> n;
    REP(i, n) {
        cin >> x >> y;
        p[i] = P(x, y);
    }

    vector<P> pts;
    vector<P> hull;
    vector<int> ans(n, n);
    for (int mask = 0; mask < (1 << n); mask++) {
        pts.clear();
        hull.clear();
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) != 0) {
                pts.push_back(p[i]);
            }
        }
        convex_hull(hull, pts);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < hull.size(); j++) {
                if ((p[i] - hull[j]).norm() < EPS) {
                    ans[i] = min(ans[i], n - (int)pts.size());
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", ans[i]);
    }
}

// -----------------------------------------------------------------------------
// Code ends 
// -----------------------------------------------------------------------------

void coding() {
    int T;
    cin >> T;
    REPA(t,1,T) {
        fprintf(stderr, "%3d / %d\n", t, T);
        printf("Case #%d:\n", t);
        solve();
    }
}

#define _LOCAL_TEST 1

int main() {
#if _LOCAL_TEST == 0
	clock_t startTime = clock();
	freopen("c.in", "r", stdin);
#elif _LOCAL_TEST == 1
	freopen("../input/C-small-attempt0.in", "r", stdin);
    freopen("../input/C-small.out", "w", stdout);
#elif _LOCAL_TEST == 2
	freopen("../input/C-large.in", "r", stdin);
    freopen("../input/C-large.out", "w", stdout);
#endif

	coding();

#if _LOCAL_TEST == 0
	clock_t elapsedTime = clock() - startTime;
	cerr << endl;
	cerr << (elapsedTime / 1000.0) << " sec elapsed." << endl;
	cerr << "This is local test" << endl;
	cerr << "Do not forget to comment out _LOCAL_TEST" << endl << endl;
#endif

}
