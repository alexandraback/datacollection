#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define N 1010
#define INF 1000000000000000LL

int p, n, a[N];

bool chk(ll t) {
	ll S = 0;
	for (int i = 0; i < n; i ++) {
		S += t/a[i]+1;
		if (S >= p) return 1;
	}
	if (S >= p) return 1;
	return 0;
}

int ff(ll t) {
	if (t < 0) return 0;
	ll S = 0;
	for (int i = 0; i < n; i ++) {
		S += t/a[i]+1;
	}
	return S;
}

int main() {
	int _; cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		cin >> n >> p;
		for (int i = 0; i < n; i ++) cin >> a[i];
		ll l = 0, r = INF;
		while (l <= r) {
			ll mid = (l+r)/2;
			if (chk(mid)) r = mid-1;
			else l = mid+1;
		}
		int t = p-ff(l-1);
		int S = -1;
		for (int i = 0; i < n; i ++)
			if (l%a[i] == 0) {
				t --;
				S = i+1;
				if (t == 0) break;
			}
		printf ("Case #%d: %d\n", __, S);
	}
	return 0;
}
