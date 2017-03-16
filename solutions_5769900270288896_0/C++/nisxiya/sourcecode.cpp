#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;


class Solution {
public:
	const static int N = 1000000+10;
	map<int, int> m;
	void solve() {
		int tcase;
		cin >> tcase;
		pre_compute();
		for (int i = 1; i <= tcase; i++) {
			int n;
			cin >> n;

			cout << "Case #" << i << ": " << f[n] << endl;
		}
	}
	int *f;
	void pre_compute() {
		f = new int[N];
		memset(f, 0, sizeof(int)* N);
		f[0] = 0;
		f[1] = 1;
		for (int i = 2; i < N; i++) {
			int i_reverse = reverse(i);
			if (i_reverse < i && i%10 != 0) f[i] = min(f[i-1], f[i_reverse]) + 1;
			else f[i] = f[i-1] + 1;
		}
//		for (int i = 1; i < 30; i++) {
//			cout << "i:" << i << " " << f[i] << endl;
//		}
	}
	int reverse(int k) {
		int ans = 0;
		while (k > 0) {
			ans *= 10;
			ans += k%10;
			k /= 10;
		}
		return ans;
	}
};

class Solution2 {
public:
	const static int R_MAX = 16+1;
	const static int C_MAX = 16+1;
	int board[R_MAX][C_MAX];
	int m[R_MAX][C_MAX][R_MAX];
	void init() {
		for (int i = 0; i < R_MAX; i++) for (int j = 0; j < C_MAX; j++) {
			board[i][j] = 0;
			for (int k = 0; k < R_MAX; k++) m[i][j][k] = 1<<30;
		}
	}
	void solve() {
		init();
		for (int r = 1; r < R_MAX; r++) {
			for (int c = 1; c < C_MAX; c++) {
				if (r * c > 16) continue;
				compute(r, c, 0);
//				printf("r:%d, c:%d  \n", r, c);
			}
		}
//		compute(3,3,0);
//		for (int k = 0; k <= 9; k++) {
//			printf("K:%d value:%d\n", k, m[3][3][k]);
//		}
		int tcase ;
		cin  >> tcase;

		for (int i = 1; i <= tcase; i++) {
//			cout << "@" << endl;
			int r, c, k;
			cin >> r >> c >> k;
			cout << "Case #" << i << ": " << m[r][c][k] << endl;
		}
	}
	void compute(int r, int c, int step) {
		if (step >= r * c) {
			// update unhappiness;
			int k = 0, unhappiness = 0;
			for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) if (board[i][j] == 1) k++;
			for (int i = 1; i < r; i++) {
				for (int j = 1; j <= c; j++) {
					if (board[i][j] && board[i+1][j]) unhappiness++;
				}
			}
			for (int j = 1; j < c; j++) {
				for (int i = 1; i <= r; i++) {
					if (board[i][j] && board[i][j+1]) unhappiness++;
				}
			}
			m[r][c][k] = min(m[r][c][k], unhappiness);
		} else {
			board[step/c + 1][step%c + 1] = 1;
			compute(r, c, step+1);
			board[step/c + 1][step%c + 1] = 0;
			compute(r, c, step+1);
		}
	}
};

int main() {
	Solution2 solution;
	solution.solve();
	return 0;
}
