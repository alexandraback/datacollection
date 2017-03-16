#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A out.txt", "w", stdout);

	int card1[4][4];
	int card2[4][4];
	int ans1;
	int ans2;

	int T;

	scanf("%d", &T);
	int count = 1;

	while(T--){
		scanf("%d", &ans1);
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				scanf("%d", &card1[i][j]);
			}
		}
		scanf("%d", &ans2);
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				scanf("%d", &card2[i][j]);
			}
		}

		int found = 0;
		int value;
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				if(card1[ans1-1][i] == card2[ans2-1][j]){
					found++;
					value = card1[ans1-1][i];
				}
			}
		}

		printf("Case #%d: ", count++);
		if(found == 1){
			printf("%d\n", value);
		}else if(found > 1){
			printf("Bad magician!\n");
		}else if(found == 0){
			printf("Volunteer cheated!\n");
		}
	}
}