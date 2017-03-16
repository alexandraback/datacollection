#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Po
{
    long long x,y;
    Po(long long a=0, long long b=0){x=a;y=b;}
    Po operator - (const Po &a) const
    {
        return Po(x - a.x, y - a.y);
    }
};

long long xm(Po a,Po b,Po c)
{
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}


bool posy(Po &a)
{
    if(a.y>0||(a.y==0&&a.x>0))
        return 1;
    return 0;
}

bool cmp(Po a,Po b)
{
    if(posy(a)!=posy(b))
        return posy(a)>posy(b);
    return xm(Po(0,0),a,b)>0;
}

int main()
{
    freopen("t.in","r",stdin);
    freopen("t.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cc=0;cc<t;cc++)
    {
        int n;
        scanf("%d",&n);
        Po p[3001];
        int ans[3001]={0};
        for(int i=0;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            p[i]=Po(x,y);
        }
        printf("Case #%d:\n",cc+1);
        for(int i=0;i<n;i++)
        {

            vector<Po> tp;
            for(int j=0;j<n;j++)
                if(p[i].x!=p[j].x||p[i].y!=p[j].y)
                    tp.push_back(p[j] - p[i]);
            ans[i]=tp.size();
            if(tp.size()<3)
            {
                ans[i]=0;

                continue;
            }
            sort(tp.begin(),tp.end(),cmp);

            int head=0;
            int ed=1;
            for(;ed<tp.size();ed++)
                if(xm(Po(0,0),tp[0],tp[ed])<0)
                    break;

            for(;head<tp.size();head++)
            {
                while(ed%tp.size()!=head)
                {
                    ed = ed%tp.size();
                    if(xm(Po(0,0),tp[head],tp[ed])<0)
                        break;
                    ed++;
                }
                int inside=ed-head;
                if(inside<=0) inside+=tp.size();
                ans[i]=min(ans[i],(int)tp.size()-inside);
            }


        }
        for(int i=0;i<n;i++)
        {
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
