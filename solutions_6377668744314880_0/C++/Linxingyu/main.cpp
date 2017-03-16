#include <cstdio>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
int test,n;
int d[3333],x[3333],y[3333],ans[3333],s[3333],on[3333];

double eps=1e-7;

struct point
{
    long long x,y,id;
} p[1011];

double dis(point a, point b) {return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}

bool cmp(point a, point b)
{
    if (fabs(atan2(a.y,a.x)-atan2(b.y,b.x))<eps) return dis(a,p[0])<dis(b,p[0]);
    else return (atan2(a.y,a.x)<atan2(b.y,b.x));
}

long long XJ(point a, point b, point c)
{
    return (b.x-a.x)*(c.y-b.y)-(c.x-b.x)*(b.y-a.y);
}

void check()
{
    int sum=0;
    for (int i=0; i<n; ++i)
        if (d[i]==1)
        {
            p[sum].x=x[i];
            p[sum].y=y[i];
            p[sum].id=i;
            ++sum;
        }
    if (sum==0) return;
    point tmp;
    for (int i=1; i<sum; ++i)
    {
        if (p[i].x<p[0].x || (p[i].x==p[0].x && p[i].y<p[0].y))
        {
            tmp=p[i];
            p[i]=p[0];
            p[0]=tmp;
        }
    }
    for (int i=sum-1; i>=0; --i)  { p[i].x-=p[0].x; p[i].y-=p[0].y;}
    sort(p+1,p+sum,cmp);
    
    if (sum>=3)
    {
        int now=sum-1, ot= sum-1;
        while (now>1 && XJ(p[0],p[sum-1],p[now-1]) == 0) --now;
        while (now<ot)
        {
            tmp=p[now];
            p[now]=p[ot];
            p[ot]=tmp;
            ++now; --ot;
        }
    }
    int tot=0;
    s[tot++]=0;
    for (int i=1; i<sum; ++i)
    {
        while (tot>=2 && XJ(p[s[tot-2]],p[s[tot-1]],p[i])<0) --tot;
        s[tot++]=i;
    }
    memset(on,0,sizeof on);
    for (int i=0; i<tot; ++i) on[p[s[i]].id]=1;
    for (int i=0; i<n; ++i)
        if (on[i] && n-sum<ans[i]) ans[i]=n-sum;
}

void dfs(int x)
{
    if (x==n) {check(); return;}
    d[x]=1;
    dfs(x+1);
    d[x]=0;
    dfs(x+1);
}

int main()
{
    freopen("/Users/Dora/Desktop/ex/ex/x.in","r",stdin);
    freopen("/Users/Dora/Desktop/ex/ex/x.out","w",stdout);
    scanf("%d",&test);
    //printf("HelloWorld");
    for (int testnum=1; testnum<=test; ++testnum)
    {
        scanf("%d",&n);
        for (int i=0; i<n; ++i) scanf("%d %d",x+i,y+i);
        for (int i=0; i<n; ++i) ans[i]=n-1;
        dfs(0);
        printf("Case #%d:\n",testnum);
        for (int i=0; i<n; ++i) printf("%d\n",ans[i]);
    }
}