#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;
#define rep(i,l,r) for (int i=(l);i<=(r);i++)

typedef double DO;
const DO eps=1e-8,inf=1e30;
const int maxn=160;
template<class T> inline T abs(const T &a) {return a<0?-a:a;}
struct Point {
	DO x,y;
	Point() {};
	Point(const Point &a) {*this=a;};
	Point(DO _x,DO _y): x(_x), y(_y) {};
	bool operator < (const Point &a) const {return x<a.x||(abs(x-a.x)<eps&&y<a.y);}
	bool operator == (const Point &a) const {return abs(x-a.x)<eps&&abs(y-a.y)<eps;}
	Point operator + (const Point &a) const {return Point(x+a.x,y+a.y);}
	Point operator - (const Point &a) const {return Point(x-a.x,y-a.y);}
	Point operator * (DO k) const {return Point(k*x,k*y);}
	DO operator * (const Point &a) const {return x*a.y-y*a.x;}
	Point operator % (DO k) const {return Point(cos(k)*x-sin(k)*y,sin(k)*x+cos(k)*y);}
	DO mu() const {return sqrt(x*x+y*y);}
	DO mu2() const {return x*x+y*y;}
	DO angle() const {return atan2(y,x);}
	void read() {scanf("%lf%lf",&x,&y);}
	void out() {printf("%.6f %.6f\n",(double)x,(double)y);}
};
struct Line {
	Point A,B;
	Line() {};
	Line(const Line &a) {*this=a;};
	Line(Point _A,Point _B): A(_A), B(_B) {};
	bool parallel(const Line &a) {return abs((B-A)*(a.B-a.A))<eps;}
	DO dist(const Point &C) {return abs((C-A)*(C-B))/(B-A).mu();}
	Point operator * (const Line &a) {
		DO k1=(B-A)*(a.A-A),k2=(a.B-A)*(B-A);
		return Point(a.A*(k2/(k1+k2))+a.B*(k1/(k1+k2)));
	}
};
bool equal(const DO &a,const DO &b)
{return abs(a-b)<eps;}

Point p[maxn],a[maxn];
Point st[maxn];
int top,n,m;

void Graham() {
	sort(a+1,a+m+1);
	int tmp=0;
	top=0;
	rep(i,1,m) {
		while (top>1&&(a[i]-st[top])*(st[top]-st[top-1])>0) top--;
		st[++top]=a[i];
	}
	tmp=top;
	for (int i=m;i>=1;i--) {
		while (top>tmp&&(a[i]-st[top])*(st[top]-st[top-1])>0) top--;
		st[++top]=a[i];
	}
	top--;
}

int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int T;scanf("%d\n",&T);
	rep(t,1,T) {
		printf("Case #%d:\n",t);
		scanf("%d\n",&n);
		rep(i,1,n) p[i].read();
		rep(i,1,n) {
			int ans=1000;
			rep(j,0,(1<<n)-1) {
				m=0;
				rep(k,1,n)
					if ( !(j&(1<<k>>1)) )
						a[++m]=p[k];
				Graham();
				bool flag=false;
				rep(k,1,top)
					if (p[i]==st[k])
					{flag=true;break;}
				if (flag) {
					if (ans>__builtin_popcount(j))
						ans=__builtin_popcount(j);
				}
				if (ans==0) break;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
