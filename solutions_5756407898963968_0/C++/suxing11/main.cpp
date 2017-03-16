# include <stdio.h>
# include <string.h>


int g[5][10][10];
int vis[20];


int main()
{
	int T, nCase = 1;
	int i, j, a, b;
	freopen ("A-small-attempt0.in", "r", stdin);
	freopen ("A_out.txt", "w", stdout);
	scanf ("%d", &T);
	while (T--)
	{
		memset (vis, 0, sizeof(vis));
		scanf ("%d", &a);
		for (i = 1; i <= 4; i++)
			for (j = 1; j <= 4; j++)
				scanf ("%d", &g[0][i][j]);
		for (i = 1; i <= 4; i++) vis[g[0][a][i]] = 1;
		
		scanf ("%d", &b);
		for (i = 1; i <= 4; i++)
			for (j = 1; j <= 4; j++)
				scanf ("%d", &g[1][i][j]);
		
		int ans = 0;
		for (i = 1; i <= 4; i++)
			if (vis[g[1][b][i]])
				if (ans != 0) ans = -1;
				else ans = g[1][b][i];
			
		printf ("Case #%d: ", nCase++);
		if (ans == -1) puts ("Bad magician!");
		else if (ans == 0) puts ("Volunteer cheated!");
		else printf ("%d\n", ans);
	}
	return 0;
}
