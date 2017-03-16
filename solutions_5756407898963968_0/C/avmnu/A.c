#include <stdio.h>

int main()
{
	int t;
	scanf("%d", &t);

	int i;
	for (i = 1; i <= t; i++) {
		int a_g;
		int g[4][4];
		int a_h;
		int h[4][4];
		int j, k;

		scanf("%d", &a_g);

		for (j = 0; j < 4; j++) {
			for (k = 0; k < 4; k++) {
				scanf("%d", &g[j][k]);
			}
		}

		scanf("%d", &a_h);

		for (j = 0; j < 4; j++) {
			for (k = 0; k < 4; k++) {
				scanf("%d", &h[j][k]);
			}
		}

		int c = 0;
		int m;

		for (j = 0; j < 4; j++) {
			for (k = 0; k < 4; k++) {
				if (g[a_g - 1][j] == h[a_h - 1][k]) {
					c++;
					m = g[a_g - 1][j];
				}
			}
		}

		printf("Case #%d: ", i);

		if (c == 0) {
			puts("Volunteer cheated!");
		} else if (c > 1) {
			puts("Bad magician!");
		} else {
			printf("%d\n", m);
		}
	}

	return 0;
}
