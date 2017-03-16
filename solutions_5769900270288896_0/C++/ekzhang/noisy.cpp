#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream in("noisy.in");
	ofstream out("noisy.out");
	int T, R, C, N;
	in >> T;
	for (int tc = 1; tc <= T; tc++) {
		in >> R >> C >> N;
		out << "Case #" << tc << ": ";
		int ans = -1;
		if (R < C) {
			int temp = R;
			R = C;
			C = temp;
		}
		if (N <= (R * C + 1) / 2) {
			ans = 0;
		}
		else if (R == 2 && C == 1) {
			ans = 1;
		}
		else if (R == 2 && C == 2) {
			if (N == 3) ans = 2;
			else ans = 4;
		}
		else if (R == 3 && C == 1) {
			ans = 2;
		}
		else if (R == 3 && C == 2) {
			if (N == 4) ans = 2;
			else if (N == 5) ans = 4;
			else ans = 7;
		}
		else if (R == 3 && C == 3) {
			if (N == 6) ans = 3;
			else if (N == 7) ans = 6;
			else if (N == 8) ans = 8;
			else ans = 12;
		}
		else if (R == 4) {
			if (C == 1) {
				if (N == 3) ans = 1;
				else ans = 3;
			}
			else if (C == 2) {
				if (N == 5) ans = 2;
				else if (N == 6) ans = 4;
				else if (N == 7) ans = 7;
				else ans = 10;
			}
			else if (C == 3) {
				if (N == 7) ans = 2;
				else if (N == 8) ans = 4;
				else if (N == 9) ans = 7;
				else if (N == 10) ans = 10;
				else if (N == 11) ans = 13;
				else ans = 17;
			}
			else {
				if (N == 9) ans = 2;
				else if (N == 10) ans = 4;
				else if (N == 11) ans = 7;
				else if (N == 12) ans = 10;
				else if (N == 13) ans = 13;
				else if (N == 14) ans = 16;
				else if (N == 15) ans = 20;
				else ans = 24;	
			}
		}
		else if (R == 5) {
			if (C == 1) {
				if (N == 4) ans = 2;
				else ans = 4;
			}
			else if (C == 2) {
				if (N == 6) ans = 2;
				else if (N == 7) ans = 4;
				else if (N == 8) ans = 7;
				else if (N == 9) ans = 10;
				else ans = 13;
			}
			else {
				if (N == 9) ans = 3;
				else if (N == 10) ans = 6;
				else if (N == 11) ans = 8;
				else if (N == 12) ans = 11;
				else if (N == 13) ans = 14;
				else if (N == 14) ans = 18;
				else ans = 22;
			}
		}
		else if (R == 6) {
			if (C == 1) {
				if (N == 4) ans = 1;
				else if (N == 5) ans = 3;
				else ans = 5;
			}
			else {
				if (N == 7) ans = 2;
				else if (N == 8) ans = 4;
				else ans = 4 + 3 * (N - 8);
			}
		}
		else if (R == 7) {
			if (C == 1) {
				if (N == 5) ans = 2;
				else if (N == 6) ans = 4;
				else ans = 6;
			}
			else {
				if (N == 8) ans = 2;
				else if (N == 9) ans = 4;
				else ans = 4 + 3 * (N - 9);
			}
		}
		else if (R == 8) {
			if (C == 1) {
				if (N == 5) ans = 1;
				else if (N == 6) ans = 3;
				else if (N == 7) ans = 5;
				else ans = 7;
			}
			else {
				if (N == 9) ans = 2;
				else if (N == 10) ans = 4;
				else ans = 4 + 3 * (N - 10);
			}
		}
		else {
			// C == 1
			ans = R - 1 - 2 * (R - N);
		}
		out << ans << endl;
	}
	return 0;
}
