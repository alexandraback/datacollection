#include<bits/stdc++.h>
#define DB double
#define LL long long
using namespace std;
const int maxn=3000+10 ;

struct pt
{
    int x,y; DB ang ;
    void get()
    {
        ang=atan2(y,x) ;
    }
    bool operator < (const pt &rhs) const
    {
        return ang<rhs.ang ;
    }
};
pt operator + (const pt &a,const pt &b) { return (pt){a.x+b.x,a.y+b.y} ; }
pt operator - (const pt &a,const pt &b) { return (pt){a.x-b.x,a.y-b.y} ; }
LL dot(const pt &a,const pt &b) { return (LL)a.x*b.x + (LL)a.y*b.y ; }
LL cross(const pt &a,const pt &b){ return (LL)a.x*b.y - (LL)a.y*b.x ; }

pt a[maxn],b[maxn] ;
int n ;
int solve(int id)
{
    if(n==1) return 0 ;
    for(int i=1,cnt=0;i<=n;i++) if(i!=id)
    {
        b[cnt]=a[i]-a[id] ;
        b[cnt].get() ;
        cnt++ ;
    }
    sort(b,b+n-1) ;
    int ans=n+1 ;
    for(int i=0,j=0;i<n-1;i++)
    {
        while(1)
        {
            int j2=(j+1)%(n-1) ;
            if(j2!=i && cross(b[i],b[j2])>=0) j=j2 ;
            else break ;
        }
        if(j>=i) ans=min(ans,n-1-(j-i+1)) ;
        else ans=min(ans,n-1-(n-1+j-i+1)) ;
        if(i==j) j++ ;
    }
    return ans ;
}

main()
{
    freopen("C.in","r",stdin) ;
    freopen("C.out","w",stdout) ;
    int T,tc=0 ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y) ;
        printf("Case #%d:\n",++tc) ;
        for(int i=1;i<=n;i++) printf("%d\n",solve(i)) ;
    }
}
