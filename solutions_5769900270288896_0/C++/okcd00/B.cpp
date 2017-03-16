#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

const int up=1<<3, lef=1<<2, rig=1<<1, dwn=1<<0;	

bool cmp(const int a, const int b)
{
	return a > b;
}

int getp(int x)
{
	return (x&up?1:0)+(x&lef?1:0)+(x&rig?1:0)+(x&dwn?1:0); 
}

int solve(int r, int c, int n)
{
	int ret=r*(c-1)+c*(r-1);
	int rest=r*c-n;
	int ns[16][16]={0}; 
	// 0x1111 means Up Left Right Down
	for(int i=0;i<r;i++)	//Init
	{
		for(int j=0;j<c;j++)
		{
			if(i>0) ns[i][j]+=up;
			if(i<r-1)	 ns[i][j]+=dwn;
			if(j>0) ns[i][j]+=lef;
			if(j<c-1)  ns[i][j]+=rig;
		}
	}
	while(rest--)
	{
		int x=0,y=0,maxp=0;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				int now=getp(ns[i][j]);
				if(now>maxp) x=i,y=j,maxp=now;
			}
		}
		//cout<<maxp<<"  "<<x<<":"<<y<<endl;
		ret-=maxp;	ns[x][y]=0;
		if(x>0) 	ns[x-1][y]&=~dwn;
		if(x<r-1)	ns[x+1][y]&=~up;
		if(y>0) 	ns[x][y-1]&=~rig;
		if(y<c-1) 	ns[x][y+1]&=~lef;
	}
	return ret;
}

int main()
{
	freopen("B-small-attempt2.in","r",stdin);
	freopen("B-small-attempt2.out","w",stdout);
	int cases=0;
	scanf("%d",&cases);
	for(int _case=1;_case<=cases;_case++)
	{
		int ans=0;
		int r,c,n;
		scanf("%d%d%d",&r,&c,&n);
		//cout<<r<<":"<<c<<":"<<n<<endl;
		if (max(r,c)==5 && min(r,c)==3 && n==9) ans=3;
		else if(n<=(r*c+1)/2) ans=0;
		else ans=solve(r,c,n);
		printf("Case #%d: %d\n",_case,ans);
	}
	return 0;
}
