#include<bits/stdc++.h>
#define sz(x) int((x).size())

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int,int> PII;
typedef std::pair<ll,ll> PLL;

template<class T> inline T pr(T x) { return --x; }
template<class T> inline T nx(T x) { return ++x; }

const int maxn = 20010;
int n,m,K,cnt[2],edge[2],corner[2];

int main() {
    int i,j,k,t,tt,T,Test,ans;
    scanf("%d",&Test);
    for (T=1; T<=Test; ++T) {
        scanf("%d%d%d",&n,&m,&K);
        if (n==1 && m==1) {
            printf("Case #%d: %d\n",T,0);
            continue;
        }
        if (n==1 || m==1) {
            if (m>1) swap(n,m);
            ans = 0;
            K -= (n+1)/2;
            if (K>0) {
                ans += K*2;
                if (!(n&1)) --ans;
            }
            printf("Case #%d: %d\n",T,ans);
            continue;
        }
        cnt[0] = cnt[1] = edge[0] = edge[1] = corner[0] = corner[1] = 0;
        for (i=1; i<=n; ++i) {
            j = 1;
            cnt[(i+j)&1] += min(i,m-j+1);
            if ((i==1 && j==1) || (i==n && j==m)) ++corner[(i+j)&1];
            else edge[(i+j)&1] += 2;
        }
        for (j=2; j<=m; ++j) {
            i = n;
            cnt[(i+j)&1] += min(i,m-j+1);
            if ((i==1 && j==1) || (i==n && j==m)) ++corner[(i+j)&1];
            else edge[(i+j)&1] += 2;
        }
        --edge[(n+1)&1]; ++corner[(n+1)&1];
        --edge[(m+1)&1]; ++corner[(m+1)&1];
        /*
        for (tt=0; tt<=1; ++tt) printf("%d ",cnt[tt]); puts("");
        for (tt=0; tt<=1; ++tt) printf("%d ",edge[tt]); puts("");
        for (tt=0; tt<=1; ++tt) printf("%d ",corner[tt]); puts("");
        */
        int KK = K;
        ans = ~0U>>1;
        for (tt=0; tt<=1; ++tt) {
            K = KK; t = 0;
            K -= cnt[tt];
            if (K>0) {
                t += min(K,corner[tt^1]) * 2; K -= corner[tt^1];
                if (K>0) {
                    t += min(K,edge[tt^1])*3; K -= edge[tt^1];
                    if (K>0) t += K*4;
                }
            }
            ans = min(ans,t);
        }
        printf("Case #%d: %d\n",T,ans);
    }

    return 0;
}
