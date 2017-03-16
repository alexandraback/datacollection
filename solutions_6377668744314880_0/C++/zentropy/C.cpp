#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

#define N 1005

struct Point
{
	int x,y;
};

Point P[N],S[N];

int n,top;

double Dis(const Point& p1,const Point& p2)
{
	return sqrt( (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y)*1.0 );
}

double Cross(const Point& p1,const Point& p2,const Point& p3,const Point& p4)
{
	return (p2.x-p1.x)*(p4.y-p3.y) - (p2.y-p1.y)*(p4.x-p3.x);
}

bool cmp(const Point& p1,const Point& p2)
{
	double C = Cross(P[0],p1,P[0],p2);
	return C ? C>0 : Dis(P[0],p1)<Dis(P[0],p2);
}

bool ponline(const Point& p,const Point& p1,const Point& p2)
{
	int a = p2.y - p1.y;
	int b = p1.x - p2.x;
	int c = p2.x*p1.y - p1.x*p2.y;
	int d = a*p.x + b*p.y + c;
	return (0 == d);
}

void Pole_Point()
{
	int id;
	Point pp = P[id=0];
	for(int i=1;i<n;i++)
		if(P[i].y < pp.y || P[i].y == pp.y && P[i].x < pp.x)
			pp = P[i] , id = i;
	P[id] = P[0] , P[0] = pp;
}

void Convex_Hull()
{
	Pole_Point();
	sort(P+1,P+n,cmp);
	S[0]=P[0],S[top=1]=P[1];
	for(int i=2;i<n;i++)
	{
		while(top && Cross(S[top-1],S[top],S[top],P[i]) <= 0)
			--top;
		S[++top] = P[i];
	}
}

bool atedge(const Point& p)
{
	for(int i=0;i<=top;i++)
	{
		if(p.x == S[i].x && p.y == S[i].y) return true;
	}
	for(int i = 1;i <= top;++i)
	{
		if(ponline(p,S[i-1],S[i])) return true;
	}
	if(S[top].x != S[0].x || S[top].y != S[0].y)
	{
		if(ponline(p,S[top],S[0])) return true;
	}

	return false;
}

void slove_small(const vector<Point>& points,vector<unsigned int>& ans)
{
	size_t size = points.size();
	if(size <= 3) return;
	for(unsigned int i = 0;i < size;++i)
	{
		P[i].x = points[i].x;
		P[i].y = points[i].y;
	}
	n = size;
	Convex_Hull();

	for(size_t i = 0;i < size;++i) ans[i] = (unsigned int)(-1);
	for(size_t i = 0;i < size;++i)
	{
		if(atedge(points[i])) ans[i] = 0;
	}

	for(unsigned int imask = 0;imask <= (1<<size);++imask)
	{
		unsigned int count = 0;
		vector<bool> used(size,false);
		for(unsigned int i = 0;i < size;++i)
		{
			if(0 == (imask&(1<<i))) continue;
			P[count].x = points[i].x;
			P[count].y = points[i].y;
			used[i] = true;
			++ count;
		}
		if(count == size) continue;
		if(count <= 2) continue;
		n = count;
		Convex_Hull();

		for(size_t i = 0;i < size;++i)
		{
			if(!used[i]) continue;
			if(atedge(points[i]))
			{
				unsigned int r = size - count;
				if(r < ans[i]) ans[i] = r;
			}
		}
	}
}


int main()
{
	unsigned int nCases = 0;scanf("%d",&nCases);
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		unsigned int n = 0;scanf("%d",&n);
		vector<Point> points(n);
		for(unsigned int i = 0;i < n;++i) scanf("%d%d",&points[i].x,&points[i].y);

		vector<unsigned int> ans(n,0);
		slove_small(points,ans);
		printf("Case #%u:\n",iCases);
		for(size_t i = 0;i < ans.size();++i) printf("%u\n",ans[i]);
	}
	return 0;
}