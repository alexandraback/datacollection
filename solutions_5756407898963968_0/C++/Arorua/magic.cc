#include <iostream>

using namespace std;

int process(int k)
{
	int a[4][4], b[4], r;
	cin >> r; r -= 1;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			cin >> a[i][j];
	for (int j = 0; j < 4; ++j)
		b[j] = a[r][j];
	cin >> r; r -= 1;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			cin >> a[i][j];
	int ans = 0, best;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j)
			if (a[r][j] == b[i]) {
				ans += 1;
				best = b[i];
				break;
			}
	}
	cout << "Case #" << k << ": ";
	if (ans == 0) {
		cout << "Volunteer cheated!" << endl;
	} else if (ans == 1) {
		cout << best << endl;	
	} else {
		cout << "Bad magician!" << endl;
	}
}

int main()
{
	int k;
	cin >> k;
	for (int i = 1; i <= k; ++i)
		process(i);
}

