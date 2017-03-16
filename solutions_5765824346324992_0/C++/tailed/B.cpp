#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<int(n); ++i)
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
typedef long long ll;
typedef pair<ll, ll> PI;

int TC;


void solve() {
	int m, N;
	cin >> m >> N;
	vector<ll> a(m);
	rep(i, m) cin >> a[i];

	ll l = 1;
	rep(i, m) {
		l = a[i] * l / __gcd(a[i], l);
	}
	ll s = 0;
	rep(i, m) {
		s += l / a[i];
	}
	N = (N-1) % s + 1;

	priority_queue<PI> Q;
	rep(i, m) Q.push(PI(0, -i));
	int n = 0;
	while(!Q.empty()) {
		ll t = -Q.top().first;
		ll i = -Q.top().second;
		Q.pop();
		n++;
		if (n == N) {
			cout << i+1 << endl;
			return;
		}

		ll nt = t + a[i];
		Q.push(PI(-nt, -i));
	}
}
int main() {
	int T; cin >> T;
	for(TC=1; TC<=T; TC++) {
		cout << "Case #" << TC << ": ";
		solve();
	}
}

