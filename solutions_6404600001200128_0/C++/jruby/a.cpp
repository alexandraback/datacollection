#include <iostream>
int m[10001];
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t=1;t<=T;t++) {
		cout << "Case #" << t << ": ";
		int N;
		cin >> N;
		for (int i=0;i<N;i++) {
			cin >> m[i];
		}
		int a1 = 0;
		for (int i=1;i<N;i++) {
			if (m[i] < m[i-1]) {
				a1 += m[i-1] - m[i];
			}
		}
		int a2 = 0;

		int low = 0;
		int high = 10000;
		int x;

		for (;;) {
			if (low >= high) break;
			//cout << low << " " << high << endl;
			x = (low + high) / 2;
			// eating with x spped at each time;
			bool fail = false;
			int ans = 0;
			for (int i=0;i<N;i++) {
				if (i>0 && m[i-1] > m[i]) {
					if (m[i-1] - m[i] > x) {
						fail = true;
						break;
					}
				}
				if (i < N-1) {
					if (m[i] > x) {
						ans += x;
					} else {
						ans += m[i];
					}
				}
			}
			if (fail) {
				low = x + 1;
			} else {
				high = x;
				a2 = ans;
			}
		}
		cout << a1 << " " << a2 << endl;

	}
	return 0;
}
