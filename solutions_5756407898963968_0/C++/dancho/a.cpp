#include <cstdio>
#include <cstring>

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 0; t < T; ++t)
	{
		int cand[32];
		memset(cand, 0, sizeof(cand));
		int row;
		scanf("%d", &row);
		for (int i = 1; i <= 4; ++i)
		{
			int k;
			for (int j = 1; j <= 4; ++j)
			{
				scanf("%d", &k);
				if (i == row)
					++cand[k];
			}
		}
		scanf("%d", &row);
		for (int i = 1; i <= 4; ++i)
		{
			int k;
			for (int j = 1; j <= 4; ++j)
			{
				scanf("%d", &k);
				if (i == row)
					++cand[k];
			}
		}
		int n2 = 0, i2 = 0;
		for (int i = 1; i <= 16; ++i)
		{
			if (cand[i] == 2)
			{
				++n2;
				i2 = i;
			}
		}
		if (n2 == 1)
			printf("Case #%d: %d\n", t + 1, i2);
		else if (n2 > 1)
			printf("Case #%d: Bad magician!\n", t + 1);
		else
			printf("Case #%d: Volunteer cheated!\n", t + 1);
	}
	return 0;
}
