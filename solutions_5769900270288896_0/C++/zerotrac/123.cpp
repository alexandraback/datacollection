#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

#define pb push_back
#define mp make_pair
#define LL long long
#define LD long double
#define maxlongint 2147483647

using namespace std;

const int inf = 999999999;
const int mod = 1000000007;

inline int Getint()
{
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	int ret = 0;
	while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
	return ret;
}

vector <int> a[2];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int T, r, c, n;

inline int Calc(int n, int p)
{
	int ret = 0;
	sort(a[p].begin(), a[p].end());
	if (n <= a[p ^ 1].size()) return ret;
	n -= a[p ^ 1].size();
	for (int i = 0; i < n; i++) ret += a[p][i];
	return ret;
}

int main()
{
	freopen("123.in", "r", stdin);
	freopen("123.out", "w", stdout);
	T = Getint();
	for (int _ = 1; _ <= T; _++)
	{
		r = Getint(), c = Getint(), n = Getint();
		a[0].clear(), a[1].clear();
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++)
			{
				int cnt = 0;
				for (int k = 0; k < 4; k++)
				{
					int x0 = i + dx[k], y0 = j + dy[k];
					if (x0 >= 1 && x0 <= r && y0 >= 1 && y0 <= c) cnt++;
				}
				a[i + j & 1].pb(cnt);
			}
		printf("Case #%d: %d\n", _, min(Calc(n, 0), Calc(n, 1)));
	}
	return 0;
}
