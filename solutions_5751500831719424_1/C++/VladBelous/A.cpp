#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ii> vii;

template<typename T> inline int sz(const T& x) { return (int)x.size(); }

int main() {
	int tc; cin >> tc;

	for(int t = 1; t <= tc; ++t) {
		int ans = -1;

		int n; cin >> n;
		vector<string> words(n);
		set<string> reps;
		for(int i = 0; i < n; ++i) {
			cin >> words[i];
			string s = words[i];
			s.resize(unique(s.begin(), s.end()) - s.begin());
			reps.insert(s);
		}

		if(sz(reps) > 1) {
			cout << "Case #" << t << ": Fegla Won" << endl;
			continue;
		}

		vvi runs(n);
		for(int i = 0; i < n; ++i) {
			char p = words[i][0];
			runs[i].push_back(1);
			for(int j = 1; j < sz(words[i]); ++j) {
				if (words[i][j] == p)
					runs[i].back() += 1;
				else
					runs[i].push_back(1);
				p = words[i][j];
			}
		}


		ans = 0;
		for(int k = 0; k < sz(runs[0]); ++k) {
			int cost = -1;
			for(int i = 0; i < n; ++i) {
				int sum = 0;
				for(int j = 0; j < n; ++j) {
					sum += abs( runs[i][k] - runs[j][k]  );
				}
				cost = cost == -1 ? sum : min(sum, cost);
			}
			ans += cost;
		}

		cout << "Case #" << t << ": " << ans << endl;
	}

	return 0;
}
