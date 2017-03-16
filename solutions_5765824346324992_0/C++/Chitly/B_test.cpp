#include<stdio.h>
int arr[1005];
int gcd(int a,int b)
{
	if(a%b==0)
		return b;
	return gcd(b,a%b);
}
int main()
{
	freopen("B-small-attempt3.in","r",stdin);
	freopen("B-small-attempt3.test","w",stdout);
	int t;
	scanf("%d",&t);
	for(int a=1;a<=t;a++)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		if(k<=n)
		{
			printf("Case #%d: %d\n",a,k);
			continue;
		}
		else
			k-=n;
		
		int gd=arr[0];
		for(int i=1;i<n;i++)
			gd=gcd(gd,arr[i]);
		int lm=gd;
		for(int i=0;i<n;i++)
			lm*=arr[i]/gd;
		int x=0;
		for(int i=0;i<n;i++)
			x+=lm/arr[i];
		
//		printf("k=%d x=%d lm=%d\n",k,x,lm);
		long long t=(long long)k/(long long)x*(long long)lm;
		k%=x;
		if(k==0)
		{
			printf("Case #%d: %d\n",a,n);
			continue;
		}
		
		
		for(int i=1;k;i++)
		{	
			bool ch=0;
			for(int j=0;j<n;j++)
			{
				if(i%arr[j]==0)
					k--;
				if(k==0)
				{
//					printf("t=%lld\n",t+i);
					printf("Case #%d: %d\n",a,j+1);
					ch=1;
					break;
				}
			}
			if(ch)
				break;
		}
	}
}
