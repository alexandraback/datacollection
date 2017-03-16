#include <stdio.h>
#include <string.h>

int r, c, n, mat[10][10];

int calc()
{
	int i, j, val = 0;	
	/*for(i = 0; i < c; i++)
	{
		for(j = 0; j < r; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}*/
	for(i = 0; i < c; i++)
		for(j = 0; j < r; j++)
			if(mat[i][j])
			{
				if(i < c - 1)
				{
					if(mat[i + 1][j])
						val++;
				}
				if(j < r - 1)
				{					
					if(mat[i][j + 1])
						val++;
				}
			}
	return val;
}

int dfs(int x, int y, int cur)
{
	//printf("%d %d %d\n", x, y, cur);
	if(x == c)
		return dfs(0, y + 1, cur);
	if(cur == n)
		return calc();
	if(y == r)
		return 1000000000;
	mat[x][y] = 1;
	int t1 = dfs(x + 1, y, cur + 1);
	mat[x][y] = 0;
	int t2 = dfs(x + 1, y, cur);
	if(t1 < t2)
		return t1;
	return t2;
}

int main()
{
	int tt, k;
	scanf("%d", &tt);
	for(k = 1; k <= tt; k++)
	{
		memset(mat, 0, sizeof mat);
		scanf("%d%d%d", &c, &r, &n);
		printf("Case #%d: %d\n", k, dfs(0, 0, 0));
	}
}
