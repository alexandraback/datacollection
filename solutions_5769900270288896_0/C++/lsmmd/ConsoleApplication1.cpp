// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#pragma warning(disable:4996)
#include "stdio.h"
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <queue>
#include <algorithm>
#include <iostream>
#include<string>
#include <set>
#include <vector>
using namespace std;
vector<vector<bool>> board;

int ans = INT_MAX;
void dfs(int i, int j, int r, int c, int rest, int val)
{
	if (i == r)
	{
		if (rest == 0)
		{
			ans = min(ans, val);
			return;
		}
		else
			return;
	}
	int nexti = i;
	int nextj = j + 1;
	if (nextj == c)
	{
		nextj = 0;
		nexti++;
	}
	if (rest > 0)
	{
		int nextval = val;
		if (i > 0 && board[i - 1][j])
		{
			nextval++;
		}
		if (j > 0 && board[i][j - 1])
		{
			nextval++;
		}
		board[i][j] = true;
		dfs(nexti, nextj, r, c, rest - 1, nextval);
		board[i][j] = false;
	}
	dfs(nexti, nextj, r, c, rest, val);
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0_out.txt", "w", stdout);
	int tk, tk1 = 0;
	cin >> tk;
	while (tk--)
	{
		ans = INT_MAX;
		tk1++;
		int r, c, n;
		cin >> r >> c >> n;
		int res = 0;
		/*if (r == 1 || c == 1)
		{
			if ((r*c) % 2 == 0)
			{
				res = max(0, (n - (r*c) / 2) * 2 + 1);
			}
			else {
				res = max(0, (n - (r*c + 1) / 2) * 2);
			}
		}
		else*/ {
			board.resize(r);
			for (int i = 0; i < r; i++)
			{
				board[i].resize(c);
			}
			dfs(0, 0, r, c, n, 0);
			res = ans;
		}
		cout << "Case #" << tk1 << ": " << res << endl;
	}
	return 0;
}