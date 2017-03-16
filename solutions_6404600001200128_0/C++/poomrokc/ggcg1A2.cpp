#include <stdio.h>
int arr[1005];
void doe(int x)
{
	int a,i,ans=0,max=0,ans2=0;
	scanf("%d",&a);
	for(i=1;i<=a;i++)
	{
		scanf("%d",&arr[i]);
		if(arr[i]<arr[i-1])
			ans+=arr[i-1]-arr[i];
		if(arr[i-1]-arr[i]>max)
			max=arr[i-1]-arr[i];
	}
	for(i=1;i<a;i++)
	{
		if(arr[i]<=max)
			ans2+=arr[i];
		else
			ans2+=max;
	}
	printf("Case #%d: %d %d\n",x,ans,ans2);
}
int main()
{
	FILE *fp=freopen("A-small-attempt0.in","r",stdin);
	FILE *fp2=freopen("out1.txt","w",stdout);
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		doe(i);
	}
	return 0;
}
