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
#include<queue>
using namespace std;
long long solve(int r, int c, int n)
{	
	if (r == 1)
	{
		int can = c / 2;
		if (c % 2) can++;
		if (n <= can)
		{
			return 0;
		}
		else
		{
			return (n - can) * 2;
		}
	}
	if (r % 2 == 0 && c % 2 == 0)
	{
		int have = (r*c) / 2;
		if (have >= n) return 0;
		int p = 2 * r + 2 * c - 4;
		int have1 = 2, have2 = p / 2 - have1, have3 = (r*c - p) / 2;
		int ans = 0;
		n -= have;
		if (n > 0)
		{
			ans += 2*min(have1, n);
			n -= min(have1, n);
		}
		if (n > 0)
		{
			ans += 3 * min(have2, n);
			n -= min(have2, n);
		}
		if (n > 0)
		{
			ans += 4 * min(have3, n);
			n -= min(have3, n);
		}
		return ans;
	}
	if (r % 2 == 1 && c % 2 == 1)
	{
		int have = (r*c) / 2+1;
		if (have >= n) return 0;
		int p = 2 * r + 2 * c - 4;
		int have1 = 0, have2 = p / 2, have3 = (r*c - p) / 2;
		int ans = 0;
		n -= have;
		if (n > 0)
		{
			ans += 2 * min(have1, n);
			n -= min(have1, n);
		}
		if (n > 0)
		{
			ans += 3 * min(have2, n);
			n -= min(have2, n);
		}
		if (n > 0)
		{
			ans += 4 * min(have3, n);
			n -= min(have3, n);
		}
		return ans;
	}
	int have = (r*c) / 2;
	if (have >= n) return 0;
	int p = 2 * r + 2 * c - 4;
	int have1 = 2, have2 = p / 2-have1, have3 = (r*c - p) / 2;
	int ans = 0;
	n -= have;
	if (n > 0)
	{
		ans += 2 * min(have1, n);
		n -= min(have1, n);
	}
	if (n > 0)
	{
		ans += 3 * min(have2, n);
		n -= min(have2, n);
	}
	if (n > 0)
	{
		ans += 4 * min(have3, n);
		n -= min(have3, n);
	}
	return ans;
}long long solve2(int r, int c, int n)
{
	if (r == 1)
	{
		int can = c / 2;
		if (c % 2) can++;
		if (n <= can)
		{
			return 0;
		}
		else
		{
			return (n - can) * 2;
		}
	}
	if (r % 2 == 0 && c % 2 == 0)
	{
		int have = (r*c) / 2;
		if (have >= n) return 0;
		int p = 2 * r + 2 * c - 4;
		int have1 = 2, have2 = p / 2 - have1, have3 = (r*c - p) / 2;
		int ans = 0;
		n -= have;
		if (n > 0)
		{
			ans += 2 * min(have1, n);
			n -= min(have1, n);
		}
		if (n > 0)
		{
			ans += 3 * min(have2, n);
			n -= min(have2, n);
		}
		if (n > 0)
		{
			ans += 4 * min(have3, n);
			n -= min(have3, n);
		}
		return ans;
	}
	if (r % 2 == 1 && c % 2 == 1)
	{
		int have = (r*c) / 2 + 1;
		if (have >= n) return 0;
		int p = 2 * r + 2 * c - 4;
		int have1 = 4, have2 = p / 2-have, have3 = (r*c - p) / 2;
		int ans = 0;
		n -= have;
		if (n > 0)
		{
			ans += 2 * min(have1, n);
			n -= min(have1, n);
		}
		if (n > 0)
		{
			ans += 3 * min(have2, n);
			n -= min(have2, n);
		}
		if (n > 0)
		{
			ans += 4 * min(have3, n);
			n -= min(have3, n);
		}
		return ans;
	}
	int have = (r*c) / 2;
	if (have >= n) return 0;
	int p = 2 * r + 2 * c - 4;
	int have1 = 2, have2 = p / 2 - have1, have3 = (r*c - p) / 2;
	int ans = 0;
	n -= have;
	if (n > 0)
	{
		ans += 2 * min(have1, n);
		n -= min(have1, n);
	}
	if (n > 0)
	{
		ans += 3 * min(have2, n);
		n -= min(have2, n);
	}
	if (n > 0)
	{
		ans += 4 * min(have3, n);
		n -= min(have3, n);
	}
	return ans;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		int r, c, n;
		cin >> r >> c >> n;
		cout << "Case #" << tt << ": " << min(min(solve(r, c, n), solve(c, r, n)), min(solve2(r, c, n), solve2(c, r, n))) << endl;
	}
}
