#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

void solve() {
	int N;
	bool f = false;
	string s[100], t[100];
	vector<int> a[100];
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> s[i];
		t[i] = s[i];
		t[i].erase(unique(t[i].begin(), t[i].end()), t[i].end());
		if (!f && i && t[i] != t[i - 1]) {
			cout << "Fegla Won";
			f = true;
		}
		for (int j = 0, k = 0; j < t[i].size(); ++j) {
			a[i].push_back(0);
			while (s[i][k] == t[i][j])
				a[i].back()++, k++;
		}
	}
	if (f)
		return;
	int ans = 0;
	for (int i = 0; i < t[0].size(); ++i) {
		int m = 1e9;
		for (int j = 1; j <= 100; ++j) {
			int s = 0;
			for (int k = 0; k < N; ++k)
				s += abs(a[k][i] - j);
			m = min(m, s);
		}
		ans += m;
	}
	cout << ans;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cout << "Case #" << i << ": ";
		solve();
		cout << endl;
	}
}
