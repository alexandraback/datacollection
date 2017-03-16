#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
#include <cstring>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define rtrav(it, v) for(typeof((v).rbegin()) it = (v).rbegin(); it != (v).rend(); ++it)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <class T>
struct Point {
    typedef T coordType;
    typedef Point P;
    typedef const P & R;
    T x, y;
    explicit Point(T x=T(), T y=T()) : x( x), y( y) { }
    bool operator<(R p) const { return x<p.x || (x==p.x && y<p.y); }
    bool operator==(R p) const { return x==p.x && y==p.y; }
    P operator+(R p) const { return P(x+p.x, y+p.y); }
    P operator-(R p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(R p) const { return x*p.x + y*p.y; }
    T cross(R p) const { return x*p.y - y*p.x; }
    T dist2() const { return x*x + y*y; } //distance^2
    double dist() const { return sqrt((double)dist2()); } //length
    //angle to x-axis in interval [-pi, pi]
    double angle() const { return atan2(y, x); }
    P unit() const { return *this/(T)dist(); } //makes dist()=1
    P perp() const { return P(-y, x); } //rotates +pi/2 radians
    P normal() const { return perp().unit(); }
    //returns point rotated a radians counterclockwise around origo
    P rotate(double a) const {
        return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a));
    }
};
template <class T>
ostream & operator<<(ostream & os, const Point<T> & p) {
    os << "(" << p.x << "," << p.y << ")";
    return os;
}
template <class T>
istream & operator>>(istream & is, Point<T> & p) {
    is >> p.x >> p.y;
    return is;
}

template <class P>
int sideOf(const P& s, const P& e, const P& p) {
    typename P::coordType a = (e-s).cross(p-s);
    return (a > 0) - (a < 0);
}


int main() {
    typedef Point<ll> PT;
    int T;
    scanf("%d", &T);
    for(int t=0;t<T;++t) {
        int N;
        scanf("%d", &N);
        vector<PT> pts;
        for(int n=0;n<N;++n) {
            int X, Y;
            scanf("%d%d", &X, &Y);
            pts.push_back(PT(X,Y));
        }
        vector<int> cutdown(N, N>3?N:0);
        for(int i=0; i<N;++i) {
            for(int j=i+1; j<N;++j) {
                int side1 = 0, side2 = 0;
                for (int k=0;k<N;++k) {
                    int side = sideOf(pts[i],pts[j], pts[k]);
                    if (side < 0)
                        side1++;
                    else if(side > 0)
                        side2++;
                }
                side1 = min(side1,side2);
                cutdown[i] = min(cutdown[i], side1);
                cutdown[j] = min(cutdown[j], side1);
            }
        }
        printf("Case #%d:\n", t+1);
        for(int n=0;n<N;++n)
            printf("%d\n",cutdown[n]);
        fflush(stdout);
    }
    return 0;
}