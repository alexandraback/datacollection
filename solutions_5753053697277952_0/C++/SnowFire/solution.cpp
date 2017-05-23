#include <stdio.h>


using namespace std;

int A[26];
int N, sum;

inline void init()
{
	int i;

	sum = 0;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
		sum += A[i];
	}
}

inline void make_move()
{
	int MAX1 = -1, MAX2 = -1, pos1 = 0, pos2 = 0;
	int i;

	for (i = 0; i < N; i++)
	{
		if (A[i] > MAX1)
		{
			MAX2 = MAX1;
			pos2 = pos1;
			MAX1 = A[i];
			pos1 = i;
		}

		else if (A[i] > MAX2)
		{
			MAX2 = A[i];
			pos2 = i;
		}
	}

	if (sum == 3 && MAX1 == MAX2 == 1)
	{
		printf("%c ", pos1 + 'A');
		A[pos1] -= 1;
		sum -= 1;
		return;
	}

	if (MAX1 >= MAX2 + 2)
	{
		printf("%c%c ", pos1 + 'A', pos1 + 'A');
		A[pos1] -= 2;
		sum -= 2;
		return;
	}

	if (MAX1 >= MAX2 + 1)
	{
		printf("%c ", pos1 + 'A');
		A[pos1] -= 1;
		sum -= 1;
		return;
	}

	else
	{
		printf("%c%c ", pos1 + 'A', pos2 + 'A');
		A[pos1] -= 1;
		A[pos2] -= 1;
		sum -= 2;
		return;
	}
}

inline void solve()
{
	while (sum)
		make_move();
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T, i;

	scanf("%d", &T);

	for (i = 1; i <= T; i++)
	{
		init();
		printf("Case #%d: ", i);
		solve();
		putchar('\n');
	}

	return 0;
}