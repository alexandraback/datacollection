#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
	freopen ("A-large.in","r",stdin);
	freopen("A-large.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int n;
		scanf("%d", &n);
		char str[100][101];
		for (int j = 0; j < n; j++) {
			scanf("%s",str[j]);
		}
		char cut[100][101];
		int count[100][101];
		for (int j = 0; j < n; j++) {
			int templen = 0;
			char x = '0';
			for (int k = 0; k < strlen(str[j]); k++) {
				if (str[j][k] == x) {
					count[j][templen - 1]++;
				} else {
					x = str[j][k];
					cut[j][templen] = x;
					count[j][templen] = 1;
					templen++;
				}
			}
			cut[j][templen] = 0;
		}
		int check = 0;
		for (int j = 0; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (strcmp(cut[j], cut[k]) != 0) {
					check = -1;
				}
			}
		}
		if (check == -1) {
			printf("Case #%d: Fegla Won\n", i + 1);
		} else {
			int sum = 0;
			for (int j = 0; j < strlen(cut[0]); j++) {
				int min = 10000;
				for (int k = 1; k <= 100; k++) {
					int cnt = 0;
					for (int l = 0; l < n; l++) {
						cnt += abs(k - count[l][j]);
					}
					if (cnt < min) {
						min = cnt;
					}
				}
				sum += min;				
			}
			printf("Case #%d: %d\n", i + 1, sum);
		}
	}

	fclose(stdout);
	return 0;
}