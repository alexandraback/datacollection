#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

char alp[30] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
	freopen("input.txt", "r", stdin);
	freopen("Text.txt", "w", stdout);
	int num;
	scanf("%d", &num);
	getchar();
	for (int i = 0; i < num; i++){
		int n;
		scanf("%d", &n);
		int arr[30];
		for (int j = 0; j < 30; j++){
			arr[j] = 0;
		}
		int sum = 0;
		for (int j = 0; j < n; j++){
			scanf("%d", &arr[j]);
			sum += arr[j];
		}
		printf("Case #%d: ", i + 1);
		while (sum > 0){
			int max = arr[0];
			int Max = 0;
			for (int j = 0; j < n; j++){
				if (max < arr[j]) {
					max = arr[j];
					Max = j;
				}
			}
			int a = 'a';
			printf("%c", alp[Max]);
			arr[Max]--;
			sum--;
			if (sum != 2){
				int max = arr[0];
				int Max = 0;
				for (int j = 0; j < n; j++){
					if (max < arr[j]) {
						max = arr[j];
						Max = j;
					}
				}
				printf("%c", alp[Max]);
				arr[Max]--;
				sum--;
			}
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}