#include<stdio.h>
#include<stdlib.h>
int main()
{
	int T;scanf("%d",&T);
	for(int lT = 1;lT <= T;lT++)
	{
		int row1;scanf("%d",&row1);
		int line1[4];
		for(int lx = 0;lx < 4;lx++)
		{
			for(int ly = 0;ly < 4;ly++)
			{
				int inp;scanf("%d",&inp);
				if(lx == row1-1)line1[ly] = inp;
			}
		}
		int row2;scanf("%d",&row2);
		int line2[4];
		for(int lx = 0;lx < 4;lx++)
		{
			for(int ly = 0;ly < 4;ly++)
			{
				int inp;scanf("%d",&inp);
				if(lx == row2-1)line2[ly] = inp;
			}
		}
		// Cross Compare:
		int cnt = 0; int ans = 0;
		for(int lr1 = 0;lr1 < 4;lr1++)
		for(int lr2 = 0;lr2 < 4;lr2++)
		{
			if(line1[lr1] == line2[lr2])
			{
				ans = line1[lr1];
				cnt++;
			}
		}
		if(cnt == 0)
			printf("Case #%d: Volunteer cheated!\n",lT);
		else if(cnt == 1)
			printf("Case #%d: %d\n",lT,ans);
		else
			printf("Case #%d: Bad magician!\n",lT);

	}
	return 0;
}
