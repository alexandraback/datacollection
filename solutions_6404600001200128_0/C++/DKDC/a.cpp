#include <iostream>

using namespace std;

int main(void)
{
	int T, n = 0;
	int N;
	cin >> T;
	while (n < T) {
		cout << "Case #" << ++n << ": ";
		cin >> N;
		int m[N];
		int d[N];
		int ans1 = 0;
		int ans2 = 0;
		int maxD = INT_MIN;
		for (int i = 0; i < N; i++) {
			cin >> m[i];
			if (i > 0) {
				d[i] = m[i - 1] - m[i];
				if (d[i] >= 0) {
					ans1 += d[i];
					if (d[i] > maxD) {
						maxD = d[i];
					}
				}
			}
		}
		cout << ans1 << " ";
		for (int i = 0; i < N - 1; i++) {
			ans2 += min(m[i], maxD);
		}
		cout << ans2 << endl;
	}
	return 0;
}
