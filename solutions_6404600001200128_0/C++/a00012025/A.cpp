#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+10 ;

int a[maxn] ;
main()
{
    freopen("A.in","r",stdin) ;
    freopen("A.out","w",stdout) ;
    int T,tc=0 ; scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        int ans1=0 , ma=0 ;
        for(int i=1;i<n;i++) if(a[i+1]<a[i])
            ans1+=a[i]-a[i+1] , ma=max(ma,a[i]-a[i+1]) ;
        int v=ma , ans2=0 ;
        if(!ma) v=0 ;
        for(int i=2,now=a[1];i<=n;i++)
        {
            int now2=max(0,now-v) ;
            ans2+=now-now2 ;
            now=max(now2,a[i]) ;
        }
        printf("Case #%d: %d %d\n",++tc,ans1,ans2) ;
    }
}
