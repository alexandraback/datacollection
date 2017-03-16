#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
#include <cassert>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)

typedef long long ll;
int T;

const int N = 10005;
ll n, x[N];

int main() {
	cin >> T;
	REP(qqq,T) {
		cin >> n;
		REP(i,n) cin >> x[i];

		ll ans1 = 0;
		REP(i,n-1) {
			if (x[i+1] < x[i]) ans1 += x[i] - x[i+1];
		}

		ll tmp = 0;
		REP(i,n-1) {
			if (x[i+1] < x[i]) tmp = max(tmp, x[i] - x[i+1]);
		}
		ll ans2 = 0;
		REP(i,n-1) {
			ans2 += min(x[i], max(tmp, x[i] - x[i+1]));
		}

		cout << "Case #" << (qqq+1) << ": " << ans1 << " " << ans2 << endl;
	}
}
