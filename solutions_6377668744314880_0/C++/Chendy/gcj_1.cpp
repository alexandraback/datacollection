#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#define LL long long 
using namespace std;
int n,m,cnt,B,head;
int a[1010];
double eps=1e-9,x,y,px,py;
const double pi=3.1415926535897;
inline int sgn(const LL &x)
{
	if (x>0) return 1;
	if (x<0) return -1;
	return 0;
}
struct point
{
	LL x,y;
	point (int _x=0,int _y=0):x(_x),y(_y){};
	bool operator ==(const point &t) const
	{
		return sgn(x-t.x)==0&&sgn(y-t.y)==0;
	}
	point operator+(const point &t) const
	{
		return point(x+t.x,y+t.y);
	}	
	point operator-(const point &t) const
	{
		return point(x-t.x,y-t.y);
	}
	point operator*(const double &k) const
	{
		return point(x*k,y*k);
	}
	inline double operator*(const point &t) const
	{
		return x*t.y-y*t.x;
	}
	point rotate() //ni shi zhen
	{
		return point(-y,x);
	}
}p[50010],q[100010],st[100010],q2[100010];
bool onit(point x,point a,point b)//point on line
{
	return sgn(x.x-max(a.x,b.x))<=0&&sgn(x.y-max(a.y,b.y))<=0&&sgn(x.x-min(a.x,b.x))>=0&&sgn(x.y-min(a.y,b.y))>=0;
}
LL dis(point p)
{
	return (LL)p.x*p.x+(LL)p.y*p.y;
}
bool cmp(const point x,const point y)
{
	return ((x-q[1])*(y-q[1])>0)||(((x-q[1])*(y-q[1])==0)&&dis(x-q[1])<dis(y-q[1]));//||(sgn(x.dg-y.dg)==0&&sgn((x.b-x.a)*(y.b-x.a))<0);
}
void calc(int m)
{
	int pos=1;
	for (int i=2;i<=m;i++)
	{
		if (sgn(q[i].x-q[pos].x)<0||(sgn(q[i].x-q[pos].x)==0&&sgn(q[i].y-q[pos].y)<0)) pos=i;
	}
	swap(q[1],q[pos]);
	sort(q+2,q+m+1,cmp);
	head=0;
	for (int i=1;i<=m;i++)
	{
		while (head>=2&&((st[head]-st[head-1])*(q[i]-st[head-1])<=0))
		head--;
		st[++head]=q[i];
	}
}
bool onbord(point p)
{
	st[0]=st[head];
	for (int i=1;i<=head;i++)
	{
		point a,b;
		a=st[i-1],b=st[i];
		if (onit(p,a,b)&&sgn((p-a)*(b-a))==0) return true;
	}
	return false;
}
void work(int lab)
{
	printf("Case #%d:\n",lab);
	scanf("%d",&n);
	int x,y;
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		p[i].x=x;
		p[i].y=y;
	}
	for (int i=1;i<=n;i++)
	{
		int ans=n+1;
		for (int s=(1<<n)-1;s>=1;s--)
		{
			m=0;
			for (int j=1;j<=n;j++)
			if (s&(1<<(j-1))) 
			q[++m]=p[j];
			calc(m);
			if (onbord(p[i])&&(s&(1<<(i-1)))) 
			{
				if (n-m<ans)
				ans=n-m;
			}
		}
		printf("%d\n",ans);
	}
}
int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int t;
	scanf("%d\n",&t);
	for (int i=1;i<=t;i++)work(i);
	return 0;
}
