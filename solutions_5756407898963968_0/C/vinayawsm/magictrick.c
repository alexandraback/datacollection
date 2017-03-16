#include <stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	int turn=1;
	while(turn<=t)
	{
		int a;
		scanf("%d",&a);
		int am[4][4];
		int i=0,j=0;
		for(;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				scanf("%d",&am[i][j]);
			}
		}
		int b;
		scanf("%d",&b);
		int bm[4][4];
		i=0;j=0;
		for(;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				scanf("%d",&bm[i][j]);
			}
		}
		int a1=0,ans=0,count=0;
		i=0;j=0;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if(am[a-1][i]==bm[b-1][j])
				{
					count++;
					ans=bm[b-1][j];
				}
			}
		}
		if(count==1)
		{
			printf("Case #%d: %d\n",turn,ans );
		}
		else if(count==0)
		{
			printf("Case #%d: Volunteer cheated!\n",turn );
		}
		else if(count>1)
		{
			printf("Case #%d: Bad magician!\n",turn );
		}

	turn++;
	}
}