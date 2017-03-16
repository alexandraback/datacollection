
#include<stdlib.h>
#include<stdio.h>
using namespace std;

int main(){
	int T, sol; 
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t){
		int pos[17] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, ans, card;
		for (int i = 0; i < 2; i++){
			scanf("%d", &ans);
			for (int r = 1; r <= 4; r++){
				for (int c = 1; c <= 4; c++){
					scanf("%d", &card);
					if (r == ans) pos[card]++;
				}
			}
		}
		sol = 0;
		for (int i = 1; i <= 16; i++){
			if (pos[i] == 2) sol = sol * 100 + i;
		}
		if (sol == 0){
			printf("Case #%d: Volunteer cheated!\n", t);
		}
		else if (sol <= 16){
			printf("Case #%d: %d\n", t, sol);
		}
		else{
			printf("Case #%d: Bad magician!\n", t);
		}
	}
	return 0;
}

