#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<vector>
#include<queue>
#include<string>
#include<sstream>
#define eps 1e-9
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define MAXN 1005
#define MAXM 40005
#define INF 0x3fffffff
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define lc (k<<1)
#define rc ((k<<1)1)
using namespace std;
typedef long long LL;
int i,j,k,n,m,x,y,T,ans,big,cas,num,len;
bool flag;

int mp[20][20],r,c;
void chk()
{
	int cnt=0;
	for (int i=0;i<r;i++)
	{
		for (int j=0;j<c;j++)
		{
			if (i>0 && mp[i][j] && mp[i-1][j]) cnt++;
			if (j>0 && mp[i][j] && mp[i][j-1]) cnt++;
		}
	}
	ans=min(ans,cnt);
} 

void dfs(int x,int y,int f)
{
	mp[x][y]=1;
	
	if (f==n) chk(); else
	{
	
		for (int j=y+1;j<c;j++)
		{
			dfs(x,j,f+1);
		}
		
		for (int i=x+1;i<r;i++)
		{
			for (int j=0;j<c;j++)
			{
				dfs(i,j,f+1);
			} 
		}
	}
	
	mp[x][y]=0;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&r,&c,&n);
		memset(mp,0,sizeof(mp));
		ans=INF;
		if (n==0) ans=0;else
		dfs(0,0,1);
		printf("Case #%d: %d\n",++cas,ans);
	} 
	return 0;
}
