#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <queue>
#include <set>
#include <sstream>
#include <cstdio>
#define FOR(i,a,b) for(int i=(a);i<=(b); i++)
#define FR(i,b) for(int i=0; i<(b);i++)
#define DR(i,b) for(int i=(b)-1; i>=0;i--)
#define DOWN(i,a,b) for(int i=(a); i >=(b); i--)
#define X first
#define Y second
#define XX first.first
#define XY first.second
#define YX second.first
#define YY second.second
#define double long double
using namespace std;

const double eps = 1e-10;
int cmp(double q,double w) {
    return (q < w + eps) ? (q > w - eps) ? 0 : -1 : 1;
}
struct point {
    double x,y;
    point (double x,double y): x(x),y(y) {}
    point () {x=y=0.0; }
    point operator +(point q) { return point(x+q.x,y+q.y); }
    point operator -(point q) { return point(x-q.x,y-q.y); }
    point operator *(double t) { return point(x*t,y*t); }
    point operator /(double t) { return point(x/t,y/t); }
    double operator *(point q){ return q.x * x + q.y * y; }
    double operator %(point q){ return x*q.y - y*q.x; }
    int cmp(point q) const { if(int t = ::cmp(x,q.x)) return t; return ::cmp(y,q.y); }
    #define Comp(x) bool operator x (point q) const { return cmp(q) x 0; }
    Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)
    #undef Comp
};
typedef vector<point> polygon;
inline int ccw(point a, point b, point c) {
    return cmp((b-a)%(c-a),0);
}
struct comp_hull {
    point pivot;
    bool operator() (point q,point w) {
        point Q = q - pivot, W = w - pivot;
        double R = Q % W;
        if (cmp(R,0)) return R < 0;
        return cmp(Q*Q,W*W) < 0;
    }
};
polygon convex_hull(polygon p) { // minimum vertices
    int j = 0, k, n = p.size();
    polygon r(n);
    if (!n) return r;
    comp_hull comp;
    comp.pivot = *min_element(p.begin(),p.end());
    sort(p.begin(),p.end(),comp);
    FR(i,n) {
        while (j > 1 && ccw(r[j-1],r[j-2],p[i]) <= 0) j--;
        r[j++] = p[i];
    }
    r.resize(j);
    return r;
}
bool eq(double x, double y) {
    return abs(x-y) < eps;
}
bool leq(double x, double y) {
    return eq(x,y) || (x < y);
}
bool linear(point A, point B, point C) {
    return eq((C-A)%(C-B),0) && leq((C-A)*(C-B),0);
}
int n;
polygon p;
point P[4000];
void solve() {
    FOR(i,1,n) {
        point pivot = P[i];
        int res = 1000000009;
        FR(state, (1 << n)) if (state) {
            p.clear();
            int cnt = 0;
            FOR(j,1,n)
            if (state & (1 << (j-1))) {
                p.push_back(P[j]);
                cnt++;
            }

            cnt = n - cnt;
            polygon q = convex_hull(p);

            int m = q.size();
            q.push_back(q[0]);
            FR(j,m) {
                if (linear(q[j], q[j+1], pivot)) {
                    res = min(res,cnt);
                }
            }
        }
        cout << res << endl;
    }

}

int main() {
    std::ios::sync_with_stdio(false);
    freopen("C-small-1.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int ntest;
    cin >> ntest;

    FOR(test,1,ntest) {
        cout << "Case #" << test << ":" << endl;;
        cin >> n;
        p.clear();
        double u,v;
        FOR(i,1,n) {
            cin >> P[i].x >> P[i].y;
            p.push_back(P[i]);
        }
        solve();
    }
    return 0;
}

