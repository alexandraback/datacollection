#include <iostream>
using namespace std;

void solve() {
	int a, aa[5][5], b, bb[5][5];
	bool he[17], she[17];
	for (int i = 1; i <= 16; ++i)
		he[i] = she[i] = false;
	cin >> a;
	for (int i = 1; i <= 4; ++i)
		for (int j = 1; j <= 4; ++j)
			cin >> aa[i][j];
	for (int i = 1; i <= 4; ++i)
		he[aa[a][i]] = true;
	cin >> b;
	for (int i = 1; i <= 4; ++i)
		for (int j = 1; j <= 4; ++j)
			cin >> bb[i][j];
	for (int i = 1; i <= 4; ++i)
		she[bb[b][i]] = true;
	for (int i = 1; i <= 16; ++i)
		she[i] = she[i] && he[i];
	int ans = 0, cnt = 0;
	for (int i = 1; i <= 16; ++i)
		if (she[i]) {
			ans = i;
			++cnt;
		}
	if (cnt == 0)
		cout << "Volunteer cheated!" << endl;
	else if (cnt > 1)
		cout << "Bad magician!" << endl;
	else
		cout << ans << endl;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
}
