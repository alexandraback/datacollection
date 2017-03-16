#include<bits/stdc++.h>

typedef long long ll;
typedef std::pair<int,int> PII;
typedef std::pair<ll,ll> PLL;

template<class T> inline T pr(T x) { return --x; }
template<class T> inline T nx(T x) { return ++x; }

const ll maxn = 1010;
ll n,a[maxn],T,m;

int main() {
    ll i,j,k,t,tt,T,Test,l,r,mid;
    scanf("%lld",&Test);
    for (T=1; T<=Test; ++T) {
        scanf("%lld%lld",&n,&m);
        for (i=1; i<=n; ++i) scanf("%lld",a+i);
        l = 0; r = ll(1e14) + 100l;
        while (l<r) {
            mid = (l+r)>>1;
            t = 0;
            for (i=1; i<=n; ++i) t += (mid+1+a[i]-1)/a[i];
            if (t<m) l = mid+1; else r = mid;
        }
        t = 0;
        for (i=1; i<=n; ++i){
            t += (l+a[i]-1)/a[i];
        }
        for (i=1; i<=n; ++i) {
            if (l%a[i]==0) ++t;
            if (t==m) break;
        }
        printf("Case #%lld: %lld\n",T,i);
    }

    return 0;
}
