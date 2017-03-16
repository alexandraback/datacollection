#include <stdio.h>
int main()
{
	int dp1[5][5];
	int dp2[5][5];
	int c=1,t,i,j,f,res,ans1,ans2,count;
	scanf("%d",&t);
	while(c<=t)
	{

		scanf("%d",&ans1);
		for (i = 0; i <= 3; ++i)
		{
			for (j = 0; j <= 3 ; ++j)
			{
				scanf("%d",&dp1[i][j]);
			}
		}

		scanf("%d",&ans2);
		for (i = 0; i <= 3; ++i)
		{
			for (j = 0; j <= 3 ; ++j)
			{
				scanf("%d",&dp2[i][j]);
			}
		}


		res=-1;
		count=0;
		ans1--;
		ans2--;
		for (i = 0; i <= 3; ++i)
		{
			for (j = 0; j <= 3; ++j)
			{
				if(dp1[ans1][i]==dp2[ans2][j])
				{
					res=dp1[ans1][i];
					count++;
				}
			}

		}
		if(res==-1)
		{
			printf("Case #%d: Volunteer cheated!\n",c);
		}
		else if(count>1)
		{
			printf("Case #%d: Bad magician!\n",c);
		}
		else
		{
			printf("Case #%d: %d\n",c,res);			
		}
		c++;
	}
	return 0;
}