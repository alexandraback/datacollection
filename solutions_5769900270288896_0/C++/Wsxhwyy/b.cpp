#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;
ofstream fout("a.out");

int dp[18][18][1024];

int main()
{
	int N, T, R, C;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> R >> C >> N;
		if (R > C)
			swap(R, C);
		int ans = 0;
		if (R == 0)
		{
			int tmp = (C + 1) / 2;
			int ans = (N - tmp) * 2;
			if (ans < 0) ans = 0;
			cout << "Case #" << t << ": " << ans << endl;
		}
		else
		{
			memset(dp, 0, sizeof(dp));
			for (int i = 0; i < 18; i++)
				for (int k = 0; k < 18; k++)
					for (int j = 0; j < 1024; j++)
						dp[i][k][j] = 100000;
			for (int i = 0; i < C; i++)
			{
				for (int j = 0; j < (1 << R); j++)
				{
					int cnt = 0, res = 0;
					int w[16];
					for (int l = 0; l < R; l++)
					{
						w[l] = j & (1 << l);
						if (w[l])
							cnt++;
					}
					for (int l = 0; l < R - 1; l++)
					{
						if (w[l] && w[l + 1])
							res++;
					}
					dp[0][cnt][j] = res;
				}
			}
			for (int i = 1; i < C; i++)
			{
				for (int j = 0; j < (1 << R); j++)
				{	
					int cnt = 0;
					for (int l = 0; l < R; l++)
					{
						if (j & (1 << l))
							cnt++;
					}
					for (int k = 0; k < (1 << R); k++)
					{
						int tmp = 0;
						for (int l = 0; l < R; l++)
						{
							if ((j & (1 << l)) && (k & (1 << l)))
								tmp++;
						}
						for (int l = 0; l <= i * R; l++)
							dp[i][l + cnt][j] = min(dp[i][l + cnt][j], 
								dp[i - 1][l][k] + dp[0][cnt][j] + tmp);
					}
				}
			}
			int res = 100000;
			for (int j = 0; j < (1 << R); j++)
			{
				res = min(res, dp[C - 1][N][j]);
			}
			cout << "Case #" << t << ": " << res << endl;
		}
		
		
	}
}