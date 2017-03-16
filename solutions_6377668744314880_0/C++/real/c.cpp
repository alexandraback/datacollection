#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
const double EPS = 1e-9, INF = 1e15, PI = acos(-1.0);
#define FOR(i,s,e) for(int i=s;i<e;i++)
#define FOE(i,s,e) for(int i=(s);i<=(int)(e);i++)
#define flt(x,y) ((x)<(y)-EPS)
#define fgt(x,y) flt(y,x)
#define fle(x,y) !fgt(x,y)
#define fge(x,y) !flt(x,y)
#define feq(x,y) (fabs((x)-(y))<EPS)

#define chkMn(x,y) x=min(x,y)
#define chkMx(x,y) x=max(x,y)

double sq(double x) { return x*x; }

struct P{
	double x, y;
	P(){ }
	P(double x,double y):x(x),y(y){ }
	void eat(){ scanf("%lf%lf",&x,&y); }
	P operator+(const P &p)const{ return P(x+p.x, y+p.y); }
	P operator-(const P &p)const{ return P(x-p.x, y-p.y); }
	P operator*(double k){ return P(x*k, y*k); }
	double operator*(P p){ return x*p.x + y*p.y; }
	double operator^(P p){ return x*p.y - y*p.x; }
	double mag2() { return x*x+y*y; }
	double mag(){ return sqrt(mag2()); }
	bool operator<(const P &p)const {
		if (feq(x,p.x)) return flt(y,p.y);
		return flt(x,p.x);
	}
	bool operator==(const P &p)const {
		return feq(x,p.x) && feq(y,p.y);
	}
	P rot(){ return P(-y,x); }
	P rot(double the) {
		return P(x*cos(the)-y*sin(the), x*sin(the)+y*cos(the));
	}
	P nor(){
		if (feq(mag(),0))	return *this;
		return *this*(1./mag());
	}
	P ref(P n) { // 2010-08-21: Reflect about vector "n"
		n = n.nor();
		return n*(n*(*this))*2 - *this;
	}
	void out() { printf("(%f,%f)\n", x, y); }
};


// ComputeIntersection
bool ssi(P a, P b, P c, P d, P &res) {
	P cd = d-c, ab = b-a;
	if (feq(cd^ab, 0))      return 0;
	double t = ((a^ab) - (c^ab)) / (cd^ab);
	double s = ((c^cd) - (a^cd)) / (ab^cd);
	if (flt(t,0) || fgt(t,1))	return 0;
	if (flt(s,0) || fgt(s,1))	return 0;
	res = c + cd*t;
	return 1;
}

// Strictly ccw
bool Ccw(P a, P b, P c) { return fgt((b-a)^(c-a), 0); }

// Lie on segment
bool Btw(P a,P b,P c) { return feq((a-c).mag(), (b-a).mag()+(c-b).mag()); }

// Input : Point - q ; Polygon - p[n]
// Return: TRUE   if  q On Edge / Inside p[n]
bool Up(const P &p) { return fle(0,p.y); }
bool inPoly(P q, P* p, int n) {
	for (int i=0; i<n; i++)
		if (Btw(p[i],q,p[(i+1)%n]))	return 1;
	int sum = 0;
	for (int i=0; i<n; i++)
		if (Up(p[i]-q)^Up(p[(i+1)%n]-q))
			sum += Ccw(q, p[i], p[(i+1)%n]) ? 1 : -1;
	return sum;
}

// distance between point/edge
double ep(P a, P b, P c) {
	double dot1 = (c-a)*(b-a);
	double dot2 = (c-b)*(a-b);
	if (dot1 < 0) return (c-a).mag();
	if (dot2 < 0) return (c-b).mag();
	return fabs((c-a)^(b-a).nor());
}

double ee2(P a, P b, P c, P d) {
	return min(ep(a,b,c), ep(a,b,d));
}

double ee(P a, P b, P c, P d) {	// edge,edge distance
    P res;
	if (ssi(a,b,c,d,res)) return 0.0;	// Proper intersection
	return min(ee2(a,b,c,d), ee2(c,d,a,b));
}

const int N = 3036;
P p[N];
int ans[N];

int main() {
    int T; scanf("%d", &T); FOE(ca, 1, T) {
        int n; scanf("%d", &n);
        FOR(i, 0, n) p[i].eat(); p[n] = p[0];
        FOR(i, 0, n) ans[i] = n - 1;

        FOR(i, 0, n) FOR(j, 0, n) if (i != j) {
            int pos = 0;
            int neg = 0;
            FOR(k, 0, n) {
                if (Ccw(p[i], p[j], p[k])) pos++;
                if (Ccw(p[j], p[i], p[k])) neg++;
            }
            ans[i] = min(ans[i], min(pos, neg));
        }

        printf("Case #%d:\n", ca);
        FOR(i, 0, n) printf("%d\n", ans[i]);
    }
}
