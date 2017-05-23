#include <iostream>
#include <cstring>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	bool cards[16];
	int A, B;
	for(int i = 0; i < T; ++i) {
		memset(cards, false, sizeof(cards));
		cin >> A;
		for(int j = 0; j < 4; ++j) {
			for(int k = 0; k < 4; ++k) {
				int p;
				cin >> p;
				if(j == A - 1) {
					cards[p - 1] = true;
				}
			}
		}
		cin >> B;
		int correct = 0;
		int ans;
		for(int j = 0; j < 4; ++j) {
			for(int k = 0; k < 4; ++k) {
				int p;
				cin >> p;
				if(j == B - 1) {
					if(cards[p - 1]) {++correct; ans = p;}
				}
			}
		}
		cout << "Case #" << i + 1 << ": ";
		if(correct == 0) {
			cout << "Volunteer cheated!";
		} else if(correct == 1) {
			cout << ans;
		} else {
			cout << "Bad magician!";
		}
		cout << endl;
	}
}