// Compiler: g++-4.8 (Ubuntu/Linaro 4.8.1-10ubuntu9) 4.8.1
// Flags: -O2 -Wall -g -std=c++0x
// Aina häviää

#include <iostream>

using namespace std;

int main() {
	cin.sync_with_stdio(false);
	
	int T;
	cin >> T;
	
	for(int t = 0; t < T; ++t) {
		int ar;
		cin >> ar;
		--ar;
		
		bool ac[17] = {0};
		
		for(int i = 0; i < 4; ++i) {
			for(int j = 0; j < 4; ++j) {
				int x;
				cin >> x;
				if(i == ar) ac[x] = true;
			}
		}
		
		int br;
		cin >> br;
		--br;
		
		bool bc[17] = {0};
		
		for(int i = 0; i < 4; ++i) {
			for(int j = 0; j < 4; ++j) {
				int x;
				cin >> x;
				if(i == br) bc[x] = true;
			}
		}
		
		int count = 0;
		int res = -1;
		
		for(int i = 1; i <= 16; ++i) {
			if(ac[i] && bc[i]) {
				++count;
				res = i;
			}
		}
		
		cout << "Case #" << t + 1 << ": ";
		if(count == 0) {
			cout << "Volunteer cheated!\n";
		} else if(count == 1) {
			cout << res << "\n";
		} else {
			cout << "Bad magician!\n";
		}
	}
	
	return 0;
}
