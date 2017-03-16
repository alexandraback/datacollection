#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int get(int b[],int i,int n)
{
	int j,count=0;
	for(j=0;j<n;j++)
		b[j]=0;
	j=0;
	while(i!=0)
	{
		b[j++]=i%2;
		i/=2;
	}
	for(j=0;j<n;j++)
		count+=b[j];
	return count;
}
void fill(int a[][16],int b[],int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			a[i][j]=b[(j+i*c)];
	}
}
int countH(int a[][16],int r,int c)
{
	int i,j,count=0;
	for(i=0;i<r-1;i++)
	{
		for(j=0;j<c-1;j++)
		{
			if(a[i][j])
			{
				if(a[i][j+1])
					count++;
				if(a[i+1][j])
					count++;
			}
		}
	}
	for(i=0;i<r-1;i++)
		if(a[i][c-1])
			{
				if(a[i+1][c-1])
					count++;
			}
	for(i=0;i<c-1;i++)
		if(a[r-1][i])
			{
				if(a[r-1][i+1])
					count++;
			}
	return count;
}
int main()
{
	long long t,T,n,i,r,c,count,min,countF;
	FILE * fr=fopen("B-small-attempt0.in","r");
	FILE * fw=fopen("B.out","w");
	fscanf(fr,"%lld",&t);
	T=t;
	int a[16][16],b[16];
	while(t--)
	{
		fscanf(fr,"%lld %lld %lld",&r,&c,&n);
		min=1111111;
		i=0;
		while(i<pow(2,(r*c)))
		{
			countF=get(b,i,r*c);
			if(countF==n)
			{
				fill(a,b,r,c);
				count=countH(a,r,c);
				if(count<min)
					min=count;
			}
			i++;
		}
		fprintf(fw, "Case #%lld: %lld\n",(T-t),min);
	}
	fclose(fr);
	fclose(fw);
}