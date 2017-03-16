#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		int n;
		cin >> n;
		vector<long long> x(n), y(n);
		for (int i = 0; i < n; ++i) {
			cin >> x[i] >> y[i];
		}
		cout << "Case #" << test << ":" << endl;

		vector<int> ans(n, n - 1);
		for (int i = 0; i < n; ++i) {
			long long xx = x[i];
			long long yy = y[i];
			for (int j = i + 1; j < n; ++j) {
				long long dx = x[j] - xx;
				long long dy = y[j] - yy;

				int cnt1 = 0, cnt2 = 0;
				for (int k = 0; k < n; ++k) {
					long long dx2 = x[k] - xx;
					long long dy2 = y[k] - yy;
					long long prod = dx*dy2 - dy*dx2;
					if (prod < 0) {
						++cnt1;
					} else if (prod > 0) {
						++cnt2;
					}
				}
				ans[i] = min(ans[i], cnt1);
				ans[i] = min(ans[i], cnt2);
				ans[j] = min(ans[j], cnt1);
				ans[j] = min(ans[j], cnt2);
			}
			cout << ans[i] << endl;
		}
	}
}
