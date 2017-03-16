#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

#define SZ(x) ((int)((x).size()))
#define PB(x) push_back(x)
#define MEMSET(x,v) memset(x,v,sizeof(x))
#define REP(i,n) for(int (i)=0;(i)<(n);++(i))

typedef long long LL;
typedef pair<LL, int> PII; typedef pair<PII, int> PII2;

#define MAXN (15)

int x[MAXN], y[MAXN];
int N;
double INF = 1e100;
double EPS = 1e-12;
typedef double T;
struct Point {
    T x, y;
    Point() {}
    Point(T x_, T y_) : x(x_), y(y_) {}
    Point(const Point &p) : x(p.x), y(p.y) {}
    Point operator + (const Point &p) const { return Point(x+p.x, y+p.y); }
    Point operator - (const Point &p) const { return Point(x-p.x, y-p.y); }
    Point operator * (double c) const { return Point(x*c, y*c ); }
    Point operator / (double c) const { return Point(x/c, y/c ); }
    bool operator < (const Point &rhs) const { return make_pair(y,x) < make_pair(rhs.y,rhs.x); }
    bool operator == (const Point &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }
};

T cross(Point p, Point q) { return p.x*q.y-p.y*q.x; }
T area2(Point a, Point b, Point c) { return cross(a,b) + cross(b,c) + cross(c,a); }
T dot(Point p, Point q) { return p.x*q.x+p.y*q.y; }
T dist2(Point p, Point q) { return dot(p-q,p-q); }

bool between(const Point &a, const Point &b, const Point &c) {
    return (fabs(area2(a,b,c)) < EPS && (a.x-b.x)*(c.x-b.x) <= 0 && 
            (a.y-b.y)*(c.y-b.y) <= 0);
}

void ConvexHull(vector<Point> &pts) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    vector<Point> up, dn;
    for (int i = 0; i < SZ(pts); i++) {
        while (SZ(up) > 1 && area2(up[SZ(up)-2], up.back(), pts[i]) > 0) // concave down
            up.pop_back();
        while (SZ(dn) > 1 && area2(dn[SZ(dn)-2], dn.back(), pts[i]) < 0) // concave up
            dn.pop_back();
        up.push_back(pts[i]);
		dn.push_back(pts[i]);
    }
    pts = dn;
    for (int i = (int) SZ(up) - 2; i >= 1; i--) pts.push_back(up[i]);
}

bool good(int at, int mask) {
    vector<Point> p;
    REP(i, N) {
        if ((1<<i) & mask) {
            p.PB(Point(x[i], y[i]));
        }
    }
    ConvexHull(p);
    for (Point a : p) {
        if (a.x == x[at] && a.y == y[at]) {
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> N;
    REP(i, N) cin >> x[i] >> y[i];
    for (int i = 0; i < N; i++) {
        int minn = N;
        for (int j = 0; j < 1<<N; j++) {
            if ((1<<i) & j) {
                if (good(i, j)) {
                    minn = min(minn, N - __builtin_popcount(j));
                }
            }
        }
        cout << minn << endl;
    }
}

int main() {
    int test;
    cin >> test;
    REP(t, test) {
        printf("Case #%d:\n", t + 1);
        solve();

    }
    
    return 0;
}
