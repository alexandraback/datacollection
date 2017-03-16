#include <bits/stdc++.h>
using namespace std;

const int
	MAXN = 20;

int T, R, C, N;
int board[MAXN][MAXN];

int bitCount(int n) {
	if (n == 0) return 0;
	else return __builtin_popcount(n);
}

int main() {

	cin >> T;
	for (int test = 1; test <= T; ++test) {


		cin >> R >> C >> N;

		int ans = 1000000;
		for (int s = 0; s < (1 << (R * C)); ++s) if (bitCount(s) == N) {
			for (int i = 0; i < R; ++i)
			for (int j = 0; j < C; ++j)
				board[i][j] = (s & (1 << (i * C + j))) != 0;

			int t = 0;
			for (int i = 0; i < R; ++i)
			for (int j = 0; j < C; ++j) if (board[i][j]) {
				if (i + 1 < R && board[i + 1][j]) t++;
				if (j + 1 < C && board[i][j + 1]) t++;
			}
			ans = min(ans, t);
		}

		cout << "Case #" << test << ": " << ans << endl;


	}

	return 0;
}
