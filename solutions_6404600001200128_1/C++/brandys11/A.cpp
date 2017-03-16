#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int solve() {
	int n;
	cin >> n;

	ll p, last;
	ll first = 0;
	ll diff = 0;

	vector<ll> m(n);
	for(ll &a: m) cin >> a;

	last = m[0];
	for(int i=1; i < n; i++) {
		p = m[i];
		first += max(0ll, last - p);
		diff = max(diff, last - p);
		last = p;
	}

	ll second = 0;
	last = m[0];
	for(int i=1; i < n; i++) {
		p = m[i];
		second += min(last, diff);
		last = p;
	}
	cout << first << " " << second;
	return 0;
}

int main(void) {
	int t;
	cin >> t;
	for(int i=1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
		cout << endl; 
	}	
}