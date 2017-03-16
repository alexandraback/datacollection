//B.Noisy Neighbors

#include<iostream>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool valid(int r, int c, int nr, int nc)
{
	return 0 <= nr && nr < r && 0 <= nc && nc < c;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t, kase = 0;
	cin >> t;
	while (t--)
	{
		int r, c, n;
		cin >> r >> c >> n;
		int num = r* c;
		int gr[16][16];
		int ans = INT_MAX;
		for (int i = 0; i < 1 << num; i++)
		{
			memset(gr, 0, sizeof(gr));
			int cnt = 0;
			for (int j = 0; j < num; j++)
			{
				if (i & 1 << j)
				{
					cnt++;
					int row = j / c;
					int col = j % c;
					gr[row][col] = true;
				}
			}
			if (cnt != n)
				continue;

			int val = 0;
			for (int j = 0; j < r; j++)
			{
				for (int k = 0; k < c; k++)
				{
					if (gr[j][k])
					{
						for (int l = 0; l < 4;l++)
						{
							int nj = j + dx[l];
							int nk = k + dy[l];
							if (valid(r, c, nj, nk) && gr[nj][nk])
								val++;
						}
					}
				}
			}
			if (val < ans)
				ans = val;
		}
		cout << "Case #" << ++kase << ": " << ans / 2 << endl;
	}
	return 0;
}