#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
int row, col;
int hp;
int board[20][20];

int check()
{
	int res = 0;
	for(int i = 0;i < row;i++)
		for(int j = 0;j < col;j++)
		{
			if (board[i][j] == 0)
				continue;

			if (i > 0 && board[i - 1][j])
				res++;
			if (j > 0 && board[i][j - 1])
				res++;
			if (i + 1 < row && board[i + 1][j])
				res++;
			if (j + 1 < col && board[i][j + 1])
				res++;
		}

	return res / 2;
}
void dfs(int r, int c, int k)
{
	if (k == n)
	{
		int h = check();
		hp = min(hp, h);
		return;
	}
	if (r >= row)
		return;

	board[r][c] = 1;
	if (c + 1 == col)
		dfs(r + 1, 0, k + 1);
	else
		dfs(r, c + 1, k + 1);
	
	board[r][c] = 0;
	if (c + 1 == col)
		dfs(r + 1, 0, k);
	else
		dfs(r, c + 1, k);

	board[r][c] = 0;
}

int main()
{
	int ncase;
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	cin >> ncase;

	for(int icase = 0;icase < ncase;icase++)
	{
		memset(board, 0, sizeof(board));
		cin >> row >> col >> n;
		
		hp = 100000;
		dfs(0, 0, 0);
		cout << "Case #" << icase + 1 << ": " << hp << endl;
	}

	return 0;
}
