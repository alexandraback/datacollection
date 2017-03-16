#include<stdio.h>

int arr[100];

int main() {
	int m, n, i, j;
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small.out", "w", stdout);

	int t, ti;
	scanf("%d", &t); 
	for (ti = 0; ti < t; ti++) {
		printf("Case #%d: ",ti+1);
		scanf("%d", &n);
		int sum = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			sum += arr[i];
		}
		while (sum > 0) {
			if (sum == 3) {
				for (j = 0; j < n; j++) {
					if (arr[j] == 1) {
						printf("%c", 'A' + j);
						arr[j]--;
						sum--;
						break;
					}
				}
			}
			else if (sum == 2) {
				for (j = 0; j < n; j++) {
					if (arr[j] == 1) {
						printf("%c", 'A' + j);
						arr[j]--;
						sum--;
					}
				}
			}
			else {
				int cmax = 0;
				for (j = 1; j < n; j++) {
					if (arr[cmax] < arr[j]) cmax = j;
				}
				printf("%c", 'A' + cmax);
				arr[cmax]--;
				sum--;
				cmax = 0;
				for (j = 1; j < n; j++) {
					if (arr[cmax] < arr[j]) cmax = j;
				}
				printf("%c", 'A' + cmax);
				arr[cmax]--;
				sum--;
			}
			printf(" ");
		}
		printf("\n");
	}
	return 0;

}