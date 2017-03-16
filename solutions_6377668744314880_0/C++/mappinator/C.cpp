#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int x[3001], y[3001];
int e[3001];
class point
{
public:
	int x, y;
	point(int x, int y):x(x), y(y){}
	point(){}
};
point d[3001];
point p[3001];
int sp;
bool y_sort(point a, point b)
{
	return (a.y<b.y||(a.y==b.y&&a.x<b.x));
}
bool k_sort(point a, point b)
{
	return atan2(a.y-p[1].y, a.x-p[1].x)<atan2(b.y-p[1].y, b.x-p[1].x);
}
point c[3001];
int sc;
long long cross(point a, point b, point c)
{
	return (long long)(b.x-a.x)*(c.y-b.y)-(long long)(c.x-b.x)*(b.y-a.y);
}
void convex()
{
	if (sp>0) sort(p+1, p+sp+1, y_sort);
	if (sp>1) sort(p+2, p+sp+1, k_sort);
	sc=1;
	c[1]=p[1];
	for (int i=2; i<=sp; i++)
	{
		sc++;
		c[sc]=p[i];
		if (sc>2)
		{
			while (true)
			{
				if (sc>2&&cross(c[sc-2], c[sc-1], c[sc])<0)
				{
					c[sc-1]=c[sc];
					sc--;
				}
				else break;
			}
		}
	}
}
bool check(point a)
{
	for (int i=1; i<=sc; i++)
	{
		if (0==cross(c[i], c[i%sc+1], a)) return true;
	}
	return false;
}
int ans[3001];
int main()
{
	int t, s=0;
	scanf("%d", &t);
	while (t--)
	{
		memset(ans, 0x3f, sizeof(ans));
		int n;
		scanf("%d", &n);
		for (int i=1; i<=n; i++)
		{
			scanf("%d%d", &x[i], &y[i]);
			d[i]=point(x[i], y[i]);
		}
		while (true)
		{
			e[n]++;
			int a=n;
			while (a>0&&e[a]>1)
			{
				e[a-1]++;
				e[a]=0;
				a--;
			}
			sp=0;
			for (int i=1; i<=n; i++)
			{
				if (e[i])
				{
					sp++;
					p[sp]=d[i];
				}
			}
			convex();
			for (int i=1; i<=n; i++)
			{
				if (check(d[i])) ans[i]=min(ans[i], n-sp);
			}
			if (0==sp) break;
		}
		printf("Case #%d:\n", ++s);
		for (int i=1; i<=n; i++)
		{
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}