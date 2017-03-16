#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 1010
using namespace std;
typedef long long LL;
struct Point
{
	int x,y,id;
	Point() {}
	Point(int x,int y): x(x),y(y) {}
	friend bool operator < (const Point &a,const Point &b)
	{
		return a.x<b.x||(a.x==b.x&&a.y<b.y);
	}
	friend Point operator - (const Point &a,const Point &b)
	{
		return Point(a.x-b.x,a.y-b.y);
	}
}a[maxn],p[maxn];
int ans[maxn],n;
void convex(int v,int n)
{
	static Point stack[maxn];
	sort(p+1,p+n+1);
	int top=0;
	for(int i=1;i<=n;++i)
	{
		while(top>1)
		{
			int dx1=p[i].x-stack[top-1].x,dy1=p[i].y-stack[top-1].y;
			int dx2=stack[top].x-stack[top-1].x,dy2=stack[top].y-stack[top-1].y;
			if((LL)dx1*dy2-(LL)dx2*dy1>=0)
				break;
			--top;
		}
		stack[++top]=p[i];
	}
	int h=top;
	for(int i=n-1;i>=1;--i)
	{
		while(top>h)
		{
			int dx1=p[i].x-stack[top-1].x,dy1=p[i].y-stack[top-1].y;
			int dx2=stack[top].x-stack[top-1].x,dy2=stack[top].y-stack[top-1].y;
			if((LL)dx1*dy2-(LL)dx2*dy1>=0)
				break;
			--top;
		}
		stack[++top]=p[i];
	}
	for(int i=1;i<=top;++i)
		ans[stack[i].id]=min(ans[stack[i].id],v);
}
void read()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i].x>>a[i].y;
		a[i].id=i,ans[i]=1<<30;
	}
}
void print()
{
	for(int i=0;i<(1<<n);++i)
	{
		int cost=0,tot=0;
		for(int j=1;j<=n;++j)
		{
			if(i>>(j-1)&1)
				p[++tot]=a[j];
			else
				++cost;
		}
		convex(cost,tot);
	}
	for(int i=1;i<=n;++i)
		printf("%d\n",ans[i]);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T,C=0;
	for(cin>>T;T;--T)
	{
		read();
		printf("Case #%d:\n",++C);
		print();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
