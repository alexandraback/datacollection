#include <bits/stdtr1c++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef complex<ld> pt;

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    for (int ca = 1; ca <= t; ca++) {
        cout << "Case #" << ca << ": ";
		
		int n; cin >> n;
		vector<pair<int, int>> v(n);
		
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i].first;
			v[i].second = i;
			sum += v[i].first;
		}
		
		vector<pair<int, int>> ans;
		while (sum > 0) {
			assert(n >= 2);
			sort(v.rbegin(), v.rend());
			for (auto p : v) {
				//cerr << p.first << ":" << p.second << " ";
				if (2*p.first > sum) {
					cerr << "false on test case " << ca << endl;
				}
			}
			//cerr << endl;
			//if n == 2, get v[0] == v[1]
			//if n == 3 (a,b,c), remove (a,b) --> (a+b-2) / c
			if (n >= 4) {
				case4:
				v[0].first--;
				v[1].first--;
				ans.push_back({v[0].second, v[1].second});
				if (v[0].first == 0) n--;
				if (v[1].first == 0) n--;
				sum -= 2;
			} else if (n == 3) {
				if (v[0].first == 1) {
					case3:
					v[0].first--;
					if (v[0].first == 0) n--;
					ans.push_back({v[0].second, -1});
					sum--;
				} else {
					goto case4;
				}
			} else if (n == 2) {
				if (v[0].first != v[1].first) {
					goto case3;
				} else {
					goto case4;
				}
			}
		}
		
		bool first = true;
		for (auto p : ans) {
			if (!first) cout << " ";
			cout << char('A'+p.first);
			if (p.second >= 0) cout << char('A'+p.second);
			first = false;
		}
		cout << endl;
    }
	return 0;
}