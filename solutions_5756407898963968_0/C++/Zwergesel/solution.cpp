#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int casenum=1; casenum<=t; casenum++) {
		int c1, c2;
		int g1[16], g2[16];
		cin >> c1;
		for (int i=0; i<16; i++) cin >> g1[i];
		cin >> c2;
		for (int i=0; i<16; i++) cin >> g2[i];
		c1 = c1 * 4 - 4;
		c2 = c2 * 4 - 4;
		int s = 0;
		for (int i=0; i<4; i++) {
			for (int j=0; j<4; j++) {
				if (g1[c1+i] == g2[c2+j]) {
					if (s == 0) s = g1[c1+i];
					else s = -1;
				}
			}
		}
		cout << "Case #" << casenum << ": ";
		if (s > 0) {
			cout << s;
		} else if (s < 0) {
			cout << "Bad magician!";
		} else {
			cout << "Volunteer cheated!";
		}
		cout << "\n";
	}
	return 0;
}