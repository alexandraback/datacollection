#include <iostream>
#include <utility>

using namespace std;

int main() {
	int _n;
	pair<int, int> cards[17];
	cin >> _n;
	for (int n = 0; n < _n; ++n) {
		int ans1, ans2;
		cin >> ans1;
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j) {
				int x;
				cin >> x;
				cards[x].first = i + 1;
			}
		cin >> ans2;
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j) {
				int x;
				cin >> x;
				cards[x].second = i + 1;
			}
		int cnt = 0;
		for (int i = 1; i <= 16; ++i)
			cnt += cards[i] == make_pair(ans1, ans2);
		cout << "Case #" << n + 1 << ": ";
		if (cnt == 0) {
			cout << "Volunteer cheated!";
		} else if (cnt > 1) {
			cout << "Bad magician!";
		} else {
			for (int i = 1; i <= 16; ++i) {
				if (cards[i] == make_pair(ans1, ans2)) {
					cout << i;
					break;
				}
			}
		}
		cout << '\n';
	}
	return 0;
}
