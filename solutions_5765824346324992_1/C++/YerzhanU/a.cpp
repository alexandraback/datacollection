#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <deque>
#include <cassert>

using namespace std;

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
#define sz(s) (int(s.size()))
#define fname "a"
#define ms(a,x) memset(a, x, sizeof(a))
#define forit(it,s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); ++it)
#define MAXN 3003

int n, p;
int a[MAXN];

inline ll get(ll x)
{
	ll res = 0;
	for (int i = 0; i < n; ++i)
		res += (x + a[i] - 1) / a[i];
	return res;
}

inline void solve()
{
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	ll l = 0, r = ll(1e15);
	while(l + 1 < r)
	{
		ll m = (l + r) / 2;
		if (get(m) < p)
			l = m;
		else
			r = m;
	}
	int k = p - get(l);
	for (int i = 0, j = 0; i < n; ++i)
	{
		if (l % a[i] == 0) ++j;
		if (j == k)
		{
			printf("%d\n", i + 1);
			return;
		}
	}
}

int main()
{
	#ifdef LOCAL
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	#endif

	int tt;
	scanf("%d", &tt);
	for (int t = 0; t < tt; ++t)
	{
		printf("Case #%d: ", t + 1);
		solve();
	}
	return 0;
}
