#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 16;
int T, N, R, C;

int mat[MAXN][MAXN * MAXN][1 << MAXN];
inline int calc(int mask) {
	int ret = 0;
	for(int i = 1 ; i < MAXN ; i++) {
		if (((mask >> i) & 1) == 1 && ((mask >> (i - 1)) & 1) == 1) {
			ret++;
		}
	}
	return ret;
}

int main() {
	cin >> T;
	for(int t = 1 ; t <= T ; t++) {
		cin >> R >> C >> N;
		if (R * C == N) {
			printf("Case #%d: %d\n", t, (2 * R * C - R - C));
			continue;
		}

		if (C > R) {
			swap(R, C);
		}
		for(int mask = 0 ; mask < (1 << C) ; mask++) {
			for(int j = 0 ; j <= N ; j++) {
				mat[0][j][mask] = 2 * R * C - R - C;
			}
			mat[0][__builtin_popcount(mask)][mask] = calc(mask);
		}
		for(int i = 1 ; i < R ; i++) {
			for(int mask = 0 ; mask < (1 << C) ; mask++) {
				int bp = __builtin_popcount(mask);
				int add = calc(mask);
				for(int j = bp ; j <= N ; j++) {
					mat[i][j][mask] = 2 * R * C - R - C;
					for(int old_mask = 0 ; old_mask < (1 << C) ; old_mask++) {
						mat[i][j][mask] = min(mat[i][j][mask], mat[i - 1][j - bp][old_mask] + __builtin_popcount(old_mask & mask) + add);
					}
				}
			}
		}
		int ans = 2 * R * C - R - C;
		for(int mask = 0 ; mask < (1 << C) ; mask++) {
			ans = min(ans, mat[R - 1][N][mask]);
		}
		printf("Case #%d: %d\n", t, ans);
	}	
	return 0;
}
