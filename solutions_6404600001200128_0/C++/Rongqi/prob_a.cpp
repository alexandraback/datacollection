#include <iostream>
#include <vector>
using namespace std;

int main() {
	int testcases;
	cin >> testcases;
	for (int testcase = 0; testcase < testcases; testcase ++) {
		int o1;
		int o2;
		int o2s;
		int n;
		vector<int> a;

		cin >> n;
		a.resize(n);
		for (int i = 0; i < n; i ++) {
			cin >> a[i];
		}

		o1 = 0;
		for (int i = 0; i < n - 1; i ++) {
			if (a[i + 1] < a[i]) o1 += (a[i] - a[i + 1]);
		}
		o2s = 0;
		for (int i = 0; i < n - 1; i ++) {
			if (a[i + 1] < a[i] && a[i] - a[i + 1] > o2s) o2s = a[i] - a[i + 1];
		}
		o2 = 0;
		for (int i = 0; i < n - 1; i ++) {
			if (a[i] > o2s) {
				o2 += o2s;
			} else {
				o2 += a[i];
			}
		}

		cout << "Case #" << testcase + 1 << ": " << o1 << " " << o2 << endl;
	}
	return 0;
}