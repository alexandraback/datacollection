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


// -----------------------------------------------------------------------------
// Code starts 
// -----------------------------------------------------------------------------

int n;
P p[3011];

void calc(int k) {
    vector<double> ang;
    for (int i = 0; i < n; i++) {
        if (i != k) {
            P diff = p[i] - p[k];
            double arg = atan2(diff.y, diff.x);
            ang.push_back(arg);
            ang.push_back(arg + 2.0 * PI);
        }
    }
    sort(ALL(ang));

    int lo, hi;
    int ans = n;
    for (int i = 0; i < n; i++) {
        if (i != k) {
            P diff = p[i] - p[k];
            double arg = atan2(diff.y, diff.x);
            lo = upper_bound(ALL(ang), arg) - ang.begin();
            hi = lower_bound(ALL(ang), arg + PI) - ang.begin();
            int left = hi - lo;
            lo = upper_bound(ALL(ang), arg + PI) - ang.begin();
            hi = lower_bound(ALL(ang), arg + 2.0 * PI) - ang.begin();
            int right = hi - lo;
            ans = min(ans, min(left, right));
        }
    }
    printf("%d\n", ans);
}

void solve() {
    int x, y;
    cin >> n;

    REP(i, n) {
        cin >> x >> y;
        p[i] = P(x, y);
    }

    if (n == 1) {
        printf("0\n");
        return;
    }

    REP(i, n) {
        calc(i);
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

#define _LOCAL_TEST 2

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
