#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <memory>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <assert.h>
using namespace std;
typedef long long LL;
LL MAX (LL a, LL b){ return (a) > (b) ? (a) : (b); }
LL MIN (LL a, LL b){ return a < b ? a : b; }
struct Lpoint {double x,y;};
bool mult(Lpoint sp, Lpoint ep, Lpoint op){
    return (sp.x - op.x) * (ep.y - op.y) >= (ep.x - op.x) * (sp.y - op.y);
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
struct Lline{Lpoint p; Ldir dir;}; 
struct Lrad{Lpoint Sp; Ldir dir;}; 
struct Lround{Lpoint co; double r;};
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
double mx(double t1,double t2){
        if(t1>t2) return t1;
        return t2;
}
double mn(double t1,double t2){
    return min(t1, t2);
}
int lsinterls(Llineseg u,Llineseg v){
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

int N;

int main(){
//	freopen ("F:\\C++\\C-small-attempt0.in","r",stdin);
//	freopen ("F:\\C++\\C-small-attempt0.out","w",stdout);
    int T;	scanf("%d",&T);
	double x[16], y[16];
	Lpoint stack[16], tmp[16], src;
	
    for(int cas=1;cas<=T;cas++) {
		scanf ("%d", &N);
        for(int i=0;i<N;i++) {
            scanf("%lf%lf", &x[i], &y[i]);
        }
		printf ("Case #%d:\n", cas);
		
		for (int i=0; i<N; i++){
			int ans = N + 1;
			for (int j=0;j<(1 << N);j++){
				int top = 0;
				for (int k=0;k<N;k++){
					if (j >> k & 1){
						stack[top].x = x[k]; 
						stack[top++].y = y[k]; 
					}
				}
				int ret = graham (stack, top, tmp);
				bool ok = false;
				for (int k=0;k<ret;k++){
					if (x[i] == tmp[k].x && y[i] == tmp[k].y){
						ok = true; break;
					}
				}
                src.x = x[i]; src.y = y[i];
                for(int k=0; k<ret; k++) {
                    Llineseg line;
                    if(k == 0) {
                        line.a = tmp[ret-1];
                        line.b = tmp[0];
                    }
                    else {
                        line.a = tmp[k-1];
                        line.b = tmp[k];
                    }
                    int res = ponls(line, src);
                    if(res) {
                        ok = true;
                        break;
                    }
                }
                if(ok) {
                    ans = min(ans, N - top);
                }
			}
			printf ("%d\n", ans);
		}
    }
    return 0;
}
