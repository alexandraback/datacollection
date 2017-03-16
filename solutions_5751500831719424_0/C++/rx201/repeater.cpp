#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

int main(int argc, char* argv[]) {
	int T;
	
	setbuf(stdout, NULL);

	scanf("%d\n", &T);
	for(int t=0; t<T; t++) {
		char characters[200];
		char freq[200][200];
		char input[200];
		int N, oldcc, ccount;
		bool bad = false;
		memset(freq, 0, sizeof(freq));
		memset(characters, 0, sizeof(characters));
		
		oldcc = -1;
		scanf("%d\n", &N);
		for(int i=0; i<N; i++) {
			scanf("%s\n", input);
			//printf("%s\n", input);
			ccount = -1;
			for( int j=0; j<strlen(input); j++) {
				if (j ==0 || (input[j] != input[j-1])) {
					ccount++;
					if (i != 0) {
						if(  characters[ccount] != input[j])
							bad = true;
					}
					characters[ccount] = input[j];
					freq[i][ccount] = 1;
					//printf("%c %d\n", characters[ccount], freq[i][ccount]);
				} else {
					freq[i][ccount]++;
					//printf("%c %d\n", characters[ccount], freq[i][ccount]);
				}
			}
			
			if (oldcc != -1 && ccount != oldcc)
				bad = true;
			oldcc = ccount;
		}
		ccount++;
		if (bad) 
			printf("Case #%d: Fegla Won\n", t+1);
		else {
			int result = 0;
			for(int i=0; i<ccount; i++) {
				int min = 2 * 100 * 100;
			
				for(int median = 0; median <= 100; median++) {
					int sum = 0;
					for(int j = 0; j < N; j++) {
						if (median >= freq[j][i])
							sum += (median - freq[j][i]);
						else
							sum += (freq[j][i] - median);
					}
					if (sum < min)
						min = sum;
				}
				
				result += min;
			}
			printf("Case #%d: %d\n", t+1, result);
		}
	}
	
	return 0;
}
