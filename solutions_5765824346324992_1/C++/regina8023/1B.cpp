#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#define LL long long
using namespace std;
int m[1005],n,b,T;
LL Calc(LL k)
{
	LL ans=0;
	for (int i=1;i<=b;i++)
	{
		ans=ans+(k+m[i]-1)/m[i];
	}
	return ans;
}
int main()
{
    freopen("t.in","r",stdin);freopen("t.out","w",stdout);
	cin>>T;
	for (int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		cin>>b>>n;
		for (int i=1;i<=b;i++)
			scanf("%d",&m[i]);
		if (n==1)
		{
			printf("1\n");
			continue;
		}
		int ans=0,mi=10000000;
		LL l=0,r=1e15;
		while (l<=r)
		{
			LL mid=(l+r)>>1LL;
			LL k=Calc(mid);
			if (k==n-1)
			{
				for (int i=1;i<=b;i++)
				{
					int x=(mid+m[i]-1)/m[i];
					int w=(1LL*x*m[i])-mid;
					if (w<mi) mi=w,ans=i;
				}
				break;
			}
			if (k>n-1) r=mid-1;
			else l=mid+1;
		}
		if (!ans)
		{
			int x=Calc(r);
			for (int i=1;i<=b;i++)
			{
				if (r%m[i]==0) x++;
				if (x==n) 
				{
					ans=i;break;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
