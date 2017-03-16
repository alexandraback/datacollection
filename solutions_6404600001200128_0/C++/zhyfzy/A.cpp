#include<bits/stdc++.h>
#define eps 1e-9
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
int a[1000];
int main()
{
	
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&T);
	for (cas=1;cas<=T;cas++)
	{
		scanf("%d",&n);
		for (i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		int ans1=0;
		for (i=1;i<n;i++)
		{
			ans1+=max(0,a[i]-a[i+1]);
		}
		
		int ans2=0;
		int rat=0;
		for (i=1;i<n;i++)
		{
			rat=max(rat,a[i]-a[i+1]);
		}
		//printf("rat=%d\n",rat);
		for (i=1;i<n;i++)
		{
			ans2+=min(rat,a[i]);
		}
		printf("Case #%d: %d %d\n",cas,ans1,ans2);
		
	}
	return 0;
}
