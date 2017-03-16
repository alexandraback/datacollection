#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int q = 1; q <= T; ++q) {
		int N;
		cin >> N;
		vector<int> P(N);
		//auto _P(P);
		//sort(_P.rbegin(), _P.rend());
		//bool choose2 = _P[0] - 2 >= _P[1];
		for (auto& p : P) cin >> p;
		cout << "Case #" << q << ":";
		int total = 0;
		for (auto& p : P) total += p;
		while (true) {
			int m = 0;
			for (int i = 1; i < N; ++i) {
				if (P[i] > P[m]) m = i;
			}
			if (P[m] == 0) break;
			cout << " " << char('A' + m);
			P[m]--;
			total--;

			for (int i = 0; i < N; ++i) {
				if (P[i] * 2 > total) {
					cout << char('A' + i);
					P[i]--;
					total--;
					break;
				}
			}
			/*if (choose2) {
				cout << char('A' + m);
				P[m]--;
				choose2 = false;
			}*/
		}
		cout << endl;
	}
	return 0;
}