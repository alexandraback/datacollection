#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int nt, it;

	cin >> nt;
	for (it = 1; it <= nt; it++) {
		int n;
		string a[100];
		int i, j, j0, k, nl;
		char c[100];
		int m[100][100], mm[100] = {};
		bool good = true;

		cin >> n;
		for (i = 0; i < n; i++) cin >> a[i];

		for (i = j = 0; i < a[0].size(); i++) {
			if (!i || a[0][i] != a[0][i - 1]) {
				c[j++] = a[0][i];
			}
		}
		nl = j;

		for (i = 0; i < n && good; i++) {
			for (j = j0 = k = 0; j < a[i].size(); j++) {
				if (!j || a[i][j] != a[i][j - 1]) {
					if (k == nl || a[i][j] != c[k]) {
						good = false;
						break;
					}
					if (j) m[k - 1][i] = j - j0;
					j0 = j;
					k++;
				}
			}
			if (j) m[k - 1][i] = j - j0;
			if (k < nl) good = false;
		}

		// cout << nl << endl;
		// for (i = 0; i < nl; i++) cout << c[i];
		// cout << endl;
		for (i = 0; i < n; i++) {
			for (j = 0; j < nl; j++) {
				mm[j] = max(mm[j], m[j][i]);
				// cout << m[j][i] << ' ';
			}
			// cout << endl;
		}

		int r = 0;

		for (i = 0; i < nl; i++) {
			int r1 = 1E9;

			for (j = 1; j <= mm[i]; j++) {
				int t = 0;

				for (k = 0; k < n; k++) t += abs(j - m[i][k]);
				r1 = min(r1, t);
			}
			// cout << c[i] << ": " << r1 << endl;
			r += r1;
		}

		cout << "Case #" << it << ": ";
		if (good) {
			cout << r;
		} else {
			cout << "Fegla Won";
		}
		cout << endl;
	}
}
