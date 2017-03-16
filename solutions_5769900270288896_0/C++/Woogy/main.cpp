#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;
int n, r, c;

int solve1()
{
	vector< vector<bool> > pole(r+3, vector<bool>(c + 3, true));
	int lastEmpty = r*c - n;
		bool flag = false;
		if (lastEmpty == 0)
			goto end;
		for (int i=2; i < r; i+=2)
		{
			if (flag) break;
			for (int j = 2; j < c; j+=2)
			{
				pole[i][j] = false;
				if (--lastEmpty <= 0)
				{
					flag = true;
					break;
				}
			}
		}
		if (flag) goto end;
		for (int i=3; i < r; i+=2)
		{
			if (flag) break;
			for (int j = 3; j < c; j+=2)
			{
				pole[i][j] = false;
				if (--lastEmpty <= 0)
				{
					flag = true;
					break;
				}
			}
		}
		if (flag) goto end;
		for (int i=2; i<r; i++)
		{
			if (!pole[i - 1][1] || !pole[i + 1][1] || !pole[i][1] || !pole[i][2]) continue;
			pole[i][1] = false;
			if (--lastEmpty <= 0)
			{
				flag = true;
				break;
			}
		}
		if (flag) goto end;
		for (int i=2; i<r; i++)
		{
			if (!pole[i-1][c] || !pole[i+1][c] || !pole[i][c] || !pole[i][c-1]) continue;
			pole[i][c] = false;
			if (--lastEmpty <= 0)
			{
				flag = true;
				break;
			}
		}
		if (flag) goto end;
		for (int j=2; j < c; j++)
		{
			if (!pole[1][j - 1] || !pole[1][j + 1] || !pole[1][j] || !pole[2][j]) continue;
			pole[1][j] = false;
			if (--lastEmpty <= 0)
			{
				flag = true;
				break;
			}
		}
		if (flag) goto end;
		for (int j=2; j < c; j++)
		{
			if (!pole[r][j - 1] || !pole[r][j + 1] || !pole[r][j] || !pole[r-1][j]) continue;
			pole[r][j] = false;
			if (--lastEmpty <= 0)
			{
				flag = true;
				break;
			}
		}
		if (flag) goto end;

		if (pole[1][2] && pole[2][1])
		{
			if (--lastEmpty <= 0)
				flag = true;
			pole[1][1] = false;
		}
		if (flag) goto end;
		if (pole[1][c - 1] && pole[2][c])
		{
			if (--lastEmpty <= 0)
				flag = true;
			pole[1][c] = false;
		}
		if (flag) goto end;
		if (pole[r][2] && pole[r - 1][1])
		{
			if (--lastEmpty <= 0)
				flag = true;
			pole[r][1] = false;
		}
		if (flag) goto end;
		if (pole[r - 1][c] && pole[r][c - 1])
		{
			if (--lastEmpty <= 0)
				flag = true;
			pole[r][c] = false;
		}

end:
		int res = 0;
		for (int i=1; i<=r; i++)
		{
			for (int j=1; j<=c; j++)
			{
				if (pole[i][j])
				{
					if (i + 1 <= r && pole[i+1][j])
						res++;
					if (j + 1 <= c && pole[i][j+1])
						res++;
				}
			}
		}
		return res;
}
int solve2()
{
	vector< vector<bool> > pole(r+3, vector<bool>(c + 3, true));
	int lastEmpty = r*c - n;
		bool flag = false;
		if (lastEmpty == 0)
			goto end;
		for (int i=2; i < r; i+=2)
		{
			if (flag) break;
			for (int j = 3; j < c; j+=2)
			{
				pole[i][j] = false;
				if (--lastEmpty <= 0)
				{
					flag = true;
					break;
				}
			}
		}
		if (flag) goto end;
		for (int i=3; i < r; i+=2)
		{
			if (flag) break;
			for (int j = 2; j < c; j+=2)
			{
				pole[i][j] = false;
				if (--lastEmpty <= 0)
				{
					flag = true;
					break;
				}
			}
		}
		if (flag) goto end;
		for (int i=2; i<r; i++)
		{
			if (!pole[i - 1][1] || !pole[i + 1][1] || !pole[i][1] || !pole[i][2]) continue;
			pole[i][1] = false;
			if (--lastEmpty <= 0)
			{
				flag = true;
				break;
			}
		}
		if (flag) goto end;
		for (int i=2; i<r; i++)
		{
			if (!pole[i-1][c] || !pole[i+1][c] || !pole[i][c] || !pole[i][c-1]) continue;
			pole[i][c] = false;
			if (--lastEmpty <= 0)
			{
				flag = true;
				break;
			}
		}
		if (flag) goto end;
		for (int j=2; j < c; j++)
		{
			if (!pole[1][j - 1] || !pole[1][j + 1] || !pole[1][j] || !pole[2][j]) continue;
			pole[1][j] = false;
			if (--lastEmpty <= 0)
			{
				flag = true;
				break;
			}
		}
		if (flag) goto end;
		for (int j=2; j < c; j++)
		{
			if (!pole[r][j - 1] || !pole[r][j + 1] || !pole[r][j] || !pole[r-1][j]) continue;
			pole[r][j] = false;
			if (--lastEmpty <= 0)
			{
				flag = true;
				break;
			}
		}
		if (flag) goto end;

		if (pole[1][2] && pole[2][1])
		{
			if (--lastEmpty <= 0)
				flag = true;
			pole[1][1] = false;
		}
		if (flag) goto end;
		if (pole[1][c - 1] && pole[2][c])
		{
			if (--lastEmpty <= 0)
				flag = true;
			pole[1][c] = false;
		}
		if (flag) goto end;
		if (pole[r][2] && pole[r - 1][1])
		{
			if (--lastEmpty <= 0)
				flag = true;
			pole[r][1] = false;
		}
		if (flag) goto end;
		if (pole[r - 1][c] && pole[r][c - 1])
		{
			if (--lastEmpty <= 0)
				flag = true;
			pole[r][c] = false;
		}

end:
		int res = 0;
		for (int i=1; i<=r; i++)
		{
			for (int j=1; j<=c; j++)
			{
				if (pole[i][j])
				{
					if (i + 1 <= r && pole[i+1][j])
						res++;
					if (j + 1 <= c && pole[i][j+1])
						res++;
				}
			}
		}
		return res;
}


int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int nTests;
	scanf("%d", &nTests);
	for (int test = 1; test <= nTests; test++)
	{
		
		scanf("%d %d %d", &r, &c, &n);
		
		
		printf("Case #%d: %d\n", test, min(solve1(), solve2()));
	}

	
	return 0;
}