#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;
LL l,r,mid,n;
int m,a[1024],Testcase;
bool check(LL mid)
{
	LL ans=0;
	for(int i=1;i<=m;i++)
		ans+=(mid-1)/a[i]+1;
	if(ans<n)return 1;
	return 0;
}
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&Testcase);
	for(int t=1;t<=Testcase;t++)
	{
		scanf("%d%I64d",&m,&n);
		int  max_a=0;
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&a[i]);
			max_a=max(max_a,a[i]);
		}
		if(n<=m)
		{
			printf("Case #%d: %d\n",t,n);
			continue;
		}
		l=1;r=n*max_a+1;
		while(l<r)
		{
			mid=(l+r)/2;
			if(check(mid))l=mid+1;
			else r=mid;
		}
		r=r-1;
		LL ans=0;
		for(int i=1;i<=m;i++)
			ans+=(r-1)/a[i]+1;
		n-=ans;
		for(int i=1;i<=m;i++)
			if(r%a[i]==0)
			{
				n--;
				if(n==0)
				{
					printf("Case #%d: %d\n",t,i);
					break;
				}
			}
	}
}