#include <bits/stdc++.h>
using namespace std;
#define int long long

int rows, cols, n, bits, ans[18][18][16*17], grid[18][18], tans;

int getAns()	{
	int ret = 0;
	for(int row = 0; row < rows; row++)	{
		for(int i=1; i<cols; i++)	{
			if(grid[row][i - 1] and grid[row][i] )	{
				ret++;
			}
		}
	}
	for(int col = 0; col < cols; col++)	{
		for(int i=1; i<rows; i++)	{
			if(grid[i][col] and grid[i - 1][col])	{
				ret++;
			}
		}
	}
	return ret;
}

void pain()	{
	cin >> rows >> cols >> n;
	if(ans[rows][cols][n] != -1)	{
		cout << ans[rows][cols][n] << "\n";
		return;
	}
	bits = rows * cols;
	tans = 10000;
	for(int mask = 0; mask < (1 << bits); mask++)	{
		if(__builtin_popcount(mask) == n)	{
			memset(grid, 0, sizeof grid);
			for(int i=0; i<rows; i++)	{
				for(int j=0; j<cols; j++)	{
					int pos = i * cols + j;
					if(mask & (1 << pos))	{
						grid[i][j] = 1;
					}
				}
			}
			tans = min(tans, getAns());
		}
	}
	ans[rows][cols][n] = tans;
	cout << tans << "\n";
}

#undef int
int main()	{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string input = "bin.txt";
	string output = "bout.txt";
	freopen(input.c_str(), "r", stdin);
	freopen(output.c_str(), "w", stdout);
	int tt; cin >> tt;
	memset(ans, -1, sizeof ans);
	for(int iii=1; iii<=tt; iii++)	{
		cout << "Case #" << iii << ": ";
		pain();
	}
}

