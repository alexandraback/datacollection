#include<stdio.h>
#include<algorithm>
using namespace std;
const int Maxn=100020;
int a[Maxn];
int main()
{
	freopen("A-small-attempt0 .in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int _,cs=1;scanf("%d",&_);
	while(_--)
	{
		int n;scanf("%d",&n);
		int ans1=0;
		int rate=0;
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		for(int i=2;i<=n;i++)
		{
			ans1+=max(0,a[i-1]-a[i]);
			if(a[i-1]>a[i])
			rate=max(rate,a[i-1]-a[i]);
		}
		int ans2=0;
		for(int i=1;i<n;i++)
		{
			ans2+=min(a[i],rate);
		}
		printf("Case #%d: %d %d\n",cs++,ans1,ans2);
	}
}
