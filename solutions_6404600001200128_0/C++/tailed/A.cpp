#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<int(n); ++i)
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
typedef long long ll;

int TC;


void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];

	int ans1 = 0;
	int dif = 0;
	rep(i, n-1) {
		ans1 += max(0, a[i] - a[i+1]);
		dif = max(dif, a[i] - a[i+1]);
	}

	int s = 0;
	rep(i, n-1) {
		int k = max(a[i] - dif, 0);
		s += a[i] - k;
	}
	cout << ans1 << " " << s << endl;
}
int main() {
	int T; cin >> T;
	for(TC=1; TC<=T; TC++) {
		cout << "Case #" << TC << ": ";
		solve();
	}
}

