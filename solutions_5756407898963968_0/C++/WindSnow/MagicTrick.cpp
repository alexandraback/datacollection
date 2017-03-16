#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("A-small-attempt1.in");
ofstream fout("A-small-attempt1.out");

#define cin fin
#define cout fout

void read(int c[4][4]) {
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			cin>>c[i][j];
}

void run() {
	int r1, r2;
	int c1[4][4], c2[4][4];
	cin>>r1;
	read(c1);
	cin>>r2;
	read(c2);
	int mark[17] = {0};
	for (int i = 0; i < 4; ++i) {
		++mark[c1[r1 - 1][i]];
		++mark[c2[r2 - 1][i]];
	}
	int ans = -1;
	for (int i = 1; i <= 16; ++i) {
		if (mark[i] == 2) {
			if (ans != -1) {
				cout<<"Bad magician!"<<endl;
				return;
			}
			ans = i;
		}
	}
	if (ans == -1) cout<<"Volunteer cheated!"<<endl;
	else cout<<ans<<endl;
}

int main() {
	int t;
	cin>>t;
	for (int i = 1; i <= t; ++i) {
		cout<<"Case #"<<i<<": ";
		run();
	}
	return 0;
}