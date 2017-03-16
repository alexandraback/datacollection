#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
ll b,n;
ll *a;
ll f(ll t) {
	ll ans = 0;
	for (ll k = 0; k < b; k++) {
		ans += (t+a[k]-1)/a[k];
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	ll cases;
	cin >> cases;
	for (ll casenum = 1; casenum <= cases; casenum++) {
		cin >> b; cin >> n;
		a = new ll[b];
		for (ll i = 0; i < b; i++) {
			cin >> a[i];
		}
		ll best;
		ll low = 0;
		ll high = 100000000000000001LL;
		while (low <= high) {
			ll x = low + (high - low)/2;
			if (f(x) >= n) {
				best = x;
				high = x-1;
			}
			else {
				low = x+1;
			}
		}
		ll togo = n - f(best-1);
		//cout << "togo:" << togo << " b:" << b << " best:" << best << endl;
		assert(togo > 0);
		ll ans = -1;
		for (ll i = 0; i < b; i++) {
			if ((best-1) % a[i] == 0) {
				togo--;
			}
			if (togo == 0) {
				ans = i+1;
				break;
			}
		}
		assert(ans != -1);
		cout << "Case #" << casenum << ": " << ans << endl;
	}
}
