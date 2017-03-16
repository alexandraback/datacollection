#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

int main() {
	int T;
	cin >> T;
	for (int x = 0; x < T; x++) {
		int a, b;
		cin >> a;
		VVI m1 (4, VI(4));
		for (int i = 0; i < 4; i++) 
			for (int j = 0; j < 4; j++)
				cin >> m1[i][j];
		VVI m2 (4, VI(4));
		cin >> b;
		for (int i = 0; i < 4; i++) 
			for (int j = 0; j < 4; j++)
				cin >> m2[i][j];
		int count = 0;
		int ans;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (m1[a-1][i] == m2[b-1][j]) {
					count++;
					ans = m1[a-1][i];
				}
			}
		}
		cout << "Case #" << x+1 << ": ";
		if (count > 1) cout << "Bad magician!" << endl;
		else if (count == 1) cout << ans << endl;
		else cout << "Volunteer cheated!" << endl;
	}
}