#include <iostream>
using namespace std;

int main() {
	int testcases, ans1, ans2, grid1[4][4], grid2[4][4];
	cin >> testcases;
	for (int tc = 1; tc <= testcases; tc++) {
		cin >> ans1;
		ans1--;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> grid1[i][j];
			}
		}
		cin >> ans2;
		ans2--;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> grid2[i][j];
			}
		}
		cout << "Case #" << tc << ": ";
		int x = -1, i;
		for (i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (grid1[ans1][i] == grid2[ans2][j]) {
					if (x == -1) {
						x = grid1[ans1][i];
					} else {
						cout << "Bad magician!" << endl;
						i = 6; j = 6;
					}
				}
			}
		}
		if (i!=7) {
			if (x == -1) cout << "Volunteer cheated!" << endl;
			else cout << x << endl;
		}
	}
}
