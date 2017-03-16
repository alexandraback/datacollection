#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:133217728")
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef vector<int> VI;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(int i = (a) - 1; i >= (b); --i)
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair
#define pi acos(-1.0)

const int MOD = 1000000007;
const int INF = 1000000007;

int cnt(int x)
{
	if (x == 0) return 0;
	return cnt(x&(x - 1)) + 1;
}

long long solve(int r, int c, int n)
{
	int N = r*c;
	int sol = INF;
	FOR(mask, 0, 1 << N)
	{
		if (cnt(mask) != n) continue;

		int m = 0;

		FOR(i,0,r)
			FOR(j, 0, c)
		{
			int b = i*c + j;
			if ((mask >> b) & 1)
			{
				if (i > 0)
				{
					// i-1 , j
					int b1 = (i - 1)*c + j;
					if ((mask >> b1) & 1) ++m;
				}

				if (j > 0)
				{
					int b2 = i*c + j - 1;
					if ((mask >> b2) & 1) ++m;
				}
			}
		}

		sol = min(sol, m);
	}
	return sol;
}

int main() 
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	int t;
	cin >> t;

	FOR(T, 0, t)
	{
		int r, c, n;
		cin >> r >> c >> n;
		cout << "Case #" << T + 1 << ": " << solve(r,c,n) << endl;
	}

	return 0;
}