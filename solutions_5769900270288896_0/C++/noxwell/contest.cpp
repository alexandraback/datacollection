#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
#define _CRT_NO_DEPRECEATE
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <memory.h>
#include <sstream>
#include <cassert>
#include <ctime>
#include <complex>

#define pb push_back
#define ll long long
#define pll pair<ll, ll>
#define mp make_pair
#define sq(x) ((x)*(x))
#define tmin(x,y,z) (min(min((x),(y)),(z)))
#define _MOD 1000000009LL
#define MOD(x) (((x) + 2LL * (_MOD)) % (_MOD))
#define INF ((int)(1e9))
#define LINF ((long long)(1e16))
#define EPS (1e-8)
#define PI (3.1415926535897932384626433832795)
#define y1 asdf_1
#define y0 asdf_2
#define j0 jj0
typedef unsigned long long ull;
typedef long double ldd;

using namespace std;

long long r, c, n;
int nx[] = { 0, -1, 1, 0 };
int ny[] = { -1, 0, 0, 1 };
bool u[20][20];
bool mu[20][20];

int get_neigh(int x, int y)
{
	int res = 0;
	for (int k = 0; k < 4; k++)
	{
		int i = x + nx[k];
		int j = y + ny[k];
		if (i >= 0 && i < r && j >= 0 && j < c && mu[i][j])
			res++;
	}
	return res;
}

long long get_u()
{
	memcpy(mu, u, sizeof mu);
	long long res = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (!mu[i][j])
				continue;
			res += get_neigh(i, j);
			mu[i][j] = 0;
		}
	}
	return res;
}

long long solve()
{
	memset(u, 0, sizeof u);
	long long res = 0;
	int cur = 0;
	for (int i = 0; i < r && cur < n; i++)
	{
		for (int j = i % 2; j < c && cur < n; j += 2)
		{
			u[i][j] = 1;
			cur++;
		}
	}

	for (int i = 0; i < r && cur < n; i++)
	{
		for (int j = 1 - i % 2; j < c && cur < n; j += 2)
		{
			u[i][j] = 1;
			cur++;
		}
	}
	res = get_u();
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < r && !flag; i++)
			for (int j = 0; j < c && !flag; j++)
			{
				if (!u[i][j]) continue;
				for (int x = 0; x < r && !flag; x++)
				{
					for (int y = 0; y < c && !flag; y++)
					{
						if (x == i && y == j) continue;
						if (u[x][y]) continue;
						u[x][y] = 1;
						u[i][j] = 0;
						int tres = get_u();
						if (tres < res)
						{
							res = tres;
							flag = 1;
							break;
						}
						u[x][y] = 0;
						u[i][j] = 1;
					}
				}
			}
	}

	return res;
}

int main()
{
	//freopen("input.txt", "w", stdout); testgen(5, 60, 120); return 0;
	//freopen("output.txt", "w", stdout);	for (int i = 1; i < 10000; i++) stress(i);	return 0;

	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int ts;
	cin >> ts;
	for (int tt = 0; tt < ts; tt++)
	{
		cin >> r >> c >> n;
		cout << "Case #" << tt + 1 << ": " << solve() << endl;
	}

	return 0;
}