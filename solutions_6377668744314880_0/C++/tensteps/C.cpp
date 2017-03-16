#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
#define Rep(i,n) for (int i=0;i<(n);i++)
#define For(i,l,r) for (int i=(l);i<=(r);i++)
#define PB push_back
#define MP make_pair
struct Point
{
    int x,y;
    Point(){}
    Point(int x,int y):x(x),y(y){}
    Point operator -(Point u)
    {
        return Point(x-u.x,y-u.y);
    }
    long long operator *(Point u)
    {
        return 1LL*x*u.y-1LL*y*u.x;
    }
} p[3005];

vector<Point> P,conv;
int T,n;
int ans[3005];


bool operator <(Point u,Point v)
{
    if (u.y==v.y) return u.x<v.x;
    return u.y<v.y;
}

void find_convex(vector<Point> &P)
{
    sort(P.begin(),P.end());
    int n=P.size();
    conv.clear();
    Rep(i,n)
    {
        while (conv.size()>1&&(conv[conv.size()-1]-conv[conv.size()-2])*(P[i]-conv[conv.size()-1])<=0)
            conv.pop_back();
        conv.push_back(P[i]);
    }
    for (int i=n-2,tp=conv.size();i>=0;i--)
    {
        while (conv.size()>tp&&(conv[conv.size()-1]-conv[conv.size()-2])*(P[i]-conv[conv.size()-1])<=0)
            conv.pop_back();
        conv.push_back(P[i]);
    }
}

int main()
{
    freopen("C-small-attempt2.in","r",stdin);
    freopen("C1.out","w",stdout);
    scanf("%d",&T);
    For(C,1,T)
    {
//        cerr<<"T = "<<C<<endl;
        scanf("%d",&n);
        Rep(i,n)
            scanf("%d%d",&p[i].x,&p[i].y);
        Rep(i,n)
            ans[i]=n;

        For(mask,1,(1<<n)-1)
        {
            P.clear();
            Rep(i,n)
                if (mask&(1<<i)) P.PB(p[i]);
            find_convex(P);

//            if (mask==((1<<n)-1))
//            {
//                Rep(i,conv.size())
//                    cerr<<"conv "<<conv[i].x<<" "<<conv[i].y<<endl;
//            }

            Rep(i,n)
            {
                Rep(j,conv.size()-1)
                    if ((conv[j]-p[i])*(conv[j+1]-p[i])==0LL)
                        ans[i]=min(ans[i],(int)(n-P.size()));
            }
        }
        if (n==1) ans[0]=0;
        printf("Case #%d:\n",C);
        Rep(i,n) printf("%d\n",ans[i]);
    }


    return 0;
}
