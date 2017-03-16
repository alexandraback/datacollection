#include <stdio.h>

int main()
{
	int i, t;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		int l1, l2;
		int a[4][4], b[4][4];
		int j, k;
		scanf("%d", &l1);
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 4; k++) {
				scanf("%d", &a[j][k]);
			}
		}
		scanf("%d", &l2);
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 4; k++) {
				scanf("%d", &b[j][k]);
			}
		}
		l1--;
		l2--;
		int count = 0;
		int result;
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 4; k++) {
				if (a[l1][j] == b[l2][k]) {
					count++;
					result = a[l1][j];
				}
			}
		}
		if (count == 0) {
			printf("Case #%d: Volunteer cheated!\n", i + 1);
		}
		else if (count > 1) {
			printf("Case #%d: Bad magician!\n", i + 1);
		}
		else {
			printf("Case #%d: %d\n", i + 1, result);
		}
	}
	return 0;
}
