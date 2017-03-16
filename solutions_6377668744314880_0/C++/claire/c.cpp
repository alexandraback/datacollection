#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
const int N=1100;
const double eps=1e-6;
struct P
{
    double  x,y;
}a[N],res[N],p0 ,in[N];
int ans[N];

double dis(P p1, P p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

bool cmp1(const P &a,const P &b)
{
    if (abs(a.y-b.y)>eps) return a.y<b.y;
    return a.x<b.x;
}

bool cmp(const P &a,const P &b)
{
    double x=atan2(a.y-p0.y,a.x-p0.x) ;
    double y=atan2(b.y-p0.y,b.x-p0.x);
    if (abs(x-y)>eps) return x<y;
    else return dis(p0,a)<dis(p0,b);
}

double xj(P p1,P p2,P p3)
{
    return (p3.y-p2.y)*(p2.x-p1.x)-(p3.x-p2.x)*(p2.y-p1.y);
}

int graham(P a[],int n,P res[])
{
    int s=3,i;
    sort(a+1,a+n+1,cmp1);
    p0=a[1];
    sort(a+2,a+n+1,cmp);
    //for (i=1; i<=n; i++) cout<<a[i].x<<' '<<a[i].y<<endl;
    res[1]=a[1]; res[2]=a[2]; res[3]=a[3];
    for (i=4; i<=n; i++)
    {
        while (s>1 && xj(res[s-1],res[s],a[i])<eps) s--;
        res[++s]=a[i];
    }
    return s;
}

bool check(P p, P p1, P p2) {
    return abs((p.y - p1.y) * (p2.x - p1.x) - (p.x - p1.x) * (p2.y - p1.y)) < eps;
}

int main()
{
    int o, cas = 0, n, m;
    scanf("%d", &o);
    while (o--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lf%lf", &in[i].x, &in[i].y);
        for (int i = 1; i <= n; i++)
            ans[i] = n;
        for (int k = 1; k < (1<<n); k++) {
            int nn = 0;
            for (int i = 1; i <= n; i++)
                if (k & (1<<(i-1)))
                    a[++nn] = in[i];
            m=graham(a,nn,res);
            res[m+1]=res[1];
            for (int i = 1; i <= n; i++)
              for (int j = 1; j <= m; j++)
               if (check(in[i], res[j], res[j+1]))
                   ans[i] = min(ans[i], n - nn);
            //cout<<k<<' '<<m<<endl;

        }
        printf("Case #%d:\n", ++cas);
        for (int i = 1; i <= n; i++)
            printf("%d\n", ans[i]);
    }
}

