#include <cstdio>

int T, ra, a[4][4], rb, b[4][4], ans, cnt;

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d", &ra);
		ra--;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				scanf("%d", &a[i][j]);
			}
		}
		scanf("%d", &rb);
		rb--;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				scanf("%d", &b[i][j]);
			}
		}
		cnt = 0;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				if (a[ra][i] == b[rb][j]) {
					ans = a[ra][i];
					cnt++;
					break;
				}
			}
		}
		printf("Case #%d: ", tc);
		if (cnt == 0) {
			printf("Volunteer cheated!\n");
		}
		else if (cnt == 1) {
			printf("%d\n", ans);
		}
		else printf("Bad magician!\n");
	}
	return 0;
}