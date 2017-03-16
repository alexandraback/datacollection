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
int b[100][100];
int n, r, c;

int howmany()
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
	return ans;
}

void solve()
{
	cin >> r >>  c >>  n;
	int best = MAX;
	for (int i = 0; i < 1 << r * c; ++i)
	{
		for (int j = 0; j < r * c; ++j)
			a[j] = (i & (1 << j)) ? 1 : 0;

		best = min(best, howmany());
	}
	cout << best;
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