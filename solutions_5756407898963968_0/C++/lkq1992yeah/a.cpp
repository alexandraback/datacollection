#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int bef[5][5], aft[5][5];
int rbef, raft;

int main()
{
	int t, cas, i, j;
	int cnt, card;
	scanf("%d", &t);
	for (cas = 1; cas <= t; cas++)
	{
		scanf("%d", &rbef);
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
				scanf("%d", &bef[i][j]);
		scanf("%d", &raft);
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
				scanf("%d", &aft[i][j]);
		cnt = card = 0;
		rbef--; raft--;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
				if (bef[rbef][i] == aft[raft][j])
				{
					cnt++; card = bef[rbef][i];
					break;
				}
		}
		printf("Case #%d: ", cas);
		if (cnt == 1)
			printf("%d\n", card);
		else if (cnt == 0)
			printf("Volunteer cheated!\n");
		else
			printf("Bad magician!\n");
	}
	return 0;
}
