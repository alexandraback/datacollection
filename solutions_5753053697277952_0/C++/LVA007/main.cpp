#include <bits/stdc++.h>

using namespace std;

const int N = (int)2e5 + 4;

void solve(int t) {
	int n;
	cin >> n;
	vector<int> p(n, 0);
	int s = 0;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		s += p[i];
	}
	cout << "Case #" << t << ": ";
	for (; ; ) {
		int x = -1, y = -1;
		for (int i = 0; i < n; ++i) {
			if (x == -1 || p[x] <= p[i]) {
				y = x, x = i;
			} else {
				if (y == -1 || p[y] <= p[i]) {
					y = i;
				}
			}
		}
		if (p[x] == 0) {
			break;
		}
		cout << char('A' + x);
		--p[x];
		if (s % 2 == 1) {
			--s;
			cout << ' ';
			continue;
		}
		if (p[x] > p[y]) {
			cout << char('A' + x);
			--p[x];
		} else {
			if (p[y] > 0) {
				cout << char('A' + y);
				--p[y];
			}
		}
		cout << ' ';
	}
	cout << '\n';
}


int main() {
	freopen("A-small-attempt2.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		solve(t);
	}
	return 0;
}