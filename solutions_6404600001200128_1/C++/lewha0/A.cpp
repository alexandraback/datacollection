#include<stdio.h>

int N, T;
int A[1000];
int Ret1, Ret2;

int main(void)
{
	int l0, l1, l2;

	scanf("%d", &T);
	for(l0 = 1; l0 <= T; l0++)
	{
		scanf("%d", &N);
		for(l1 = 0; l1 < N; l1++) scanf("%d", &A[l1]);

		Ret1 = Ret2 = 0;

		int maxdiff = 0;
		for(l1 = 1; l1 < N; l1++)
		{
			if(A[l1-1] - A[l1] > 0)
			{
				Ret1 += A[l1-1] - A[l1];
				if(A[l1-1] - A[l1] > maxdiff) maxdiff = A[l1-1] - A[l1];
			}
		}
		for(l1 = 1; l1 < N; l1++)
		{
			if(A[l1-1] - maxdiff < 0) Ret2 += A[l1-1];
			else Ret2 += maxdiff;
		}

		printf("Case #%d: %d %d\n", l0, Ret1, Ret2);
	}
	return 0;
}
