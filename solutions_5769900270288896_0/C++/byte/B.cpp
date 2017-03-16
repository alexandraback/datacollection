#include <iostream>
using namespace std;

int happy(int bits, int R, int C, int N) {
	int ans = 10000000;
	int filled = 0;
	bool plot[16][16];
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			plot[i][j] = false;
		}
	}
	int index = 0;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (bits & (1 << index)) {
				plot[i][j] = true;
				filled++;
			}
			index++;
		}
	}
	if (filled != N) {
		return ans;
	}
	ans = 0;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (i + 1 < R && plot[i][j] && plot[i + 1][j]) {
				ans++;
			}
			if (j + 1 < C && plot[i][j] && plot[i][j + 1]) {
				ans++;
			}
		}
	}
	return ans;
}

int main() {
	int T, R, C, N;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		cin >> R >> C >> N;
		int aprt = R * C;
		int ans = 10000000;
		for (int i = 0; i < (1 << aprt); ++i) {
			ans = min(ans, happy(i, R, C, N));
		}
		cout << ans << "\n";
	}
	return 0;
}