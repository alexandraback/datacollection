/*
ID: eoart2
PROG: transform
LANG: C++
*/
//#define MYDEBUG
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:134217728")
#include <cstdio>
#include <iostream>
#include <iomanip> 
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <functional>
#include <cassert>
#include <random>

const long long MOD = 1000000007;
const int INF = 1000000000;
const int MAXN = 200005;
const double EPS = 1e-10;
const int HASH_POW = 7;
const double PI = acos(-1.0);

using namespace std;

void my_return(int code)
{
#ifdef MYDEBUG
	cout << "\nTime = " << fixed << setprecision(3) << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
	exit(code);
}

int r, c, n;
bool p[16][16];

bool next_soch()
{
	for (int i = r*c - 2; i >= 0; --i)
	{
		int j = i + 1;
		int x1 = i/c, y1 = i%c, x2 = j/c, y2 = j%c;
		if (p[x1][y1] && !p[x2][y2])
		{
			p[x1][y1] = false;
			p[x2][y2] = true;
			int cnt = 0;
			for (int k = j + 1; k < r*c; ++k)
			{
				int x = k/c, y = k%c;
				if (p[x][y])
				{
					++cnt;
					p[x][y] = false;
				}
			}
			for (int k = 0; k < cnt; ++k)
			{
				int x = (j + 1 + k)/c, y = (j + 1 + k)%c;
				p[x][y] = true;
			}
			return true;
		}
	}
	return false;
}

int main()
{
	//cin.sync_with_stdio(0);
	mt19937 mt_rand(time(NULL));
	#ifdef MYDEBUG
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	#else
	freopen("B-small-attempt0.in", "rt", stdin);
	freopen("B-small-attempt0.out", "wt", stdout);
	#endif
	
	int CASE;
	scanf("%d", &CASE);
	for (int t = 1; t <= CASE; ++t)
	{
		scanf("%d %d %d", &r, &c, &n);
		int ans = 100000;
		memset(p, 0, sizeof p);
		for (int i = 0; i < n; ++i)
		{
			int x = i/c, y = i%c;
			p[x][y] = true;
		}
		do
		{
			int cnt = 0;
			for (int i = 0; i < r; ++i)
			{
				for (int j = 0; j < c - 1; ++j)
				{
					if (p[i][j] && p[i][j + 1])
						++cnt;
				}
			}
			for (int i = 0; i < r - 1; ++i)
			{
				for (int j = 0; j < c; ++j)
				{
					if (p[i][j] && p[i + 1][j])
						++cnt;
				}
			}
			ans = min(ans, cnt);
		} while (next_soch());
		if (ans == 100000)
			ans = 0;
		printf("Case #%d: %d\n", t, ans);
	}

	my_return(0);
}