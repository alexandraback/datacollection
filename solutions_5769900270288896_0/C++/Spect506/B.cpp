#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 100005;
int r, c, n, ans;
vector<int> a[maxn];
void work()
{
	for (int i = 1; i <= r; i++)
	{
		int st;
		if (i & 1)
			st = 1;
		else
			st = 2;
		for (int j = st; j <= c; j += 2)
		{
			a[i][j] = 1;
			n--;
			if (n == 0)
				return;
		}
	}
	for (int i = 2; i <= c; i += 2)
	{
		a[1][i] = 1;
		n--;
		if (n == 0)
			return;
	}
	for (int i = 2; i <= r; i += 2)
	{
		a[i][1] = 1;
		n--;
		if (n == 0)
			return;
	}
	int st;
	if (a[1][c] == 1)
		st = 2;
	else
		st = 1;
	for (int i = st; i <= r; i += 2)
	{
		a[i][c] = 1;
		n--;
		if (n == 0)
			return;
	}
	if (a[r][1] == 1)
		st = 2;
	else
		st = 1;
	for (int i = st; i <= c; i += 2)
	{
		a[r][i] = 1;
		n--;
		if (n == 0)
			return;
	}
	for (int i = 2; i < r; i++)
		for (int j = 2; j < c; j++)
			if (a[i][j] == 0)
			{
				a[i][j] == 1;
				n--;
				if (n == 0)
					return;
			}
	return;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test;
	scanf("%d", &test);
	for (int tt = 1; tt <= test; tt++)
	{
		scanf("%d%d%d", &r, &c, &n);
		if (r > c)
		{
			r ^= c, c ^= r, r ^= c;
		}
		printf("Case #%d: ", tt);
		if (n == 0)
		{
			printf("0\n");
			continue;
		}
		int tmp;
		if ((r & 1) && (c & 1))
			tmp = ((r - 2) * (c - 2) + 1) >> 1;
		else
			tmp = (r - 2) * (c - 2) >> 1;
		if (r * c - n <= tmp)
		{
			printf("%d\n", r * c * 2 - c - r - 4 * (r * c - n));
			continue;
		}
		for (int i = 1; i <= r; i++)
			for (int j = 0; j <= c; j++)
				a[i].push_back(0);
		ans = 0;
		work();
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++)
			{
				if (!a[i][j])
					continue;
				if (i < r)
					ans += a[i + 1][j];
				if (j < c)
					ans += a[i][j + 1];
			}
			//for (int i = 1; i <= r; i++){
			//	for (int j = 1; j <= c; j++)
			//		printf("%d ", a[i][j]);printf("\n");}
		printf("%d\n", ans);
		for (int i = 1; i <= r; i++)
			a[i].clear();
	}
	return 0;
}
