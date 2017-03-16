#include<bits/stdc++.h>

typedef long long ll;
typedef std::pair<int,int> PII;
typedef std::pair<ll,ll> PLL;

template<class T> inline T pr(T x) { return --x; }
template<class T> inline T nx(T x) { return ++x; }

const int maxn = 1010;
int a[maxn],ans1,ans2,n;

int main() {
    int i,j,k,t,tt,T,Test;
    scanf("%d",&Test);
    for (T=1; T<=Test; ++T) {
        scanf("%d",&n);
        for (i=1; i<=n; ++i) scanf("%d",a+i);
        ans1 = ans2 = 0;
        for (i=1; i<n; ++i)
            if (a[i]>a[i+1]) ans1 += a[i]-a[i+1];
        int tmp = 0;
        for (i=1; i<n; ++i)
            if (a[i]>=a[i+1]) tmp = std::max(tmp,a[i]-a[i+1]);
        for (i=1; i<n; ++i)
            ans2 += std::min(tmp,a[i]);
        printf("Case #%d: %d %d\n",T,ans1,ans2);
    }

    return 0;
}
