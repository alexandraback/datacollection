#include <iostream>

using namespace std;

int main(void)
{
	int T, r1, r2, i, j;
	int x[4][4], y[4][4];

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> r1;	r1--;
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
				cin >> x[i][j];
		cin >> r2;	r2--;
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
				cin >> y[i][j];

		int a = -1;
		for (i = 0; i < 4; i++) {
			int b = -1;
			for (j = 0; j < 4; j++)
				if (x[r1][i] == y[r2][j]) {
					b = y[r2][j];
					break;
				}
			if (b != -1)
				if (a != -1) {
					a = -2;
					break;
				} else
					a = b;
		}

		cout << "Case #" << t << ": ";
		if (a == -1)		cout << "Volunteer cheated!";
		else if (a == -2)	cout << "Bad magician!";
		else				cout << a;
		cout << endl;

	}

	return 0;
}
