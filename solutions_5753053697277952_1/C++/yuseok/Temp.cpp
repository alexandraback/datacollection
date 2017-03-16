#include<stdio.h>

int main(void)	{
	int test, T;
	int i, k, n, tot, max;
	int A[26];

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &T);

	for (test = 1; test <= T; test++)	{
		scanf("%d", &n);

		for (i = tot = 0; i < n; i++)	{
			scanf("%d", &A[i]);
			tot += A[i];
		}

		printf("Case #%d: ", test);

		while (tot > 2)	{
			for (i = max = 0; i < n; i++)	{
				if (max < A[i])
					max = A[i];
			}

			for (i = k = 0; i < n && k < 2 && tot > 2; i++)	{
				if (A[i] == max)	{
					printf("%c", i + 'A');
					A[i]--;
					tot--;
					k++;
				}
			}
			printf(" ");
		}

		for (i = 0; i < n; i++)	{
			if (A[i] != 0)
				printf("%c", i + 'A');
		}

		printf("\n");
	}

	return 0;
}