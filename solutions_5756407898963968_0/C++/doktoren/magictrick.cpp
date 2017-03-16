
#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int ti=1; ti<=t; ti++) {
		int n1, c1[16], n2, c2[16];
		cin >> n1;
		n1 = 4*(n1-1);
		for (int i=0; i<16; i++)
			cin >> c1[i];
		cin >> n2;
		n2 = 4*(n2-1);
		for (int i=0; i<16; i++)
			cin >> c2[i];
		int solution = -1;
		for (int i1=0; i1<4; i1++)
			for (int i2=0; i2<4; i2++)
				if (c1[n1 + i1] == c2[n2 + i2]) {
					if (solution == -1) {
						solution = c1[n1 + i1];
					} else {
						solution = -2;
					}
				}
		cout << "Case #" << ti << ": ";
		if (solution == -1)
			cout << "Volunteer cheated!";
		else if (solution == -2)
			cout << "Bad magician!";
		else
			cout << solution;
		cout << endl;
	}
	return 0;
}
