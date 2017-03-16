#include <algorithm>
#include <cassert>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

#define FR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,n) FR(i,0,n)
#define CLR(x,a) memset(x,a,sizeof(x))
#define setmin(a,b) a = min(a,b)
#define PB push_back
#define FORALL(i,v) for(typeof((v).end())i=(v).begin();i!=(v).end();++i)
#define MP make_pair
#define A first
#define B second
#define RF(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define BEND(v) (v).begin(),(v).end()
#define SZ(v) int((v).size())
#define FORI(i,v) FOR(i,SZ(v))
typedef long double ld;
typedef long long ll;

typedef complex<ll> cpx;

//#define dlog printf
#define dlog(...)

const bool DO_VRF = true;

int halfspace(const cpx & p) {
    assert(norm(p) != 0);
    return (imag(p) == 0 && real(p) < 0) || imag(p) < 0;
}
bool nearer_ccw(const cpx & p, const cpx & q) {
    return halfspace(conj(p) * q) == 0;
}
bool lt_ccw(const cpx & p, const cpx & q) {
    int hsp = halfspace(p), hsq = halfspace(q);
    if (hsp != hsq) return hsp < hsq;
    return imag(conj(p) * q) > 0;
}
bool coray(const cpx & p, const cpx & q) {
    cpx r = conj(p) * q;
    assert(norm(r) != 0);
    return real(r) > 0 && imag(r) == 0;
}

bool vrf_lt_ccw(const cpx & p, const cpx & q) {
    return lt_ccw(p,q) && !lt_ccw(q,p);
}

void check() {
    assert(nearer_ccw(cpx(10, 0), cpx(10, 10)));
    assert(!nearer_ccw(cpx(10, 10), cpx(10, 0)));
    assert(nearer_ccw(cpx(10, 0), cpx(10, 0)));

    assert(halfspace(cpx(100, 100)) == 0);
    assert(halfspace(cpx(100, -100)) == 1);

    assert(coray(cpx(5,5), cpx(10,10)));
    assert(!coray(cpx(5,5), cpx(-10,-10)));

    // more halfspace check
    assert(halfspace(cpx(5,0)) == 0);
    assert(halfspace(cpx(-3,-5)) == 1);

    // sort check
    assert(vrf_lt_ccw(cpx(5, 0), cpx(5, 1)));
    assert(vrf_lt_ccw(cpx(5, 0), cpx(-1, 2)));
    assert(vrf_lt_ccw(cpx(5, 0), cpx(-2, 2)));
    assert(vrf_lt_ccw(cpx(5, 0), cpx(-3, -5)));

    assert(vrf_lt_ccw(cpx(5, 1), cpx(-1, 2)));
    assert(vrf_lt_ccw(cpx(5, 1), cpx(-2, 2)));
    assert(vrf_lt_ccw(cpx(5, 1), cpx(-3, -5)));

    assert(vrf_lt_ccw(cpx(-1, 2), cpx(-2, 2)));
    assert(vrf_lt_ccw(cpx(-1, 2), cpx(-3, -5)));

    assert(vrf_lt_ccw(cpx(-2, 2), cpx(-3, -5)));
}

const int inf = 123456789;
size_t N;
ll X[4096], Y[4096]; 
cpx ps[4096];
void doit(int cas)
{
    scanf(" %zu", &N);

    FOR(i,N) {
        ll x,y;
        scanf("%lld%lld", &x, &y);
        ps[i] = cpx(x,y);
    }

    printf("Case #%d:\n", cas);
    FOR(i,N) {
        vector<cpx> qs; // translated space points
        FOR(j,N) if (i != j) qs.push_back(ps[j] - ps[i]);
        assert(qs.size() + 1 == N);

        int vrf = inf;
        if (DO_VRF) {
            int Q = qs.size();
            FOR(j,Q) {
                int cur = 0;
                FOR(k,Q) {
                    cpx r = conj(qs[j]) * qs[k];
                    if (imag(r) > 0) ++cur;
                }
                dlog("  VERIFY j = %2d: cur = %d\n", j, cur);
                vrf = min(vrf, cur);
            }
        }
        dlog("  vrf = %d\n", vrf);

        sort(BEND(qs), lt_ccw);

        vector<pair<cpx,int>> ws; // weighted unique angles
        int s = 0;
        while (s < qs.size()) {
            int e = s;
            while (e < qs.size() && coray(qs[s], qs[e])) ++e;
            ws.push_back( make_pair(qs[s], e - s));
            s = e;
        }

        int ans = inf;

        int W = ws.size();
        FOR(j,W) ws.push_back(ws[j]);

        FOR(j,W) dlog("  %2lld %2lld count %d\n",
            real(ws[j].first), imag(ws[j].first), ws[j].second);

        int cur = 0;
        int b = 0;
        FOR(a,W) {
            while (b < a + W && nearer_ccw(ws[a].first, ws[b].first)) {
                cur += ws[b].second;
                ++b;
            }
            cur -= ws[a].second;
            assert(b > a);
            dlog("  cur = %d (a = %d, b = %d)\n", cur, a, b);

            ans = min(ans, cur);
        }

        if (N == 1) ans = 0;

        if (vrf != inf) assert(ans == vrf);

        printf("%d\n", ans);
    }
}

int T;
int main() {
    check();
    scanf(" %d", &T);
    assert(1 <= T && T <= 100);
    FOR(cas,T) doit(cas+1);
    return 0;
}
