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

struct Line
{
    Point st,ed;
    Line(){}
    Line(Point st,Point ed):st(st),ed(ed){}
}ln;

bool operator <(Point u,Point v)
{
    return atan2(u.y,u.x)<atan2(v.y,v.x);
}

bool onLeft(Line u,Point v)
{
    return (u.ed-u.st)*(v-u.st)>0;
}

bool onLine(Line u,Point v)
{
    return (u.ed-u.st)*(v-u.st)==0;
}

int T,n,l,r,ans;
vector<Point> P;

int main()
{
    freopen("C-large.in","r",stdin);
    freopen("Clarge.out","w",stdout);
    scanf("%d",&T);
    For(C,1,T)
    {
        cerr<<"C = "<<C<<endl;
        scanf("%d",&n);
        Rep(i,n)
            scanf("%d%d",&p[i].x,&p[i].y);


        printf("Case #%d:\n",C);
        if (n==1)
        {
            printf("0\n");
            continue;
        }

//            P.clear();
//            Rep(i,n)
//                if (mask&(1<<i)) P.PB(p[i]);
//            find_convex(P);
//
////            if (mask==((1<<n)-1))
////            {
////                Rep(i,conv.size())
////                    cerr<<"conv "<<conv[i].x<<" "<<conv[i].y<<endl;
////            }
//
//            Rep(i,n)
//            {
//                Rep(j,conv.size()-1)
//                    if ((conv[j]-p[i])*(conv[j+1]-p[i])==0LL)
//                        ans[i]=min(ans[i],(int)(n-P.size()));
//            }




        Rep(i,n)
        {
            P.clear();
            Rep(j,n)
                if (j!=i) P.PB(p[j]-p[i]);

            sort(P.begin(),P.end());
            ln.st=Point(0,0);
            ln.ed=P[0];

//            Rep(i,P.size())
//                cerr<<"Point "<<P[i].x<<" "<<P[i].y<<endl;

            l=0;
            while (l+1<P.size()&&onLine(ln,P[l+1])) l++;
            ln.ed=P[l];

            r=l;
            while (onLeft(ln,P[(r+1)%P.size()])) r++;

            ans=(r-l+P.size())%P.size();

            while (l<P.size())
            {

                while (onLeft(ln,P[(r+1)%P.size()])) r++;
//                cerr<<"l r "<<l<<" "<<r<<endl;
                ans=min(ans,(int)((r-l+P.size())%P.size()));
                l++;
                ln.ed=P[l];
                while (l+1<P.size()&&onLine(ln,P[l+1])) l++;
                ln.ed=P[l];
                if (r<l)
                {
                    ans=0; break;
                }
            }
            printf("%d\n",ans);
        }
    }



    return 0;
}
