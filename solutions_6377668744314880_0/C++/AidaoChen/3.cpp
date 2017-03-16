#include <bits/stdc++.h>
using namespace std;
#define For(i,l,r) for (int i=(l),r__=(r);i<=r__;i++)
const int mN=3100;
struct point
{
    int x,y;
} op[mN],p[mN];
point operator-(point a,point b)
{
    point c;
    c.x=a.x-b.x;
    c.y=a.y-b.y;
    return c;
}
typedef long long LL;
LL cross(const point& a,const point& b)
{
    return LL(a.x)*b.y-LL(a.y)*b.x;
}
bool cmp(const point& a,const point& b)
{
    return atan2(a.y,a.x)<atan2(b.y,b.x);
}
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.in.out","w",stdout);
    int ta;
    cin>>ta;
    For(tz,1,ta)
    {
        int n;
        cin>>n;
        For(i,1,n)
            cin>>op[i].x>>op[i].y;
        printf("Case #%d:\n",tz);
        For(i,1,n)
        {
            int tot=0;
            For(j,1,n)
                if (i!=j)
                {
                    p[tot]=op[j]-op[i];
                    tot++;
                }
            sort(p,p+tot,cmp);
            int v=0;
            int mp=0;
            For(k,0,tot-1)
            {
                while (((v+1)%tot)!=k && cross(p[k],p[(v+1)%tot])>=0)
                    v=(v+1)%tot;
                mp=max(mp,(v+tot-k)%tot+1);
            }
            cout<<n-(mp+1)<<endl;
        }


    }
}


