#include <stdio.h>

int a[1010];
int main(void)
{
	int tt ,ii;
	int n ,i;
	int ans1 ,ans2;
	int max;
	
	scanf("%d" ,&tt);
	for (ii=1 ; ii<=tt ; ii++)
	{
		scanf("%d" ,&n);
		for (i=1 ; i<=n ; i++)	
		{
			scanf("%d" ,&a[i]);	
		}
		ans1=0;
		for (i=1 ; i<n ; i++)
		{
			if (a[i]>a[i+1])
			{
				ans1+=(a[i]-a[i+1]);	
			}
		}
		max=0;
		for (i=1 ; i<n ; i++)
		{
			if (a[i]-a[i+1]>max)	
			{
				max=a[i]-a[i+1];
			}
		}
		ans2=0;
		for (i=1 ; i<n ; i++)
		{
			if (a[i]<=max)	
			{
				ans2+=a[i];
			}
			else
			{
				ans2+=max;
			}
		}
		printf("Case #%d: %d %d\n" ,ii ,ans1 ,ans2);
	}
	
	return 0;
}
