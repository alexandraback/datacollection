#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

typedef long long ll;

int adj[10000][10000];

int testbit(int n, int m)
{
	return (n>>m)&1;
}

int bitcount(int n)
{
	int res=0;
	while(n)
	{
		res+=n&1;
		n>>=1;
	}
	return res;
}

void print(int r, int c, int n)
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			printf("%d",testbit(n,i*c+j));
		puts("");
	}
}

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int solve(int r, int c, int n)
{
	int res=1000000;
	int by;
	for(int i=0;i<(1<<(r*c));i++)
	{
		if(bitcount(i)!=n) continue;
		int cur=0;
		for(int j=0;j<r;j++)
			for(int k=0;k<c;k++)
				adj[j][k]=testbit(i,j*c+k);
		for(int j=0;j<r;j++)
			for(int k=0;k<c;k++)
			{
				for(int t=0;t<4;t++)
				{
					int nj=j+dx[t];
					int nk=k+dy[t];
					if(0<=nj && nj<r && 0<=nk && nk<c)
					{
						cur+=adj[j][k]*adj[nj][nk];
					}
				}
			}
		res=min(res,cur);
		if(res==cur)
			by=i;
	}
	print(r,c,by);
	return res/2;
}

int greedy(int r, int c, int n)
{
	int gres=1000000;
	for(int t=0;t<2;t++)
	{
		int tn=n;
		int cnt[5]={};
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				if((i+j)%2==t)
					cnt[0]++;
				else
				{
					int deg=0;
					for(int t=0;t<4;t++)
					{
						int nj=i+dx[t];
						int nk=j+dy[t];
						if(0<=nj && nj<r && 0<=nk && nk<c)
							deg++;
					}
					cnt[deg]++;
				}
		int res=0;
		for(int i=0;i<5;i++)
		{
			res+=min(tn,cnt[i])*i;
			tn-=min(tn,cnt[i]);
		}
		gres=min(gres,res);
	}
	return gres;
}


int solve()
{
	int r,c;
	scanf("%d%d",&r,&c);
	int n;
	scanf("%d",&n);
//	assert(solve(r,c,n)==greedy(r,c,n));
	return greedy(r,c,n);
}


int main()
{
	int T;
	scanf("%d",&T);
	for(int test=1;test<=T;test++)
		printf("Case #%d: %d\n",test, solve());
	return 0;
}
