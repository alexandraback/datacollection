#include <iostream>

using namespace std;

int t, x, l1, l2;
int a[20];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
	for (int k = 0; k < t; k++) {
		for (int i = 1; i <= 16; i++) a[i] = 0;
		cin >> l1;
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++) {
				cin >> x;
				if (i == l1) a[x]++;
			}
		}
		cin >> l2;
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++) {
				cin >> x;
				if (i == l2) a[x]++;
			}
		}
		int cur = -1;
		for (int i = 1; i <= 16; i++) {
			if (a[i] == 2) {
				if (cur == -1) cur = i;
				else cur = 0;
			}
		}
		if (cur == -1) {
			cout << "Case #" << k + 1 << ": " << "Volunteer cheated!" << endl;
		} else if (cur == 0) {
			cout << "Case #" << k + 1 << ": " << "Bad magician!" << endl;
		} else {
			cout << "Case #" << k + 1 << ": " << cur << endl;
		}
	}
}