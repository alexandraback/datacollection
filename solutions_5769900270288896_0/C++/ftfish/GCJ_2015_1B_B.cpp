#include <bits/stdc++.h>
using namespace std;
const int mn = 17;

int f[2][1<<mn][mn*mn];

int main() {
	int Tc;
	scanf("%d", &Tc);
	for (int Tn = 1; Tn <= Tc; ++Tn) {
		int R, C, N;
		cin >> R >> C >> N;

		if (C > R) swap(R, C);

		memset(f, 0x3f, sizeof(f));
		f[0][0][0] = 0;
		int finalans = 0x3f3f3f3f;
		for (int i = 1; i <= R; ++i) {
			memset(f[i&1], 0x3f, sizeof(f[0]));
			for (int j = 0; j < (1<<C); ++j){
				int pcj = __builtin_popcount(j);
				int thisline = 0;
				for (int t = 0; t < C; ++t)
					if ((j & (1 << t)) && (j & (1 << (t + 1)))) thisline++;
				for (int k = pcj; k <= N; ++k){
					int ans = 0x3f3f3f3f;
					for (int j2 = 0; j2 < (1<<C); ++j2) {
						ans = min(ans, f[(i&1)^1][j2][k-pcj] + __builtin_popcount(j & j2) + thisline);
					}
					f[i&1][j][k] = ans;
					if (i == R && k == N) finalans = min(finalans, ans);
				}
			}
		}

		printf("Case #%d: ", Tn);
		printf("%d\n", finalans);
	}
	return 0;
}
