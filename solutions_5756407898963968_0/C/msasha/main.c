#include <stdio.h>

int main(void){
	int t, tn;
	
	scanf("%d\n", &t);
	for (tn = 1; tn <= t; ++tn){
		int ans, i;
		int row[4];
		
		scanf("%d\n", &ans);
		
		for (i = 1; i <= 4; ++i){
			if (i == ans){
				int j;
				for (j = 0; j < 4; ++j){
					scanf("%d", &row[j]);
					getchar(); // Skip the newline
				}
			}
			else{
				int c;
				while ((c = getchar()) != '\n');
			}
		}
		
		scanf("%d\n", &ans);
		
		int count = 0;
		int result = -1;
		for (i = 1; i <= 4; ++i){
			if (i == ans){
				int j;
				for (j = 0; j < 4; ++j){
					int val;
					scanf("%d", &val);
					getchar(); // Skip the newline
					
					int k;
					for (k = 0; k < 4; ++k){
						if (row[k] == val){
							count++;
							result = val;
						}
					}
					
				}
			}
			else{
				int c;
				while ((c = getchar()) != '\n');
			}
		}
		
		printf("Case #%d: ", tn);
		if (count == 1)
			printf("%d\n", result);
		else if (count == 0)
			printf("Volunteer cheated!\n");
		else
			printf("Bad magician!\n");
	}
	
	return 0;
}