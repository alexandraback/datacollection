#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
#define INF 9999999999999LL
int main() {
	ios::sync_with_stdio(false);
	ll cases;
	cin >> cases;
	for (ll casenum = 1; casenum <= cases; casenum++) {
		ll r; ll c; ll n;
		cin >> r; cin >> c; cin >> n;
		ll lim = 1<<(r*c);
		bool **a = new bool*[r+1];
		for (ll i = 0; i <= r; i++) {
			a[i] = new bool[c+1];
		}
		for (ll i = 0; i <= r; i++) {
			for (ll j = 0; j <= c; j++) {
				a[i][j] = false;
			}
		}
		ll ans = INF;
		for (ll z = 0; z < lim; z++) {
			if (__builtin_popcountll(z) != n) continue;
			ll t = z;
			for (ll i = 0; i < r; i++) {
				for (ll j = 0; j < c; j++) {
					a[i][j] = ((t & 0x1) != 0);
					t = t >> 1;
				}
			}
			ll cand = 0;
			for (ll i = 0; i < r; i++) {
				for (ll j = 0; j < c; j++) {
					if (a[i][j]) {
						if (a[i][j+1]) {
							cand++;
						}
						if (a[i+1][j]) {
							cand++;
						}
					}
				}
			}
			ans = min(ans,cand);
		}
		cout << "Case #" << casenum << ": " << ans << endl;
	}
}
