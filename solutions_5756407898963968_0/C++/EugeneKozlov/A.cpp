#include <cstdio>

int main()
{
	// 3 2 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 3 1 2 5 4 3 11 6 15 9 10 7 12 13 14 8 16 2 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 2 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 2 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 3 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int N, first, second;
	int x[4][4], y[4][4];
	int c;
	int nc;
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
	{
		nc = 0;
		scanf("%d", &first);
		--first;
		for(int j = 0; j < 4; ++j)
			scanf("%d %d %d %d", x[j]+0, x[j]+1, x[j]+2, x[j]+3);
		scanf("%d", &second);
		--second;
		for(int j = 0; j < 4; ++j)
			scanf("%d %d %d %d", y[j]+0, y[j]+1, y[j]+2, y[j]+3);
		for(int k = 0; k < 4; ++k)
			for(int m = 0; m < 4; ++m)
			{
				if(y[second][m] == x[first][k])
				{
					++nc;
					c = y[second][m];
				}
			}
		if(nc == 0)
			printf("Case #%d: Volunteer cheated!\n", i);
		else if(nc == 1)
			printf("Case #%d: %d\n", i, c);
		else
			printf("Case #%d: Bad magician!\n", i);
	}

}
