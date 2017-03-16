#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

const int maxn = 2005;
int tst, m;
ll n, a[maxn];
ll calc(ll v)  { //# < v
	ll sum = 0;
	for (int i = 1; i <= m; i ++)  {
		ll tmp = v / a[i];
		if (v % a[i] == 0)  tmp --;
		sum += tmp + 1;
	}
	return sum;
}

int main()  {
	scanf("%d", &tst);
	for (int t = 1; t <= tst; t ++)  {
		scanf("%d%lld", &m, &n);
		for (int i = 1; i <= m; i ++)  
			scanf("%lld", &a[i]);
		ll l = 0, r = (ll)1e15;
		#define md ((l + r) >> 1)
		while (l <= r)  {
			if (calc(md) < n)  l = md + 1;
			else r = md - 1;
		}
		ll v = l - 1;
		int ans = 0;
		n -= calc(v);
		//printf("v=%lld\n",v);
		for (int i = 1; i <= m; i ++)  {
			if (v % a[i] == 0)  n --;
			if (n == 0)  {
				ans = i;
				break;
			}
		}
		printf("Case #%d: %d\n",t, ans);
	}
	return 0;
}