#include<bits/stdc++.h>
#define INF 100000000000005LL
#define LL long long
using namespace std;
const int maxn=1000+10 ;

int m,a[maxn] ;
LL getnum(LL t)
{
    if(t==0) return 0 ;
    LL ret=0 ;
    for(int i=1;i<=m;i++) ret+=(t-1)/a[i]+1 ;
    return ret ;
}

main()
{
    freopen("B.in","r",stdin) ;
    freopen("B.out","w",stdout) ;
    int T,tc=0 ; scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d%d",&m,&n) ;
        for(int i=1;i<=m;i++) scanf("%d",&a[i]) ;

        LL l=-1 , r=INF ;
        while(r-l>1)
        {
            LL mid=(r+l)/2 ;
            if(getnum(mid)>=n) r=mid ;
            else l=mid ;
        }

        int val=getnum(l) ;
        for(int i=1;i<=m;i++) if(l%a[i]==0 && ++val==n)
            {printf("Case #%d: %d\n",++tc,i) ; break ;}
    }
}
