#include <cstdio>
#include <cstring>

int main()
{
	int test, T, t[17], i, j, k, ans, v, count, card;

	scanf("%d", &T);
	for (test = 1; test <= T; test++)
	{
		memset(t, 0, sizeof(t));

		for (i = 0, count = 0; i < 2; i++)
		{
			scanf("%d", &ans);
			for (j = 1; j <= 4; j++)
			{
				for (k = 1; k <= 4; k++)
				{
					scanf("%d", &v);

					if (j == ans && ++t[v] == 2)
					{
						count++;
						card = v;
					}
				}
			}
		}

		if (count == 0)
		{
			printf("Case #%d: Volunteer cheated!\n", test);
		}
		else if (count == 1)
		{
			printf("Case #%d: %d\n", test, card);
		}
		else
		{
			printf("Case #%d: Bad magician!\n", test);
		}
	}

	return 0;
}
