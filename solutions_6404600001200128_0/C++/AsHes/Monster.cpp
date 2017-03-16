#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t,n,ind=0,flag;
	long long int r1=0,r2=0,hi,low,mid,ans,tot,a[1010];
	scanf("%d",&t);
	while(t--)
	{
		ind++;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		r1=0;
		r2=0;
		for(int i=1;i<n;i++)
		{
			if(a[i]<a[i-1])
			{
				r1+=a[i-1]-a[i];
			}
		}
		/*hi=10010;
		low=0;
		while(low<=hi)
		{
			mid=(low+hi)/2;
			tot=a[0];
			flag=0;
			//if(mid==1)  printf("here\n");
			for(int i=1;i<n;i++)
			{
				if(tot-mid*10<=a[i])
				{
				    ;
					//tot=a[i];
					//tot=max(0LL,tot-mid*10);
				}
				else
				{
				    //printf("tot=%lld %d %lld %d\n",tot,i,tot-mid*10,a[i]);
					flag=1;
					break;
				}
				tot=a[i];
			}
			if(flag)
			{
				low=mid+1;
			}
			else
			{
				ans=mid;
				hi=mid-1;
			}
		}
		tot=a[0];
		printf("%lld\n",ans);*/
		long long int maxi=0;
		for(int i=1;i<n;i++)
		{
		    maxi=max(maxi,a[i-1]-a[i]);
		}
		tot=a[0];
		for(int i=1;i<n;i++)
		{
			if(tot-maxi<=0)
			{
				r2+=tot;
				//tot=0;
			}
			else
			{
				r2+=maxi;
				//tot-=ans*10;
			}
			tot=a[i];
		}/*
		for(int i=1;i<n;i++)
		{
			if(tot-ans*10<=0)
			{
				r2+=tot;
				//tot=0;
			}
			else
			{
				r2+=ans*10;
				//tot-=ans*10;
			}
			tot=a[i];
		}*/
		printf("Case #%d: %lld %lld\n",ind,r1,r2);
	}
	return 0;
}
