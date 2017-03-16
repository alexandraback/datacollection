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

const int MAXN = 1005;

int N, M, a[MAXN];

void init()
{
	scanf("%d%d", &N, &M);
	fo (i, 1, N) a[i] = Read();
}

LL Check(LL mid)
{
	LL sum = 0;
	fo (i, 1, N) sum += mid / a[i];
	return sum;
}

void work()
{
	if (M <= N) { printf("%d\n", M); return; } M -= N;
	LL l = 0, r = 1e15, ans = 0;
	while (l <= r)
	{
		LL mid = (l + r) >> 1;
		if (Check(mid) < M) ans = mid, l = mid + 1; else r = mid - 1;
	}
	M -= Check(ans);
	fo (i, 1, N) if ((ans + 1) % a[i] == 0)
		if (-- M == 0) { printf("%d\n", i); return; }
}

int main()
{
	freopen("b.in", "r", stdin), freopen("b.out", "w", stdout);
	int cases = Read();
	fo (ca, 1, cases)
	{
		init();
		printf("Case #%d: ", ca);
		work();
	}
	return 0.0;
}

