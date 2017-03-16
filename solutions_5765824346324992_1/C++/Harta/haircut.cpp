#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz size()
typedef long long ll;
typedef vector<int> vi;
const int oo = (int)1e9;
const int MAXB = 1010;
int t, b, m[MAXB];
ll n;

bool ok(ll x) {
	ll tot = 0;
	for (int i = 0; i < b; i++) {
		tot += x / m[i] + 1;
	}
	return tot >= n;
}

int main() {
	scanf("%d", &t);
	int xx = 1;
	while (t--) {
		scanf("%d%lld", &b, &n);
		for (int i = 0; i < b; i++) scanf("%d", &m[i]);
		ll lo, hi, mid, ans;
		lo = 0; hi = (ll)1e15;
		while (lo <= hi) {
			mid = lo + (hi - lo) / 2;
			if (ok(mid)) {
				ans = mid;
				hi = mid - 1;
			} else lo = mid + 1;
		}
		ll tot = 0;
		for (int i = 0; i < b; i++) {
			if (ans != 0) {
				tot += (ans - 1) / m[i] + 1;
			}
		}
		assert(tot < n);
		int ans2 = 0;
		for (int i = 0; i < b; i++) {
			if (ans % m[i] == 0) {
				tot++;
				if (tot == n) {
					ans2 = i + 1;
					break;
				}
			}
		}
		printf("Case #%d: %d\n", xx++, ans2);
	}
	return 0;
}
