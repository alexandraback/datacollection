#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<bitset>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
bool cur[25][25];
long long solve(int r, int c, int n)
{
	int ans = 20 * r*c;	
	for (int mask = 0; mask < (1 << r*c); mask++)
	{
		int used = 0;
		int tmp = mask, x = 1, y = 1;
		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 25; j++)
			{
				cur[i][j] = false;
			}
		}
		for (int i = 1; i <= r*c; i++)
		{
			if (tmp % 2 == 1)
			{
				cur[y][x] = true;
				used++;
			}
			x++;
			if (x > c)
			{
				x = 1;
				y++;
			}
			tmp /= 2;
		}
		if (used != n) continue;
		int curans = 0;
		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				if (cur[i][j] && cur[i+1][j])
				{
					curans++;
				}
				if (cur[i][j] && cur[i][j + 1])
				{
					curans++;
				}
			}
		}
		ans = min(ans, curans);
	}
	return ans;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++)
	{
		int r, c, n;
		cin >> r >> c >> n;		
		cerr << tt << endl;
		cout << "Case #" << tt << ": " << solve(r,c,n) << endl;
	}
}
