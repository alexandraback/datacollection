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

int a[10010];
int n, T;

int main()
{
	freopen("123.in", "r", stdin);
	freopen("123.out", "w", stdout);
	T = Getint();
	for (int _ = 1; _ <= T; _++)
	{
		n = Getint();
		for (int i = 1; i <= n; i++) a[i] = Getint();
		int ans1 = 0, ans2 = 0;
		for (int i = 2; i <= n; i++) if (a[i] < a[i - 1]) ans1 += a[i - 1] - a[i];
		int mx = 0;
		for (int i = 2; i <= n; i++) if (a[i] < a[i - 1]) mx = max(mx, a[i - 1] - a[i]);
		mx = mx;
		for (int i = 1; i <= n - 1; i++)
		{
			if (mx > a[i]) ans2 += a[i]; else ans2 += mx;
		}
		printf("Case #%d: %d %d\n", _, ans1, ans2);
	}
	return 0;
}
