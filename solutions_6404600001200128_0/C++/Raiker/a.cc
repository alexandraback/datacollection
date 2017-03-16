#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int ncases;

	cin >> ncases;

	for (int c = 1; c <= ncases; c++) {
		int n;

		cin >> n;

		vector<int> m;

		for (int i = 0; i < n; i++) {
			int mq;
			cin >> mq;
			m.push_back(mq);
		}

		int prev = 0;
		int biggest_drop = 0;
		int sum_drops = 0;

		for (int &mq : m) {
			if (mq < prev) {
				biggest_drop = max(biggest_drop, prev - mq);
				sum_drops += (prev - mq);
			}
			prev = mq;
		}

		int m2eaten = 0;
		for (int i = 0; i < m.size() - 1; i++) {
			m2eaten += min(m[i], biggest_drop);
		}
		cout << "Case #" << c << ": " << sum_drops << " " << m2eaten << endl;
	}

	return 0;
}
