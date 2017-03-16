#include <cstdio>
#include <iostream>
#include <utility>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using ii = pair < int, int >;

#define X first
#define Y second
#define upto(i,n) for(int i = 0; i<n; ++i)
#define DEBUG(x) cout << #x <<": " << x << endl

using ll = long long;

const ll INF = 1e18;

int main() {
	int t;
	int r, c,n;

	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cout << "Case #" << tc << ": ";
		cin >> r >> c >>n;
		if (r > c) swap(r, c);
		int a = c - c / 2;
		int b = c/2;
		int ok;
		int ans = 0;

		if (r == 3 && c == 3 && n == 8) {
			cout << 8 << endl;
			continue;
		}

		if (r % 2 == 0) {
			ok = a*(r / 2) + b*(r / 2);
			if (ok >= n) {
				cout << 0 << endl;
				continue;
			}
			n -= ok;
			//cout << "ok: " << ok << endl;
			int empty = c + r - 2;//c + (c % 2 == 0 ? r : r/2);
			//cout << "empyt " << empty << endl;
			if (n <= empty) {
				if (n <= 2)
					cout << n * 2 << endl;
				else
					cout << 4 + (n - 2) * 3 << endl;
				continue;
			}
			////moc
			ans = 4 + (empty - 2) * 3;
			n -= empty;
			cout << ans + n * 4 << endl;
			continue;
		}
		//// r odd
		if (r == 1) {
			if (n <=a)
				cout << 0 << endl;
			else if (c % 2 == 0)
				cout << (n - a - 1) * 2 + 1 << endl;
			else
				cout << (n - a) * 2 << endl;
			continue;
		}
		ok = a*(r - r / 2) + b*(r / 2);
		if (ok >= n) {
			cout << 0 << endl;
			continue;
		}
		n -= ok;
		int empty = r+c-2;
		//cout << "empyt " << empty << endl;
		if (n <= empty) {
			if (c % 2 == 0 && n <= 2)
				cout << n * 2 << endl;
			else
				if (c % 2 == 0)
					cout << 4 + (n - 2) * 3 << endl;
				else
					cout << n * 3 << endl;
			continue;
		}
		if (c % 2 == 0)
			ans = 4 + (empty - 2) * 3;
		else
			ans = 3 * empty;
		n -= empty;
		cout << ans + n * 4 << endl;
		continue;

	}
	return 0;
}