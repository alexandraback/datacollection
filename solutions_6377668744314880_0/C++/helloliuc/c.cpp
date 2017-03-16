#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;
struct Lpoint {double x,y;};

bool mult(Lpoint sp, Lpoint ep, Lpoint op){
    return (sp.x - op.x) * (ep.y - op.y)
        >= (ep.x - op.x) * (sp.y - op.y);
}
bool operator < (const Lpoint &l, const Lpoint &r){
    return l.y < r.y || (l.y == r.y && l.x < r.x);
}
int graham(Lpoint pnt[], int n, Lpoint res[]){
    int i, len, k = 0, top = 1;
    sort(pnt, pnt + n);
    if (n == 0) return 0; res[0] = pnt[0];
    if (n == 1) return 1; res[1] = pnt[1];
    if (n == 2) return 2; res[2] = pnt[2];
    for (i = 2; i < n; i++) {
        while (top && mult(pnt[i], res[top], res[top-1])) top--;
        res[++top] = pnt[i];
    }
    len = top; res[++top] = pnt[n - 2];
    for (i = n - 3; i >= 0; i--) {
        while (top!=len && mult(pnt[i], res[top], res[top-1])) top--;
        res[++top] = pnt[i];
    }
    return top;
}

#define infinity 1e20
#define EP 1e-10
const int MAXV = 300 ;
const double PI = 2.0*asin(1.0);
struct Llineseg{ Lpoint a,b;};
struct Ldir{double dx,dy;};
struct Lline{Lpoint p; Ldir dir;}; //直线
struct Lrad{Lpoint Sp; Ldir dir;}; //射线
struct Lround{Lpoint co; double r;};//圆

double p2pdis(Lpoint p1,Lpoint p2) {
    return (sqrt((p1.x-p2.x) * (p1.x-p2.x) +
                (p1.y-p2.y) * (p1.y-p2.y)));
}


double xmulti(Lpoint p1,Lpoint p2,Lpoint p0) {
    return((p1.x-p0.x) * (p2.y-p0.y) -
            (p2.x-p0.x) * (p1.y-p0.y));
}
int ponls(Llineseg l,Lpoint p) {
    return( (xmulti(l.b,p,l.a)==0) &&
            ( ((p.x-l.a.x)*(p.x-l.b.x)<0 ) ||((p.y-l.a.y)*(p.y-l.b.y)<0 )) );
}

double mx(double t1,double t2)
{
        if(t1>t2) return t1;
        return t2;
}

double mn(double t1,double t2)
{
    return min(t1, t2);
}

int lsinterls(Llineseg u,Llineseg v)
{
    return( (mx(u.a.x,u.b.x)>=mn(v.a.x,v.b.x))&&
            (mx(v.a.x,v.b.x)>=mn(u.a.x,u.b.x))&&
            (mx(u.a.y,u.b.y)>=mn(v.a.y,v.b.y))&&
            (mx(v.a.y,v.b.y)>=mn(u.a.y,u.b.y))&&
            (xmulti(v.a,u.b,u.a)*xmulti(u.b,v.b,u.a)>=0)&&
            (xmulti(u.a,v.b,v.a)*xmulti(v.b,u.b,v.a)>=0));
}

int Euqal_Point(Lpoint p1,Lpoint p2) {
        return((fabs(p1.x-p2.x)<EP)&&(fabs(p1.y-p2.y)<EP));
}

int lsinterls_A(Llineseg u,Llineseg v) {
        return((lsinterls(u,v)) && (!Euqal_Point(u.a,v.a))&&
                         (!Euqal_Point(u.a,v.b)) &&
                         (!Euqal_Point(u.b,v.a))&&(!Euqal_Point(u.b,v.b)));

}

/*
int pinplg(int vcount,Lpoint Polygon[],Lpoint q)
{
    int c=0,i,n;
    Llineseg l1,l2;
    l1.a=q; l1.b=q; l1.b.x=infinity; n=vcount;
    for (i=0;i<vcount;i++) {
        l2.a=Polygon[i];
        l2.b=Polygon[(i+1)%n];
        if ((lsinterls_A(l1,l2))||
            (
            (ponls(l1,Polygon[(i+1)%n])) &&
            (
            (!ponls(l1,Polygon[(i+2)%n])) &&
            (xmulti(Polygon[i],Polygon[(i+1)%n],l1.a) * xmulti(Polygon[(i+1)%n],Polygon[(i+2)%n],l1.a)>0)
              ||
                  (ponls(l1,Polygon[(i+2)%n]))&& (xmulti(Polygon[i],Polygon[(i+2)%n],l1.a) * xmulti(Polygon[(i+2)%n],Polygon[(i+3)%n],l1.a)>0)
                  )))
            c++;
    }
    return (c%2!=0);
}
*/

int main()
{
    double x[16], y[16];
    Lpoint arg[16];
    Lpoint res[16];
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++) {
        printf("Case #%d:\n", cas);
        int n;
        scanf("%d", &n);
        for(int i=0;i<n;i++) {
            scanf("%lf%lf", &x[i], &y[i]);
        }
        for(int i=0;i<n;i++) {
            int ans = n+1;
            int resj = -1;
            for(int j=0;j<(1<<n); j++) {
                int tail = 0;
                for(int k=0; k<n;k++) {
                    if(j & (1<<k)) {
                        arg[tail].x = x[k];
                        arg[tail].y = y[k];
                        tail++;
                    }
                }
                int ret = graham(arg, tail, res);
                /*
                if(j == 0x1ff) {
                printf("j:%d ret:%d\n",j,  ret);
                for(int p = 0; p<ret; p++) {
                    printf("%lf %lf\n", res[p].x, res[p].y);
                }
                getchar();
                }
                */
                /*
                Lpoint src;
                src.x = x[i]; src.y = y[i];
                //int pinplg(int vcount,Lpoint Polygon[],Lpoint q);
                Lpoint polygon[16];
                for(int i=0; i<ret;i++) {
                    polygon[i].x = res[i].x;
                    polygon[i].y = res[i].y;
                }
                int ok = pinplg(ret, polygon, src);
                */
                bool ok = false;
                for(int k=0; k<ret; k++) {
                    if(x[i] == res[k].x && y[i] == res[k].y) {
                        ok = true;
                        break;
                    }
                }

                Lpoint src;
                src.x = x[i]; src.y = y[i];
                for(int i=0; i<ret; i++) {
                    Llineseg line;
                    if(i == 0) {
                        line.a = res[ret-1];
                        line.b = res[0];
                    }
                    else {
                        line.a = res[i-1];
                        line.b = res[i];
                    }
                    int tmp_ret = ponls(line, src);
                    if(tmp_ret) {
                        ok = true;
                        break;
                    }
                }
                if(ok) {
                    ans = min(ans, n - tail);
                    resj = j;
                }
            }
            printf("%d\n", ans);
            //printf("resj:0x%x\n", resj);
        }
    }

    return 0;
}
