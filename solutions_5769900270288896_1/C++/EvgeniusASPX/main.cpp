#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAX = 1000200;
int a[MAX];
bool b[10010][10010];
int n, r, c;
int good = 0;
int howmany(bool fPrint)
{
	int rc = r*c;
	int cnt = 0;
	for (int i = 0; i < rc; ++i)
		if (a[i])
			cnt++;
	if (cnt != n)
		return MAX;
	memset(b, 0, sizeof(b));
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; ++j)
			b[i][j] = a[(i - 1)* c + j - 1];
	int ans = 0;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; ++j)
		{
			if (b[i][j] && b[i + 1][j])
				ans++;
			if (b[i][j] && b[i][j + 1])
				ans++;
		}
	if (ans == good && fPrint)
	{
		cout << "++++++++++++\n";
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
				cout << b[i + 1][j + 1];
			cout << endl;
		}
		cout << "++++++++++++";
	}
	return ans;
}

void solve()
{
	cin >> r >>  c >>  n;
	int best = MAX;
	/*for (int i = 0; i < 1 << r * c; ++i)
	{
		for (int j = 0; j < r * c; ++j)
			a[j] = (i & (1 << j)) ? 1 : 0;

		best = min(best, howmany(false));
	}*/
	
	memset(b, false, sizeof(b));
	int best1 = 0;
	int left = n;
	for (int i = 1; i <= r; ++i)
		for (int j = 1; j <= c; ++j)
			if ((i + j) % 2 == 0)
				b[i][j] = true, left--;

	if (left > 0)
	{
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= r; ++i)
			for (int j = 1; j <= c; ++j)
				if (!b[i][j])
				{
					int cnt = 0;
					if (b[i - 1][j])
						cnt++;
					if (b[i + 1][j])
						cnt++;
					if (b[i][j + 1])
						cnt++;
					if (b[i][j - 1])
						cnt++;
					a[cnt]++;
				}

		for (int k = 1; k < 5; ++k)
		{
			if (left > 0)
			{
				int take = min(left, a[k]);
				best1 += k * take;
				left -= take;
			}
		}
	}
	memset(b, false, sizeof(b));
	int best2 = 0;
	left = n;
	for (int i = 1; i <= r; ++i)
		for (int j = 1; j <= c; ++j)
			if ((i + j) % 2 == 1)
				b[i][j] = true, left--;

	if (left > 0)
	{
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= r; ++i)
			for (int j = 1; j <= c; ++j)
				if (!b[i][j])
				{
					int cnt = 0;
					if (b[i - 1][j])
						cnt++;
					if (b[i + 1][j])
						cnt++;
					if (b[i][j + 1])
						cnt++;
					if (b[i][j - 1])
						cnt++;
					a[cnt]++;
				}

		for (int k = 1; k < 5; ++k)
		{
			if (left > 0)
			{
				int take = min(left, a[k]);
				best2 += k * take;
				left -= take;
			}
		}
	}

	/*if (best != best1 && best != best2)
	{
		good = best;

		for (int i = 0; i < 1 << r * c; ++i)
		{
			for (int j = 0; j < r * c; ++j)
				a[j] = (i & (1 << j)) ? 1 : 0;

			howmany(true);
		}
	}*/
	cout << min(best1, best2);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	
	for (int i = 0; i < T; ++i)
	{
		cout << "Case #" << i + 1 << ": ";
		solve();
		cout << endl;
	}
	return 0;
}