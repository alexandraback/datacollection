#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define REP(i,n) for(int i = 0; i < (n); i++)
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;

ll b, n;
int m[1000+20];

ll test(ll t) {
	ll tot = 0;
	REP(i,b) {
		tot += t / m[i];
		if (t % m[i] != 0) tot++;
	}
	return tot;
}

int solve() {
	cin >> b >> n;
	REP(i,b) cin >> m[i];
	ll lo = 0;
	ll hi = m[0] * (n+1);
	while (lo < hi) {
		ll mi = lo + (hi-lo) / 2;
		if (test(mi) >= n) {
			hi = mi;
		} else {
			lo = mi + 1;
		}
	}
	lo--;
	ll elapsed = test(lo);
	ll left = n - elapsed;
	// cout << elapsed << ' ' << left << endl;
	REP (i, b) {
		if (lo % m[i] == 0) {
			left--;
			if (left == 0)
				return i+1;
		}
	}
	cout << "!!!!!!!!!! ERR" << endl;
	return 1;
}

int main() {
	int t;
	scanf(" %d", &t);
	REP(i, t) {
		printf("Case #%d: %d\n", i+1, solve());
	}
}