#include <iostream>
#include "stdio.h"

using namespace std;

int main() {
	int t;
	cin >> t;

	int n;
	int x[20], y[20];
	int co[20][20];
	for (int tcount = 1; tcount <= t; ++tcount) {
		cin >> n;

		for (int i = 0; i < n; ++i) {
			cin >> x[i] >> y[i];
		}

		for (int i = 0; i < n; ++i) {
			co[i][i] = 10000;
		}

		for (int i = 0; i < n; ++i) {
			for (int j = i+1; j < n; ++j) {
				int les = 0, mor = 0;
				for (int k = 0; k < n; ++k) {
					long long cross = (long long)(x[j] - x[i]) * (long long)(y[k] - y[i]) - (long long)(x[k] - x[i]) * (long long)(y[j] - y[i]);
					if (cross < 0)
						++les;
					else if (cross > 0)
						++mor;
				}

				co[i][j] = co[j][i] = min(les, mor);
			}
		}
		

		cout << "Case #" << tcount << ":" << endl;
		for (int i = 0; i < n; ++i) {
			int min = 100000;

			for (int j = 0; j < n; ++j)
				if (co[i][j] < min)
					min = co[i][j];

			cout << min << endl;
		}
	}

	return 0;
}