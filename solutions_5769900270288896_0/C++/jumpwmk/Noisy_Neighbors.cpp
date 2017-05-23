#include <stdio.h>

using namespace std;

int x[20][20];
int r,c,n,min;

void play(int i,int j,int state)
{
	if(i==r+1)
	{
		// for(i=1;i<=r;i++)
		// {
		// 	for(j=1;j<=c;j++)
		// 	{
		// 		printf("%d ",x[i][j]);
		// 	}
		// 	printf("\n");
		// }
		if(state < n)
			return;
		int cnt=0;
		for(i=1;i<=r;i++)
		{
			for(j=1;j<=c;j++)
			{
				if(x[i][j]&&x[i+1][j])
					cnt++;
				if(x[i][j]&&x[i][j+1])
					cnt++;
			}
		}
		if(cnt<min)
			min=cnt;
		return;
	}
	x[i][j]=1;
	// printf("%d %d\n",i,j);
	if(j<c)
		play(i,j+1,state+1);
	else play(i+1,1,state+1);
	x[i][j]=0;
	if(j<c)
		play(i,j+1,state);
	else play(i+1,1,state);
}

int main()
{
	int q,k;
	// freopen("test.in","r",stdin);
	// freopen("test.out","w",stdout);
	scanf("%d",&q);
	for(k=1;k<=q;k++)
	{
		scanf("%d %d %d",&r,&c,&n);
		min=1000000;
		play(1,1,0);
		printf("Case #%d: %d\n",k,min);
	}
	return 0;
}