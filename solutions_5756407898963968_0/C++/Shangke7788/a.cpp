#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int a[4][4], b[4][4], n, m;

int main() {
	int n_case = 0;
	scanf("%d", &n_case);
	for (int ca = 1; ca <= n_case; ca++) {
		scanf("%d", &n), n--;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		scanf("%d", &m), m--;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				scanf("%d", &b[i][j]);
			}
		}
		int num = 0, ans = -1;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (a[n][i] == b[m][j]) {
					num++, ans = a[n][i];
				}
			}
		}
		if (num == 0) {
			printf("Case #%d: Volunteer cheated!\n", ca);
		} else if (num > 1) {
			printf("Case #%d: Bad magician!\n", ca);
		} else {
			printf("Case #%d: %d\n", ca, ans);
		}
	}
	return 0;
}
