#include"stdio.h"
#include"string.h"
#include"algorithm"
using namespace std;
int first[1234],next[1234],u[1234],e=0;
void add(int x,int y)
{
	u[e]=y;next[e]=first[x];first[x]=e++;
	u[e]=x;next[e]=first[y];first[y]=e++; 
}
int dp[1234],cnt[1234];
void dfs(int x,int fa)
{
	int ch=0;
	int da=0,db=0,ca,cb;
	for(int i=first[x];~i;i=next[i])
	if(u[i]!=fa)
	{
		dfs(u[i],x);
		ch++;
		cnt[x]+=cnt[u[i]];
		if(dp[u[i]]>da)
		{
			db=da;			
			da=dp[u[i]];
		}
		else if(dp[u[i]]<=da&&dp[u[i]]>db)
		{
			db=dp[u[i]];
		}
	}	
	cnt[x]++;
	dp[x]++;
	if(ch==1)
	{
		dp[x]=1;
	}
	else if(ch>=2)
	{
		dp[x]=da+db+1;	
	}
//	printf("---> %d %d %d\n",x,dp[x],cnt[x]);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int t,x,y,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		e=0;
		memset(first,-1,sizeof(first));
		for(int i=1;i<n;i++)
		{
			scanf("%d %d",&x,&y);
			add(x,y);
		}
		int min_ans=n-1;
		for(int i=1;i<=n;i++)
		{
			memset(dp,0,sizeof(dp));
			memset(cnt,0,sizeof(cnt));
			dfs(i,-1);
			min_ans=min(min_ans,cnt[i]-dp[i]);
		}
		printf("Case #%d: %d\n",cas++,min_ans);	
	}
}