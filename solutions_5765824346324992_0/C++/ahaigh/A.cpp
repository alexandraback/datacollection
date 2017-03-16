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
	ll x = 0;
	REP(i,b) x += 1 + (t / m[i]);
	return x;
}

ll brute() {
	ll time = 0;
	int here;
	priority_queue<pair<int,int> > q;
	REP(i,b) q.push(make_pair(-time, -i));	
	REP(i,n) {
		time = -q.top().first;
		here = -q.top().second;
		//cout << time << " " << here << endl;
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

		ll low = 0, high = 1e15;
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

		int at = have_served(low-1);

		int ans = b;
		REP(i,b) {
			if (low % m[i] == 0) {
				at++;
				if (at == n) ans = i;
			}
		}

		cout << "Case #" << (qqq+1) << ": " << (ans+1) << endl;
		//cout << (brute()+1) << endl;
		if (n < 5000) {
			assert(ans == brute());
		}
	}
}
