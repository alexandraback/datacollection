#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		int row;
		cin >> row;
		int first[4];
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				int card;
				cin >> card;
				if (i + 1 == row) {
					first[j] = card;
				}
			}
		}

		cin >> row;
		int count = 0;
		int match;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				int card;
				cin >> card;
				if (i + 1 == row) {
					for (int k = 0; k < 4; ++k) {
						if (first[k] == card) {
							++count;
							match = card;
						}
					}
				}
			}
		}

		cout << "Case #" << test << ": ";
		if (count == 1) {
			cout << match;
		} else if (count == 0) {
			cout << "Volunteer cheated!";
		} else {
			cout << "Bad magician!";
		}
		cout << endl;
	}
}
