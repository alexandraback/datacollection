#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
int caseNumber,t,ans,n,b,m[1111],a[1111];
int main()
{
	freopen("B-small-attempt2.in","r",stdin);
	freopen("Boutput.txt","w",stdout);
	scanf("%d",&caseNumber);
	for (int i=1;i<=caseNumber;i++)
	{
		scanf("%d%d",&b,&n);
		__int64 Max=0,sum=0;
		for (int j=0;j<b;j++)
		{
			scanf("%d",&m[j]);
			if (m[j]>Max) Max=m[j];
		}
		__int64 r=n*Max/b, l=0, mid=0;
		while (l<=r)
		{
			mid=(l+r)/2;
			sum=0;t=0;
			for (int j=0;j<b;j++)
			{
				sum+=((mid-1)/m[j])+1;
				if (mid%m[j]==0) a[t++]=j;
			}
			if (sum<=(n-1) && sum+t>(n-1)) 
			{
				ans=a[n-sum-1]; break;
			}
			if (sum+t<=n-1) l=mid+1;
			else r=mid-1;
		}
		printf("Case #%d: %d\n",i,ans+1);
	}
//	system("pause");
	return 0;
}
