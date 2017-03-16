#include <stdio.h>

int main (void) {
	int a, b;
	char temp[81];
	
	int answers;
	int cardsRead[4];
	int cardsTotal[16];
	int cases;
	int currentCase;
	int final;
	int reading;
	int times;
	
	fgets(temp, 80, stdin);
	sscanf(temp, "%d", &cases);
	for (currentCase = 1; currentCase <= cases; currentCase++) {
	
		answers = 0;
		for (a = 0; a < 16; a++) {
			cardsTotal[a] = 0;
		}
		
		for (times = 0; times < 2; times++) {
			fgets(temp, 80, stdin);
			sscanf(temp, "%d", &reading);
			for (a = 1; a <= 4; a++) {
				fgets(temp, 80, stdin);
				sscanf(temp, "%d %d %d %d", &cardsRead[0], &cardsRead[1], &cardsRead[2], &cardsRead[3]); 
				if (a == reading) {
					for (b = 0; b < 4; b++) {
						cardsTotal[cardsRead[b]-1]++;
					}
				}
			}
		}
		
		for (a = 0; a < 16; a++) {
			if (cardsTotal[a] == 2) {
				final = a+1;
				answers++;
			}
		}
		
		if (answers == 0) {
			printf("Case #%d: Volunteer cheated!\n", currentCase);
		}
		else if (answers == 1) {
			printf("Case #%d: %d\n", currentCase, final);
		}
		else {
			printf("Case #%d: Bad magician!\n", currentCase);
		}
	}
	return 0;
}