#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

#define MAXN 3005

int cas, tc, n, cnt, N;
int ans[MAXN];

const double eps = 1e-10;

int dcmp(double x){
	if(fabs(x)<eps) return 0;
	else return x<0?-1:1;
}

struct Point{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
	bool operator<(const Point &b)const{
		return (dcmp(x-b.x)<0 || dcmp(x-b.x) == 0 && dcmp(y-b.y) < 0); 
	}
	bool operator==(const Point &b)const{
		return (dcmp(x-b.x)==0 && dcmp(y-b.y)==0);
	}
}a[MAXN], b[MAXN], p[MAXN], q[MAXN];
typedef Point Vector;
Vector operator+(Vector A,Vector B){return Vector(A.x+B.x,A.y-B.y);}
Vector operator-(Point A,Point B){return Vector(A.x-B.x,A.y-B.y);}
Vector operator*(Vector A,double p){return Vector(A.x*p,A.y*p);}
Vector operator/(Vector A,double p){return Vector(A.x/p,A.y/p);}

double Dot(Vector A,Vector B){return A.x*B.x+A.y*B.y;}
double Cross(Vector A,Vector B){return A.x*B.y-A.y*B.x;}

struct Segment{
	Point a,b;
	Segment(){}
	Segment(Point a,Point b):a(a),b(b){}
};

bool PointOnSegment(Point A,Segment S){
	return dcmp(Cross(S.a-A,S.b-A))==0 && dcmp(Dot(S.a-A,S.b-A))<0;
} 

int PointInPolygon(Point A,Point*p,int n){
	int wn=0;
	for(int i=0;i<n;i++)
	{
		if(A == p[i]) return 1;
		if(PointOnSegment(A,Segment(p[i],p[(i+1)%n]))) return 1;
	}
	return 0;
} 

void Andrew(Point*p,int n,Point*q,int &m){
	sort(p,p+n);
	m=0;
	for(int i=0;i<n;i++){
		while(m>1 && dcmp(Cross(q[m-1]-q[m-2],p[i]-q[m-2]))<=0) m--;
		q[m++]=p[i];
	}
	int k=m;
	for(int i=n-2;i>=0;i--){
		while(m>k && dcmp(Cross(q[m-1]-q[m-2],p[i]-q[m-2]))<=0) m--;
		q[m++]=p[i];
	}
	if(n>1) m--;
} 

void solve()
{
	for (int i = 0; i < cnt; i ++) p[i] = b[i];
	Andrew(p, cnt, q, N);
	for (int i = 1; i <= n; i ++)
		if (PointInPolygon(a[i], q, N))
		{
			if (cnt > ans[i])
				ans[i] = cnt;
		}
}

void dfs(int u)
{
	if (u > n)
	{
		solve();
		return;
	}
	dfs(u + 1);
	b[cnt ++] = a[u];
	dfs(u + 1);
	cnt --;
}

int main()
{
	freopen("C.in", "r", stdin); freopen("C.out", "w", stdout);
	scanf("%d", &cas);
	for (tc = 1; tc <= cas; tc ++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%lf%lf", &a[i].x, &a[i].y);
		memset(ans, 0, sizeof(ans)); cnt = 0;
		dfs(1);
		printf("Case #%d:\n", tc);
		for (int i = 1; i <= n; i ++) printf("%d\n", n - ans[i]);
	}
	return 0;
}
