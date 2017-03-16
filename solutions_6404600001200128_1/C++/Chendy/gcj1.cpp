#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#define LL long long 
using namespace std;
int n,m,cnt,B,head;
int a[1010];
void work(int lab)
{
	printf("Case #%d: ",lab);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int ans=0,ans2=0;
	for (int i=1;i<n;i++) if (a[i]>=a[i+1]) ans+=a[i]-a[i+1];
	int maxn=0;
	for (int i=1;i<n;i++) maxn=max(maxn,a[i]-a[i+1]);
	for (int i=2;i<=n;i++) 
	{
		ans2+=min(a[i-1],maxn);
	}
	printf("%d %d\n",ans,ans2);
}
int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int t;
	scanf("%d\n",&t);
	for (int i=1;i<=t;i++)work(i);
	return 0;
}
