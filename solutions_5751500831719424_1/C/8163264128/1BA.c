#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a, const void *b)
{
	return *(const int*)a - *(const int*)b;
}

int main(void)
{
	int T, x, N, l, r, y, i, j;
	char t[100], s[101], c;
	int cnt[100][100];
	scanf("%d ", &T);
	for (x = 1; x <= T; x++)
	{
		scanf("%d ", &N);
		scanf("%s ", s);

		c = '\0';
		l = 0;
		for (i = 0; s[i]; i++)
		{
			if (s[i] == c)
			{
				cnt[l - 1][0]++;
				continue;
			}
			cnt[l][0] = 1;
			t[l++] = c = s[i];
		}

		j = 0;
		for (r = 1; r < N; r++)
		{
			scanf("%s ", s);
			if (j != -100)
			{
				c = '\0';
				j = 0;
				for (i = 0; s[i]; i++)
				{
					if (s[i] == c)
					{
						cnt[j - 1][r]++;
						continue;
					}
					if (s[i] == t[j])
					{
						c = s[i];
						cnt[j++][r] = 1;
					}
					else
					{
						j = -100;
						break;
					}
				}
				if (j != l) j = -100;
			}
		}

		if (j == -100)
		{
			printf("Case #%d: Fegla Won\n", x);
		}
		else
		{
			y = 0;
			for (i = 0; i < l; i++)
			{
				qsort(cnt[i], N, sizeof(int), compare_int);
				for (j = 0; (j << 1) < N; j++)
					y += cnt[i][N - 1 - j] - cnt[i][j];
			}
			printf("Case #%d: %d\n", x, y);
		}
	}
	return 0;
}