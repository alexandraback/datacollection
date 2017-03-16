#include <bits/stdc++.h>
using namespace std;

const int N = 4;

int run() {
	int _, mk, x;
	cin >> _;
	for (int cas = 1; cas <= _; ++cas) {
		set<int> a, b;
		cin >> mk;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> x;
				if (i + 1 == mk) a.insert(x);
			}
		}
		cin >> mk;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> x;
				if (i + 1 == mk) b.insert(x);
			}
		}
		set<int> c;
		set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));
		cout << "Case #" << cas << ": ";
		if (c.size() == 0) cout << "Volunteer cheated!" << endl;
		else if (c.size() == 1) cout << *c.begin() << endl;
		else cout << "Bad magician!" << endl;
	}
	return 0;
}

int main() {
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A-small-attempt1.out", "w", stdout);
	ios::sync_with_stdio(0);
	return run();
}
