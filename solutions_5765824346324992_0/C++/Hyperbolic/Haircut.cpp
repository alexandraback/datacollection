#include <stdio.h>
void solve(int);
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) solve(i);
}
int x[1010];
void solve(int T)
{
	int a,b,i;
	long long int h,min,max,count,sum,ans;
	scanf("%d%d",&a,&b);
	for(i=1;i<=a;i++) scanf("%d",&x[i]);
	min=0,max=(long long int)b*100000;
	while(min<=max)
	{
		sum=0;
		h=(min+max)/2;
		for(i=1;i<=a;i++)
		{
			sum+=h/x[i]+1;
		}
		if(sum>=b)
		{
			ans=h;
			max=h-1;
		}
		else min=h+1;
	}
	sum=0;
	for(i=1;i<=a;i++)
	{
		sum+=(ans-1)/x[i]+1;
	}
	count=b-sum;
	for(i=1;i<=a;i++)
	{
		if(ans%x[i]==0)
		{
			if(count==1)
			{
				printf("Case #%d: %d\n",T,i);
				return;
			}
			else count--;
		}
	}
}
