#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <set>
#define maxn 5010
using namespace std;
#define eps 1e-8
struct point{
    double x,y;
    int id;
    point(){}
    point(double _x,double _y): x(_x),y(_y){};
    void out()
    {
        printf("%.2f %.2f\n",x,y);
    }
    bool operator ==(point a) const
    {
        return x==a.x&&y==a.y;
    }
    point  operator +(point a) const
    {
        return point(x+a.x,y+a.y);
    }
    point operator -(point a) const
    {
        return point(x-a.x,y-a.y);
    }
    point operator *(double v) const
    {
        return point(x*v,y*v);
    }
    point operator /(double v) const
    {
        return point(x/v,y/v);
    }
    double operator *(point a) const
    {
        return x*a.y-y*a.x;
    }
    bool operator <(point a) const
    {
        return y<a.y|| fabs(a.y-y)<eps &&x<a.x;
    }
}p[maxn];
int A[maxn];
vector<point> a,b;
int graham()
{
    int ans=0;
    if(a.size()<=3)
    {
        for(int i=0;i<a.size();i++)
            A[a[i].id]=1;
        return 0;
    }
    sort(a.begin(),a.end());
    b.clear();
    b.push_back(a[0]);
    b.push_back(a[1]);
    int top=1;
    for(int i=2;i<a.size();i++)
    {
        while(top&&(a[i]-b[top-1])*(b[top]-b[top-1])>eps) top--,b.pop_back();
        b.push_back(a[i]);
        top++;
    }
    int len=top;
    for(int i=a.size()-2;i>=0;i--)
    {
        while(top!=len&&(a[i]-b[top-1])*(b[top]-b[top-1])>eps)top--,b.pop_back();
        b.push_back(a[i]);
        top++;
    }
    for(int i=0;i<=top;i++)
    A[b[i].id]=1;
    return 0;
}
int ans[maxn];
void solve(int flag,int n){
    int num=0;
    memset(A,0,sizeof(A));
    a.clear();
    b.clear();
    for(int i=0;i<n;i++){
        if((flag>>i)&1){
            num++;
            a.push_back(p[i]);
        }
    }
    //printf("%d %d\n",n,num);
    graham();
    for(int i=0;i<n;i++){
        if(A[i]){
            ans[i]=min(ans[i],n-num);
        }
    }

}
int main(){
    freopen("dd.in","r",stdin);
    freopen("out.txt","w+",stdout);
    int ncase,T=0;
    scanf("%d",&ncase);
    while(ncase--){
        printf("Case #%d:\n",++T);
        int n;
        scanf("%d",&n);
        //printf("%d\n",n);
        int limit=1<<n;
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&p[i].x,&p[i].y);
            p[i].id=i;
            ans[i]=n;
        }
        for(int i=1;i<limit;i++){
            solve(i,n);
        }
        for(int i=0;i<n;i++)
        printf("%d\n",ans[i]);
    }
    return 0;
}
