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

int N;
int ms[1024];
void doit(int cas)
{
    scanf(" %d", &N);
    assert(2 <= N && N <= 1000);
    FOR(i,N) {
        scanf(" %d", &ms[i]);
        assert(0 <= ms[i] && ms[i] <= 10000);
    }

    int maxdrop = 0;

    int ans1 = 0;
    FOR(i,N-1) {
        int drop = ms[i] - ms[i+1];
        maxdrop = max(maxdrop, drop);
        if (drop >= 0) ans1 += drop;
    }

    int ans2 = 0;
    FOR(i,N-1) {
        ans2 += min(ms[i], maxdrop);
    }

    printf("Case #%d: %d %d\n", cas, ans1, ans2);
}

int T;
int main() {
    scanf(" %d", &T);
    assert(1 <= T && T <= 100);
    FOR(cas,T) doit(cas+1);
    return 0;
}
