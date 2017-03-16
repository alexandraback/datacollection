#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	ll cases;
	cin >> cases;
	for (ll casenum = 1; casenum <= cases; casenum++) {
		ll n;
		cin >> n;
		ll *a = new ll[n];
		for (ll i = 0; i < n; i++) {
			cin >> a[i];
		}
		ll x = 0;
		for (ll i = 1; i < n; i++) {
			x += max(0LL, a[i-1] - a[i]);
		}
		ll y = 0;
		for (ll i = 1; i < n; i++) {
			y = max(y,a[i-1] - a[i]);
		}
		ll ans = 0;
		for (ll i = 0; i < (n-1); i++) {
			ans += min(a[i],y);
		}
		cout << "Case #" << casenum << ": " << x << " " << ans << endl;
	}
}
