#include <stdio.h>

#define TEST_NUM 3

char inname[100];
char outname[100];

int arr[1000];

void process()
{
	int b,n,i;
	long long s,g,x,p,r;
	scanf("%d%d",&b,&n);
	for(i=0;i<b;i++)
		scanf("%d",&arr[i]);
	if(n<=b)
	{
		printf("%d",n);
		return;
	}
	s=0;
	g=100000000000000LL;
	while(s<g)
	{
		x=(s+g+1)/2;
		p=0;
		for(i=0;i<b;i++)
			p+=(x-1)/arr[i]+1;
		if(n<=p)
			g=x-1;
		else
			s=x;
	}
	r=0;
	for(i=0;i<b;i++)
		r+=(s-1)/arr[i]+1;
	for(i=0;i<b;i++)
	{
		if(s%arr[i]==0)
			r++;
		if(n==r)
		{
			printf("%d",i+1);
			return;
		}
	}
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