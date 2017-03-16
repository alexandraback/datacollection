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

int a[1010];
int T, n, loc;

int main()
{
	freopen("123.in", "r", stdin);
	freopen("123.out", "w", stdout);
	T = Getint();
	for (int _ = 1; _ <= T; _++)
	{
		n = Getint(), loc = Getint();
		for (int i = 1; i <= n; i++) a[i] = Getint();
		LL l = 0, r = 100000000000000LL, ans = 0;
		while (l <= r)
		{
			LL mid = (l + r) / 2;
			LL cnt = 0;
			for (int i = 1; i <= n; i++)
			{
				cnt += mid / a[i] + 1;
				if (cnt >= loc) break;
			}
			if (cnt >= loc) ans = mid, r = mid - 1; else l = mid + 1;
		}
		LL now = 0;
		for (int i = 1; i <= n; i++) now += ans / a[i] + (ans % a[i] != 0);
		for (int i = 1; i <= n; i++)
		{
			now += (ans % a[i] == 0);
			if (now == loc) {printf("Case #%d: %d\n", _, i); break;}
		}
	}
	return 0;
}
