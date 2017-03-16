#include <stdio.h>
#include <string.h>

#define INF (1<<20)
#define MIN(a,b) (((a)<(b))?(a):(b))

int R,C;
int grid[20][20];

int check()
{
	//int f = 0;
	int c = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j =0; j < C; j++)
		{ 
			//f += grid[i][j];
			if (i < R-1 && grid[i][j] && grid[i+1][j]) c++;
			if (j < C-1 && grid[i][j] && grid[i][j+1]) c++;
		}
	}
	//printf("%d %d\n", c, f);
	return c;
}

int best(int r, int c, int n)
{
	if (n < 0) return INF;
	if (r >= R-1 && c >= C)
	{
		/*for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
					printf("%d ", grid[i][j]);
				printf("\n");
			}*/
		//printf("n = %d, check = %d\n", n, check());
		return (n == 0)?check():INF;
	}
	if (c >= C) c=0,r++;
	//printf("R,C = %d,%d, r,c = %d,%d\n", R, C, r, c);
	int b = best(r, c+1, n);
	grid[r][c] = 1;
	int t = best(r, c+1, n-1);
	grid[r][c] = 0;
	return MIN(b,t);
}

int main()
{
	int T,a;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		scanf("%d %d %d", &R, &C, &a);
		memset(grid, 0, sizeof(grid));
		printf("Case #%d: %d\n", t, best(0,0,a));
	}
}
