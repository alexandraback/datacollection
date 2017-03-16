#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string toString(int x) {
	if (x == 0) return "0";
	string s;
	while (x) s.push_back('0' + x % 10), x /= 10;
	reverse(s.begin(), s.end());
	return s;
}

string solve() {
	int a[5][5], b[5][5];
	int x, y;
	cin >> x;
	for (int i = 1; i <= 4; i++)
	for (int j = 1; j <= 4; j++)
		cin >> a[i][j];
	cin >> y;
	for (int i = 1; i <= 4; i++)
	for (int j = 1; j <= 4; j++)
		cin >> b[i][j];
	int c = 0, z = 0;
	for (int i = 1; i <= 16; i++) {
		bool xx = false, yy = false;
		for (int j = 1; j <= 4; j++)
			xx |= a[x][j] == i,
			yy |= b[y][j] == i;
		if (xx && yy) c++, z = i;
	}
	if (c == 0) return "Volunteer cheated!";
	if (c == 1) return toString(z);
	return "Bad magician!";
}


int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": " << solve() << endl;
	}
}