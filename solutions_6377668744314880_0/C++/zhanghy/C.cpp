#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define N 1005

struct Point
{
    int x,y,id;
}P[N],S[N],OR[N];

int T,Ni,n,top;
int ans[N];

double Dis(const Point& p1,const Point& p2)
{
    return sqrt( (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y)*1.0 );
}

double Cross(const Point& p1,const Point& p2,const Point& p3,const Point& p4)
{
    return (p2.x-p1.x)*(p4.y-p3.y) - (p2.y-p1.y)*(p4.x-p3.x);
}

bool cmp(const Point& p1,const Point& p2)
{
    double C = Cross(P[0],p1,P[0],p2);
    return C ? C>0 : Dis(P[0],p1)<Dis(P[0],p2);
}

void Pole_Point()
{
    int id;
    Point pp = P[id=0];
    for(int i=1;i<n;i++)
        if(P[i].y < pp.y || P[i].y == pp.y && P[i].x < pp.x)
            pp = P[i] , id = i;
    P[id] = P[0] , P[0] = pp;
}

void Convex_Hull()
{
    Pole_Point();
    sort(P+1,P+n,cmp);
    S[0]=P[0],S[top=1]=P[1];
    for(int i=2;i<n;i++)
    {
        while(top && Cross(S[top-1],S[top],S[top],P[i]) <= 0)
            --top;
        S[++top] = P[i];
    }
}

int main()
{
    freopen("/Users/zhanghanyuan/Documents/codejam/round1A/1.in","r",stdin);
    freopen("/Users/zhanghanyuan/Documents/codejam/round1A/1.out","w",stdout);
    scanf("%d",&T);
    for (int kase = 1;kase <= T; kase++) {
            scanf("%d",&Ni);
            for (int i = 0;i < Ni; i++) {
                scanf("%d%d",&OR[i].x,&OR[i].y);
	    	ans[i] = 0;
	    }
            for (int k = 1;k < (1<<Ni); k++) {
                n = 0;
                for(int i=0;i<Ni;i++) {
                    if ((1<<i)&k) {
                        P[n].x = OR[i].x; P[n].y = OR[i].y;
                    	P[n].id = i;
                        n++;
                    }
                }
                Convex_Hull();
                //cout<<"k: "<<k<<endl;
                S[top+1] = S[0];
                for (int i = 0;i < Ni; i++) {
                    int x = OR[i].x,y = OR[i].y;
                    bool flag = false;
                    if ((1<<i)&k)
                    for(int j=0;j<=top;j++) {
                        Point a = S[j],b = S[j+1];
                        if((x-a.x)*(b.y-a.y)-(y-a.y)*(b.x-a.x)==0) {flag = true; break;}
                    }
                    if (flag) ans[i] = max(ans[i],n);
                }
            }
           printf("Case #%d:\n",kase);
	       for (int i = 0;i < Ni; i++) printf("%d\n",Ni-ans[i]);
    }
	return 0;
}
