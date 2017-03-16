#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=20;
const double pi=atan(1.0)*4;
struct node{
    double x,y;
    int id;
    bool operator < (const node &a) const{
        return atan2(y,x) < atan2(a.y,a.x);
    }
}p[maxn],e[maxn],res[maxn];
int dcmp(double x){
    if(fabs(x)<=1e-8) return 0;
    return x>0?1:-1;
}

int cmp(node a,node b)
{
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
int cross(node a,node b,node c)
{
    return dcmp((a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y));
}
int convex(int n)
{
    if(n<=2) return 0;
    sort(e,e+n,cmp);
    int m=0,i,j,k;
    for(i=0;i<n;i++)
    {
        while(m>1&&cross(res[m-1],e[i],res[m-2])<=0)m--;
        res[m++]=e[i];
    }
    k=m;
    for(i=n-2;i>=0;i--)
    {
        while(m>k&&cross(res[m-1],e[i],res[m-2])<=0)m--;
        res[m++]=e[i];
    }
    if(n>1)m--;
    return m;
}
double lenght(node a,node b)
{
    return sqrt(1.0*(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}


bool on( node p1,node p2 ,node p )
{
    double max=(p1.x > p2.x ? p1.x : p2.x);
    double min=(p1.x < p2.x ? p1.x : p2.x);
    double max1=(p1.y > p2.y ? p1.y : p2.y);
    double min1=(p1.y < p2.y ? p1.y : p2.y);
    if( dcmp(p.x-min)>=0 && dcmp(p.x-max)<=0 &&
        dcmp(p.y-min1)>=0 && dcmp(p.y-max1)<=0 )
        return 1;
    else
        return 0;
}

int main()
{
   freopen("C-small-attempt6.in","r",stdin);
freopen("C-small-attempt6.out","w",stdout);
    int T,n,ans[30];
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&p[i].x,&p[i].y);
            p[i].id=i;
        }
        sort(p,p+n,cmp);
        int all=(1<<n);
        for(int i=0;i<n;i++){
            int r=-1;
            for(int j=0; j<all; j++) if(j&(1<<i)){
                int num=0;
                for(int k=0; k<n;k++) if(j&(1<<k)){
                    e[num].x = p[k].x;
                    e[num].y = p[k].y;
                    num++;
                }
                int m = convex(num);
                if(m<2) continue;
               // printf("%d\n",m);
                sort(res,res+m);
                bool tag=0;
                for(int q=0;q<m;q++) if(on(res[q],res[(q+1)%m],p[i]) && cross(res[q],res[(q+1)%m],p[i])<=0){
                    tag=1;break;
                }
                if(tag){
                    num = n-num;
                    if(r==-1 || r>num){
                        r=num;
                    }
                }
            }
            ans[p[i].id]=(r==-1?n-1:r);
        }
        printf("Case #%d:\n",ca);
        for(int i=0;i<n;i++){
            printf("%d\n",ans[i]);
        }
        cerr<<ca<<endl;
    }
    return 0;
}
