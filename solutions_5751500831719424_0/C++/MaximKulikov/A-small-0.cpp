#include "cmath"
#include "cstdio"
#include "algorithm"
#include "map"
#include "numeric"
#include "queue"
#include "set"
#include "string"
#include "utility"
#include "vector"
#include "iostream"
#include "iomanip"

using namespace std;

int d[128][128];

string fill(string& s, int ind) {
	string res = "";
	for (int j = 0, k = 1, n = s.size(), l = 0; j < n; ++j) {
		if (j + 1 < n && s[j] == s[j + 1]) {
			++k;
		}
		else {
			d[l++][ind] = k;
			k = 1;
			res += s[j];
		}
	}
	return res;
}

int solve() {
	int n, m;
	cin >> n;

	string a, b;
	cin >> a;

	cerr << "test" << endl;
	cerr << a << endl;

	a = fill(a, 0);

	for (int i = 1; i < n; ++i) {
		cin >> b;
		cerr << b << endl;
		if (fill(b, i) != a) return -1;
	}
	cerr << "-----------" << endl;
	cerr << a << endl;

	m = a.size();
	int res = 0, l = (n + 1)/2 - 1, k;
	for (int i = 0; i < m; ++i) {
		sort(&d[i][0], &d[i][n]);
		k = d[i][l];

		for (int j = 0; j < n; ++j) {
			cerr << d[i][j] << " ";
		}
		cerr << endl;

		cerr << k << endl;
		for (int j = 0; j < n; ++j) {
			res += abs(d[i][j] - k);
			cerr << abs(d[i][j] - k) << " ";
		}
		cerr << endl;
		cerr << endl;
		cerr << endl;
	}
	cerr << endl;

	return res;
}

int main() {

	freopen("A-small-0.in", "r", stdin);
	freopen("A-small-0.out", "w", stdout);

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {

		int ans = solve();
		cout << "Case #" << t << ": ";
		if (ans < 0) {
			cout << "Fegla Won";
		}
		else {
			cout << ans;
		}
		cout << endl;
	}
	
	return 0;
}
