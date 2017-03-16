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

int a[1005];

int main()
{
	freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	int cases = Read();
	fo (ca, 1, cases)
	{
		int N = Read();
		fo (i, 1, N) a[i] = Read();
		int ans1 = 0, ans2 = 0, me = 0;
		fo (i, 2, N) if (a[i] < a[i - 1]) ans1 += a[i - 1] - a[i], me = max(me, a[i - 1] - a[i]);
		if (me)
		{
		//	int sing = (me - 1) / 10 + 1;
			fo (i, 1, N - 1)
				ans2 += min(a[i], me);
		}
		printf("Case #%d: %d %d\n", ca, ans1, ans2);
	}
	return 0;
}

