#include <stdio.h>
int bard[1000000];
int checker[1000000];
int eu(int x,int y)
{
	int temp,cx=x,cy=y;
	if(y>x)
	{
		temp=y;
		y=x;
		x=temp;
	}
	while(x%y)
	{
		x=x%y;
		temp=y;
		y=x;
		x=temp;
	}
	return cx*cy/y;
}
void doe(int x)
{
	checker[0]=0;
	int i,a,b,check=1,i2,ans,max=99999999,maxi,c2=0,lol,k;
	scanf("%d %d",&a,&b);
	for(i=0;i<a;i++)
	{
		scanf("%d",&bard[i]);
		checker[i]=0;
		if(bard[i]<=max)
		{
			max=bard[i];
			maxi=i;
		}
	}
	for(i=0;i<a;i++)
	{
		check=eu(check,bard[i]);
	}
	if(b<=a)
		ans=b;
	else
	{
		
		for(i=0;i<a;i++)
		{
		c2+=check/bard[i];
		}
		b%=c2;
		for(i2=0;i2<a;i2++)
		{
				checker[++checker[0]]=i2;
		}
		for(i=1;i<=check;i++)
		{
			for(i2=0;i2<a;i2++)
			{
				if(i%bard[i2]==0)
				checker[++checker[0]]=i2;
			}
		}
		checker[0]=maxi;
		ans=checker[b]+1;
	}
	printf("Case #%d: %d\n",x,ans);
}
int main()
{
	FILE *fp=freopen("B-small-attempt4.in","r",stdin);
	FILE *fp2=freopen("out2.txt","w",stdout);
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		doe(i);
	}
	return 0;
}
