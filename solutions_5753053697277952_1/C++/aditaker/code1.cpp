#include<bits/stdc++.h>
using namespace std;

int main()
{
	int  n,i,j,k,t,max,count,l,r,flag,temp;
	scanf("%d",&t);
	char use[]={'1','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	for(i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		max=-1;
		count=0;flag=0;
		scanf("%d",&n);
		int array[n+1];
		for(j=1;j<=n;j++)
		{
			scanf("%d",&array[j]);
			if(array[j]>max)
				max=array[j];
		}
		while(max!=0)
		{
		count=0;
		flag=0;
		for(j=1;j<=n;j++)
		{
			if(array[j]==max)
			{
				count++;
			}
		}
		if(count%2==0)
		{
			for(k=1;k<=n;k++)
			{
				if(array[k]==max && flag==0)
				{
					l=k;
					flag=1;
				}
				else if(array[k]==max && flag==1)
				{
					printf("%c%c ",use[l],use[k]);
					flag=0;
				}
			}
		}
		else
		{
			for(k=1;k<=n;k++)
			{
				if(array[k]==max)
				{
					printf("%c ",use[k]);
					break;
				}
			}
			
			for(r=k+1;r<=n;r++)
			{
				if(array[r]==max && flag==0)
				{
					l=r;
					flag=1;
				}
				else if(array[r]==max && flag==1)
				{
					printf("%c%c ",use[l],use[r]);
					flag=0;
				}
			}
		}
		for(j=1;j<=n;j++)
		{
			if(array[j]==max)
			{
				array[j]--;
			}
		}
		max--;
		}
		printf("\n");
	}
	return 0;
}
