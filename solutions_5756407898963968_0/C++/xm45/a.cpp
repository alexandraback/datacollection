#include<stdio.h>
#include<stdlib.h>
int T;
void rd(int *h)
{
	int i=0,j=0,k=0,l=0;
	scanf("%d",&k);
	for(i=1;i<=4;i++)
		for(j=1;j<=4;j++)
		{
			scanf("%d",&l);
			h[l]+=(i==k);	
		}
}
void work()
{
	int h[17]={0};
	rd(h);
	rd(h);
	int i=0;
	int cnt=0;
	int ans=0;
	for(i=1;i<=16;i++)
		if(h[i]==2)
		{
			cnt++;
			ans=i;
		}
	switch(cnt)
	{
		case(0):
			printf("Volunteer cheated!");
			break;	
		case(1):
			printf("%d",ans);
			break;
		default:
			printf("Bad magician!");
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int i=0;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		printf("Case #%d: ",i);
		work();
		printf("\n");
	}
}
