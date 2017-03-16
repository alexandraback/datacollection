#include <bits/stdc++.h>

using namespace std;

int A[20][20];
void solve(int t) {
	int C, R, N;
	scanf("%d%d%d", &R, &C, &N);
	int ans = 1 << 30;
	for(int mask = 0; mask < (1 << (R * C)); ++mask) {
		bitset< 20 > B(mask);
		if(B.count() != N) continue;
		memset(A, 0, sizeof(A));
		for(int r = 0; r < R; ++r)
			for(int c = 0; c < C; ++c) {
				A[r + 1][c + 1] = B[r * C + c];
			}
		int tmp = 0;
		for(int r = 1; r <= R; ++r)
			for(int c = 1; c <= C; ++c) {
				if(A[r][c] == 0) continue;
				tmp += A[r - 1][c] + A[r + 1][c] + A[r][c + 1] + A[r][c - 1];
			}
		ans = min(ans, tmp);
		if(ans == 0) break;
	}
	printf("Case #%d: %d\n", t, ans / 2);
}

int main() {
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t)
		solve(t);
}
