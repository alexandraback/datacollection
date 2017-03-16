#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,t;
struct point
{
    long long x,y;
    int id;
};
point p[3010];
point st[6010];
int ans[3010];

bool cmp(const point&a,const point&b)
{
    return (a.y<b.y)||((a.y==b.y)&&(a.x<b.x));
}

long long cal(point&a,point&b,point&c)
{
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

void convex_hull()
{
    sort(p,p+n,cmp);
    t=1;
    st[0]=p[0];
    for(int i=1;i<n;i++)
    {
        while(t>1&&cal(st[t-2],st[t-1],p[i])<0)t--;
        st[t++]=p[i];
    }
    for(int i=n-2;i>=0;i--)
    {
        while(t>1&&cal(st[t-2],st[t-1],p[i])<0)t--;
        st[t++]=p[i];        
    }
    t--;
//    for(int i=0;i<t;i++)
    //printf("%lld %lld\n",st[i].x,st[i].y);
}

void calc()
{
    //for(int i=t;i<t+t;i++)
    //st[i]=st[i-t];
    for(int i=0;i<n;i++)ans[i]=n;
//    for(int i=0;i<t;i++)
    //      ans[st[i].id]=0;
    //for(int i=0;i<t;i++)
    for(int i=0;i<n;i++)
        for(int k=0;k<n;k++)
            if (ans[p[k].id]>0&&i!=k)
            {
                int tot=0,an=ans[p[k].id];
                //for(int j=0;(j<n)&&(tot<an);j++)
                 for(int j=0;j<n;j++)
                    if (cal(p[i],p[k],p[j])<0)
                        tot++;
                //if (p[k].id==4)
                //printf("%lld %lld %d\n",p[i].x,p[i].y,tot);
                if (ans[p[k].id]>tot){
                    ans[p[k].id]=tot;
                }
                if (ans[p[i].id]>tot){
                    ans[p[i].id]=tot;
                }
                tot=0,an=ans[p[k].id];
                //for(int j=0;(j<n)&&(tot<an);j++)
                for(int j=0;j<n;j++)
                    if (cal(p[i],p[k],p[j])>0)
                        tot++;
                if (ans[p[k].id]>tot){
                    ans[p[k].id]=tot;
                }
                if (ans[p[i].id]>tot){
                    ans[p[i].id]=tot;
                }
                                
                //printf("%d %d\n",tot1,tot);
            }
    if (n==1)ans[0]=0;
}

int main()
{
    //freopen("cs4.in","r",stdin);
    //freopen("cs.out","w",stdout);
    int tt;
    scanf("%d",&tt);
    for(int ii=1;ii<=tt;ii++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lld%lld",&p[i].x,&p[i].y);
            p[i].id=i;            
        }
        //convex_hull();
        calc();
        printf("Case #%d:\n",ii);
        ///printf("%d %d\n",n,t);
        for(int i=0;i<n;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
    
            
            
        
