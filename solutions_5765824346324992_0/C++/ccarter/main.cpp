#include <iostream>
#include <cstdio>
using namespace std;
 long long div(long long x,int y)
{
	if (x==0)
		return 0;
	else
		return (x-1)/y+1;
}
int main()
{
    int tt,tc;
    scanf("%d",&tt);
    for (tc=1;tc<=tt;tc++)
	{
		int b,n;
		scanf("%d %d",&b,&n);
		int times[1000];
		for (int i=0;i<b;i++)
			scanf("%d",&times[i]);
		long long be=0,ed=100000ll*1000000000ll;
		int ans;
		while (be<=ed)
		{
			long long mid=(be+ed)/2;
			long long serv=0;
			int start=0;
			for (int i=0;i<b;i++)
			{
				serv+=div(mid,times[i]);
				if (mid%times[i]==0)
					start++;
			}
			if (serv<n && serv+start>=n)
			{
				n-=serv;
				for (int i=0;i<b;i++)
				{
					if (mid%times[i]==0)
						n--;
					if (n==0)
					{
						ans=i;
						break;
					}
				}
				break;
			}
			else if (serv<n)
				be=mid+1;
			else
				ed=mid-1;
		}
		printf("Case #%d: %d\n",tc,ans+1);
	}
    return 0;
}
