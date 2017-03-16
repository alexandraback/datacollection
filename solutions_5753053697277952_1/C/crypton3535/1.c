#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp =fopen("a.in","r");
	FILE *f =fopen("b.txt","w");
	long long int k,diff,i,n,test,arr[1005],sum,max,max_index;
	fscanf(fp,"%lld",&test);
	for(k=1;k<=test;k++)
	{
	sum=0;
	fprintf(f,"Case #%lld: ",k);
	fscanf(fp,"%lld",&n);
	for(i=0;i<n;i++)
	{
	fscanf(fp,"%lld",&arr[i]);
	sum+=arr[i];
	}
	if(n==2)
	{
		diff=arr[0]-arr[1];
		if(diff>0)
		{
			for(i=0;i<diff;i++)
			{
				fprintf(f,"A ");
			}
			arr[0]=arr[1];
		}
		else if(diff<0)
		{
			for(i=0;i<diff;i++)
			{
				fprintf(f,"B ");
			}
			arr[1]=arr[0];
		}
		for(i=0;i<arr[1];i++)
		{
			fprintf(f,"AB ");
		}
		fprintf(f,"\n");
		continue;

	}
	while(1){
	max=-1;
	max_index=-1;
	for(i=0;i<n;i++)
	{
	if(arr[i]>max)
	{
	max=arr[i];
	max_index=i;
	}
	}
	if(max_index==-1)
	{
	break;
	}
	fprintf(f,"%c ",max_index+65);
	arr[max_index]--;
	sum--;
	if(sum==2)
	{
	for(i=0;i<n;i++)
	{
	if(arr[i]!=0)
	{
	fprintf(f,"%c",i+65);
	}
	}
	fprintf(f,"\n");
	break;
	}
	}
	}
	return 0;
}