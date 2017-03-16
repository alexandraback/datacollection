#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdio>
#include <map>
#include <hash_map>
#include <string>
#include <iomanip>
#include <vector>
#include <memory.h>
#include <queue>
#include <set>
#include <stack> 
#include <algorithm>
#include <math.h>
#include <sstream>
#include <functional>
#include <bitset>
#pragma comment (linker, "/STACK:167177216")
using namespace std;
#define mems(A, val) memset(A, val, sizeof(A))
#define mp(a, b) make_pair(a, b)
#define all(B) (B).begin(), (B).end()
#define forn(it, from, to) for(int it = from; it < to; ++it)
#define forit (it, coll) for(auto it = coll.begin(); it != coll.end(); ++it)
const int MAX = 2147483647;
const int MAXN = 1000000 + 10000;
typedef long long LL;
const LL MOD = 1000000000 + 7;

int D[17][1 << 16][17];
int r,c,n;
int rec(int num, int mask, int need)
{
	if (num == r)
	{
		if (need == 0) return 0;
		return 999999999;
	}

	if (need == 0) return 0;
	int result = 999999999;
	for (int i = 0; i < (1 << c); ++i)
	{
		int count = 0;
		for(int j = 0; j < c; ++j)
		{
			if (i & (1 << j)) count++;
		}

		if (count > need) continue;
		int bad = 0;
		for(int j = 0; j < c; ++j)
		{
			if ((mask & (1 << j)) && (i & (1 << j)))
			{
				bad++;
			}
		}

		for(int j = 0; j < c - 1; ++j)
		{
			if ((i & (1 << j)) && (i & (1 << (j + 1))))
			{
				bad++;
			}
		}

		if (D[num + 1][i][need - count] == -1)
		{
			D[num + 1][i][need - count] = rec(num + 1, i, need - count);
		}

		result = min(result, D[num + 1][i][need - count] + bad);
	}
	return result;
}

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    //freopen("f.in", "r", stdin); freopen("f.out", "w", stdout);
#endif
	int T;
	cin>>T;
	
	forn(asdasd, 0, T)
	{
		
		cin>>r>>c>>n;
		if (c > r) swap(c, r);
		int ans = 0;
		mems(D, -1);
		ans = rec(0, 0, n);
		printf("Case #%d: %d\n", asdasd + 1,ans);
	}

    return 0;
}