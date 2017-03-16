#include <cstdio>

char __input[64];
int row1, row2;
int temp;
int num;
int possible[17];
int t;

int main()
{
	printf("Input file = "); fflush(stdout);
	scanf("%s", __input);
	freopen(__input, "r", stdin);
	freopen("out.A.txt", "w", stdout);

	scanf("%d", &t);
	for (int _ = 1;_ <= t;_++)
	{
		num = 0;
		for (int i = 0;i < 17;i++)
			possible[i] = 0;
		scanf("%d", &row1);
		row1--;
		for (int i = 0;i < 4;i++)
		{
			for (int j = 0;j < 4;j++)
			{
				scanf("%d", &temp);
				if (i == row1)
				{
					possible[temp] = true;
					num++;
				}
			}
		}
		scanf("%d", &row2);
		row2--;
		for (int i = 0;i < 4;i++)
		{
			for (int j = 0;j < 4;j++)
			{
				scanf("%d", &temp);
				if (i != row2 && possible[temp])
				{
					possible[temp] = false;
					num--;
				}
			}
		}
		printf("Case #%d: ", _);
		if (num == 0)
			printf("Volunteer cheated!\n");
		else if (num >= 2)
			printf("Bad magician!\n");
		else
		{
			for (int i = 0;i < 17;i++) if (possible[i])
				printf("%d\n", i);
		}
	}

	return 0;
}
