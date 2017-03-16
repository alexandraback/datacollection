#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas) {
		int v[17] = {};
		for (int r, k = 0; k < 2; ++k) {
			scanf("%d", &r);
			for (int i = 1; i <= 4; ++i) {
				for (int a, j = 0; j < 4; ++j) {
					scanf("%d", &a);
					if (i == r) v[a]++;
				}
			}
		}
		int cnt = 0, ans = 0;
		for (int i = 1; i <= 16; ++i) {
			if (v[i] == 2) ans = i, ++cnt;
		}
		printf("Case #%d: ", cas);
		if (cnt == 1) printf("%d\n", ans);
		else if (!cnt) puts("Volunteer cheated!");
		else puts("Bad magician!");
	}
}