#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int nTests, test;
	cin >> nTests;
	for (int test = 1; test <= nTests; ++test) {
		int n;
		cin >> n;
		vector<int> m(n);
		for (int i = 0; i < n; ++i) {
			cin >> m[i];
		}

		// first method
		int y = 0;
		for (int i = 1; i < n; ++i) {
			if (m[i] < m[i - 1]) {
				y += m[i - 1] - m[i];
			}
		}

		// second method
		int z = 0;

		int rate = 0; // per 10 sec
		for (int i = 1; i < n; ++i) {
			if (m[i] < m[i - 1]) {
				rate = max(rate, m[i - 1] - m[i]);
			}
		}
		for (int i = 1; i < n; ++i) {
			z += min(rate, m[i - 1]);
		}
		cout << "Case #" << test << ": " << y << " " << z << endl;
	}
	return 0;
}
