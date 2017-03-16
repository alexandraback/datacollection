//
#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<vector>
#include<map>
#define FOR(i,s,t) for(int i=(s);i<=(t);i++)
#define CFOR(i) for(;i>0;i--)
#define DFOR(i,s,t) for(int i=(s);i>=(t);i--)
#define PFOR(i,s,t,p) for(int i=(s);i<=(t);i+=p)
#define SD(i) scanf("%d",&i)
#define SLLD(i) scanf("%lld",&i)
#define MEM(a,t) memset(a,t,sizeof(a))
#define PIA system("pause")
#define MAXINT 0xfffffff
#define MARK cout<<"MARK"<<endl;
#define BUG cout<<"error!"<<endl;
#define LL long long
using namespace std;
ifstream fin ("in.txt");
ofstream fout ("out.txt");

#ifdef _WIN32 // FUCK OLD MSVC & LATEST MINGW
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

/********************************************************************************************/
const double EPS = 1e-8;
const double PI = 3.1415926535897932384626433832795;
int sgn(double x){
	if( fabs(x)<EPS )	return 0;
	return x>0 ? 1:(-1);
}
double sqr(double x){
	return x*x;
}
struct Point{
	double x,y;
	Point(){x=y=0;}
	Point(double _x,double _y):x(_x),y(_y){}
	Point operator + (const Point &a)const{
		return Point(x+a.x,y+a.y);
	}
	Point operator - (const Point &a)const{
		return Point(x-a.x,y-a.y);
	}
	Point operator * (const double &k)const{
		return Point(x*k,y*k);
	}
	Point operator / (const double &k)const{
		return Point(x/k,y/k);
	}
	Point& operator = (const Point &a){
		x=a.x; y=a.y;
		return *this;
	}
	bool operator < (const Point &a)const{
		return sgn(x-a.x)<0 || (!sgn(x-a.x)&&sgn(y-a.y)<0);

	}
	bool operator == (const Point &a)const{
		return !sgn(x-a.x) && !sgn(y-a.y);
	}
	bool operator != (const Point &a)const{
		return sgn(x-a.x) || sgn(y-a.y);
	}
	Point normal()const{
		return Point(-y,x);
	}
	void output(){
		printf("(%.2f,%.2f)\n",x,y);
	}
	void input(){
		scanf("%lf%lf",&x,&y);
	}
};
/********************************************************************************************/
const int MAXN = 3010;
Point sp[MAXN],p[MAXN];
double a[MAXN*2];
//const double PI = acos(-1);
int n;
int casnum=0;
void solve(){
	printf("Case #%d:\n",++casnum);
	if(n<=3){
		FOR(i,1,n)	printf("0\n");
		return ;
	}

	int ans;
	Point o;

	FOR(i,1,n){
		o = sp[i];
		int cnt=0;
		FOR(j,1,n){
			if(i!=j)	a[cnt++] = atan2(sp[j].y-o.y,sp[j].x-o.x);
		}

		n--;

		sort(a,a+n);
		FOR(j,0,n-1)	a[j+n]=a[j]+2*PI;
		ans = n+n;
		int p1,p2;
		p1=0;p2=0;
		while(p1<n){
			while(sgn(a[p2]-a[p1]-PI)<0)	p2++;
			ans=min(ans,p2-p1-1);
			while(sgn(a[p2]-a[p1]-PI)==0)	p2++;
			ans=min(ans,p1+n-p2);
			p1++;
		}
		printf("%d\n",ans);

		n++;
	}
}
void init(){
	scanf("%d",&n);
	FOR(i,1,n)	sp[i].input();
}

void openfile(){
	//freopen("in.txt","r",stdin);
	//
	freopen("C3.txt","w",stdout);
}

int main(){
	//
	openfile();
	int T;scanf("%d",&T);
	CFOR(T){
		init();
		solve();
	}
	//PIA;
    	return 0;
}
