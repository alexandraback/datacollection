#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define LL long long
using namespace std;
int T,n,a[1005];
int main()
{
    freopen("t.in","r",stdin);freopen("t.out","w",stdout);
	cin>>T;
	for (int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		LL ans1=0,ans2=0;
		double ma=0.0;
		for (int i=2;i<=n;i++)
			if (a[i]<a[i-1]) 
			{
				ans1+=a[i-1]-a[i];
				ma=max(ma,(double)(a[i-1]-a[i])/10);
			}
		for (int i=1;i<n;i++)
			if (a[i])
			{
				if ((int)(ma*10)>=a[i]) ans2+=a[i];
				else ans2+=(int)(ma*10);
			}
		printf("%lld %lld\n",ans1,ans2);
	}
	return 0;
}
