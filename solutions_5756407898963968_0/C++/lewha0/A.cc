#include<stdio.h>

int T;
int A[4][4], B[4][4], AA, BB;

int main(void)
{
	int l0, l1, l2;

	scanf("%d", &T);
	for(l0 = 1; l0 <= T; l0++)
	{
		scanf("%d", &AA);
		for(l1 = 0; l1 < 4; l1++) for(l2 = 0; l2 < 4; l2++) scanf("%d", &A[l1][l2]);
		scanf("%d", &BB);
		for(l1 = 0; l1 < 4; l1++) for(l2 = 0; l2 < 4; l2++) scanf("%d", &B[l1][l2]);

		AA--; BB--;

		int cnt = 0, val = -1;
		for(l1 = 0; l1 < 4; l1++) for(l2 = 0; l2 < 4; l2++) if(A[AA][l1] == B[BB][l2]){ cnt++; val = A[AA][l1]; }

		printf("Case #%d: ", l0);
		if(cnt == 0)
		{
			printf("Volunteer cheated!\n");
		}
		else if(cnt == 1)
		{
			printf("%d\n", val);
		}
		else
		{
			printf("Bad magician!\n");
		}
	}
	return 0;
}
