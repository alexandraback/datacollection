#include <cstdio>
#include <cstring>

int n, total;
int a[30];

int main() {
	int T;
	scanf("%d\n", &T);
	for (int ttt = 1; ttt <= T; ++ ttt)
	{
		printf("Case #%d: ", ttt);

		scanf("%d\n", &n);
		total = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d\n", &a[i]);
			total += a[i];
		}
		fprintf(stderr, "Case #%d: ", ttt);


		while (total)
		{
			int m1 = 0, m2 = 0, t1 = -1, t2 = -1;
			for (int i = 0; i < n; ++i)
			{
				if (a[i] <= m1 && a[i] > m2)
				{
					m2 = a[i];
					t2 = i;
				}
				if (a[i] > m1)
				{
					m2 = m1;
					m1 = a[i];
					t2 = t1;
					t1 = i;
				}
			}

			if (a[t1] == a[t2] && total != 3)
			{
				printf("%c%c ", t1 + 'A', t2 + 'A');
				a[t1] --;
				a[t2] --;
				total -= 2;
			}
			else
			{
				if (total == 3)
				{
					printf("%c ", t1 + 'A');
					a[t1] --;
					--total;
				}
				else
				if (a[t1] == 1)
				{
					printf("%c ", t1 + 'A');
					a[t1] --;
					--total;
				}
				else
				{
					printf("%c%c ", t1 + 'A', t1 + 'A');
					a[t1] -= 2;
					total -= 2;
				}
			}

			for (int i = 0; i < n; ++i)
				fprintf(stderr, "%d ", a[i]);
			fprintf(stderr, "\n");
		}
		printf("\n");

	}

	return 0;
}