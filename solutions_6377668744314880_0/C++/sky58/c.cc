#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
const double EPS = 1e-10;
const double INF = 1e+10;
const double PI = acos(-1);
int sig(double r) { return (r < -EPS) ? -1 : (r > +EPS) ? +1 : 0; }
struct Pt {
	double x, y;
	Pt() {}
	Pt(double x, double y) : x(x), y(y) {}
	Pt operator+(const Pt &a) const { return Pt(x + a.x, y + a.y); }
	Pt operator-(const Pt &a) const { return Pt(x - a.x, y - a.y); }
	Pt operator*(const Pt &a) const { return Pt(x * a.x - y * a.y, x * a.y + y * a.x); }
	Pt operator-() const { return Pt(-x, -y); }
	Pt operator*(const double &k) const { return Pt(x * k, y * k); }
	Pt operator/(const double &k) const { return Pt(x / k, y / k); }
	double abs() const { return sqrt(x * x + y * y); }
	double abs2() const { return x * x + y * y; }
	double arg() const { return atan2(y, x); }
	double dot(const Pt &a) const { return x * a.x + y * a.y; }
	double det(const Pt &a) const { return x * a.y - y * a.x; }
};
ostream &operator<<(ostream &os, const Pt &a) { os << "(" << a.x << ", " << a.y << ")"; return os; }
double tri(const Pt &a, const Pt &b, const Pt &c) { return (b - a).det(c - a); }
struct seg{
	Pt s,t;
	seg(){}
	seg(Pt s,Pt t): s(s),t(t){}
};
int iSP(Pt a,Pt b,Pt c){
	int s=sig((b-a).det(c-a));
	if(s) return s;//+-1:not intersect
	if(sig((b-a).dot(c-a))<0) return -2;//c-a-b
	if(sig((a-b).dot(c-b))<0) return 2;//a-b-c
	return 0;//a-c-b
}
Pt p[3643];
int mi[3643];
int main()
{
	int n,t,x,y;
	cin>>t;
	rep(i,t){
		cin>>n;
		rep(j,n){
			cin>>x>>y;p[j]=Pt(x,y);
		}
		rep(j,n) mi[j]=114514;
		if(n<2) mi[0]=0;
		rep(j,n) rep(k,n){
			if(j==k) continue;
			int a=0,b=0;
			rep(l,n){
				if(j==l || k==l) continue;
				if(iSP(p[j],p[k],p[l])==1) a++;
				if(iSP(p[j],p[k],p[l])==-1) b++;
			}
			mi[j]=min(mi[j],min(a,b));
		}
		printf("Case #%d:\n",i+1);
		rep(j,n) cout<<mi[j]<<endl;
	}
}
