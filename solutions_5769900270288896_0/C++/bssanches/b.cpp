#include <bits/stdc++.h>

using namespace std;


int n,t;
int maior,r,c;
int mat[30][30];

void solve(int x, int y, int n)
{
	if (x == r)
	{
		// printf("n = %d\n",n);
		int cont = 0;
		for (int i = 0; i < r; ++i)
		{
			for (int j = 1; j < c; ++j)
			{
				if (mat[i][j] && mat[i][j-1])
				{
					cont++;
				}
			}
		}

		for (int i = 1; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				if (mat[i - 1][j] && mat[i][j])
				{
					cont++;
				}
			}
		}

		if (n == 0)
			maior = min(maior, cont);
		return;
	}

	if (y == c)
	{
		solve(x + 1, 0, n);
		return;
	}

	if (n > 0)
	{
		mat[x][y] = 1;
		solve(x, y + 1, n - 1);
	}
	mat[x][y] = 0;
	solve(x, y + 1, n);
}
int main(void)
{
	cin >> t;

	for (int cases = 1; cases <= t; ++cases)
	{
		cin >> r >> c >> n;
		maior = 0x3f3f3f3f;
		memset(mat, 0, sizeof mat);
		solve(0, 0, n);
		cout << "Case #" << cases <<": " << maior << "\n";
	}
	return 0;
}