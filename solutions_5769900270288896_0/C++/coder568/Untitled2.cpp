#include<stdio.h>
#include<stdlib.h>
long long int n,m,k,min,ar[2000][2000];
void dig()
{
	long long int i,j,ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m-1;j++)
		{
			if(ar[i][j]==1&&ar[i][j+1]==1)
			ans++;
		}
	}
	for(j=1;j<=m;j++)
	{
		for(i=1;i<=n-1;i++)
		{
			if(ar[i][j]==1&&ar[i+1][j]==1)
			ans++;
		}
	}
	if(ans<min)
	min=ans;
}
void value(long long int r,long long int c,long long int ans)
{
	long long int i,j;
	if(ans==k)
	dig();
    if(ans<k)
	{
		if(c<=m)
		{
			ar[r][c]=1;
			value(r,c+1,ans+1);
			ar[r][c]=0;
			value(r,c+1,ans);
		}
		else
		{
			if(r<n)
			{
				ar[r+1][1]=1;
				value(r+1,2,ans+1);
				ar[r+1][1]=0;
				value(r+1,2,ans);
			}
		}
	}
}
int main()
{
    long long int i,j,l,p,q,t;
	FILE *fi,*fo;
	fo=fopen("test.txt", "w+");
	fi=fopen("abc.txt","r");
	fscanf(fi,"%lld",&t);
	for(q=0;q<t;q++)
	{
		fscanf(fi,"%lld%lld%lld",&n,&m,&k);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			ar[i][j]=0;
		}
		min=10000010;
		value(1,1,0);
		fprintf(fo,"Case #%lld: %lld\n",q+1,min);
	}
	//system(pause);
	return 0;
}
	
