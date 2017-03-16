#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int t, T;
	cin >> T;
	for (t = 0; t < T; ++t) {
		int N;
		cin >> N;
		vector<int> m(N);
		for (int i = 0; i < N; ++i) {
			cin >> m[i];
		}

		int y = 0, rate = 0;
		for (int i = 1; i < N; ++i) {
			if (m[i] < m[i-1]) {
				y += m[i-1]-m[i];
				rate = max(rate, m[i-1]-m[i]);
			}
		}

		int z = 0;
		for (int i = 0; i < N-1; ++i) {
			z += min(rate, m[i]);
		}

		cout << "Case #" << (t+1) << ": " << y << " " << z << endl;
	}
	return 0;
}