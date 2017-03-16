#include <cstdio>

const int N = 18;
const int dx[2] = {0, 1}, dy[2] = {1, 0};

bool b[N][N];
int n, m, k, sum;
int te;

void go(int t, int k)
{
	if (k == 0)
	{
		int r = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (b[i][j])
					for (int k = 0; k < 2; k++)
					{
						int x = i + dx[k], y = j + dy[k];
						if (x >= 0 && x < n && y >= 0 && y < m && b[x][y])
							++r;
					}
		if (r < sum)
			sum = r;
	}
	if (k > 0)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (i * m + j >= t && !b[i][j])
				{
					b[i][j] = true;
					go(i * m + j, k - 1);
					b[i][j] = false;
				}
}

int main()
{
	scanf("%d", &te);
	for (int tn = 1; tn <= te; tn++)
	{
		sum = 1e9;
		scanf("%d%d%d", &n, &m, &k);
		go(0, k);

		printf("Case #%d: %d\n", tn, sum);
	}

	return 0;
}