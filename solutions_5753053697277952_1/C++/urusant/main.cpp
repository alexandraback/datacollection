#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	set <pair <int, int> > s;
	for (int i = 0; i < n; ++i) {
		s.insert({a[i], i});
	}
	while (!s.empty()) {
		if (s.size() == 2) {
			int x = s.begin()->second;
			s.erase(s.begin());
			int y = s.begin()->second;
			s.erase(s.begin());
			cout << char('A' + x) << char('A' + y) << ' ';
			a[x]--;
			a[y]--;
			if (a[x] > 0) {
				s.insert({a[x], x});
			}
			if (a[y] > 0) {
				s.insert({a[y], y});
			}
		} else {
			int x = s.rbegin()->second;
			s.erase({a[x], x});
			cout << char('A' + x) << ' ';
			a[x]--;
			if (a[x] > 0) {
				s.insert({a[x], x});
			}
		}
	}
	cout << endl;
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		solve();
	}
}