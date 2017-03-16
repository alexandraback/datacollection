#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAXN 100

int ans;
int r, c, n;

bool occupied[MAXN][MAXN];

void dfs(int x, int y, int z, int val)
{
	if (val >= ans)
		return;

	if (z == 0)
	{
		ans = val;
		return;
	}

	if (y > c)
	{
		dfs(x + 1, 1, z, val);
		return;
	}
	if (x > r)
		return;

	occupied[x][y] = true;
	dfs(x, y + 1, z - 1, val + (occupied[x][y - 1] ? 1 : 0) + (occupied[x - 1][y] ? 1 : 0));

	occupied[x][y] = false;
	dfs(x, y + 1, z, val);
}

int main()
{
	FILE *fin = fopen("b.in", "r");
	FILE *fout = fopen("b.out", "w");

	int T;
	fscanf(fin, "%d", &T);

	for (int testCase = 1; testCase <= T; testCase++)
	{
		fscanf(fin, "%d%d%d", &r, &c, &n);

		memset(occupied, 0, sizeof(occupied));

		ans = 2 * r * c;

		dfs(1, 1, n, 0);

		fprintf(fout, "Case #%d: %d\n", testCase, ans);
	}

	return 0;
}
