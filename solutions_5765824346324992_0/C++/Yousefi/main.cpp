#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL);

constexpr int B = 1111;

typedef long long ll;
typedef pair<ll, ll> pii;

int main() { _
	ll t;
	cin >> t;
	for (ll test = 1; test <= t; ++test) {
		set<vector<pii>> us;
		cout << "Case #" << test << ": ";
		set<pii> pq;
		vector<ll> v;
		ll b, n, m[B], t = 0;
		cin >> b >> n;
		for (ll i = 1; i <= b; ++i) {
			cin >> m[i];
			pq.emplace(0, i);
		}
		for (ll i = 1; i <= n; ++i) {
			vector<pii> tmp;
//			cerr << "{ ";
			for (auto k: pq) {
				tmp.emplace_back(k.first, k.second);
			}
			auto mne = min_element(tmp.begin(), tmp.end()) -> first;
			for (auto &k: tmp) {
				k.first -= mne;
//				cerr << "(" << k.first << ", " << k.second << "), ";
			}
			auto j = *pq.begin();
			pq.erase(pq.begin());
			pq.emplace(j.first + m[j.second], j.second);
//			cerr << "} -> " << j.second << "\n\n\n";
			if (us.find(tmp) != us.end()) {
//				cerr << "\nFOUNDFOUND!\n";
				cout << v[(n - 1) % (v.size())] << '\n';
				goto hell;
			} else {
				v.emplace_back(j.second);
				us.insert(tmp);
			}
			if (i == n)
				cout << j.second << '\n';
		}
	hell:
		;
	}
}