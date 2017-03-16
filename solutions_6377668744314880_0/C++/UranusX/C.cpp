#include <cstdio>
#include <algorithm>

using namespace std; 

const int MaxN = 16;

struct TPoint
{
	int x, y;
};

bool operator < (const TPoint& A, const TPoint& B)
{
	if (A.x != B.x)
		return A.x < B.x;
	return A.y < B.y;
}

int N;
TPoint P[100000];
int Stack[100000], Top, Limit;
int Order[100000];
int Ans[100000];

long long CrossProduct(TPoint A, TPoint B, TPoint C)
{
	return (long long) (B.x - A.x) * (long long) (C.y - A.y) - (long long) (B.y - A.y) * (long long) (C.x - A.x);
}

void Update(int i)
{
	while (Top > Limit && CrossProduct(P[Stack[Top - 1]], P[Stack[Top]], P[i]) < 0LL)
		Top --;
	Stack[++ Top] = i;
}

void Graham_Scan(int Bit)
{
	Top = 0;
	Limit = 1;
	for (int i = 0; i < N; i ++)
		if (Bit & (1 << i))
			Update(Order[i]);
	Limit = Top;
	for (int i = N - 1; i >= 0; i --)
		if (Bit & (1 << i))
			Update(Order[i]);
	Top --;
}

void Work()
{
	scanf("%d", &N); 
	for (int i = 0; i < N; i ++)
	{
		scanf("%d%d", &P[i].x, &P[i].y);
		Order[i] = i; 
		Ans[i] = 0;
	}
	for (int i = 0; i < N; i ++)
		for (int j = 0; j < N; j ++)
			if (P[Order[i]] < P[Order[j]])
				swap(Order[i], Order[j]);
	
	for (int Mask = 1; Mask < (1 << N); Mask ++)
	{
		int Count = 0;
		for (int i = 0; i < N; i ++)
			if (Mask & (1 << i))
				Count ++;
		Graham_Scan(Mask);
//printf("--- %d ---\n", Mask);
		for (int i = 1; i <= Top; i ++)
		{
//printf("%d ", Stack[i]);
			if (Ans[Stack[i]] < Count)
				Ans[Stack[i]] = Count;
		}
//printf("\n");
	}
	
	for (int i = 0; i < N; i ++)
		printf("%d\n", N - Ans[i]);
}

int main()
{
	freopen("C-small-attempt2.in", "r", stdin);
	freopen("C-small-attempt2.out", "w", stdout);
	int Cases;
	scanf("%d", &Cases);
	for (int Case = 1; Case <= Cases; Case ++)
	{
		printf("Case #%d:\n", Case);
		Work();
	}
	return 0;
}
