#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 0; t++ < T;) {
		int N, m, last = 0;
		int diff[1001], x[1001];
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> x[i];
			diff[i] = x[i] - last;
			last = x[i];
		}

		int s1 = 0, s2 = 0;
		int maxn = 0;
		// method 1
		for (int i = 0; i < N; i++) {
			if (diff[i] < 0) {
				s1 += -diff[i];
			}
			maxn = min(maxn, diff[i]);
		}
		maxn = -maxn;
		int s = 0;
		for (int i = 0; i < N - 1; i++) {
			s = x[i];
			if (s < maxn) {
				s2 += s;
			} else {
				s2 += maxn;
			}
		}
		//cout << "at least: " << maxn / 10 - !!(maxn % 10) << endl;
		cout << "Case #" << t << ": " << s1 << " " << s2 << endl;
	}
	return 0;
}