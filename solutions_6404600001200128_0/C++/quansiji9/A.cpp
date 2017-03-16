#include <iostream>
#include "stdio.h"

using namespace std;

int main() {
	int t;
	cin >> t;

	int n;
	int m[1024];
	for (int tcount = 1; tcount <= t; ++tcount) {
		cin >> n;

		int ans1 = 0, ans2 = 0;
		cin >> m[0];

		int rmax = -10000000;
		//int rmaxpos = -1;
		for (int i = 1; i < n; ++i) {
			cin >> m[i];
			int temp = m[i-1] - m[i];
			if (temp > 0) {
				ans1 += temp;
				if (temp > rmax)
					rmax = temp;
			}
		}

		if (rmax < 0) {
			ans2 = 0;
		}
		else {
			for (int i = 0; i < n-1; ++i) {
				if (m[i] < rmax)
					ans2 += m[i];
				else
					ans2 += rmax;
			}
		}
		

		cout << "Case #" << tcount << ": " << ans1 << " " << ans2 << endl;
	}

	return 0;
}