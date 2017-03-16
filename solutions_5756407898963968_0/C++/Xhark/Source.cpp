#include <stdio.h>
const int N = 4, B = 2;
int board[B][N][N];
int row[B];
int count[N*N];
int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T-- > 0) {
		for (int b = 0; b < B; b++) {
			scanf("%d", &row[b]);
			row[b] --;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					scanf("%d", &board[b][i][j]);
					board[b][i][j] --;
				}
			}
		}
		for (int i = 0; i < N*N; i++) count[i] = 0;
		for (int b = 0; b < B; b++) {
			int i = row[b];
			for (int j = 0; j < N; j++) {
				count[board[b][i][j]] ++;
			}
		}
		int sol = -1, solcount = 0;
		for (int i = 0; i < N*N; i++) {
			if (count[i] == B) {
				sol = i; solcount++;
			}
		}
		static int cs = 1;
		printf("Case #%d: ", cs++);
		if (solcount == 1) {
			printf("%d\n", sol+1);
		}
		else if (solcount == 0) {
			printf("Volunteer cheated!\n");
		}
		else {
			printf("Bad magician!\n");
		}
	}
	return 0;
}