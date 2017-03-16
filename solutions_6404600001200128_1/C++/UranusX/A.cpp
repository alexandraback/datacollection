#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int A[100000];

int Work()
{
	scanf("%d", &N);
	int Ans1 = 0, d = 0, Ans2 = 0;
	for (int i = 0; i < N; i ++)
	{
		scanf("%d", &A[i]);
		if (i > 0 && A[i] < A[i - 1])
			Ans1 += A[i - 1] - A[i];
		if (i > 0 && A[i - 1] - A[i] > d)
			d = A[i - 1] - A[i];
	}
	for (int i = 0; i < N - 1; i ++)
		Ans2 += min(A[i], d);
	printf("%d %d\n", Ans1, Ans2);
	return 0;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int Cases;
	scanf("%d", &Cases);
	for (int Case = 1; Case <= Cases; Case ++)
	{
		printf("Case #%d: ", Case);
		Work();
	}
	return 0;
}
