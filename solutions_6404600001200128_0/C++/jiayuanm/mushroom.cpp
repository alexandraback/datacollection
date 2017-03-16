#include <iostream>
#include <string>

using namespace std;

int m[10005];

int main () {
	int t, n;
	cin >> t;
	for (int cs = 1; cs <= t; ++cs) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> m[i];
		}

		int sol1 = 0, mx = 0;
		for (int i = 1; i < n; ++i) {
			if (m[i] >= m[i-1])
				continue;
			sol1 += (m[i-1] - m[i]);
			mx = max(mx, m[i-1] - m[i]);
		}

		int sol2 = 0;
		for (int i = 1; i < n; ++i) {
			//if (m[i] >= m[i-1]) {
				sol2 += min(mx, m[i-1]);
			//}
			//else {
			//	sol2 += min(mx, m[i-1]);
			//}
		}
		cout << "Case #" << cs << ": " << sol1 << " " << sol2 << endl;
	}


	return 0;
}