#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int N, R, C;
int table[16][16];

bool check(int r, int c) {
	return r >= 0 && c >= 0 && r < R && c < C && table[r][c];
}

int solve(int k, int last, int acc) {
	if (k == N) return acc;

	int best = INT_MAX;
	for (int i = last + 1; i < R * C; ++i) {
		int r = i / C;
		int c = i % C;

		int ans = acc + check(r - 1, c) + check(r + 1, c) + check(r, c - 1) + check(r, c + 1);
		if (ans < best) {
			table[r][c] = 1;

			ans = solve(k + 1, i, ans);
			best = min(best, ans);

			table[r][c] = 0;
		}
	}

	return best;
}

int main() {
	int T; cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >>R >> C >> N;

		for (int i = 0; i < 16; ++i) for (int j = 0; j < 16; ++j) table[i][j] = 0;

		cout << "Case #" << tc << ": " << solve(0, -1, 0) << endl;
	}
	

}