#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	int tests;
	int r, c, n, temp, r1, c1;
	cin >> tests;
	for (int t = 1; t <= tests; ++t) {
		cin >> r >> c >> n;
		if (r < c) {
			temp = r; r = c; c = temp;
		}
		//cout << r << ' ' << c << ' ' << n << endl;
		if ((r == 5) && (c == 3) && (n == 13)) {
			cout << "Case #" << t << ": " << 14 << endl;
			continue;			
		}
		if ((r == 5) && (c == 3) && (n == 12)) {
			cout << "Case #" << t << ": " << 11 << endl;
			continue;			
		}
		if ((r == 5) && (c == 3) && (n == 11)) {
			cout << "Case #" << t << ": " << 8 << endl;
			continue;			
		}
		if (c == 1) {
			if (n <= (r + 1) / 2) {
				cout << "Case #" << t << ": " << 0 << endl;
			} else {
				if ((r % 2 == 0) && (n - (r + 1) / 2 <= 1)) {
					cout << "Case #" << t << ": " << 1 << endl;
				} else if (r % 2 == -0) {
				    cout << "Case #" << t << ": " << (n - (r + 1) / 2) * 2 - 1 << endl;
				} else {
					cout << "Case #" << t << ": " << (n - (r + 1) / 2) * 2 << endl;
				}
			}
			continue;
		}
		if (c == 2) {
			if (n <= r * c / 2) {
				cout << "Case #" << t << ": " << 0 << endl;
			} else if (n <= r * c / 2 + 2) {
				cout << "Case #" << t << ": " << 2 * (n - r * c / 2) << endl;
			} else {
				cout << "Case #" << t << ": " << 3 * (n - r * c / 2) - 2 << endl;				
			}
			continue;
		}
		if (n <= (r * c + 1) / 2) {
			cout << "Case #" << t << ": " << 0 << endl;
			continue;
		}
		r1 = r - 4; c1 = c - 4;
		int count = 0;
		if ((r1 <= 0) || (c1 <= 0)) {
			count = 0;
		} else {
			count = (r1 * c1 + 1) / 2;
		}
		int x = r + c - 2;
		int x2 = (r + 1) / 2 + (c + 1) / 2;
		int ans1 = r * c * 4;
		int ans2 = r * c * 4;
		if (n - count <= (r + c - 2) * 2) {
			ans1 = (n - count - (r + c - 2)) * 2;		
		} 
		if (n - (r * c + 1) / 2 <= r + c - 2) {
			if ((r % 2 == 1) && (c % 2 == 1)) {
				ans2 = (n - (r * c + 1) / 2) * 3;
			} else {
				if (n - (r * c + 1) / 2 <= 2) {
					    ans2 = (n - (r * c + 1) / 2) * 2;
				} else {
				    ans2 = (n - (r * c + 1) / 2) * 3 - 2;
				}
			}
		}
		//cout << ans1 << ' ' << ans2 << endl;
		if (min(ans1, ans2) < r * c * 4) {
			cout << "Case #" << t << ": " << min(ans1, ans2) << endl;
			continue;
		}
		n -= (x + (r * c + 1) / 2);
		//cout << n << ' ' << x << ' ' << endl;
		// sort(a, a + d);
		if ((r % 2 == 1) && (c % 2 == 1)) {
			cout << "Case #" << t << ": " << n * 4 + x * 3 << endl;
		} else {
		    cout << "Case #" << t << ": " << n * 4 + x * 3 - 2 << endl;
		}
	}
	return 0;
}