#include <cstdio>
#include <algorithm>

using namespace std;

struct tacka
{
    long long x,y;
    inline bool desno(void) const
    {
        return ((x>0) || (x==0 && y<0));
    }

    inline bool operator < (const tacka &cpr) const
    {
        if (desno()!=cpr.desno())
            return desno();
        return 1ll*y*cpr.x<1ll*cpr.y*x;
    }
    inline tacka operator - (const tacka &op) const
    {
        tacka ret;
        ret.x=x-op.x;
        ret.y=y-op.y;
        return ret;
    }
    inline long long operator * (const tacka &op) const
    {
        return 1ll*x*op.y-1ll*op.x*y;
    }
};

int tc;
int n;
tacka t[3005];
tacka sw[6005];

int main()
{
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    scanf("%d",&tc);
    for (int it=1; it<=tc; it++)
    {
        scanf("%d",&n);
        for (int i=1; i<=n; i++)
            scanf("%lld%lld",&t[i].x,&t[i].y);
        if (n<=3)
        {
            printf("Case #%d:\n",it);
            for (int i=1; i<=n; i++)
                printf("0\n");
            continue;
        }
        printf("Case #%d:\n",it);
        for (int c=1; c<=n; c++)
        {
            for (int i=1; i<=n; i++)
                sw[i-(i>c)]=t[i]-t[c];
            sort(sw+1,sw+n);
            for (int i=1; i<n; i++)
                sw[n+i-1]=sw[i];
            int mx=1;
            int last=1;
            for (int p=1; p<n; p++)
            {
                if (last<p)
                    last=p;
                while (last<2*n-1 && sw[p]*sw[last+1]>=0)
                    last++;
                mx=max(mx,last-p+1);
            }
            mx=min(n-1,mx);
            printf("%d\n",n-1-mx);
        }
    }

}
