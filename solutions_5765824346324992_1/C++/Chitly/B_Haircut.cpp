#include<stdio.h>
long long arr[1005];
int n;
long long bsearch(long long st,long long lt,long long k)
{
	long long md = st+(lt-st)/2;
	long long count=0;
	for(int i=0;i<n;i++)
		count+=md/arr[i];
//	printf("ch -> %lld %lld %lld -> %lld\n",st,lt,md,count);
	if(count>k)
	{
		if(st<md-1)
			return bsearch(st,md-1,k);
		else
			return md-1;
	}
	else if(count<k)
	{
		if(lt-md==1)
			return md;
		if(md<lt)
			return bsearch(md,lt,k);
		else 
			return lt;
			
	}
	else
		return md;
}
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int a=1;a<=t;a++)
	{
		long long k;
		scanf("%d%lld",&n,&k);
		for(int i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		if(k<=n)
		{
			printf("Case #%d: %lld\n",a,k);
			continue;
		}
		else
			k-=n;
		long long max = 1;
		max = max<<53-1;
//		printf("k=%lld\n",k);
		long long t = bsearch(1,max,k);
//		printf("t=%lld\n",t);
		for(int i=0;i<n;i++)
			k-=t/arr[i];
		if(k==0)
		{
			while(true)
			{
				bool ch=0;
				for(int i=n-1;i>=0;i--)
					if(t%arr[i]==0)
					{
						printf("Case #%d: %d\n",a,i+1);
						ch=1;
						break;
					}
				if(ch)
					break;
				t--;
			}
			continue;
		}
		if(k<0)
		{
			printf("error\n");
			continue;
		}
		bool ch=1;
		while(ch)
		{
			t++;
			for(int i=0;i<n;i++)
			{
				if(t%arr[i]==0)	k--;
				if(k==0)
				{
					printf("Case #%d: %d\n",a,i+1);
					ch=0;
					break;
				}
			}
		}
	}
}
