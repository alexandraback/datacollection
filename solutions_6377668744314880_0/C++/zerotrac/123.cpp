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

struct dwell
{
	LL x, y, z;
};

dwell a[3010], b[3010];

int stk[3010], ans[3010], c[3010];
int T, n;

inline LL Cross(LL a, LL b, LL c, LL d)
{
	return a * d - b * c;
}

inline bool cmp(const dwell &p, const dwell &q)
{
	LL v1x = p.x - a[1].x, v1y = p.y - a[1].y;
	LL v2x = q.x - a[1].x, v2y = q.y - a[1].y;
	double cos1 = (double)v1x / sqrt(v1x * v1x + v1y * v1y);
	double cos2 = (double)v2x / sqrt(v2x * v2x + v2y * v2y);
	return cos1 > cos2;
}

inline void Graham(int n)
{
	int w = 1;
	for (int i = 2; i <= n; i++)
	{
		if (a[i].y < a[w].y || (a[i].y == a[w].y && a[i].x < a[w].x)) w = i;
	}
	swap(a[1], a[w]);
	sort(a + 2, a + n + 1, cmp);
	int top = 1;
	stk[top] = 1;
	for (int i = 2; i <= n; i++)
	{
		while (top > 1)
		{
			LL v1x = a[stk[top]].x - a[stk[top - 1]].x, v1y = a[stk[top]].y - a[stk[top - 1]].y;
			LL v2x = a[i].x - a[stk[top]].x, v2y = a[i].y - a[stk[top]].y;
			if (Cross(v1x, v1y, v2x, v2y) < 0) top--; else break;
		}
		stk[++top] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		bool flag = false;
		for (int j = 2; j <= top; j++)
		{
			LL v1x = a[i].x - a[stk[j]].x, v1y = a[i].y - a[stk[j]].y;
			LL v2x = a[i].x - a[stk[j - 1]].x, v2y = a[i].y - a[stk[j - 1]].y;
			if (Cross(v1x, v1y, v2x, v2y) == 0) {flag = true; break;}
		}
		if (Cross(a[i].x - a[stk[1]].x, a[i].y - a[stk[1]].y, a[i].x - a[stk[top]].x, a[i].y - a[stk[top]].y) == 0) flag = true;
		if (flag) ans[a[i].z] = max(ans[a[i].z], n);
	}
}

int main()
{
	freopen("123.in", "r", stdin);
	freopen("123.out", "w", stdout);
	T = Getint();
	for (int _ = 1; _ <= T; _++)
	{
		n = Getint();
		for (int i = 1; i <= n; i++) scanf("%I64d%I64d", &b[i].x, &b[i].y);
		memset(c, 0, sizeof(c));
		memset(ans, 0, sizeof(ans));
		while (!c[0])
		{
			int now = 0;
			for (int i = 1; i <= n; i++) now += c[i];
			if (now)
			{
				int wh = 0;
				for (int i = 1; i <= n; i++) if (c[i]) a[++wh].x = b[i].x, a[wh].y = b[i].y, a[wh].z = i;
				Graham(wh);
			}
			int k = n;
			while (c[k]) c[k] = 0, k--;
			c[k]++;
		}
		printf("Case #%d:\n", _);
		for (int i = 1; i <= n; i++) printf("%d\n", n - ans[i]);
	}
	return 0;
}
