#include <stdio.h>

int main() {
	int t, i, j, k, card1[4][4], card2[4][4], r1, r2, count, num;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%d", &r1);
		for (j = 0; j < 16; j++)
			scanf("%d", &card1[j / 4][j % 4]);
		scanf("%d", &r2);
		for (j = 0; j < 16; j++)
			scanf("%d", &card2[j / 4][j % 4]);
		count = 0;
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 4; k++) {
				if (card1[r1 - 1][j] != 0 && card1[r1 - 1][j] == card2[r2 - 1][k]) {
					count++;
					num = card2[r2 - 1][k];
					card1[r1 - 1][j] = card2[r2 - 1][k] = 0;
				}
			}
		}
		printf("Case #%d: ", i + 1);
		if (count == 1)
			printf("%d\n", num);
		else if (count > 1)
			printf("Bad magician!\n");
		else
			printf("Volunteer cheated!\n");
	}
	return 0;
}
