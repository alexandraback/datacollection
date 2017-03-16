#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=1010;
const double pi=atan(1.0)*4;
struct node{
    LL x,y;
}e[maxn],res[maxn],pp[maxn];
int cmp(node a,node b)
{
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
LL cross(node a,node b,node c)//向量积
{
    return (LL)(a.x-c.x)*(b.y-c.y)-(LL)(b.x-c.x)*(a.y-c.y);
}
int convex(int n)//求凸包上的点
{
    sort(e,e+n,cmp);
    int m=0,i,k;
    //求得下凸包，逆时针
    //已知凸包点m个，如果新加入点为i，则向量(m-2,i)必定要在(m-2,m-1)的逆时针方向才符合凸包的性质
    //若不成立，则m-1点不在凸包上。
    for(i=0;i<n;i++)
    {
        while(m>1&&cross(res[m-1],e[i],res[m-2])<0)m--;
        res[m++]=e[i];
    }
    k=m;
    //求得上凸包
    for(i=n-2;i>=0;i--)
    {
        while(m>k&&cross(res[m-1],e[i],res[m-2])<0)m--;
        res[m++]=e[i];
    }
    if(n>1)m--;//起始点重复。
    return m;
}
int main()
{
    int i,j,t,m,NN=0,n;
    cin>>t;
    while(t--){
        cin>>m;
        for(i=0;i<m;i++){
            scanf("%d%d",&e[i].x,&e[i].y);
        }
        printf("Case #%d:\n",++NN);
        for(i=0;i<m;i++){
            /*
            int p=1<<m;
            int x=100000;
            for(j=0;j<p;j++){
                if(j&(1<<i)){
                    n=0;
                    int w=0;
                    for(int f=0;f<m;f++){
                        if(j&(1<<f)){
                            e[n++]=pp[f];
                            w++;
                        }
                    }
                    int q;
                    q=convex(n);
                    int k=0;
                    for(int f=0;f<q;f++){
                        if(res[f].x==pp[i].x&&res[f].y==pp[i].y){
                            k=1;
                            break;
                        }
                    }
                    if(k){
                        x=min(x,m-w);
                    }
                }
            }
            printf("%d\n",x);*/
            int s=1000000;
            for(int j=0;j<m;j++){
                if(i!=j){
                    int x=0,y=0;
                    for(int f=0;f<m;f++){
                        if(cross(e[i],e[j],e[f])<0) x++;
                        else if(cross(e[i],e[j],e[f])>0) y++;
                    }
                    s=min(s,min(x,y));
                }
            }
            if(s>100000) s=0;
            printf("%d\n",s);
        }
    }
}