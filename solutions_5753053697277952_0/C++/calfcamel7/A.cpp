#include <stdio.h>
int a[100];
int n;
int hefa()
{
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += a[i];
	for(int i = 0; i < n; i++)
		if(a[i] * 2 > sum)
			return false;
	return true;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int cas = 1; cas <= T; cas++)
	{
		printf("Case #%d:", cas);
		scanf("%d",&n);
		for(int i = 0; i < n; i++)
			scanf("%d",&a[i]);
		int sum = 0;
		for(int i = 0; i < n; i++)
			sum += a[i];
		while(sum > 0)
		{
			int maxi = 0;
			int maxv = a[0];
			for(int i = 1; i < n; i++)
				if(a[i] > maxv)
				{
					maxv = a[i];
					maxi = i;
				}
			a[maxi]--;
			sum--;
			if(hefa())printf(" %c", 'A' + maxi);
			else
			{
				char ch = 'A' + maxi;
				maxi = 0;
				maxv = a[0];
				for(int i = 1; i < n; i++)
					if(a[i] > maxv)
					{
						maxv = a[i];
						maxi = i;
					}
				a[maxi]--;
				sum--;
				printf(" %c%c", ch, 'A' + maxi);
			}
		}
		printf("\n");
	}
}