#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<queue>
#include<map>
using namespace std;
#define PII pair<int,int>
#define X first
#define Y second
#define PB push_back
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FOE(i,a,b) for (int i=(a);i<=(b);i++)
#define INF (1 << 30)
#define EPS (1e-9)
#define REP(i,n) FOR(i,0,n)
#define LL long long
const double PI = acos(-1.0);
#define flt(x,y) ((x)<(y)-EPS)
#define fgt(x,y) flt(y,x)
#define fle(x,y) !fgt(x,y)
#define fge(x,y) !flt(x,y)
#define feq(x,y) (fabs((x)-(y))<EPS)
#define N 4000
struct P{
	double x, y;
	P(){ }
	P(double x,double y):x(x),y(y){ }
	void eat(){ scanf("%lf%lf",&x,&y); }
	P operator+(const P &p)const{ return P(x+p.x, y+p.y); }
	P operator-(const P &p)const{ return P(x-p.x, y-p.y); }
	P operator*(double k){ return P(x*k, y*k); }
	/* 3D dot and cross
	 *         double operator * (P p){ x * p.x + y * p.y + z * p.z; }
	 *                 P operator ^ (P p) { return P(y * p.z - z * p.y, - (x * p.z - z * p.x),                                 x * p.y - y * p.x); }
	 *                         */
	double operator*(P p){ return x*p.x + y*p.y; }
	double operator^(P p){ return x*p.y - y*p.x; }
	double mag2() { return x*x+y*y; }
	double mag(){ return sqrt(mag2()); }
	bool operator<(const P &p)const {// usage example: convex hull
		if (feq(x,p.x)) return flt(y,p.y);
		return flt(x,p.x);
	}
	bool operator==(const P &p)const { return feq(x,p.x) && feq(y,p.y);    }
	P rot(){ return P(-y,x); }
	P rot(double the) { return P(x*cos(the)-y*sin(the), x*sin(the)+y*cos(the                                )); }
	P nor(){
		if (feq(mag(),0)) return *this;
		return *this*(1./mag());
	}
	P ref(P n) { // Reflect about vector "n"
		n = n.nor();
		return n*(n*(*this))*2 - *this;
	}
	void prt() { printf("(%f,%f)\n", x, y); }
}p[N], q[N], hl[N];
int n, m, qsz, a[N], sz;
int cnt(int x){
	int ret = 0;
	while(x){
		x -= x & -x;
		ret++;
	}
	return ret;
}

bool ccw(P a, P b, P c) { return fgt((b-a)^(c-a), 0); }


void hull(){
	int n = qsz;
	P *p = q;
	sz = 0; sort(q, q + n);//sort in PII
	for (int i = 0; i < n; i++){
		while (sz > 1 && !ccw(hl[sz - 2], hl[sz - 1], p[i])) sz--;
		hl[sz++] = p[i];
	} int k = sz;
	for (int i = n - 2; i >= 0; i--){//n-1 ??
		while (sz > k && !ccw(hl[sz - 2], hl[sz - 1], p[i])) sz--;
		hl[sz++] = p[i];
	}
	if (sz == 1) hl[sz] = hl[0];
	if (sz > 1) --sz;
}

bool Btw(P a,P b,P c) { return feq((a-c).mag(), (b-a).mag()+(c-b).mag()); }

int bound(P p){
	FOR(i,0,sz) if (hl[i] == p) return 1;
	FOR(i,0,sz) if (Btw(hl[i], p, hl[(i + 1) % sz])) return 1;
	return 0;
}

int main(){
	int T;
	scanf("%d", &T);
	FOE(cc,1,T){
		printf("Case #%d:\n", cc);
		scanf("%d", &n);
		FOR(i,0,n) p[i].eat();
		FOR(i,0,n) a[i] = n;
		FOR(i,0,(1<<n)){
			qsz = 0;
			FOR(j,0,n) if ((1 << j) & i) q[qsz++] = p[j];
			hull();
			FOR(j,0,n) if (bound(p[j])) a[j] = min(a[j], n - cnt(i));
		}
		FOR(i,0,n) printf("%d\n", a[i]);
	}
	return 0;
}

