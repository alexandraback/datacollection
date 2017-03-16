#include <cstdio>
using namespace std;

int main() {
	int T, i, j, k, A, B, X[5][5], Y[5][5], cnt, f;
	
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A.txt", "w", stdout);
	
	scanf("%d", &T);
	for (i = 1; i <= T; i++) {
		scanf("%d", &A);
		for (j = 1; j <= 4; j++)
			for (k = 1; k <= 4; k++)
				scanf("%d", &X[j][k]);
		scanf("%d", &B);
		for (j = 1; j <= 4; j++)
			for (k = 1; k <= 4; k++)
				scanf("%d", &Y[j][k]);
		for (j = 1, cnt = 0; j <= 4; j++)
			for (k = 1; k <= 4; k++)
				if (X[A][j] == Y[B][k]) {
					cnt++;
					f = X[A][j];
				}
		switch (cnt) {
			case 0: printf("Case #%d: Volunteer cheated!\n", i); break;
			case 1: printf("Case #%d: %d\n", i, f); break;
			default: printf("Case #%d: Bad magician!\n", i);
		}
	}
	
	return 0;
}
