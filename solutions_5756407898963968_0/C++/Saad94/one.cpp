#include <iostream>
//#include 
using namespace std;

int main() {
	int one[4][4], temp[4];
	int num, row, finans, ans, junk, anscount = 0;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> row;
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				if (j == row-1) {
					cin >> temp[k];
				}
				else {
					cin >> junk;
				}
			}
		}
		cin >> row;
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				if (j == row-1) {
					cin >> ans;
					for (int m = 0; m < 4; m++) {
						if (ans == temp[m]) {
							anscount++;
							finans = ans;
							break;
						}
					}
				}
				else {
					cin >> junk;
				}
			}
		}
		if (anscount == 0) {
			cout << "Case #" << i + 1 << ": " << "Volunteer cheated!";
		}
		else if (anscount == 1) {
			cout << "Case #" << i + 1 << ": " << finans;
		}
		else {
			cout << "Case #" << i + 1 << ": " << "Bad magician!";
		}
		cout << "\n";
		anscount = 0;
	}
}