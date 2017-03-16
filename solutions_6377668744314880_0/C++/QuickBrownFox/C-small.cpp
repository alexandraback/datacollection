#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define gc getchar
int getint() { unsigned int c; int x = 0; while (((c = gc()) - '0') >= 10) { if (c == '-') return -getint(); if (!~c) exit(0); } do { x = (x << 3) + (x << 1) + (c - '0'); } while (((c = gc()) - '0') < 10); return x; }
int getstr(char *s) { int c, n = 0; while ((c = gc()) <= ' ') { if (!~c) exit(0); } do { s[n++] = c; } while ((c = gc()) > ' ' ); s[n] = 0; return n; }
template<class T> inline bool chmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template<class T> inline bool chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }

typedef ll Real;
const ll eps = 0;
const ll real_inf = 1LL << 60;
int isign(Real r) {  return (r < -eps) ? -1 : (r > eps) ? 1 : 0; return 0; }
inline Real ab(Real x) { return x > 0 ? x : -x; }
struct Point {
    Real x, y;
    int idx;
    Point() {};
    Point(Real x, Real y) : x(x), y(y) {};
    Point& operator+=(const Point& a) { x += a.x, y += a.y; return *this; }
    Point& operator-=(const Point& a) { x -= a.x, y -= a.y; return *this; }
    Point operator-() const { return Point(-x, -y); }
    Point operator+(const Point& a) const { return Point(*this) += a; }
    Point operator-(const Point& a) const { return Point(*this) -= a; }
    Point operator*(Real k) const { return Point(x * k, y * k); }
    Point operator/(Real k) const { return Point(x / k, y / k); }
    bool operator<(const Point& a) const { return (x != a.x) ? (x < a.x) : (y < a.y); }
    bool operator==(const Point& a) const { return isign(x - a.x) == 0 and isign(y - a.y) == 0; }
};
Point operator*(const Real& k, const Point& p) { return Point(k * p.x, k * p.y); }
inline Real abs(const Point& a) { return sqrt(a.x * a.x + a.y * a.y); }
inline Real nrm(const Point& a) { return a.x * a.x + a.y * a.y; }
inline Real arg(const Point& a) { Real t = atan2(a.y, a.x); return t > 0 ? t : t + 2 * M_PI; } // [0, 2pi)
inline Real crs(const Point& a, const Point& b) { return a.x * b.y - b.x * a.y; }
inline Real dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }
inline Real arg(const Point& a, const Point& b) { Real t = abs(arg(a) - arg(b)); if (t > M_PI) t = 2 * M_PI - t; return t; }
inline Point rotate(const Point& p, Real rad) { Real a = abs(p), t = arg(p); return Point(a * cos(t + rad), a * sin(t + rad)); }
inline Point rotate(const Point& p, const Point& o, Real rad) { return rotate(p - o, rad) + o; }
// a -> b -> c
// 1 = accw, -1 = ccw, 2 = b-a-c, -2 = a-b-c, 0 = b-c-a or same points
inline int ccw(Point a, Point b, Point c) { b -= a, c -= a, a.x = crs(b, c); if (a.x > 0) return 1; if (a.x < 0) return -1; if (dot(b, c) < 0) return 2; a.x = nrm(b), a.y = nrm(c); if (a.x < a.y) return -2;  return 0; }
inline Real pt_pt_dist(Point p, const Point& q) { p -= q; return abs(p); }
ostream& operator<< (ostream& os, const Point& a) { os << "("<<a.x << ", " << a.y << ")"; return os; }

vector<Point> convex_hull(vector<Point> ps) {
    int n = ps.size(), k = 0; if (n <= 2) return ps;
    sort(ps.begin(), ps.end());
    vector<Point> ch(2 * n);
    for (int i = 0; i < n; ch[k++] = ps[i++])
    while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
    for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--])
    while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
    ch.resize(k-1);
    return ch;
}

void print_case(int test_case) { printf("Case #%d: ", test_case); }

int n;

void solve_case() {
    int i, j;
    n = getint();
    vector<Point> points(n);
    for (i = 0; i < n; i++) {
        points[i].x = getint();
        points[i].y = getint();
        points[i].idx = i;
    }

    vector<int> res(n, n - 1);

    for (int h = 0; h < 1 << n; h++) {
        int popc = __builtin_popcount(h);
        if (popc < 2) continue;
        vector<Point> use_points;
        for (i = 0; i < n; i++) if (h >> i & 1) {
            use_points.push_back(points[i]);
        }
        vector<Point> chull = convex_hull(use_points);
        vector<int> add_points;
        for (i = 0; i < chull.size(); i++) {
            Point o = chull[i];
            Point p1 = chull[(i + 1) % chull.size()];
            for (j = 0; j < n; j++) {
                Point p2 = points[j];
                if (o == p2) continue;
                if (p1 == p2) continue;
                Point v1 = p1 - o;
                Point v2 = p2 - o;
                if (v1.x * v2.y == v1.y * v2.x) {
                    add_points.push_back(j);
                }
            }
        }

        int need_cut = n - popc;
        for (i = 0; i < chull.size(); i++) {
            int which = chull[i].idx;
            chmin(res[which], need_cut);
        }
        for (i = 0; i < add_points.size(); i++) {
            int which = add_points[i];
            chmin(res[which], need_cut);
        }
    }

    puts("");
    for (i = 0; i < n; i++) {
        printf("%d\n", res[i]);
    }

    return;
}

int main () {
    int test_count, test_case = getint();
    for (test_count = 0; test_count < test_case; test_count++) {
        print_case(test_count + 1);
        solve_case();
    }
    return 0;
}
