#include <iostream>
using namespace std;

int cases, num, row;
int seen[16];

int main() {
	cin>>cases;
	for (int c = 1; c <= cases; c++) {
		cout<<"Case #"<<c<<": ";
		for (int i = 0; i < 16; i++) seen[i] = 0;
		for (int i = 0; i < 2; i++) {
			cin>>row;
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					cin>>num;
					if (j == row-1) seen[num-1] ++;
				}
			}
		}
		int sure = 0;
		for (int i = 0; i < 16; i++) sure += (seen[i] == 2);
		if (sure == 1) {
			for (int i = 0; i < 16; i++) if (seen[i] == 2) cout<<i+1<<"\n";
		} else if (sure == 0) cout<<"Volunteer cheated!\n";
		else cout<<"Bad magician!\n";
	}
	return 0;
}