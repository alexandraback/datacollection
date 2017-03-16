#include <iostream>
#include <vector>
using namespace std;

long long calc(vector<long long> & a, long long x) {
	long long r = 0;
	for (int i = 0; i < a.size(); i ++) {
		r += (x + a[i] - 1) / a[i];
	}
	return r;
}

int main() {
	int testcases;
	cin >> testcases;
	for (int testcase = 0; testcase < testcases; testcase ++) {
		int m, n;
		int o = 0;
		vector<long long> a;
		cin >> n >> m;
		a.resize(n);
		for (int i = 0; i < n; i ++) {
			cin >> a[i];
		}

		double t = 0.0;
		for (int i = 0; i < n; i ++) {
			t = t + 1.0 / a[i];
		}
		t = (m - 1 - n) * 1.0 / t;
		long long f = t;
		if (f < 0) f = 0;

//		cout << "f = " << f << endl;

		long long x = f;

		while (calc(a, x) < m) {
			x ++;
		}
		x --;

//		cout << "x = " << x << endl;

		long long no = m - calc(a, x);

//		cout << "no = " << no << endl;

		for (int i = 0; i < n; i ++) {
			if (x % a[i] == 0) {
				no --;
				if (no == 0) {
					o = i + 1;
					break;
				}
			}
		}

		cout << "Case #" << testcase + 1 << ": " << o << endl;
	}
	return 0;
}