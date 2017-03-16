#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pllll;

struct cmp {
	bool operator()(const pllll &b1, const pllll &b2) const {
		// return true if b1 has lower priority than b2
		return b1.first > b2.first || (b1.first == b2.first && b1.second > b2.second);
	}
};

ll nbarbers;
ll barbers[10000];

// number of completed + in progress cuts
ll eval(ll t) {
	ll numcut = 0;
	for (int i = 0; i < nbarbers; i++) {
		ll q = t / barbers[i];
		ll r = t % barbers[i];
		if (r > 0) q++;
		numcut += q;
	}
	return numcut;
}
int main() {
	int nc; cin >> nc; 
	for (int cs = 1; cs <= nc; cs++) {
		ll n; cin >> nbarbers >> n;
		for (int i = 0; i < nbarbers; i++) {
			cin >> barbers[i];
		}

		ll hi = 100000LL * (n / nbarbers + 10LL);
		ll lo = 0;
		while (hi - lo > 2) {
			//cerr << lo << " " << hi << endl;
			ll mid = (lo+hi)/2;
			if (eval(mid) >= n) hi = mid;
			else lo = mid;
		}
		while (lo < hi && eval(lo+1) < n) lo++;

		//lo = 0;
		ll num = eval(lo);
		//cerr << "time = " << lo << ", num = " << num << endl;
		priority_queue<pllll, vector<pllll>, cmp> q;
		for (int i = 0; i < nbarbers; i++) {
			ll next = barbers[i] * (lo / barbers[i]);
			if (lo % barbers[i] > 0) next += barbers[i];
			q.push(pllll(next, i));
		}

		ll ans = 0;
		while (num < n) {
			pllll barber = q.top();
			q.pop();

			//cerr << "customer " << num << ", barber " << barber.second << ", time " << barber.first << endl;
			ans = barber.second;
			q.push(pllll(barber.first + barbers[barber.second], barber.second));
			num++;
		}

		cout << "Case #" << cs << ": " << ans+1 << endl;
	}
}
