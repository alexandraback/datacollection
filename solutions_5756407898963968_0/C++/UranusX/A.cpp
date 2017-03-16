#include <cstdio>

int Al, Bl;
int A[4][4], B[4][4];
int P[17];

void Work()
{
	scanf("%d", &Al);
	Al --;
	for (int i = 0; i < 4; i ++)
		for (int j = 0; j < 4; j ++)
			scanf("%d", &A[i][j]);
	scanf("%d", &Bl);
	Bl --;
	for (int i = 0; i < 4; i ++)
		for (int j = 0; j < 4; j ++)
			scanf("%d", &B[i][j]);
	for (int i = 1; i <= 16; i ++)
		P[i] = 0;
	for (int i = 0; i < 4; i ++)
	{
		P[A[Al][i]] ++;
		P[B[Bl][i]] ++;
	}
	int Cnt = 0;
	for (int i = 1; i <= 16; i ++)
		if (P[i] == 2)
			Cnt ++;
	if (Cnt == 0)
		printf("Volunteer cheated!\n");
	else if (Cnt == 1)
	{
		for (int i = 1; i <= 16; i ++)
			if (P[i] == 2)
				printf("%d\n", i);
	}
	else
		printf("Bad magician!\n");
}

int main()
{
	freopen("A-small.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
    int Cases;
    scanf("%d", &Cases);
    for (int Case = 1; Case <= Cases; Case ++)
    {
		printf("Case #%d: ", Case);
		Work();
    }
    return 0;
}