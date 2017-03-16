#include <stdio.h>

#define TEST_NUM 1

char inname[100];
char outname[100];

int arr[1000];

void process()
{
	int n,r=0,d=0,s=0,t,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=1;i<n;i++)
		if(arr[i-1]>arr[i])
			r+=arr[i-1]-arr[i];
	printf("%d ",r);
	for(i=1;i<n;i++)
	{
		t=arr[i-1]-arr[i];
		d=t>d?t:d;
	}
	for(i=0;i<n-1;i++)
		s+=d<arr[i]?d:arr[i];
	printf("%d",s);
}

void pre_process()
{
}

int main()
{
	sprintf(inname,"%d.in",TEST_NUM);
	sprintf(outname,"%d.out",TEST_NUM);
	freopen(inname,"r",stdin);
	freopen(outname,"w",stdout);
	int tn,ti;
	scanf("%d",&tn);
	pre_process();
	for(ti=1;ti<=tn;ti++)
	{
		printf("Case #%d: ",ti);
		process();
		printf("\n");
	}
	return 0;
}