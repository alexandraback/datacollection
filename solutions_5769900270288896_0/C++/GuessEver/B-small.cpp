#include <cstdio>
#include <cstring>

int n, R, C;
int choose[100];
int a[100][100];
int ans = -1;

void Solve()
{
	//for(int i = 1; i <= n; i++) printf("%d ", choose[i]); puts("");
	memset(a, 0, sizeof(a));
	for(int i = 1; i <= n; i++)
	{
		int x = (choose[i] - 1) / C + 1;
		int y = (choose[i] - 1) % C + 1;
		a[x][y] = 1;
	}
	int res = 0;
	for(int i = 2; i <= R; i++)
		for(int j = 1; j <= C; j++)
			if(a[i][j] && a[i-1][j]) res++;
	for(int i = 1; i <= R; i++)
		for(int j = 2; j <= C; j++)
			if(a[i][j] && a[i][j-1]) res++;
	if(ans == -1 || res < ans) ans = res;
}

void dfs(int x, int pre)
{
	if(x > n)
	{
		Solve();
		return;
	}
	for(int i = pre + 1; i <= R * C; i++)
	{
		choose[x] = i;
		dfs(x + 1, i);
	}
}

int main()
{
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		scanf("%d%d%d", &R, &C, &n);
		ans = -1; dfs(1, 0);
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}
