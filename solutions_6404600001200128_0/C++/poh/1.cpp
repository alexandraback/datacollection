#include<stdio.h>
int a[1005];
int main()
{
	FILE* fp=freopen("input.txt","r",stdin);
	FILE* fp2=freopen("output.txt","w",stdout);
	int i,j,n,t,ans=0,max=0,sum=0;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		ans=0;
		max=0;
		sum=0;
		scanf("%d",&n);
		for(j=0;j<n;j++)
			scanf("%d",&a[j]);
		for(j=1;j<n;j++)
			if(a[j]<a[j-1])
			{
				ans+=a[j-1]-a[j];
				if(a[j-1]-a[j]>max)
					max=a[j-1]-a[j];
			}
		for(j=0;j<n-1;j++)
			if(a[j]<=max)
				sum+=a[j];
			else
				sum+=max;
		printf("Case #%d: %d %d\n",i+1,ans,sum);
	}
	scanf(" ");
}

