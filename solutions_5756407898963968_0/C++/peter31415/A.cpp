#include <cstdio>
using namespace std;

const int SIZE = 4;

void readBoard(int a[][SIZE]);
void solve(int caseNumber);

void solve(int caseNumber)
{
	int a1[SIZE][SIZE];
	int a2[SIZE][SIZE];
	int g1;
	int g2;
	scanf("%d", &g1);	
	readBoard(a1);
	scanf("%d", &g2);
	readBoard(a2);
	g1--;
	g2--;

	int interSize = 0;
	int firstInter = -1;
	for(int c1 = 0; c1 < SIZE; c1++)
	{
		for(int c2 = 0; c2 < SIZE; c2++)
		{
			if (a1[g1][c1] == a2[g2][c2])
			{
				interSize++;
				if (interSize == 1)
				{
					firstInter = a1[g1][c1];
				} else {
					printf("Case #%d: Bad magician!\n", caseNumber);
					return;
				}
			}
		}
	}

	if (interSize == 1)
	{
		printf("Case #%d: %d\n", caseNumber, firstInter);
	} else
	{	
		printf("Case #%d: Volunteer cheated!\n", caseNumber);
	}

}

void readBoard(int a[][SIZE])
{
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
}

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("out", "w", stdout);

	int t;
	scanf("%d", &t);

	for(int i = 1;i <= t; i++)
	{
		solve(i);
	}
}