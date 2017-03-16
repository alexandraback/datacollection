#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
typedef long long int64;
#define rep(x, n) for (int x = 1; x <= n; ++x)
#define zrp(x, n) for (int x = n; x; --x)
#define FOR(x, l, r) for (int x = l; x <= r; ++x)
#define foredge(i, x) for (int i = start[x]; i; i = e[i].l)
struct edge{int a, l;};
int n, m, k, now;
int s[10];

int work()
{
	s[1] = 0;
	s[2] = 0;
	s[3] = 0;
	s[4] = 0;

	int cnt = 0;
	rep(i, n) rep(j, m)
	{
		if ((i + j) & 1)
		{
			int tmp = 4;
			++cnt;
			if (i == 1) --tmp;
			if (i == n) --tmp;
			if (j == 1) --tmp;
			if (j == m) --tmp;
			++s[tmp];
		}
	}

	int res = 0, kk = k;
	if (kk <= (n * m) - cnt) return 0;

	kk -= (n * m) - cnt;

	res += min(kk, s[1]);
	kk -= min(kk, s[1]);
	res += min(kk, s[2]) * 2;
	kk -= min(kk, s[2]);
	res += min(kk, s[3]) * 3;
	kk -= min(kk, s[3]);
	res += min(kk, s[4]) * 4;
	kk -= min(kk, s[4]);
	int ans = res;

	s[1] = 0;
	s[2] = 0;
	s[3] = 0;
	s[4] = 0;
	cnt = 0;
	rep(i, n) rep(j, m)
	{
		if (((i + j) & 1) == 0)
		{
			int tmp = 4;
			++cnt;
			if (i == 1) --tmp;
			if (i == n) --tmp;
			if (j == 1) --tmp;
			if (j == m) --tmp;
			++s[tmp];
		}
	}

	res = 0, kk = k;
	if (kk <= (n * m) - cnt) return 0;
	kk -= (n * m) - cnt;

	res += min(kk, s[1]);
	kk -= min(kk, s[1]);
	res += min(kk, s[2]) * 2;
	kk -= min(kk, s[2]);
	res += min(kk, s[3]) * 3;
	kk -= min(kk, s[3]);
	res += min(kk, s[4]) * 4;
	kk -= min(kk, s[4]);

	return min(ans, res);

}

int main()
{
	int ca, t;
	scanf("%d", &ca);
	rep(t, ca)
	{
		scanf("%d%d%d", &n, &m, &k);
		printf("Case #%d: %d\n", t, work());
	}
	return 0;
}
