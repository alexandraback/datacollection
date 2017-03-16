#include <cstdio>

int t, row, r, res; char g[22], dn;
int main() {
	freopen("a.in", "r", stdin); freopen("a.out", "w", stdout);
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		printf("Case #%d: ", tc);
		for (int i = 0; i <= 16; i++) g[i] = 1;
		for (int i = 0; i < 2; i++) {
			scanf("%d", &row);
			for (int j = 1; j <= 4; j++) for (int k = 0; k < 4; k++) {
				scanf("%d", &r);
				if (j!=row) g[r] = 0;
			}
		}
		res = dn = 0;
		for (int i = 1; i <= 16; i++) if (g[i]) {
			if (res) {
				printf("Bad magician!\n"); dn = 1; break;
			}
			res = i;
		}
		if (!res) printf("Volunteer cheated!\n");
		else if (!dn) printf("%d\n", res);
	}


	return 0;
}