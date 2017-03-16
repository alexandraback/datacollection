#include <stdio.h>

long long a[1010];
int main(void)
{
	int tt ,ii;
	int b ,i;
	long long n;
	long long p1 ,p2 ,p12;
	long long sum;
	int ans;
	
	scanf("%d" ,&tt);
	for (ii=1 ; ii<=tt ; ii++)
	{
		scanf("%d %I64d" ,&b ,&n);
		n-=b;
		for (i=1 ; i<=b ; i++)
		{
			scanf("%I64d" ,&a[i]);
		}
		p1=0;
		p2=200000;
		p2*=1000000000;
		while (p1<p2)
		{
			p12=(p1+p2)/2;
			sum=0;
			for (i=1 ; i<=b ; i++)
			{
				sum+=p12/(a[i]);
			}
			if (sum>=n)
			{
				p2=p12;
			}
			else
			{
				p1=p12+1;
			}
		}
		sum=0;
		for (i=1 ; i<=b ; i++)
		{
			sum+=p1/(a[i]);
		}
		for (i=1 ; i<=b ; i++)
		{
			if (p1%a[i]!=0)
			{
				sum++;	
			}
		}					
		for (i=1 ; i<=b ; i++)
		{
			if (p1%a[i]==0)	
			{
				sum++;
				if (sum==b+n)
				{
					break;	
				}
			}
		}
		ans=i;
		printf("Case #%d: %d\n" ,ii ,ans);
	}
	
	return 0;
}
