#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

struct P {
    ll y, x;

    P operator-(const P &o) const {
        P res;
        res.y = y-o.y;
        res.x = x-o.x;
        return res;
    }
};

P o;

ll cross(P a, P b) {
    return a.x*b.y-b.x*a.y;
}

bool cmp(P a, P b) {
    a = a-o; b = b-o;
    int ah = a.y > 0 || (a.y == 0 && a.x > 0);
    int bh = b.y > 0 || (b.y == 0 && b.x > 0);
    //printf("%d:(%lld,%lld) %d:(%lld,%lld)\n", ah, a.y, a.x, bh, b.y, b.x);
    if (ah != bh) {
        return ah > bh;
    }
    return cross(a,b) < 0;
}

int main() {
    int T; scanf("%d", &T);
    FO(Z,1,T+1) {
        int n; scanf("%d", &n);
        vector<P> l(n);
        FO(i,0,n) scanf("%lld %lld", &l[i].y, &l[i].x);
        printf("Case #%d:\n", Z);
        for (P p : l) {
            //printf("PROC %lld, %lld\n", p.y, p.x);

            vector<P> c = l;
            FO(i,0,sz(c)) {
                if (c[i].y == p.y && c[i].x == p.x) {
                    c.erase(c.begin()+i);
                }
            }
            o = p;
            sort(c.begin(),c.end(),cmp);

            if (sz(c) <= 2) {
                printf("0\n");
                continue;
            }

            int res = 1e9;
            int L = 0;
            FO(p0,0,sz(c)) {
                //printf("%lld,%lld\n", c[p0].y, c[p0].x);
                int p1 = (p0+L+1)%sz(c);
                while (cross(p-c[p0],p-c[p1]) < 0) {
                    L++;
                    p1 = (p0+L+1)%sz(c);
                }
                //printf("%lld,%lld\n", c[p1].y, c[p1].x);
                //printf("--\n");
                res = min(res,L);
                L--;
                if (L < 0) L = 0;
            }
            printf("%d\n", res);
        }
    }
}

