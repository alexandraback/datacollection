#include <cstdio>

int main() {
	int T;
	int n;
	int a[2][5];
	int ans;
	scanf("%d", &T);
	for (int case_no = 0; case_no < T; case_no++) {
		for (int i = 0; i < 2; i++) {
			scanf("%d", &n);
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					if (j == n - 1) {
						scanf("%d", &a[i][k]);
					} else {
						scanf("%d", &ans);
					}
				}
			}
		}
		ans = -1;
		for (int i = 0 ; i < 4; i++) {
			for (int j = 0 ; j < 4; j++) {
				if (a[0][i] == a[1][j]) {
					if (ans == -1) {
						ans = a[0][i];
					} else if (ans > 0) {
						ans = -2;
					}
				}
			}
		}
		printf("Case #%d: ", case_no + 1);
		if (ans == -1) {
			printf("Volunteer cheated!\n");
		} else if (ans == -2) {
			printf("Bad magician!\n");
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
}
