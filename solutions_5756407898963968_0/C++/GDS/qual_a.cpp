#include <iostream>
#include <vector>
using namespace std;

vector< int > v1(4), v2(4);

void input() {
	int n1, n2;
	cin >> n1;
	n1--;
	for (int i = 0; i < 16; ++i) {
		int tmp;
		cin >> tmp;
		if (n1 == i/4) v1[i%4] = tmp;
	}
	cin >> n2;
	n2--;
	for (int i = 0; i < 16; ++i) {
		int tmp;
		cin >> tmp;
		if (n2 == i/4) v2[i%4] = tmp;
	}
}

int search() {
	bool alreadyfound = false;
	int result;
	for (int i1 = 0; i1 < 4; ++i1) {
		for (int i2 = 0; i2 < 4; ++i2) {
			if (v1[i1] == v2[i2]) {
				if (alreadyfound) return 0;
				else {
					alreadyfound = true;
					result = v1[i1];
				}
			}
		}
	}
	if (not alreadyfound) return -1;
	return result;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		input();
		int x = search();
		cout << "Case #" << i << ": ";
		if (x == -1) cout << "Volunteer cheated!" << endl;
		else if (x == 0) cout << "Bad magician!" << endl;
		else cout << x << endl;
	}
}