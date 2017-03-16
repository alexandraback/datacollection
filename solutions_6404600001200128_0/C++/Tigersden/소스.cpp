#include <stdio.h>
int tcase,n,a[1100];
int main()
{
	int loop,i,j,ans,max,rate;
	freopen("A-small-attempt1.in","r",stdin);
	freopen("A-small-attempt1.out","w",stdout);
	scanf("%d",&tcase);
	for(loop=1;loop<=tcase;loop++)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		printf("Case #%d: ",loop);
		ans=0;
		for(i=1;i<n;i++)
		{
			if(a[i+1]<a[i])
				ans+=(a[i]-a[i+1]);
		}
		printf("%d ",ans);
		ans=max=0;
		for(i=1;i<n;i++)
		{
			if(a[i]-a[i+1]>max)
				max=a[i]-a[i+1];
		}
		for(i=1;i<n;i++)
		{
			if(max<a[i])
				ans+=max;
			else
				ans+=a[i];

		}
		printf("%d\n",ans);
	}
	return 0;
}