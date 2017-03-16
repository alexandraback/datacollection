#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int l0 = 0; l0 < t; l0++) {
		int n, prev = 0, cnt = 0, cnt2 = 0, maxi = 0;
		cin >> n;
		vector<int> a(n, 0);
		for (int l1 = 0; l1 < n; l1++) {
			int m;
			cin >> m;
			if (l1 > 0) {
				if (prev > m) {
					cnt += prev - m;
					if (prev - m > maxi) {
						maxi = prev - m;
					}
				}
			}
			prev = m;
			a[l1] = m;
		}
		int cur = 0;
		for (int l1 = 0; l1 < n; l1++) {
			cnt2 += min(cur, maxi);
			cur = (cur > maxi ? cur - maxi : 0);
			if (a[l1] > cur) {
				cur = a[l1];
			}
		}
		cout << "Case #" << l0 + 1 << ": " << cnt << ' ' << cnt2 << endl;
	}
	return 0;
}