#include <iostream> 
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cassert> 
using namespace std;
#define rep(i,n) for(int i=1;i<=(n);++i)
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
struct point
{
	int x,y;
	long long operator *(point ano)
	{
		return x*(long long)ano.y-y*(long long)ano.x;
	}
	point operator -(point ano)
	{
		return (point){x-ano.x,y-ano.y};
	}
}ind[3001];
int n;
void task()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d%d",&ind[i].x,&ind[i].y);
	rep(i,n)
	{
		int res=n-1;
		rep(j,n)
		{
			int tmp1=0,tmp2=0;
			if(j==i)continue;
			rep(k,n)
			{
				if((ind[k]-ind[i])*(ind[j]-ind[i])>0)++tmp1;
				if((ind[k]-ind[i])*(ind[j]-ind[i])<0)++tmp2;
			}
			res=min(res,min(tmp1,tmp2));
		}
		printf("%d\n",res);
	}
}
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int nt;scanf("%d",&nt);
	rep(i,nt)
	{
		printf("Case #%d:\n",i);
		task();
	}
}
	
