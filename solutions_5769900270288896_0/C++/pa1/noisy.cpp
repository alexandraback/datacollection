#include <iostream>
#define forn(i, s, n) for (int i = (s); i < (n); i++)
#define sI(N) scanf("%d", &N)
using namespace std;

int bitc(int N) {
	int bc = 0;
	while (N > 0) {
		if ((N&1)) {
			bc++;
		}
		N = N >> 1;
	}
	return bc;
}

int solve(int R, int C, int N) {
	int tr = R * C;
	int positions[R+2][C+2];
	for (int i = 0; i < R + 2; i++) {
		positions[i][0] = 0;
		positions[i][C + 1] = 0;
	}
	for (int i = 0; i < C + 2; i++) {
		positions[0][i] = 0;
		positions[R + 1][i] = 0;
	}
	int ans = 2 * R * C;
	for (int i = 0; i < (1 << tr); i++) {
		if (bitc(i) == N) {
			int ct = 0;
			int j = i;
			for (int m = 0; m < R; m++) {
				int rd = (i >> (C * m)) & ((1 << C) - 1);
				for (int n = 0; n < C; n++) {
					positions[m + 1][n + 1] = ((rd & (1 << n)) > 0) ? 1 : 0;
				}
			}

			for (int m = 1; m <= R; m++) {
				for (int n = 1; n <= C; n++) {
					if (positions[m][n] == 1 && positions[m][n-1] == 1) {
						ct++;
					}
				}
			}

			for (int m = 1; m <= C; m++) {
				for (int n = 1; n <= R; n++) {
					if (positions[n][m] == 1 && positions[n - 1][m] == 1) {
						ct++;
					}
				}
			}

			ans = min(ans, ct);
		}
	}
	return ans;
}

int main() {
	int T, t;
	sI(T);
	forn(t, 1, T + 1) {
		int R, C, N;
		sI(R);sI(C);sI(N);
		int ans = solve(R, C, N);
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}