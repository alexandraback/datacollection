#include <stdio.h>

int T, a1, a2, cnt, rez;
int a[10][10], b[10][10];

int main()
{	int tt, i, j;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for(tt=1; tt<=T; ++tt)
	{
		cnt=0;
		scanf("%d", &a1);
		for(i=1; i<=4; ++i)
			for(j=1; j<=4; ++j)
				scanf("%d", &a[i][j]);
		scanf("%d", &a2);
		for(i=1; i<=4; ++i)
			for(j=1; j<=4; ++j)
				scanf("%d", &b[i][j]);
		for(i=1; i<=4; ++i)
			for(j=1; j<=4; ++j)
				if(a[a1][i] == b[a2][j])
				{
					cnt++;
					rez = a[a1][i];
				}
		printf("Case #%d: ", tt);
		if(cnt == 1)
			printf("%d\n", rez);
		else if(cnt == 0)
			printf("Volunteer cheated!\n");
		else
			printf("Bad magician!\n");
	}
	return 0;
}