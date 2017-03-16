#include<iostream>
#include<cstdio>
using namespace std;
int no(int x)
	{
	int c=0;
	while(x)
		{
		if(x%2==1)
			c++;
		x/=2;	
		}
	return c;
	}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

int t,i,j,k;
int T;
int R,C,N;
scanf("%d",&T);
for(t=1;t<=T;t++)
	{
	scanf("%d %d %d",&R,&C,&N);
	int c=1<<(R*C);
	//printf("%d\n",c);
	int ans=1<<30;
	int count;
	for(k=0;k<c;k++)
		{
//		printf("%d %d\n",k,no(k));	
		if(no(k)!=N)
			{
			continue;
			}
		int p=k;
		
		int build[18][18]={0};
		for(i=1;i<=R;i++)
			{
			for(j=1;j<=C;j++)
				{
				build[i][j]=p%2;
				p/=2;
				}
			}
		count=0;
		for(i=1;i<=R;i++)
			{
			for(j=1;j<=C;j++)
				{
				if(build[i][j]==1)
				count+=build[i+1][j]+build[i-1][j]+build[i][j-1]+build[i][j+1];
			//	printf("%d\n",count);
				}
			}
		if(count%2)
			{
//			for(i=1;i<=R;i++)
//				{
//				for(j=1;j<=C;j++)
//					{
//					printf("%d ",build[i][j]);
//					}
//				printf("\n");
//				}
//			printf("%d %d\n",count,k);
			return 1;
			}
		count/=2;
		ans=min(ans,count);
		}
	printf("Case #%d: %d\n",t,ans);
	}
return 0; 
}
