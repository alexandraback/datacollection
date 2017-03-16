/*
	Time : 0839Z 20141119
	Task : Codeforces 321D
	Tags : Enumeration
	Stat : Coding
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <map>
#include <set>
#include <cmath>
#include <numeric>

#define fi first
#define se second
#define fo(i,a,b) for (int i = a; i <= b; i ++)
#define fd(i,a,b) for (int i = a; i >= b; i --)
#define fe(i,x,y) for (int i = x, y = lnk[i]; i; i = nxt[i], y = lnk[i])
#define mkp make_pair
#define pb push_back
#define Fill(x,y) memset(x,y,sizeof(x))
#define Cpy(x,y) memcpy(x,y,sizeof(x))
#define Bit(x,y) ((((x) >> (y)) & 1))
#define mit map<int,SI>::iterator
#define sit SI::iterator

using namespace std;
 
typedef long long LL;
typedef long double LD;
typedef pair <double, double> PD;
typedef pair <LL, LL> PLI;
typedef pair <PD, int> PDI;
typedef pair <int, int> PI;
typedef pair <int, PI> PII;
typedef pair <PI, PI> PIII;
typedef set <PI> SI;
typedef vector <int> VI;
 
int Read()
{
    char c; while (c = getchar(), (c != '-') && (c < '0' || c > '9'));
    bool neg = (c == '-'); int ret = (neg ? 0 : c - 48);
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + c - 48;
    return neg ? -ret : ret;
}

const int MAXN = 3005;
const long double eps = 1e-12, pi = acos(-1);

PI a[MAXN];
int N, sx, sy, ord[MAXN];
long double rad[MAXN<<1];

void init()
{
	scanf("%d", &N);
	fo (i, 1, N)
		scanf("%d%d", &a[i].fi, &a[i].se);
}

int sign(long double x) { return x < -eps ? -1 : x > eps ? 1 : 0; }

bool cmp(int x, int y) { return sign(atan2l(a[x].se - sy, a[x].fi - sx) - atan2l(a[y].se - sy, a[y].fi - sx)) < 0; }

void work()
{
	if (N <= 3) { fo (i, 1, N) puts("0"); return; }
	fo (i, 1, N)
	{
		sx = a[i].fi, sy = a[i].se; int n = 0;
		fo (j, 1, N) if (i != j) rad[++ n] = atan2l(a[j].se - a[i].se, a[j].fi - a[i].fi);
		sort(rad + 1, rad + N);
		fo (j, N, n+n) rad[j] = rad[j - n] + 2 * pi;
		int k = 1, ans = N - 3;
		fo (j, 1, n)
		{
			for (k = max(k, j); k <= n + n && sign(rad[k] - rad[j] - pi) <= 0; k ++);
			ans = min(ans, n - k + j);
		}
		printf("%d\n", ans);
	}
}

int main()
{
	freopen("c.in", "r", stdin), freopen("c.out", "w", stdout);
	int cases = Read();
	fo (ca, 1, cases)
	{
		init();
		printf("Case #%d:\n", ca);
		work();
	}
	return 0.0;
}

