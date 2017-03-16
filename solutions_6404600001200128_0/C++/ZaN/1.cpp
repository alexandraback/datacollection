#include <iostream>
#include <vector>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		int n;
		cin >> n;
		vector<int> m(n);
		for (int i = 0; i < n; ++i) {
			cin >> m[i];
		}

		int cnt1 = 0;
		int mdiff = 0;

		for (int i = 0; i < n - 1; ++i) {
			if (m[i] > m[i + 1]) {
				cnt1 += m[i] - m[i + 1];
				mdiff = max(mdiff, m[i] - m[i + 1]);
			}
		}

		int cnt2 = 0;
		for (int i = 0; i < n - 1; ++i) {
			cnt2 += min(m[i], mdiff);
		}
		
		cout << "Case #" << test << ": " << cnt1 << " " << cnt2 << endl;
	}
}
