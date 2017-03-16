#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> a;
int r, c;
int ret;

void backtr(int x, int y, int rc, int remain)
{
	if (remain > rc) return;
	if (x == r || remain == 0)
	{
		int tmp = 0;
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
			{
				if (a[i][j] == 1)
				{
					if (i != r - 1 && a[i + 1][j] == 1) tmp++;
					if (j != c - 1 && a[i][j + 1] == 1) tmp++;
				}
			}
		if (ret > tmp) ret = tmp;
		return;
	}
	if (y == c - 1)
	{
		backtr(x + 1, 0, rc - 1, remain);
		a[x][y] = 1;
		backtr(x + 1, 0, rc - 1, remain - 1);
		a[x][y] = 0;
	}
	else
	{
		backtr(x, y + 1, rc - 1, remain);
		a[x][y] = 1;
		backtr(x, y + 1, rc - 1, remain - 1);
		a[x][y] = 0;
	}
}

int go(int n)
{
	a.assign(r, vector<int>(c, 0));
	ret = 987987987;
	backtr(0, 0, r * c, n);
	return ret;
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn)
	{
		int n;
		scanf("%d%d%d", &r, &c, &n);
		printf("Case #%d: %d\n", cn, go(n));
	}
	return 0;
}