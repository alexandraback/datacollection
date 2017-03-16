#include <stdio.h>
int have[26];
void doe()
{
	int n,max=0,min=999999,mn,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&have[i]);
	while(1)
	{
		max=0;
		min=999999;
		for(i=1;i<=n;i++)
			if(have[i]>max)
			{
				max=have[i];
				mn=i;
			}
		for(i=1;i<=n;i++)
			if(have[i]<min)
			{
				min=have[i];
			}
		if(max==min)
			break;
		have[mn]--;
		printf("%c ",mn+64);
	}
	if(max!=0)
	{
		if(n%2==0)
		{
			for(i=1;i<=max;i++)
			{
				for(int i2=1;i2<=n;i2+=2)
					printf("%c%c ",i2+64,i2+65);
			}
		}
		else
		{
			for(i=1;i<=max;i++)
			{
				printf("%c ",n+64);
				for(int i2=1;i2<n;i2+=2)
					printf("%c%c ",i2+64,i2+65);
			}
		}
	}
	printf("\n");
}
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		printf("Case #%d: ",i),doe();
	return 0;
}
