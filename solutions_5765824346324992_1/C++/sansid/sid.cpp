#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

long long int a[1000006],n;

long long int fn(long long int x,long long int k)
{
	long long int sum=0,i;
	for(i=1;i<=n;i++)
	{
		sum=sum+1+(x-1)/a[i];
	}
	if(sum>=k)
	return 1;
	return 0;
}

long long int fn2(long long int x,long long int k)
{
	long long int sum=0,i,y;
	y=x;
	for(i=1;i<=n;i++)
	{
		sum=sum+1+(x-2)/a[i];
	}
	//printf("aa %lld %lld\n",x,sum);
	k=k-sum;
	for(i=1;i<=n;i++)
	{
		if((y-1)%a[i]==0)
		k--;
		if(k<=0)
		return i;
	}
}

int main()
{
	freopen("abc.txt","r",stdin);
	freopen("test.txt","w",stdout);
	long long int f,f1,i,x,y,m,k,ans,l,r;
	scanf("%lld",&f);
	for(f1=1;f1<=f;f1++)
	{
		scanf("%lld %lld",&n,&k);
		for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
		if(k<=n)
		{
			ans=k;
		}
		else
		{
			l=1;r=1000000000000000006;
			while(1)
			{
				//printf("%lld %lld\n",l,r);
				if(fn(l,k)==0 && fn(l+1,k)==1)
				{
					ans=fn2(l+1,k);
					break;
				}
				m=(l+r)/2;
				if(fn(m,k)==1)
				r=m;
				else
				l=m;
			}
		}
		printf("Case #%lld: %lld\n",f1,ans);
	}
	return 0;
}
	
