#include <iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int C;
	cin >> C;
	for (int Case = 1; Case <= C; Case++)
	{
		cout << "Case #" << Case << ": ";

		int row1, row2;
		int card1[4], card2[4];

		cin >> row1;
		for (int i = 0; i < 4; i++) {
			if (i + 1 == row1) {
				cin >> card1[0] >> card1[1] >> card1[2] >> card1[3];
			}
			else {
				int garbage;
				cin >> garbage >> garbage >> garbage >> garbage;
			}
		}

		cin >> row2;
		for (int i = 0; i < 4; i++) {
			if (i + 1 == row2) {
				cin >> card2[0] >> card2[1] >> card2[2] >> card2[3];
			}
			else {
				int garbage;
				cin >> garbage >> garbage >> garbage >> garbage;
			}
		}

		int theCard = 0;
		bool cardFound = false, badMagician = false;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (card1[i] == card2[j]) {
					if (cardFound) badMagician = true;
					else cardFound = true, theCard = card1[i];
				}
			}
		}

		if (!cardFound) {
			cout << "Volunteer cheated!" << endl;
		}
		else if (badMagician) {
			cout << "Bad Magician!" << endl;
		}
		else {
			cout << theCard << endl;
		}

	}

}