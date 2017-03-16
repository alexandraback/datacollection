#include<iostream>
#include<set>

using namespace std;

int main() {
	int kases;
	cin >> kases;
	for (int kase = 1; kase <= kases; kase++) {
		int r;
		cin >> r;
		set<int> cards;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				int n;
				cin >> n;
				if (r == i+1) {
					cards.insert(n);
				}
			}
		}
		cin >> r;
		set<int> finalCards;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				int n;
				cin >> n;
				if (r == i+1) {
					if (cards.count(n)) {
						finalCards.insert(n);
					}
				}
			}
		}

		cout << "Case #" << kase << ": ";
		if (finalCards.empty()) cout << "Volunteer cheated!";
		else if (finalCards.size() > 1) cout << "Bad magician!";
		else cout << *(finalCards.begin());
		cout << endl;
	}
	return 0;
}
