#include<fstream>
using namespace std;
#include<algorithm>
#include<vector>
#include<memory.h>
FILE*fin=fopen("input.txt","r");
FILE*fout=fopen("output.txt","w");
struct Point
{
	__int64 x,y;
	int focus;
	bool isLeftOf1(const Point a,const Point b) const
	{
		if(a.x*b.y+b.x*y+x*a.y-a.y*b.x-b.y*x-y*a.x!=0)return a.x*b.y+b.x*y+x*a.y-a.y*b.x-b.y*x-y*a.x>0;
		return (x-a.x)*(x-a.x)+(y-a.y)*(y-a.y)-(b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y)>0;
	}
	bool isLeftOf2(const Point a,const Point b) const
	{
		return a.x*b.y+b.x*y+x*a.y-a.y*b.x-b.y*x-y*a.x>=0;
	}
}a[20],b[20];
int n,d[20];
vector<Point> s;
bool cmp1(const Point &a,const Point &b)
{
	if(a.y!=b.y)return a.y<b.y;
	return a.x<b.x;
}
bool cmp2(const Point &p,const Point &q)
{
	return q.isLeftOf1(b[1],p);
}
int main()
{
	int i,j,k,l,x,t,flag;
	fscanf(fin,"%d",&n);
	for(i=1;i<=n;++i)
	{
		fscanf(fin,"%d",&x);
		for(j=1;j<=x;++j)fscanf(fin,"%I64d%I64d",&a[j].x,&a[j].y);
		fprintf(fout,"Case #%d:\n",i);
		for(j=1;j<=x;++j)
		{
			for(k=x-1;k>=2;--k)
			{
				for(l=1;l<=k;++l)d[l]=1;
				for(;l<x;++l)d[l]=0;
				do
				{
					flag=1;
					t=0;
					for(l=1;l<j;++l)
					{
						if(d[l])
						{
							b[++t].x=a[l].x;
							b[t].y=a[l].y;
							b[t].focus=0;
						}
					}
					for(;l<x;++l)
					{
						if(d[l])
						{
							b[++t].x=a[l+1].x;
							b[t].y=a[l+1].y;
							b[t].focus=0;
						}
					}
					b[++t].x=a[j].x;
					b[t].y=a[j].y;
					b[t].focus=1;
					sort(&b[1],&b[t+1],cmp1);
					sort(&b[2],&b[t+1],cmp2);
					b[++t].x=b[1].x;
					b[t].y=b[1].y;
					b[t].focus=0;
					s.clear();
					s.push_back(b[1]);
					s.push_back(b[2]);
					for(l=3;l<=t;++l)
					{
						while(!b[l].isLeftOf2(s[s.size()-2],s[s.size()-1]))
						{
							if(s.back().focus)flag=0;
							s.pop_back();
						}
						s.push_back(b[l]);
					}
					if(flag)goto end;
				}while(!prev_permutation(&d[1],&d[k]));
			}
end:
			fprintf(fout,"%d\n",x-1-k);
		}
	}
	fcloseall();
	return 0;
}