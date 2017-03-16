#include "cstdio"

int main()
{
	int T;
	int l1, l2, ans;
	int* candi = new int[4];
	int* input = new int[4];
	scanf("%d",&T);
	for (int Case = 1; Case <= T; Case++)
	{
		ans = -1;
		scanf("%d", &l1);
		for (int i=1;i<=4;i++)
		{
			if (i == l1)
			{
				scanf("%d %d %d %d", &candi[0], &candi[1], &candi[2], &candi[3]);
			}
			else
			{
				scanf("%d %d %d %d", &input[0], &input[1], &input[2], &input[3]);
			}
		}
		scanf("%d", &l2);
		for (int i=1;i<=4;i++)
		{
			scanf("%d %d %d %d", &input[0], &input[1], &input[2], &input[3]);
			if (i == l2)
			{
				for(int j=0;j<4;j++)
				{
					for(int k=0;k<4;k++)
					{
						if(candi[j] == input[k])
						{
							if(ans == -1)
							{
								ans = candi[j];
							}
							else
							{
								ans = 17;
							}
						}
					}
				}
			}
		}
		if(ans == -1) printf("Case #%d: Volunteer cheated!\n", Case);
		else if(ans == 17) printf("Case #%d: Bad magician!\n", Case);
		else printf("Case #%d: %d\n", Case, ans);
	}
	return 0;
}