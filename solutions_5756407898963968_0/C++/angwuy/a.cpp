#include <cstdio>
#include <cstring>

const int N = 4;

int a[10][10], b[10][10];
int cnt[100];

void solve()
{
	int k;
	memset(cnt, 0, sizeof(cnt));
	scanf("%d", &k);
	for (int i = 1; i <= N; ++i)
	for (int j = 1; j <= N; ++j)
		scanf("%d", &a[i][j]);
	for (int i = 1; i <= N; ++i)
		++cnt[a[k][i]];
	scanf("%d", &k);
	for (int i = 1; i <= N; ++i)
	for (int j = 1; j <= N; ++j)
		scanf("%d", &b[i][j]);
	for (int i = 1; i <= N; ++i)
		++cnt[b[k][i]];
	int ans = -1;
	for (int i = 1; i <= N * N; ++i)
	if (cnt[i] == 2)
	{
		if (ans == -1) ans = i;
		else
		{
			printf("Bad magician!\n");
			return;
		}
	}
	if (ans == -1) printf("Volunteer cheated!\n");
	else           printf("%d\n", ans);
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	int ii, tt;
	scanf("%d", &tt);
	for (int ii = 1; ii <= tt; ++ii)
	{
		printf("Case #%d: ", ii);
		solve();
	}
	return 0;
}