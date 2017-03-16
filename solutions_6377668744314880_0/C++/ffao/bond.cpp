#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <inttypes.h>
#include <ctype.h>
#include <algorithm>
#include <utility>
#include <iostream>

using namespace std;

#define TRACE(x...) x
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n")

#define _foreach(it, b, e) for (typeof(b) it = (b); it != (e); it++)
#define foreach(x...) _foreach(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

const int INF = 0x3F3F3F3F;
const double EPS = 1e-10;

int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
    double x, y;
    point(double x = 0, double y = 0): x(x), y(y) {}
    point operator +(point q) { return point(x + q.x, y + q.y); }
    point operator -(point q) { return point(x - q.x, y - q.y); }
    point operator *(double t) { return point(x * t, y * t); }
    point operator /(double t) { return point(x / t, y / t); }
    double operator *(point q) { return x * q.x + y * q.y; }
    double operator %(point q) { return x * q.y - y * q.x; }
    int cmp(point q) const {
        if (int t = ::cmp(x, q.x)) return t;
        return ::cmp(y, q.y);
    }
    bool operator ==(point q) const { return cmp(q) == 0; }
    bool operator !=(point q) const { return cmp(q) != 0; }
    bool operator < (point q) const { return cmp(q) < 0; }
    friend ostream& operator <<(ostream& o, point p) {
        return o << "(" << p.x << ", " << p.y << ")";
    }
    static point pivot;
};
point point::pivot;
double abs(point p) { return hypot(p.x, p.y); }
double arg(point p) { return atan2(p.y, p.x); }
typedef vector<point> polygon;



int T, teste;
int n;
point pp[11000];

int main() {
    for (scanf("%d", &T); T; T--) {
        printf("Case #%d:\n", ++teste);

        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &pp[i].x, &pp[i].y);
        }

        for (int i = 0; i < n; i++) {
            vector< double > ot;
            vector< double > leave;

            int cur = 0;
            int ax = 0;

            for (int j = 0; j < n; j++) if (i != j) {
                if (pp[j].y > pp[i].y) ot.push_back( arg(pp[j]-pp[i]) );
                else if (pp[j].y < pp[i].y) {
                    leave.push_back( arg(pp[i] - pp[j]) );
                    cur++;
                }
                else {
                    if (pp[j].x > pp[i].x) ot.push_back( arg(pp[j]-pp[i]) );
                    ax++;
                }
            }

            sort(ot.begin(), ot.end());
            sort(leave.begin(), leave.end());

            int ans = min(cur, n-1-cur-ax);
            
            int ee = 0;
            int ll = 0;
            while (ee < ot.size() || ll < leave.size()) {
                int cte = 0;
                int cto = 0;
                
                if (ee < ot.size() && ll < leave.size() && cmp(ot[ee], leave[ll]) == 0) {
                    double val = ot[ee];
                    while (ee < ot.size() && cmp(val, ot[ee]) == 0) {
                        cte++;
                        ee++;
                    }
                    while (ll < leave.size() && cmp(val, leave[ll]) == 0) {
                        cto++;
                        ll++;
                    }

                    int c1 = cur-cto;
                    int c2 = cur+cte;
                    int kk = min( min(c1, n-1-c1), min(c2, n-1-c2) );
                    ans = min(ans, kk);
                    cur += cte-cto;
                }
                else {
                    //if (ee < ot.size() && ll < leave.size())printf("ee %f ll %f\n", ot[ee], leave[ll]);
                    if (ee < ot.size()) {
                        if (ll == leave.size() || ot[ee] < leave[ll] + EPS) {
                            ee++;
                            cur++;
                        }
                        else {
                            ll++;
                            cur--;
                        }
                    }
                    else {
                        ll++;
                        cur--;
                    }
                    //printf("point = %d cur = %d\n", i, cur);
                    ans = min(ans, min(cur, n-1-cur));
                }       
            }
            printf("%d\n", ans);
        }


    }
}