#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define FORD(x,y,z) for(int x=y;x>=z;x--)
#define MSET(x,y) memset(x,y,sizeof(x))
#define FOR(x,y) for(__typeof(y.begin()) x=y.begin();x!=y.end();x++)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size()
#define M 30
using namespace std;
typedef long long LL;
int n,m,k,t,ans,dx[4]={-1,1,0,0},dy[4]={0,0,1,-1};
bool ch[M][M];
bool val(int x,int y)
{
	return x>=0 && y>=0 && x<n && y<m;
}
void dfs(int x,int y,int cnt)
{
	if(cnt==0)
	{
		int tmp=0;
		int nx,ny;
		REP(i,0,n-1)REP(j,0,m-1)if(ch[i][j])
		{
			REP(d,0,3)
			{
				nx = i+dx[d];
				ny = j+dy[d];
				if(val(nx,ny) && ch[nx][ny]) tmp++;
			}
		}
		ans = min(ans, tmp);
	}
	if(x>=n)
	{
		return;
	}

	int nx=x,ny=y+1;
	if(ny>=m) nx=x+1, ny=0;
	ch[x][y] = true;
	dfs(nx,ny,cnt-1);

	ch[x][y]=false;
	dfs(nx,ny,cnt);
}
int main()
{
	scanf("%d",&t);
	REP(tt,1,t)
	{
		ans = 2000;
		scanf("%d %d %d",&n,&m,&k);
		dfs(0,0,k);
		printf("Case #%d: %d\n",tt,ans/2);
	}
	return 0;
}

