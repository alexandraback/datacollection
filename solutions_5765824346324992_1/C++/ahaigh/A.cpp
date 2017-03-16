#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
#include <cassert>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)

typedef long long ll;
int T;

ll b, n, m[1005];

ll have_served(ll t) {
	if (t < 0) return 0;

	ll x = 0;
	REP(i,b) x += 1 + (t / m[i]);
	return x;
}

ll brute() {
	ll time = 0;
	ll here;
	priority_queue<pair<ll,ll> > q;
	REP(i,b) q.push(make_pair(-time, -i));	
	REP(i,n) {
		time = -q.top().first;
		here = -q.top().second;
		//cout << i << " " << time << " " << here << endl;
		q.pop();
		q.push(make_pair(-(time + m[here]), -here));
	}
	return here;
}

int main() {
	cin >> T;
	REP(qqq,T) {
		cin >> b >> n;
		REP(i,b) cin >> m[i];

		ll low = 0, high = ((1ll)<<50);
		while (low < high) {	
			ll mid = (low+high)/2;
			if (have_served(mid) < n) {
				low = mid+1;
			} else {
				high = mid;
			}
		}

		//cout << low << " " << n << " " << have_served(low-1) << " " <<
		//		have_served(low) << endl;

		ll at = have_served(low-1);
		//cout << low << " " << at << endl;

		ll ans = b;
		REP(i,b) {
			if (low % m[i] == 0) {
				at++;
				if (at == n) ans = i;
			}
		}

		cout << "Case #" << (qqq+1) << ": " << (ans+1) << endl;
		assert(ans >= 0 && ans < b && low >= 0 && low < ((1ll)<<50));

		//cout << (brute()+1) << endl;nano
		if (n < 500000) {
			//cout << "check" << endl;
			assert(ans == brute());
		}
	}
}
