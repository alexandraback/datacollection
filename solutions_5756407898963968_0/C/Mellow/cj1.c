#include<stdio.h>
int main()
{
	FILE* fp = 0;
	if(0 == ( fp = freopen("cj1.in", "w" ,stdout)))
   		 printf("Cannot open file.\n");
	int T = 0;
	scanf("%d",&T);
	for(int cT = 0; cT < T; cT ++)
	{
		int row1 = 0;
		int row2 = 0;
		int r1[4] = {0,0,0,0};
		int r2[4] = {0,0,0,0};
		int result[17] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		int rTemp = 0;

		scanf("%d",&row1);
		for(int temp = 1; temp <= 4; temp ++)
		{
			if (temp == row1)
			{
				scanf("%d %d %d %d",r1,r1 + 1, r1 + 2, r1 + 3);
				continue;
			}
			scanf("%d %d %d %d",&rTemp, &rTemp, &rTemp, &rTemp);
		}

		scanf("%d",&row2);		
		for(int temp = 1; temp <= 4; temp ++)
		{
			if (temp == row2)
			{
				scanf("%d %d %d %d",r2,r2 + 1, r2 + 2, r2 + 3);
				continue;
			}
			scanf("%d %d %d %d",&rTemp, &rTemp, &rTemp, &rTemp);
		}
		for (int i = 0; i < 4; ++i)
		{
			result[ r1[i] ] ++;
			result[ r2[i] ] ++;
		}
		for (int i = 1; i < 17; ++i)
		{
			if (result[i] == 2)
			{
				if (!result[0])
				{
					result[0] = i;
				}else
				{
					result[0] = -1;
					break;
				}
			}
		}
		if (result[0])
		{
			if (result[0] < 0)
			{
				printf("Case #%d: Bad magician!\n", cT + 1);
			}else
			{
				printf("Case #%d: %d\n", cT + 1, result[0]);
			}
		}else
		{
			printf("Case #%d: Volunteer cheated!\n", cT + 1);
		}
	}
	fclose(fp);
}
