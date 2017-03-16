#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-10
using namespace std;
int n;
int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    else return x>0?1:-1;
}
struct point
{
    double x,y,ang;
    point(double x=0,double y=0):x(x),y(y) { ang=atan2(y,x);}
    point operator -(point a)
    {
        return point(x-a.x,y-a.y);
    }
    bool operator < (const point& a) const
    {
        return ang<a.ang;
    }
};
double cross(point a,point b)
{
    return a.x*b.y-a.y*b.x;
}
point p[3006],f[3006];
int tot;
main()
{
    freopen("C-small-attempt2.in","r",stdin);
    freopen("C-small-attempt2.out","w",stdout);
    int T,cas=0;scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);

        for(int i=0;i<n;i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);
        printf("Case #%d:\n",++cas);
        for(int i=0;i<n;i++)
        {
            tot=0;
            int ans=10000000;
            for (int j=0;j<n;j++) if(i!=j)
            f[tot++]=point(p[j]-p[i]);
            sort(f,f+tot);
            if(tot==0) {printf("0\n");continue;}
            if(tot==1) {printf("0\n");continue;}
            if(tot==2) {printf("0\n");continue;}
            //for(int j=0;j<tot;j++)
            //cout<<f[j].x<<" "<<f[j].y<<"=="<<f[j].ang<<endl;
            int u=0,v,all=1;
            for(v=1;dcmp(cross(f[u],f[v]))>=0&&u!=v;v=(v+1)%tot)
            all++;
            //cout<<v<<"==="<<all<<endl;
            ans=min(ans,tot-all);
            all--;
            for(u++;u!=0;u=(u+1)%tot,all--)
            {
                if(u==v) all++,v=(v+1)%tot;
                for(;dcmp(cross(f[u],f[v]))>=0&&u!=v;v=(v+1)%tot)
                all++;
                //cout<<u<<"*"<<v<<"++"<<all<<endl;
                ans=min(ans,tot-all);
            }
            printf("%d\n",ans);
        }
    }
}
