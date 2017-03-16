#include <bits/stdc++.h>

using namespace std;
typedef long long int64;
#define DEBUG(x) cerr << #x << " = " << x << endl;
#define REP(x, n) for(__typeof(n) x = 0; x < (n); ++x)
#define FOR(x, b, e) for(__typeof(b) x = (b); x != (e); x += 1 - 2 * ((b) > (e)))
const int INF = 1000000001;
const double EPS = 10e-9;

#ifndef CATCH_TEST
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	REP(o, t) {
		int n;
		cin >> n;
		vector<pair<int, char>> parties;
		REP(x, n) {
			int p;
			cin >> p;
			parties.push_back(make_pair(p, 'A' + x));
		}
		vector<pair<char, char>> res;
		sort(parties.begin(), parties.end());
		while(parties[n - 1].first != parties[n - 2].first) {
			--parties[n - 1].first;
			res.push_back(make_pair(parties[n - 1].second, '0'));
		}
		REP(x, n - 2) {
			while(parties[x].first > 0) {
				--parties[x].first;
				res.push_back(make_pair(parties[x].second, '0'));
			}
		}
		while(parties[n - 1].first > 0) {
			--parties[n - 1].first;
			--parties[n - 2].first;
			res.push_back(make_pair(parties[n - 1].second, parties[n - 2].second));
		}
		cout << "Case #" << o + 1 << ": ";
		for (auto it : res) {
			cout << it.first;
			if (it.second != '0') {
				cout << it.second;
			}
			cout << " ";
		}
		cout << endl;
	}
	return 0;
}
#endif