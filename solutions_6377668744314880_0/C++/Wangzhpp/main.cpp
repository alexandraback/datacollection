#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

const double eps=1e-8;
const double inf=1e20;
const double pi=acos(-1.0);
const int maxp=1010;

int sgn(double x){
    if(fabs(x)<eps) return 0;
    if(x<0)         return -1;
    else            return 1;
}
inline double sqr(double x){return x*x;}

struct Point{
    double x,y;Point(){}
    Point(double _x,double _y){x=_x;y=_y;}
    bool   operator == (Point b)const{return sgn(x-b.x)==0 && sgn(y-b.y)==0;}
    bool   operator <  (Point b)const{return sgn(x-b.x)==0?sgn(y-b.y)<0:x<b.x;}
    Point  operator -  (const Point &b)const{return Point(x-b.x,y-b.y);}
    double operator ^  (const Point &b)const{return x*b.y-y*b.x;}
};
struct Line{
    Point s,e;Line(){}
    Line(Point _s,Point _e){s=_s;e=_e;}
    bool operator ==(Line v){
    return (s== v.s)&&(e==v.e);}
    int relation(Point p){
    int c=sgn((p-s)^(e-s));
    if(c<0)return 1;
    else if(c>0)return 2;
    else return 3;
    }
};

using namespace std;

int T,x,y,n,ans[233333];
Point a[23333];

int main(){
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    scanf("%d",&T);
for(int t=1;t<=T;t++){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){scanf("%d %d",&x,&y);a[i].x=x;a[i].y=y;}
    if(n==1){printf("Case #%d:\n",t);printf("%d\n",0);continue;}
    for(int i=1;i<=n;i++)ans[i]=2000000000;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(j!=i){
                Line now(a[i],a[j]);
                int o1=0,o2=0;
                for(int k=1;k<=n;k++){
                    if(now.relation(a[k])==1)o1++;
                    if(now.relation(a[k])==2)o2++;
                }
                int haha=min(o1,o2);
                    ans[i]=min(ans[i],haha);
                    ans[j]=min(ans[j],haha);
            }
        }
    }
    printf("Case #%d:\n",t);
    for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
}

    return 0;
}
