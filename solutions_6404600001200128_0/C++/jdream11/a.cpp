#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int ans1,ans2,n,Testcase,rate,a[1024];
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&Testcase);
	for(int t=1;t<=Testcase;t++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		ans1=ans2=0;rate=0;
		for(int i=2;i<=n;i++)
			if(a[i]<a[i-1])
			{
				ans1+=a[i-1]-a[i];
				rate=max(rate,a[i-1]-a[i]);
			}
		for(int i=2;i<=n;i++)
			if(a[i-1]<rate)
				ans2+=a[i-1];
			else ans2+=rate;
		printf("Case #%d: %d %d\n",t,ans1,ans2);
	}
}