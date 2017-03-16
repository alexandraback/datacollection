#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

int r1, r2;
int mat1[4][4];
int mat2[4][4];

void solve()
{
	int cand = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (mat1[r1][i] == mat2[r2][j]) {
				if (cand > 0) {
					printf("Bad magician!\n");
					return;
				}
				cand = mat1[r1][i];
			}
		}
	}
	if (cand > 0) {
		printf("%d\n", cand);
	} else {
		printf("Volunteer cheated!\n");
	}
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		printf("Case #%d: ", i);
		scanf("%d", &r1);
		for (int j = 0; j < 16; j++) {
			scanf("%d", &mat1[0][j]);
		}
		r1--;
		scanf("%d", &r2);
		for (int j = 0; j < 16; j++) {
			scanf("%d", &mat2[0][j]);
		}
		r2--;
		solve();
	}
	return 0;
}
