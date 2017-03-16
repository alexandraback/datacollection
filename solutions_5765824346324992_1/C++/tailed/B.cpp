#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<int(n); ++i)
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
typedef long long ll;
typedef pair<ll, ll> PI;

int TC;


ll a[1010];
ll B, N;
ll sum(ll t) {
	ll s = 0;
	rep(i, B) s += t / a[i] + 1;
	return s;
}
void solve() {
	cin >> B >> N;
	rep(i, B) cin >> a[i];

	ll low = -1, high = 1LL<<50;
	while(high - low > 1) {
		ll t = (low+high)/2;

		if (sum(t) >= N) high = t;
		else low = t;
	}

	ll t = high;

	assert(sum(t) >= N);
	assert(sum(t-1) < N);

	ll rem = N - sum(t-1);
	assert(rem >= 0);
	rep(i, B) {
		if (t % a[i] != 0) continue;
		rem--;
		if (rem == 0) {
			cout << i+1 << endl;
			return;
		}
	}
	assert(false);

}
int main() {
	int T; cin >> T;
	for(TC=1; TC<=T; TC++) {
		cout << "Case #" << TC << ": ";
		solve();
	}
}

