#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <iostream>
#include <algorithm>
#define bit(k) (1<<(k))
using namespace std;
const int maxn=20;
const double pi=atan(1.0)*4;
struct node{
    int x,y,id;
}e[maxn],p[maxn],res[maxn];

int ans[maxn];
int cmp(node a,node b)
{
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
int cross(node a,node b,node c)
{
    return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y);
}
int convex(int n)
{
    sort(e,e+n,cmp);
    int m=0,i,j,k,ans=0;
    for(i=0;i<n;i++)
    {
        while(m>1&&cross(res[m-1],e[i],res[m-2])<0)m--;
        res[m++]=e[i];
    }
    k=m;
    for(i=n-2;i>=0;i--)
    {
        while(m>k&&cross(res[m-1],e[i],res[m-2])<0)m--;
        res[m++]=e[i];
    }
    if(n>1)m--;
    for(i=0;i<m;++i) ans|=bit(res[i].id);
    return ans;
}
double lenght(node a,node b)
{
    return sqrt(1.0*(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int T,n,cal=0;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case #%d:\n", ++cal);
        int i,j,k,m;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            ans[i]=1e9, scanf("%d%d",&p[i].x,&p[i].y), p[i].id=i;
        
        for(i=0;i<bit(n);++i){
          int cc=0;
          for(j=0;j<n;++j) if((i>>j)&1) e[cc++]=p[j];
          int res=convex(cc);
          for(j=0;j<n;++j) if( ((i>>j)&1) && ((res>>j)&1) ){
            ans[j] = min(ans[j], n-cc);
          }
        }
        for(i=0;i<n;++i) printf("%d\n",ans[i]);
    }
    return 0;
}
