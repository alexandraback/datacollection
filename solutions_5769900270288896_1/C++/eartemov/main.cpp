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

int main()
{
	//cin.sync_with_stdio(0);
	mt19937 mt_rand(time(NULL));
	#ifdef MYDEBUG
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	#else
	freopen("B-large.in", "rt", stdin);
	freopen("B-large.out", "wt", stdout);
	#endif

	int CASE;
	scanf("%d", &CASE);
	for (int t = 1; t <= CASE; ++t)
	{
		int r, c, n;
		int ans = 1000000000;
		scanf("%d %d %d", &r, &c, &n);
		int cnt[5], used, pt;

		memset(cnt, 0, sizeof cnt);
		used = 0;
		pt = 1;
		for (int i = 1; i <= r; ++i)
		{
			for (int j = 1; j <= c; ++j)
			{
				if ((i + j) % 2 == 0)
				{
					int tmp = 0;
					if (i > 1)
						++tmp;
					if (i < r)
						++tmp;
					if (j > 1)
						++tmp;
					if (j < c)
						++tmp;
					++cnt[tmp];
				}
				else
				{
					++used;
				}
			}
		}
		int sum = 0;
		for (int i = 0; i < n - used; ++i)
		{
			if (cnt[pt] == 0)
				++pt;
			--cnt[pt];
			sum += pt;
		}
		ans = min(ans, sum);

		memset(cnt, 0, sizeof cnt);
		used = 0;
		pt = 1;
		for (int i = 1; i <= r; ++i)
		{
			for (int j = 1; j <= c; ++j)
			{
				if ((i + j) % 2 == 1)
				{
					int tmp = 0;
					if (i > 1)
						++tmp;
					if (i < r)
						++tmp;
					if (j > 1)
						++tmp;
					if (j < c)
						++tmp;
					++cnt[tmp];
				}
				else
				{
					++used;
				}
			}
		}
		sum = 0;
		for (int i = 0; i < n - used; ++i)
		{
			while (cnt[pt] == 0)
				++pt;
			--cnt[pt];
			sum += pt;
		}
		ans = min(ans, sum);

		printf("Case #%d: %d\n", t, ans);
	}

	my_return(0);
}