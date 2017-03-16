#include<stdio.h>

long long int n,m,k,min,a[1006][1008];

void fn2()
{
	long long int c,i,j;
	c=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m-1;j++)
		{
			if(a[i][j]==1 && a[i][j+1]==1)
			c++;
		}
	}
	for(j=1;j<=m;j++)
	{
		for(i=1;i<=n-1;i++)
		{
			if(a[i][j]==1 && a[i+1][j]==1)
			c++;
		}
	}
	if(c<min)
	min=c;
}


void fn(long long int x,long long int y,long long int c)
{
	long long int i,j;
	if(c==k)
	{
		/*for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			printf("%lld ",a[i][j]);
			printf("\n");
		}
		printf("\n");*/
		fn2();
	}
	if(c<k)
	{
		if(y<=m)
		{
			a[x][y]=1;
			fn(x,y+1,c+1);
			a[x][y]=0;
			fn(x,y+1,c);
		}
		else
		{
			if(x<n)
			{
				a[x+1][1]=1;
				fn(x+1,2,c+1);
				a[x+1][1]=0;
				fn(x+1,2,c);
			}
		}
	}
}
		

int main()
{
	freopen("abc.txt","r",stdin);
	freopen("test.txt","w",stdout);
	long long int f,f1,i,j;
	scanf("%lld",&f);
	for(f1=1;f1<=f;f1++)
	{
		scanf("%lld %lld %lld",&n,&m,&k);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			a[i][j]=0;
		}
		min=10000006;
		fn(1,1,0);
		printf("Case #%lld: %lld\n",f1,min);
	}
	return 0;
}
	
