#include <iostream>

using namespace std;

int mark[16];

int main() {
	int T;
	cin >> T;
	for (int tt=1; tt<=T; ++tt) {
		int a;
		for (int i=0; i<16; ++i)
			mark[i] = 0;
		cin >> a;
		for (int i=0; i<4; ++i)
			for (int j=0; j<4; ++j) {
				int temp;
				cin >> temp;
				if (i == a-1)
					mark[temp-1] ++;
			}
		cin >> a;
		for (int i=0; i<4; ++i)
			for (int j=0; j<4; ++j) {
				int temp;
				cin >> temp;
				if (i == a-1)
					mark[temp-1] ++;
			}

		int num_2 = 0;
		int last_2 = -1;
		for (int i=0; i<16; ++i)
			if (mark[i] == 2) {
				num_2 ++;
				last_2 = i+1;
			}

		cout << "Case #" << tt << ": ";
		if (num_2 == 0)
			cout << "Volunteer cheated!" << endl;
		else if (num_2 == 1)
			cout << last_2 << endl;
		else
			cout << "Bad magician!" << endl;
	}
	return 0;
}
