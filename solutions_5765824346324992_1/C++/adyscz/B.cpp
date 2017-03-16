#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int mins(vector<ll> &Ms, ll N)
{
	const ll MAX = 1000000000ULL * 100000ULL;
	ll b = 0, e = MAX + 10;
	while (true) {
		ll cnt = Ms.size();
		ll m = (b + e) / 2;
		for (ll M : Ms)
			cnt += m / M;
		if (cnt < N) {
			b = m + 1;
			continue;
		}
		ll less = 0;
		if (m > 0) {
			less = Ms.size();
			for (ll M : Ms)
				less += (m-1) / M;
			if (less >= N) {
				e = m - 1;
				continue;
			}
		}
		ll zb = N - less;
		vector<int> rem;
		for (int i = 0; i < Ms.size(); ++i) {
			if (m % Ms[i] == 0)
				rem.push_back(i + 1);
		}
		return rem[zb-1];
	}
}

int main()
{
	int T; cin >> T;
	for (int t = 1; t <= T; ++t) {
		ll N, B; cin >> B >> N;
		vector<ll> Ms;
		for (int i = 0; i < B; ++i) {
			int m; cin >> m;
			Ms.push_back(m);
		}
		cout << "Case #" << t << ": " << mins(Ms, N) << endl;
	}
	return 0;
}
