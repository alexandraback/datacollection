#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
typedef long long ll;
#define INF 1e9
#define maxn 3005
#define maxm 100086+10
#define mod 100007
#define eps 1e-8
#define PI acos(-1.0)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define scan(n) scanf("%d",&n)
#define scanll(n) scanf("%I64d",&n)
#define scan2(n,m) scanf("%d%d",&n,&m)
#define scans(s) scanf("%s",s);
#define ini(a) memset(a,0,sizeof(a))
#define out(n) printf("%d\n",n)
#define out1(ans,i,n) rep(i,n) printf("%d%c",ans[i],i==n-1?'\n':' ')
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
struct Point
{
	double x,y;
	Point(double xx,double yy)
	{
		x=xx;
		y=yy;
	}
	Point()
	{
		x=0;
		y=0;
	}
}a[maxn], b[maxn], c[maxn];
typedef Point Vector;
Vector operator+(Vector A,Vector B)
{
	return Vector(A.x+B.x,A.y+B.y);
}
Vector operator-(Point A,Point B)
{
	return Vector(A.x-B.x,A.y-B.y);
}
Vector operator*(Vector A,double p)
{
	return Vector(A.x*p,A.y*p);
}
Vector operator/(Vector A,double p)
{
	return Vector(A.x/p,A.y/p);
}
Vector operator*(double p,Vector A)
{
	return Vector(A.x*p,A.y*p);
}
Vector operator/(double p,Vector A)
{
	return Vector(A.x/p,A.y/p);
}
bool operator<(const Point& a,const Point& b)
{
	return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
int dcmp(double x)
{
	if(fabs(x)<eps)
	{
		return 0;
	}
	else
		return x<0?-1:1;
}
bool operator==(const Point& a,const Point& b)
{
	return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
}
double Dot(Vector a,Vector b)
{
	//计算点积
	return a.x*b.x+a.y*b.y;
}
double Cross(Vector a,Vector b)
{
	//计算叉积
	return a.x*b.y-a.y*b.x;
}
double Length(Vector a)
{
	//计算长度
	return sqrt(Dot(a,a));
}
int ConvexHull(Point* p,int n,Point* ch)
{
	//计算凸包，输入点数组p，个数为n，输出点数组ch，函数返回凸包顶点数
	//输入不能有重复点，函数执行完后输入点的顺序被破坏
	//如果不希望在凸包的边上有输入点，把两个<=改成<
	//在精度要求高时建议用dcmp比较
	sort(p,p+n);
	int m=0;
	for(int i=0;i<n;i++)
	{
		while(m>1&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<0)
			m--;
		ch[m++]=p[i];
	}
	int k=m;
	for(int i=n-2;i>=0;i--)
	{
		while(m>k&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<0)
			m--;
		ch[m++]=p[i];
	}
	if(n>1)
		m--;
	return m;
}

int n;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt", "w", stdout);
#endif    
	
	int T;
	cin>>T;
	int cas = 1;
	while(T--)
	{
		cin>>n;
		rep(i, n)
		{
			cin>>a[i].x>>a[i].y;
		}
	//	int m = ConvexHull(a, n, b);
		printf("Case #%d:\n",cas++);
		rep(i, n)
		{
			int ans = n + 1;
			for(int j = 0; j < (1<<n); j++)
			{
				int cnt = 0;
				for(int k = 0;k < n;k ++)
				{
					if(((1 << k) & j) && k != i)
					{
						continue;
					}
					else
					{
						c[cnt++] = a[k];
					}
				}
				int m = ConvexHull(c, cnt, b);
				rep(k,m)
				{
					if(b[k] == a[i])
					{
						ans = min(ans, n-cnt);
						break;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}