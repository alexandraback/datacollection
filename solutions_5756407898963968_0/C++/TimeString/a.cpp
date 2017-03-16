#include <stdio.h>

int main() {
	int ecase, ecount;
	scanf("%d", &ecase);

	for (ecount = 1; ecount <= ecase; ecount++) {
		int array[1000];
		for (int i = 1; i <= 16; i++)
			array[i] = 0;
		for (int k = 0; k < 2; k++) {
			int n;
			scanf("%d", &n);
			for (int i = 1; i <= 4; i++) {
				for (int j = 0; j < 4; j++) {
					int t;
					scanf("%d", &t);
					if (i == n)
						array[t]++;
				}
			}
		}


		int count[3];
		count[0] = count[1] = count[2] = 0;
		int answer = -1;
		for (int i = 1; i <= 16; i++) {
			if (array[i] == 2)
				answer = i;
			count[ array[i] ]++;
		}
		if (count[2] == 1)
			printf("Case #%d: %d\n", ecount, answer);
		else if (count[2] > 1)
			printf("Case #%d: Bad magician!\n", ecount);
		else
			printf("Case #%d: Volunteer cheated!\n", ecount);
	}

	return 0;
}
