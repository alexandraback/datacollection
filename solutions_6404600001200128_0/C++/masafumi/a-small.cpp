#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

int main() {
	int t, n;

	cin >> t;
	vector<int> y(t), z(t), m(1000);

	for (int i = 0; i < t; i++) {
		fill(m.begin(), m.end(), 0);
		int rate = 0;
		int diff;

		cin >> n;
		cin >> m[0];

		for (int j = 1; j < n; j++) {
			cin >> m[j];

			diff = m[j - 1] -m[j];
			if (diff > 0) {
				y[i] += diff;
			}
			rate = max(rate, diff);
		}

		for (int j = 0; j < n - 1; j++) {
			z[i] += min(rate, m[j]);
		}

	}

	for (int i = 0; i < t; i++) {
		printf("Case #%d: %d %d\n", i + 1, y[i], z[i]);
	}
	return 0;
}
