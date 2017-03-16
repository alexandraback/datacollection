#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define ll long long
#define pb push_back 
#define mp make_pair
#define FOR(x, l, r) for(x = (l); x <= (r); x++)
#define FORD(x, r, l) for(x = (r); x >= (l); x --)
using namespace std;

int n, a[10000], m;
ll check(ll num) {
	ll ret = n;
	if (num < 0) return 0;
	for (int i = 1; i <= n; i ++) ret += num / a[i];
	return ret;
}
int main()
{
	int tt, cas = 0, ans;
	ll l, r, mid;
	cin >> tt;
	while (tt --) {
		cin >> n >> m;
		l = r = 0;
		for(int i = 1; i <= n; i ++) {
			scanf("%d", a + i);
			r = max(r, (ll)a[i]);
		}
		r = r * (m / n + 1);
		while (l < r) {
			mid = (l + r) / 2;
			if (check(mid) < m) l = mid + 1;
			else r = mid;
		}
		vector<int> now;
		for (int i = 1; i <= n; i ++)
			if (l % a[i] == 0) now.pb(i);
		m = m - check(l - 1);
		printf("Case #%d: %d\n", ++cas, now[m - 1]);

	}
	return 0;
}


