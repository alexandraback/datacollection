#include<cstdio>
#include<cstring>
#include<algorithm>
#define fou(i,j,k) for (int i=j;i<=k;i++)
#define fod(i,j,k) for (int i=j;i>=k;i--)
using namespace std;

typedef long long LL;

const int maxn=50;
const int oo=1000000000;

int n,m,K,ans;
bool f[maxn][maxn];

void init()
{
	scanf("%d%d%d",&n,&m,&K);
}

void dfs(int x,int y,int cnt,int tot)
{
	if (y>m){
		x++;y=1;
	}
	if (x>n){
		if (cnt==K && ans>tot) ans=tot;
		return;
	}
	dfs(x,y+1,cnt,tot);
	if (f[x-1][y]) tot++;
	if (f[x][y-1]) tot++;
	f[x][y]=true;
	dfs(x,y+1,cnt+1,tot);
	if (f[x-1][y]) tot--;
	if (f[x][y-1]) tot--;
	f[x][y]=false;
}

void solve()
{
	memset(f,false,sizeof(f));
	ans=oo;
	dfs(1,1,0,0);
	printf("%d\n",ans);
}

int main()
{
	int T;
	scanf("%d",&T);
	fou(i,1,T){
		printf("Case #%d: ",i);
		init();
		solve();
	}
	return 0;
}
