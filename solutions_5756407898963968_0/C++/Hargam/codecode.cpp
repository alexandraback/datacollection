#include <stdio.h>

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	int tcount,i,j,tests,a1,a2,C1[4],C2[4],same=0,answer,flush,k;
	scanf("%d",&tests);
	for(tcount=0;tcount<tests;tcount++)
	{
		same=0;
		scanf("%d",&a1);
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(i+1==a1)
				{
					scanf("%d",&C1[j]);
				}
				else
				{
					scanf("%d",&flush);
				}
			}
		}
		scanf("%d",&a2);
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(i+1==a2)
				{

						scanf("%d",&C2[j]);
						for(k=0;k<4;k++)
						{
							if(C2[j]==C1[k])
							{
								same++;
								answer=C2[j];
							}
						}

				}
				else
				{
					scanf("%d",&flush);
				}
			}
		}
		if(same==0)
		{
			printf("Case #%d: Volunteer cheated!\n",tcount+1);
		}
		else if(same==1)
		{
			printf("Case #%d: %d\n",tcount+1,answer);
		}
		else
		{
			printf("Case #%d: Bad magician!\n",tcount+1);
		}
	}
    return 0;
}
