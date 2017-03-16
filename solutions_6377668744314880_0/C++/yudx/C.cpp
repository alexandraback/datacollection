#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<string.h>
#include<vector>
#include<map>
#include<set>
#include<iostream>

using namespace std;

typedef long long ll;

struct point
{
    ll x,y;
    point(ll x=0,ll y=0):x(x),y(y){}
    void read(){scanf("%lld %lld",&x,&y);}
};
bool operator <(point a,point b)
{
    return atan2(a.y,a.x)<atan2(b.y,b.x);
}
point operator -(point a,point b)
{
    return point(a.x-b.x,a.y-b.y);
}
ll cross(point a,point b)
{
    return a.x*b.y-a.y*b.x;
}
ll dot(point a, point b)
{
    return a.x*b.x+a.y*b.y;
}
int n,qn;
point p[10005],q[10005];

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int T,I=1,i,j;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++) p[i].read();
        printf("Case #%d:\n",I++);
        for(i=0;i<n;i++)
        {
            qn=0;
            for(j=0;j<n;j++) if(i!=j) q[qn++]=p[j]-p[i];
            sort(q,q+qn);
            int ii=0,jj=0;
            for(jj=1;jj<qn;jj++) if(cross(q[ii],q[jj])<0||(cross(q[ii],q[jj])==0&&dot(q[ii],q[jj])<0)) break;
            if(jj>=qn) {printf("0\n");continue;}
            int r=jj-ii-1;
            for(ii=1;ii<qn&&jj<qn*2;ii++)
            {
                while(jj<qn*2)
                {
                    if(cross(q[ii],q[jj%qn])<0||(cross(q[ii],q[jj%qn])==0&&dot(q[ii],q[jj%qn])<0)) break;
                    else ++jj;
                }
                if(jj<qn*2) r=min(r,jj-ii-1);
            }
            printf("%d\n",r);
        }
    }
    return 0;
}
