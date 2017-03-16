#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	//ifstream infile("in.txt");
	//cin.rdbuf(infile.rdbuf());

	int t;

	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		int r, c, n;
		cin >> r >> c >> n;

		int mindot = c / 2;
		int maxdot = (c & 1) ? mindot + 1 : mindot;
		int rowcount = (r & 1) ? (r + 1) / 2 : r / 2;
		int maxsupported = maxdot * rowcount + mindot * (r - rowcount);
		long long minans = (n <= maxsupported ? 0 : 999999999999999LL);

		if (n > maxsupported)
		{
			for (int count = 0; count < 2; count++)
			{
				vector<vector<bool>> ap(r, vector<bool>(c, false));
				vector<vector<int>> noise(r, vector<int>(c, 0));
				int nn = n;

				for (int i = 0; i < r; i++)
				{
					int j = (i & 1) ? 0 : 1;
					if (i & 1)
						j = (count == 0) ? 0 : 1;
					else
						j = (count == 0) ? 1 : 0;

					for (; j < c; j += 2)
					{
						ap[i][j] = true;
						int ii = i - 1, jj = j;
						if (ii >= 0 && ii < r && jj >= 0 && jj < c)
						{
							noise[ii][jj]++;
						}
						ii = i, jj = j + 1;
						if (ii >= 0 && ii < r && jj >= 0 && jj < c)
						{
							noise[ii][jj]++;
						}
						ii = i + 1, jj = j;
						if (ii >= 0 && ii < r && jj >= 0 && jj < c)
						{
							noise[ii][jj]++;
						}
						ii = i, jj = j - 1;
						if (ii >= 0 && ii < r && jj >= 0 && jj < c)
						{
							noise[ii][jj]++;
						}
						nn--;
					}
				}

				long long ans = 0;
				for (; nn; nn--)
				{
					int ai = 0, aj = 0;

					for (int i = 0; i < r; i++)
					{
						for (int j = 0; j < c; j++)
						{
							if (!ap[i][j] && (ap[ai][aj] || noise[i][j] < noise[ai][aj]))
							{
								ai = i;
								aj = j;
							}
						}
					}

					ap[ai][aj] = true;
					ans += noise[ai][aj];
				}

				if (ans < minans)
					minans = ans;
			}
		}

		cout << "Case #" << tc << ": " << minans << endl;
	}

	return 0;
}
