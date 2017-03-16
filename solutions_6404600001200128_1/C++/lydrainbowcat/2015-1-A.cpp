#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<queue>

using namespace std;

int a[1010];
int T;

int main()
{
	scanf("%d",&T);
	for (int test=1;test<=T;test++)
	{
		int n,r1=0,r2=0,p2=0,last=0;
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d",a+i);
		for (int i=1;i<n;i++)
			if (a[i]<a[i-1])
				r1+=a[i-1]-a[i];
		for (int i=1;i<n;i++)
			p2=max(p2,a[i-1]-a[i]);
		for (int i=0;i<n-1;i++)
			r2+=min(a[i],p2);
		printf("Case #%d: ",test);
		printf("%d %d\n", r1,r2);
	}
	return 0;
}