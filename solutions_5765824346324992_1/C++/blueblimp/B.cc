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

#define dlog printf
//#define dlog(...)

const int inf = 123456789;
int B,N;
ll M[1024];

ll f(ll t) {
    ll ret = 0;
    FOR(k,B) {
        ret += (t + M[k] - 1) / M[k];
    }
    return ret;
}

void doit(int cas)
{
    scanf(" %d %d", &B, &N);
    assert(1 <= B && B <= 1000);
    assert(1 <= N && N <= 1000000000);
    FOR(k,B) {
        scanf("%lld", &M[k]);
        assert(1 <= M[k] && M[k] <= 100000);
    }

    ll lo = 0;
    assert(f(lo) == 0);
    assert(f(1) == B);
    ll hi = 1;
    while (f(hi) < N) {
        assert(hi < 100000000000000LL);
        hi *= 2;
    }

    while (lo+1 < hi) {
        ll mid = lo + (hi-lo)/2;
        if (f(mid) < N) lo = mid;
        else hi = mid;
    }

    int ans = inf;
    ll acc = f(lo);
    FOR(k,B) {
        if (lo % M[k] == 0) {
            ++acc;
            if (acc == N) ans = k;
        }
    }
    assert(acc == f(lo+1));

    assert(ans != inf);
    printf("Case #%d: %d\n", cas, ans + 1);
}

int T;
int main() {
    scanf(" %d", &T);
    assert(1 <= T && T <= 100);
    FOR(cas,T) doit(cas+1);
    return 0;
}
