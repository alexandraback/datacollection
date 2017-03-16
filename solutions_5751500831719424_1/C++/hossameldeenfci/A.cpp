#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("A-large.in", "rt", stdin);
	freopen("A-large.out", "wt", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T; cin >> T;
	for (int t = 0; t < T; ++t) {
		cout << "Case #" << t + 1 << ": ";

		int N; cin >> N;
		string arr[128];
		for (int i = 0; i < N; ++i)
			cin >> arr[i], arr[i] += "Q";
		vector<pair<char, int> > v[128];

		for (int i = 0; i < N; ++i) {
			int last = 0, cur = 1;
			while(cur < arr[i].size()) {
				if (arr[i][last] == arr[i][cur])
					++cur;
				else {
					v[i].push_back(make_pair(arr[i][last], cur - last));
					last = cur, ++cur;
				}
			}
		}

		bool b = 1;
		for (int i = 1; i < N && b; ++i) {
			if (v[0].size() != v[i].size())
				cout << "Fegla Won\n", b = 0;
			for (int j = 0; j < v[0].size() && b; ++j)
				if (v[0][j].first != v[i][j].first)
					cout << "Fegla Won\n", b = 0;
		}
		if (!b)
			continue;

		int sum = 0;
		for (int i = 0; i < v[0].size(); ++i) {
			int mn = 1e9;
			for (int j = 0; j < N; ++j) {
				int anotherSum = 0;
				for (int k = 0; k < N; ++k)
					anotherSum += abs(v[j][i].second - v[k][i].second);
				mn = min(mn, anotherSum);
			}
			sum += mn;
		}

		cout << sum << "\n";
	}

	return 0;
}
