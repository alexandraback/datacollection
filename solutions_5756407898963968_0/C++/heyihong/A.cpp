#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int ca, c, r, x;
int b[17];

int main() {
	freopen("in.txt", "r", stdin);
	cin >> ca;
	for (int c = 1; c <= ca; ++c) {
		memset(b, 0, sizeof(b));
		for (int k = 0; k != 2; ++k) {
			cin >> r; --r;
			for (int i = 0; i != 4; ++i) 
				for (int j = 0; j != 4; ++j) {
					cin >> x;
					if (i == r) ++b[x];
				}
		}
		int cnt = 0, num;
		for (int i = 1; i <= 16; ++i)
			if (b[i] == 2) {
				++cnt; num = i;
			}
		cout << "Case #" << c << ": ";
		if (cnt == 0) cout << "Volunteer cheated!" << endl;
		else if (cnt == 1) cout << num << endl;
		else cout << "Bad magician!" << endl;
	}
	return 0;
}