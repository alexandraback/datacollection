#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;
int T,n,ans1,ans2,rate;
int a[1012];
int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&T);
	for(int t = 1;t <= T; ++ t)
	{
		rate = 0;
		ans1 = 0;
		ans2 = 0;
		scanf("%d",&n);
		for(int i = 1;i <= n; ++ i)
			scanf("%d",&a[i]);
		for(int i = 1;i < n; ++ i)
			if (a[i] > a[i + 1])
				ans1 += a[i] - a[i + 1];
		for(int i = 1;i < n; ++ i)
		if (a[i] > a[i + 1])
			rate =  max(rate,a[i] - a[i + 1]);
		for(int i = 1;i < n; ++ i)
		if (a[i] < rate)
			ans2 += a[i];
		else
			ans2 += rate;
		
		printf("Case #%d: %d %d\n",t,ans1,ans2);
	}
}