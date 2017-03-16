#define GCJ_NEWLINE
#include "../../lib/include.h"

const double pi = acos(-1.0);
const double EPS = 1e-9;

#include <complex>
#define P(p) const point &p
#define L(p0, p1) P(p0), P(p1)
#define C(p0, r) P(p0), double r
#define PP(pp) pair<point,point> &pp
typedef complex<double> point;
typedef pair<int,int> ipoint;
double dot(P(a), P(b)) { return real(conj(a) * b); }
double cross(P(a), P(b)) { return imag(conj(a) * b); }
ll cross(const ipoint &a, const ipoint &b) {
    return (ll)a.first * b.second - (ll)a.second * b.first;
}
point rotate(P(p), double radians = pi / 2, P(about) = point(0,0)) { 
    return (p - about) * exp(point(0, radians)) + about; }
point reflect(P(p), L(about1, about2)) {
    point z = p - about1, w = about2 - about1;
    return conj(z / w) * w + about1; }
point proj(P(u), P(v)) { return dot(u, v) / dot(u, u) * u; }
point normalize(P(p), double k = 1.0) { 
    return abs(p) == 0 ? point(0,0) : p / abs(p) * k; } //TODO: TEST
bool parallel(L(a, b), L(p, q)) { return abs(cross(b - a, q - p)) < EPS; }
double ccw(P(a), P(b), P(c)) { return cross(b - a, c - b); }
ipoint sub(ipoint a, ipoint b) {
    return ipoint(a.first - b.first, a.second - b.second);
}
ll ccw(const ipoint &a, const ipoint &b, const ipoint &c) { return cross(sub(b, a), sub(c, b)); }
bool collinear(P(a), P(b), P(c)) { return abs(ccw(a, b, c)) < EPS; }
bool collinear(L(a, b), L(p, q)) {
    return abs(ccw(a, b, p)) < EPS && abs(ccw(a, b, q)) < EPS;  }
double angle(P(a), P(b), P(c)) {
    return acos(dot(b - a, c - b) / abs(b - a) / abs(c - b)); }
double signed_angle(P(a), P(b), P(c)) {
    return asin(cross(b - a, c - b) / abs(b - a) / abs(c - b)); }
double angle(P(p)) { return atan2(imag(p), real(p)); }
point perp(P(p)) { return point(-imag(p), real(p)); }
double progress(P(p), L(a, b)) {
    if (abs(real(a) - real(b)) < EPS)
        return (imag(p) - imag(a)) / (imag(b) - imag(a));
    else return (real(p) - real(a)) / (real(b) - real(a)); }
bool intersect(L(a, b), L(p, q), point &res, bool segment = false) {
    // NOTE: check for parallel/collinear lines before calling this function
    point r = b - a, s = q - p;
    double c = cross(r, s), t = cross(p - a, s) / c, u = cross(p - a, r) / c;
    if (segment && (t < 0-EPS || t > 1+EPS || u < 0-EPS || u > 1+EPS))
        return false;
    res = a + t * r;
    return true;
}
point closest_point(L(a, b), P(c), bool segment = false) {
    if (segment) {
        if (dot(b - a, c - b) > 0) return b;
        if (dot(a - b, c - a) > 0) return a;
    }
    double t = dot(c - a, b - a) / norm(b - a);
    return a + t * (b - a);
}
double line_segment_distance(L(a,b), L(c,d)) {
    double x = INFINITY;
    if (abs(a - b) < EPS && abs(c - d) < EPS) x = abs(a - c);
    else if (abs(a - b) < EPS) x = abs(a - closest_point(c, d, a, true));
    else if (abs(c - d) < EPS) x = abs(c - closest_point(a, b, c, true));
    else if ((ccw(a, b, c) < 0) != (ccw(a, b, d) < 0) &&
             (ccw(c, d, a) < 0) != (ccw(c, d, b) < 0)) x = 0;
    else {
        x = min(x, abs(a - closest_point(c,d, a, true)));
        x = min(x, abs(b - closest_point(c,d, b, true)));
        x = min(x, abs(c - closest_point(a,b, c, true)));
        x = min(x, abs(d - closest_point(a,b, d, true)));
    }
    return x;
}
int intersect(C(A, rA), C(B, rB), point & res1, point & res2) { 
    double d = abs(B - A);
    if ((rA + rB) <  (d - EPS) || d < abs(rA - rB) - EPS) return 0;
    double a = (rA*rA - rB*rB + d*d) / 2 / d, h = sqrt(rA*rA - a*a);
    point v = normalize(B - A, a), u = normalize(rotate(B-A), h);
    res1 = A + v + u, res2 = A + v - u;
    if (abs(u) < EPS) return 1; return 2;
}
int intersect(L(A, B), C(O, r), point & res1, point & res2) {
     double h = abs(O - closest_point(A, B, O));
     if(r < h - EPS) return 0;
     point H = proj(O - A, B - A) + A, v = normalize((B - A), sqrt(r*r - h*h));
     res1 = H + v; res2 = H - v;
     if(abs(v) < EPS) return 1; return 2;
 }
int tangent(P(A), C(O, r), point & res1, point & res2) {
    point v = O - A; double d = abs(v);
    if (d < r - EPS) return 0;
    double alpha = asin(r / d), L = sqrt(d*d - r*r);
    v = normalize(v, L);
    res1 = A + rotate(v, alpha); res2 = A + rotate(v, -alpha);
    if (abs(r - d) < EPS || abs(v) < EPS) return 1;
    return 2;
}
void tangent_outer(point A, double rA, point B, double rB, PP(P), PP(Q)) {
    if (rA - rB > EPS) { swap(rA, rB); swap(A, B); }
    double theta = asin((rB - rA)/abs(A - B));
    point v = rotate(B - A, theta + pi/2), u = rotate(B - A, -(theta + pi/2));
    u = normalize(u, rA);
    P.first = A + normalize(v, rA); P.second = B + normalize(v, rB);
    Q.first = A + normalize(u, rA); Q.second = B + normalize(u, rB);
}

typedef vector<point> polygon;
double polygon_area_signed(polygon p) {
    double area = 0; int cnt = size(p);
    for (int i = 1; i + 1 < cnt; i++)
        area += cross(p[i] - p[0], p[i + 1] - p[0]);
    return area / 2; }
double polygon_area(polygon p) { return abs(polygon_area_signed(p)); }
#define CHK(f,a,b,c) (f(a) < f(b) && f(b) <= f(c) && ccw(a,c,b) < 0)
int point_in_polygon(polygon p, point q) {
    int n = size(p); bool in = false; double d;
    for (int i = 0, j = n - 1; i < n; j = i++)
        if (collinear(p[i], q, p[j]) &&
            0 <= (d = progress(q, p[i], p[j])) && d <= 1)
            return 0;
    for (int i = 0, j = n - 1; i < n; j = i++)
        if (CHK(real, p[i], q, p[j]) || CHK(real, p[j], q, p[i]))
            in = !in;
    return in ? -1 : 1; }
// pair<polygon, polygon> cut_polygon(const polygon &poly, point a, point b) {
//     polygon left, right;
//     point it(-100, -100);
//     for (int i = 0, cnt = poly.size(); i < cnt; i++) {
//         int j = i == cnt-1 ? 0 : i + 1;
//         point p = poly[i], q = poly[j];
//         if (ccw(a, b, p) <= 0) left.push_back(p);
//         if (ccw(a, b, p) >= 0) right.push_back(p);
//         // myintersect = intersect where
//         // (a,b) is a line, (p,q) is a line segment
//         if (myintersect(a, b, p, q, it))
//             left.push_back(it), right.push_back(it);
//     }
//     return pair<polygon, polygon>(left, right);
// }

#define MAXN 4000
ipoint hull[MAXN];
bool cmp(const ipoint &a, const ipoint &b) {
    return a < b;
    // return abs(real(a) - real(b)) > EPS ? real(a) < real(b) : imag(a) < imag(b);
}

int convex_hull(vector<ipoint> p) {
    int n = size(p), l = 0;
    sort(p.begin(), p.end(), cmp);
    for (int i = 0; i < n; i++) {
        if (i > 0 && p[i] == p[i - 1]) continue;
        // while (l >= 2 && ccw(hull[l - 2], hull[l - 1], p[i]) >= 0) l--;
        while (l >= 2 && ccw(hull[l - 2], hull[l - 1], p[i]) > 0) l--;
        hull[l++] = p[i];
    }
    int r = l;
    for (int i = n - 2; i >= 0; i--) {
        if (p[i] == p[i + 1]) continue;
        // while (r - l >= 1 && ccw(hull[r - 2], hull[r - 1], p[i]) >= 0) r--;
        while (r - l >= 1 && ccw(hull[r - 2], hull[r - 1], p[i]) > 0) r--;
        hull[r++] = p[i];
    }
    return l == 1 ? 1 : r - 1;
}

struct solver {

    solver() {
    }

    void solve(bool process, istream &cin, ostream &cout) {

        int n;
        cin >> n;
        vector<pair<int, int> > trees(n);
        for (int i = 0; i < n; i++) {
            cin >> trees[i].first >> trees[i].second;
        }

        LOGIC;

        map<ii, int> no;
        for (int i = 0; i < n; i++) {
            no[trees[i]] = i;
        }

        vector<int> mn(n, INF);

        for (int now = 1; now < (1 << n); now++) {
            vector<pair<int, int> > curtrees;
            for (int i = 0; i < n; i++) {
                if (now & (1 << i)) {
                    curtrees.push_back(trees[i]);
                }
            }

            int cnt = convex_hull(curtrees);
            int removed = n - size(curtrees);
            for (int i = 0; i < cnt; i++) {
                mn[no[hull[i]]] = min(mn[no[hull[i]]], removed);
            }
        }

        OUTPUT;
        for (int i = 0; i < n; i++) {
            cout << mn[i] << endl;
        }
    }
};

// see https://github.com/SuprDewd/GoogleCodeJamRunner
#include "../../lib/gcj.h"
