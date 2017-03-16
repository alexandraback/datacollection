#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	int tests;
	int n;
	int a[2000];
	cin >> tests;
	for (int t = 1; t <= tests; ++t) {
		cin >> n;
		for (int i = 0; i < n; ++i) 
			cin >> a[i];
		int x = 0;
		int y = 0;
		int mmax = 0;
		for (int i = 1; i < n; ++i) {
			if (a[i] < a[i - 1]) {
				x += (a[i - 1] - a[i]);
			if (a[i - 1] - a[i] > mmax)
				mmax = a[i - 1] - a[i];
			}
		}
		for (int i = 1; i < n; ++i) {
			if (a[i - 1] < mmax) {
				y += a[i - 1];
			} else {
				y += mmax;
			}
		}

		// sort(a, a + d);
		cout << "Case #" << t << ": " << x << " " << y << endl;
	}
	return 0;
}