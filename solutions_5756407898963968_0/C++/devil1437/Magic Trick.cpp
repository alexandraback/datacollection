#include <stdio.h>
#include <stdlib.h>

int main(){
	int SQUARE_LENGTH = 4;
	int numTestCase = 0, numSame = 0;
	int answer = 0, output = 0;
	int sequence[2][4] = {0};
	int i, j, temp;
	int testCase;
	
	scanf("%d", &numTestCase);
	
	for(testCase = 0; testCase < numTestCase; testCase++){
		numSame = 0;
		
		scanf("%d", &answer);
		
		for(i = 0; i < SQUARE_LENGTH; i++){
			for(j = 0; j < SQUARE_LENGTH; j++){
				if(i+1 == answer){
					scanf("%d", &sequence[0][j]);
				}
				else{
					scanf("%d", &temp);
				}
			}
		}
		
		scanf("%d", &answer);
		
		for(i = 0; i < SQUARE_LENGTH; i++){
			for(j = 0; j < SQUARE_LENGTH; j++){
				if(i+1 == answer){
					scanf("%d", &sequence[1][j]);
				}
				else{
					scanf("%d", &temp);
				}
			}
		}
		
		for(i = 0; i < SQUARE_LENGTH; i++){
			for(j = 0; j < SQUARE_LENGTH; j++){
				if(sequence[0][i] == sequence[1][j]){
					numSame++;
					output = sequence[0][i];
				}
			}
		}
		
		switch(numSame){
			case 1:
				printf("Case #%d: %d\n", testCase+1, output);
				break;
			case 0:
				printf("Case #%d: Volunteer cheated!\n", testCase+1);
				break;
			default:
				printf("Case #%d: Bad magician!\n", testCase+1);
				break;
		}
	}
	
	return 0;
}
