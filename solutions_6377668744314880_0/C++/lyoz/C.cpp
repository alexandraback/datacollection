#include <bits/stdc++.h>
using namespace std;

#define dump(...) cout<<"# "<<#__VA_ARGS__<<'='<<(__VA_ARGS__)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define peri(i,a,b) for(int i=int(b);i-->int(a);)
#define rep(i,n) repi(i,0,n)
#define per(i,n) peri(i,0,n)
#define all(c) begin(c),end(c)
#define mp make_pair
#define mt make_tuple

using uint=unsigned int;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using vd=vector<double>;
using vvd=vector<vd>;
using vs=vector<string>;

template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& p){
	return os<<'('<<p.first<<','<<p.second<<')';
}

template<typename Tuple>
void print_tuple(ostream&,const Tuple&){}
template<typename Car,typename... Cdr,typename Tuple>
void print_tuple(ostream& os,const Tuple& t){
	print_tuple<Cdr...>(os,t);
	os<<(sizeof...(Cdr)?",":"")<<get<sizeof...(Cdr)>(t);
}
template<typename... Args>
ostream& operator<<(ostream& os,const tuple<Args...>& t){
	print_tuple<Args...>(os<<'(',t);
	return os<<')';
}

template<typename Ch,typename Tr,typename C>
basic_ostream<Ch,Tr>& operator<<(basic_ostream<Ch,Tr>& os,const C& c){
	os<<'[';
	for(auto i=begin(c);i!=end(c);++i)
		os<<(i==begin(c)?"":" ")<<*i;
	return os<<']';
}

constexpr int INF=1e9;
constexpr int MOD=1e9+7;
constexpr double EPS=1e-9;

struct Point{
	double x,y;
	Point(){}
	Point(double x,double y):x(x),y(y){}
	Point& operator+=(Point p){x+=p.x,y+=p.y; return *this;}
	Point& operator-=(Point p){x-=p.x,y-=p.y; return *this;}
	Point& operator*=(double c){x*=c,y*=c; return *this;}
	Point& operator/=(double c){x/=c,y/=c; return *this;}
};
Point operator+(Point a,Point b){return a+=b;}
Point operator-(Point a,Point b){return a-=b;}
Point operator*(Point a,double c){return a*=c;}
Point operator*(double c,Point a){return a*=c;}
Point operator/(Point a,double c){return a/=c;}
bool operator==(Point a,Point b){return abs(a.x-b.x)<EPS && abs(a.y-b.y)<EPS;}
bool operator!=(Point a,Point b){return !(a==b);}

struct Line{
	Point pos,dir;
	Line(){}
	Line(Point p,Point d):pos(p),dir(d){}
	Line(double x,double y,double u,double v):pos(x,y),dir(u,v){}
};

ostream& operator<<(ostream& os,const Point& p){
	return os<<'('<<p.x<<','<<p.y<<')';
}
ostream& operator<<(ostream& os,const Line& l){
	return os<<'('<<l.pos<<','<<l.dir<<')';
}

int Signum(double x){
	return x<-EPS?-1:x>EPS?1:0;
}
double Abs2(Point p){
	return p.x*p.x+p.y*p.y;
}
double Dot(Point a,Point b){
	return a.x*b.x+a.y*b.y;
}
double Cross(Point a,Point b){
	return a.x*b.y-a.y*b.x;
}

int CCW(Point a,Point b,Point c){
	b-=a,c-=a;
	if(int sign=Signum(Cross(b,c)))
		return sign; // 1:ccw,-1:cw
	if(Dot(b,c)<-EPS)
		return -2;   // c-a-b
	if(Abs2(b)<Abs2(c)-EPS)
		return 2;    // a-b-c
	return 0;      // a-c-b (inclusive)
}

void solve_small()
{
	int n; scanf("%d",&n);
	vector<Point> ps(n);
	rep(i,n) scanf("%lf%lf",&ps[i].x,&ps[i].y);
	
	puts("");
	
	if(n<=2){
		rep(i,n) puts("0");
		return;
	}
	
	rep(i,n){
		int mn=INF;
		rep(j,n) if(i!=j){
			int cnt=0;
			rep(k,n) cnt+=CCW(ps[i],ps[j],ps[k])==-1;
			mn=min(mn,cnt);
		}
		printf("%d\n",mn);
	}
}

int main()
{
	int tc; scanf("%d",&tc);
	rep(i,tc){
		printf("Case #%d: ",i+1);
		solve_small();
	}
}
