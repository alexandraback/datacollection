#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define EPS 1e-10
typedef long long LL;

#define eps 1e-10
#define zero(x) (fabs(x)<eps)
struct point{ double x, y; };

double xmult(point p1, point p2, point p0){
    return (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);
}

point p1, p2;
int graham_cp(const void* a, const void* b){
    point *pa = (point*)a;
    point *pb = (point*)b;
    double ret = xmult(*pa, *pb, p1);
    if (zero(ret)) return xmult(*pa, *pb, p2) > 0 ? 1 : -1;
    else return (ret>0 ? 1 : -1);
}
void _graham(int n, point* p, int& s, point* ch){
    int i, k = 0;
    for (p1 = p2 = p[0], i = 1; i<n; p2.x += p[i].x, p2.y += p[i].y, i++)
    if (p1.y - p[i].y>eps || (zero(p1.y - p[i].y) && p1.x>p[i].x))
        p1 = p[k = i];
    p2.x /= n, p2.y /= n;
    p[k] = p[0], p[0] = p1;
    qsort(p + 1, n - 1, sizeof(point), graham_cp);
    for (ch[0] = p[0], ch[1] = p[1], ch[2] = p[2], s = i = 3; i<n; ch[s++] = p[i++])
    for (; s>2 && xmult(ch[s - 2], p[i], ch[s - 1])<-eps; s--);
}

int graham(int n, point* p, point* convex, int maxsize = 1, int dir = 1){
    point* temp = new point[n];
    int s, i;
    _graham(n, p, s, temp);
    for (convex[0] = temp[0], n = 1, i = (dir ? 1 : (s - 1)); dir ? (i<s) : i; i += (dir ? 1 : -1))
    if (maxsize || !zero(xmult(temp[i - 1], temp[i], temp[(i + 1) % s])))
        convex[n++] = temp[i];
    delete[]temp;
    return n;
}

point p[20], convex[20];

void run() {
    int n;
    cin >> n;
    vector<point> ps(n);
    REP(i, n) cin >> ps[i].x >> ps[i].y;

    REP(pi, n) {
        if (n <= 3) {
            cout << 0 << endl;
            continue;
        }

        int mi = n - 3;
        REP(st, 1 << n) {
            if (st & (1 << pi)) continue;
            int sz = 0;
            REP(i, n) if ((st & (1 << i)) == 0) p[sz++] = ps[i];
            if (n - sz >= mi) continue;
            int r = graham(sz, p, convex, 1, 1);
            bool isok = false;
            REP(i, r) {
                if (zero(ps[pi].x - convex[i].x) && zero(ps[pi].y - convex[i].y)) {
                    isok = true;
                    break;
                }
            }
            if (isok) mi = n - sz;
        }

        cout << mi << endl;
    }
}

int main() {
    int k;
    cin >> k;
    FOR(c,1,k) {
        cout << "Case #" << c << ":" << endl;
        run();
    }
    return 0;
}
