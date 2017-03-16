#include <stdio.h>
#include <string.h>

int ch1[5][5];
int ch2[5][5];

int main()
{
	int T, i, j, ans, ncas = 1, r1, r2;
	//FILE *p;
	//freopen("C:\\Users\\think\\Desktop\\A-small-attempt1.in", "r", stdin);
	//p = freopen("C:\\Users\\think\\Desktop\\A.txt", "w", stdout);
	scanf("%d", &T);
	while (T--)
	{
		ans = 0;
		scanf("%d", &r1);
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
				scanf("%d", &ch1[i][j]);
		scanf("%d", &r2);
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
				scanf("%d", &ch2[i][j]);
		int sum = 0;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (ch1[r1-1][i] == ch2[r2-1][j]) ans = ch1[r1-1][i], sum++;
			}
		}
		printf("Case #%d: ", ncas++);
		if (sum == 1) printf("%d\n", ans);
		else if(sum == 0) printf("Volunteer cheated!\n");
		else printf("Bad magician!\n");
	}

	return 0;
}