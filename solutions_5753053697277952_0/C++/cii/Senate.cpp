#include<stdio.h>
#include<stdlib.h>

#define maxPartySize 26

int main() {

	int test;
	scanf("%d", &test);
	for(int t=0; t<test; t++) {
		int n;
		scanf("%d", &n);
		int senate[maxPartySize];
		for(int i=0; i<n; i++) 
			scanf("%d", &senate[i]);
		printf("Case #%d:", t+1);
		int sum =0;
		for(int i=0; i<n; i++)
			sum += senate[i];
		while(sum>0) {
			if(sum > 2) {
				int maxTarget = 0;
				for(int i=1; i<n; i++) {
					if(senate[i] > senate[maxTarget]) 
						maxTarget = i;
				}
				printf(" %c", 'A'+maxTarget);
				sum -= 1;
				senate[maxTarget] -= 1;
				maxTarget = 0;
				for(int i=1; i<n; i++) {
					 if(senate[i] > senate[maxTarget])
						maxTarget = i;
				}
				if(senate[maxTarget] > (sum/2)) {
					printf("%c", 'A'+maxTarget);
					senate[maxTarget] -= 1;
					sum -= 1;
				}
			}
			else {
				printf(" ");
				for(int i=0; i<n; i++) {
					if(senate[i] > 0) {
						printf("%c", 'A'+i);
						senate[i] -= 1;
						sum -= 1;
					}
				}
			}
		}
		printf("\n");
	}

	return 0;
}

