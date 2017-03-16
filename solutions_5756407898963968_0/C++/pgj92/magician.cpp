#include <iostream>
using namespace std;

int row[2][4];
int T;
int dummy;

void readInput(int no)
{
	int ans;

	cin >> ans;
	for (int i = 0; i < 4; i++)
		if (ans == i + 1)
			cin >> row[no][0] >> row[no][1] >> row[no][2] >> row[no][3];
		else
			cin >> dummy >> dummy >> dummy >> dummy;
}

void printr(int no)
{
	cout << row[no][0] << row[no][1] << row[no][2] << row[no][3] << endl;
}

void isIn(int r1[4], int r2[4])
{
	int card = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (r1[i] == r2[j]) {
				if (card != 0) {
					cout << "Bad magician!" << endl;
					return;
				} else {
					card = r1[i];
				}
			}

	if (card == 0)
		cout << "Volunteer cheated!" << endl;
	else
		cout << card << endl;
}

void solve(int tc)
{
	readInput(0);
	readInput(1);

	cout << "Case #" << tc << ": ";
	isIn(row[0], row[1]);
}

int main()
{
	cin >> T;
	for (int i = 1; i <= T; i++) {
		solve(i);
	}

	return 0;
}