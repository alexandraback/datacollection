#include<bits/stdc++.h>

using namespace std;

long long int n,m[1010];
int b;
long long int solve()
{
	long long int x,hi,low,h,l,y,tot,num,ans=b-1,a1,a2;
	int flag=0;
	low=0;
	hi=b-1;
	//printf("here\n");
	for(int j=0;j<b;j++)
	{
		x=j;
		h=1000000001;
		l=1;
		flag=0;
		while(l<=h)
		{
			y=(l+h)/2;
			tot=(m[x]*(y-1));
			num=0;
			for(int i=0;i<b;i++)
			{
				num+=tot/m[i];
				if(tot%m[i]!=0)	num++;
				else
				{
				    if(i<x) num++;
				}
			}
			if(num>n-1)
			{
				h=y-1;
			}
			else if(num<n-1)
			{
				l=y+1;
			}
			else
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			ans=j;
		}
	}
	ans++;
	return ans;
}
int main()
{
	int t,ind=0;
	long long int ans;
	scanf("%d",&t);
	while(t--)
	{
		ind++;
		scanf("%d%lld",&b,&n);
		for(int i=0;i<b;i++)
		{
			scanf("%lld",&m[i]);
		}
		ans=solve();
		printf("Case #%d: %lld\n",ind,ans);;
	}
}
