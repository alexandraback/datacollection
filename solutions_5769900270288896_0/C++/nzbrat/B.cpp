# include <cstdio>
# include <cmath>
# include <cstring>
# include <string>
# include <vector>
# include <queue>
# include <map>
# include <algorithm>
# include <iostream>

using namespace std;

int r, c, n;

int used[20][20];

int ans, cnt;

void go (int x, int y, int t)
{
	int i, j;
	if (t == n)
	{
		///cout << "sweg\n" << endl;
		cnt = 0;
		for (i = 1; i <= r; i ++)
			for (j = 1; j <= c; j ++)
				if (used[i][j])
					cnt += used[i - 1][j] + used[i][j - 1];
		if (cnt < ans)
			 ans = cnt;
		return ;
	}
	if (x > r || y > c)
		return;

	used[x][y] = 0;
	if (y + 1 <= c)
		go (x, y + 1, t);
	else
		go (x + 1, 1, t);
	used[x][y] = 1;
	if (y + 1 <= c)
		go (x, y + 1, t + 1);
	else
		go (x + 1, 1, t + 1);
	used[x][y] = 0;
}

int main ()
{
	int t, t1;
	scanf ("%d", &t);
	for (t1 = 1; t1 <= t; t1 ++)
	{
		scanf ("%d%d%d", &r, &c, &n);
		ans = 1e9;
		go (1, 1, 0);
		printf ("Case #%d: %d\n", t1, ans);
	}
	return 0;
}

