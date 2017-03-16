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

int n;
int a[MAXN];

inline void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	int ans1 = 0;
	for (int i = 0; i + 1 < n; ++i)
		if (a[i] > a[i + 1])
			ans1 += a[i] - a[i + 1];
	int t = 0;
	for (int i = 0; i + 1 < n; ++i)
		t = max(t, a[i] - a[i + 1]);
	int ans2 = 0;
	for (int i = 0; i + 1 < n; ++i)
		ans2 += min(t, a[i]);
	printf("%d %d\n", ans1, ans2);
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
