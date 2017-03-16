#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn = 1005;
const ll inf=1000000000000000LL;

int n,m;
int a[maxn];

ll cal(ll x) {
    ll ret=0;
    for(int i=1; i<=n; i++) {
        if(x%a[i]==0LL)ret+=x/a[i]+1;
        else ret+=(x+a[i]-1)/a[i];
    }
    return ret;
}
ll cal2(ll x) {
    if(x<0LL)return 0;
    ll ret=0;
    for(int i=1; i<=n; i++)
        if(x%a[i]==0LL)ret+=x/a[i];
        else ret+=(x+a[i]-1)/a[i];
    return ret;
}

int main() {
   // freopen("in.cpp", "r", stdin);
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out", "w", stdout);
    int ncase=0;
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)scanf("%d",&a[i]);
        ll l=0,r=inf;
        ll ret=r;
        while(l<=r) {
            ll mid=(l+r)>>1LL;
            ll tt=cal(mid);
            if(tt>=m) {
                ret=mid;
                r=mid-1;
            } else l=mid+1;
        }
        ll tt=cal2(ret);
        int ans=0,cha=(int)(m-tt);
        for(int i=1; i<=n; i++) {
            if(ret%a[i]==0LL) {
                if(cha==1) {
                    ans=i;
                    break;
                } else cha--;
            }
        }
        printf("Case #%d: %d\n",++ncase,ans);
    }
    return 0;
}
