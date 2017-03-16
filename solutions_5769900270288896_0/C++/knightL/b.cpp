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

int adj[16][16];

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

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int solve()
{
	int r,c;
	scanf("%d%d",&r,&c);
	int n;
	scanf("%d",&n);
	int res=1000000;
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
	}
	return res/2;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int test=1;test<=T;test++)
		printf("Case #%d: %d\n",test, solve());
	return 0;
}
