#include <stdio.h>
using namespace std;

int T;
int N;
int P[30];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t, i, j, k;

	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		scanf("%d", &N);
		for (i = 0; i < N; i++)
			scanf("%d", &P[i]);

		printf("Case #%d: ", t);
		while (true) {
			int sum = 0;
			for (i = 0; i < N; i++) sum += P[i];
			if (sum == 0) break;

			int max = 0;
			int select1, select2;
			bool next = false;
			for (i = -1; i < N; i++) {
				for (j = -1; j < N; j++) {
					if ((i >= 0 && P[i] > 0) || (j >= 0 && P[j] > 0)) {
						int count = 0;
						bool flag1 = false, flag2 = false;
						if (i >= 0 && P[i] > 0) { P[i]--; count++; flag1 = true; }
						if (j >= 0 && P[j] > 0) { P[j]--; count++; flag2 = true; }

						int sum = 0;
						for (k = 0; k < N; k++) sum += P[k];

						bool err = false;
						for (k = 0; k < N; k++) {
							if ((double)P[k] / (double)sum > 0.5) err = true;
						}
						if (!err && max < count) {
							select1 = i;
							select2 = j;
							max = count;
						}

						if (flag1) P[i]++;
						if (flag2) P[j]++;
					}
				}
			}
			if (select1 >= 0) {
				printf("%c", select1 + 'A');
				P[select1]--;
			}
			if (select2 >= 0) {
				printf("%c", select2 + 'A');
				P[select2]--;
			}
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}
