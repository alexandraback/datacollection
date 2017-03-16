#include<stdio.h>
int arr[1005];
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int a=1;a<=t;a++)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		int x=0,y=0,max=0;
		for(int i=1;i<n;i++)
			if(arr[i-1]>arr[i])
			{
				if(max<arr[i-1]-arr[i])
					max = arr[i-1]-arr[i];
				x+=arr[i-1]-arr[i];
			}
		for(int i=0;i<n-1;i++)
			if(arr[i]<=max)
				y+=arr[i];
			else if(arr[i]>max)
				y+=max;
		printf("Case #%d: %d %d\n",a,x,y);
	}
}
