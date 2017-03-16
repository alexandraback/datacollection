#include <cstdio>
#include <iostream>
using namespace std;
int a[1001];
int main()
{
	int t, s=0;
	scanf("%d", &t);
	while (t--)
	{
		int b, n;
		scanf("%d%d", &b, &n);
		for (int i=1; i<=b; i++)
		{
			scanf("%d", &a[i]);
		}
		long long l=0, r=1000000000000000ll;
		while (l!=r)
		{
			long long m=(l+r)/2;
			long long sum=0;
			for (int i=1; i<=b; i++)
			{
				sum+=m/a[i]+1;
			}
			if (sum>=(long long)n) r=m;
			else l=m+1;  
		}
		long long sum=0;
		for (int i=1; i<=b; i++)
		{
			sum+=l/a[i]+1;
			if (0==l%a[i]) sum--;
		}
		for (int i=1; i<=b; i++)
		{
			if (0==l%a[i])
			{
				sum++;
				if (sum==n)
				{
					printf("Case #%d: %d\n", ++s, i);
					break;
				}
			}
		}
	}
	return 0;
}