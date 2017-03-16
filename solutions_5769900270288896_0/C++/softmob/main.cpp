#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <string>
#include <functional>
#include <algorithm>
#include <stdint.h>
#include <vector>
using namespace std;

int get_bit(int n, int i)
{
	return (n >> i) & 1;
}

void solve(int test)
{
	int r, c, n;
	cin >> r >> c >> n;
	vector<vector<int> > v(r, vector<int>(c));
	int mask = (1 << 16) - 1;
	int ans = r * c * r * c;
	int dx[] = { 1, 0 };
	int dy[] = { 0, 1 };
	for (int u = 0; u <= mask; ++u)
	{
		int cnt = 0;
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				if (get_bit(u, cnt))
					v[i][j] = 1;
				else
					v[i][j] = 0;
				++cnt;
			}
		}
		int cur_ans = 0, mx = 0;
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				if (v[i][j] == 1)
					++mx;
				for (int y = 0; y < 2; ++y)
				{
					int nx = i + dx[y];
					int ny = j + dy[y];

					if (!(nx < r && ny < c))
						continue;

					if (v[i][j] == 1 && v[nx][ny] == 1)
						++cur_ans;

				}
			}
		}
		if (mx == n)
			ans = min(cur_ans, ans);
	}
	cout << "Case #" << test << ": " << ans << endl;
}

int main(void)
{
#if 1
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		solve(i);
	}
	return 0;
}