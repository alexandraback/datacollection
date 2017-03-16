#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <utility>
#include <string.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cctype>

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef long lint;

#define MP make_pair
#define PB push_back
#define EPS 0.0000001
#define ALL(a) a.begin(), a.end()

const int INF = 1000 * 1000 * 1000;
const int MOD = 1000 * 1000 * 1000 + 7;
const lint INF_L = 1000 * 1000 * 1000;
const ll INF_LL = 1LL * INF_L * INF_L;
const ll MOD_LL = 1000000000007LL;


ll gcd(ll a, ll b)
{
	while (b)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}

ll lcm(ll a, ll b)
{
	return (a / gcd(a, b)) * b;
}

int onesCount(int n)
{
	int cnt = 0;
	while (n)
	{
		cnt += (1 & n);
		n >>= 1;
	}
	return cnt;
}

int cells[17][17];
int r, c, n;

void reset(int v)
{
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cells[i][j] = v;
		}
	}
}

void fill(int v, int mask)
{
	for (int k = 0; k < r * c; ++k)
	{
		if (1 & mask >> k)
		{
			cells[k / c][k % c] = v;
		}
	}
}

int calc()
{
	int cnt = 0;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c - 1; ++j)
		{
			cnt += (cells[i][j] == 1 && cells[i][j + 1] == 1);
		}
	}
	for (int j = 0; j < c; ++j)
	{
		for (int i = 0; i < r - 1; ++i)
		{
			cnt += (cells[i][j] == 1 && cells[i + 1][j] == 1);
		}
	}
	return cnt;
}

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		int n;
		cin >> r >> c >> n;
		int ans = -1;
		int v = 1;
		if (n > r * c / 2)
		{
			v = 0;
			n = r * c - n;
		}
		for (int j = 0; j < 1 << r * c; ++j)
		{
			if (onesCount(j) == n)
			{
				reset(1 - v);
				fill(v, j);
				int cur = calc();
				if (ans == -1 || cur < ans)
					ans = cur;
			}
		}
		printf("Case #%d: %d\n", i, ans);
	}

	return 0;
}