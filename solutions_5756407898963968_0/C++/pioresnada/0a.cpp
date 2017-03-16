#include <iostream>
//#include <string>
//#include <algorithm>
using namespace std;
int main() {
	int t; cin >> t;
	int g1, g2, c1[4], c2[4], c0[4], y, n;
	for (int i = 0; i < t; ++i) {
		y = 0;
		cin >> g1;
		for (int j = 0; j < 4; ++j)
			if (j == g1-1)
				for (int k = 0; k < 4; ++k)
					cin >> c1[k];
			else
				for (int k = 0; k < 4; ++k)
					cin >> c0[k];
		cin >> g2;
		for (int j = 0; j < 4; ++j)
			if (j == g2-1)
				for (int k = 0; k < 4; ++k)
					cin >> c2[k];
			else
				for (int k = 0; k < 4; ++k)
					cin >> c0[k];
		/*for (int j = 0; j < 4; ++j)
			cout << c1[j] << ' '; cout << endl;
		for (int j = 0; j < 4; ++j)
			cout << c2[j] << ' '; cout << endl;*/
		for (int j = 0; j < 4; ++j)
			for (int k = 0; k < 4; ++k)
				if (c1[k] == c2[j]) { ++y; n = c1[k]; }
		cout << "Case #" << i+1 << ": ";
		if (!y) cout << "Volunteer cheated!\n";
		else if (y == 1) cout << n << endl;
		else cout << "Bad magician!\n";
	}
}
