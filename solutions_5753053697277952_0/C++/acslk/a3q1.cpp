#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int T, N;
int p[26];

int main() {

	cin >> T;

	for (int t = 1; t <= T; t++) {

		memset(p, 0, 26);
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> p[i];

		printf("Case #%d:", t);

		int maxi, otheri, max, nump;
		do {
			maxi = -1;
			max = 0;
			nump = 0;
			for (int i = 0; i < N; i++) {
				if (p[i] > max) {
					max = p[i];
					maxi = i;
				}
				if (p[i] != 0) {
					nump++;
					otheri = i;
				}
			} 
			if (nump == 2) {
				cout << ' ' << (char)('A' + maxi) << (char)('A' + otheri);
				p[maxi]--;
				p[otheri]--;
			}
			else if (nump > 2) {
				cout << ' ' << (char)('A' + maxi);
				p[maxi]--;
			}
		} while (maxi != -1);

		cout << "\n";

	}
}