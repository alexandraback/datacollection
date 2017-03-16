#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
	int nt;
	cin >> nt;
	for (int t = 1; t <= nt; t++) {
		cout << "Case #" << t << ": ";
		int x;
		cin >> x;
		int a[4][4];
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> a[i][j];
			}
		}
		int y;
		cin >> y;
		int b[4][4];
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> b[i][j];
			}
		}
		int c[4];
		for (int i = 0; i < 4; i++) {
			c[i] = a[x - 1][i];
		}
		int d[4];
		for (int i = 0; i < 4; i++) {
			d[i] = b[y - 1][i];
		}
		int m = 0;
		int s = 0;
		for (int i = 0; i < 4; i++) {
			bool f = false;
			for (int j = 0; j < 4; j++) {
				if (c[i] == d[j]) {
					f = true;
					break;
				}
			}
			if (f) {
				m = c[i];
				s++;
			}
		}
		if (s == 1) {
			cout << m;
		} else if (s == 0) {
			cout << "Volunteer cheated!";
		} else {
			cout << "Bad magician!";
		}
		cout << endl;
	}
	return 0;
}

