#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void solve() {
	int r;
	vector<bool> A(16,false), B(16,false);
	cin >> r;
	r--;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int n;
			cin >> n;
			n--;
			assert(n >= 0 && n < 16);
			if (i == r) {
				assert(A[n] == false);
				A[n] = true;
			}
		}
	}
	cin >> r;
	r--;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int n;
			cin >> n;
			n--;
			assert(n >= 0 && n < 16);
			if (i == r) {
				assert(B[n] == false);
				B[n] = true;
			}
		}
	}
	int sol = -1;
	for (int i = 0; i < 16; i++) {
		if (A[i] && B[i]) {
			if (sol != -1) {
				cout << "Bad magician!" << endl;
				return;
			}
			sol = i;
		}
	}
	if (sol == -1)
		cout << "Volunteer cheated!" << endl;
	else
		cout << (sol + 1) << endl;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cout << "Case #" << (i + 1) << ": ";
		solve();
	}
	return 0;
}
