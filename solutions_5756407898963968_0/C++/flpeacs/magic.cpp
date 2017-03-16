#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int t, a1, a2, cont, answer, i, j, cases;
	int grid1[4][4], grid2[4][4];
	int r[17];

	scanf("%d", &t);

	for(cases = 1; cases <= t; cases++){
		cont = 0;

		for(i = 0; i < 17; i++)
			r[i] = 0;		
	
		scanf("%d", &a1);

		for(i = 0; i < 4; i++){
			for(j = 0; j < 4; j++){
				scanf("%d", &grid1[i][j]);
				if(i + 1 == a1){
					r[grid1[i][j]]++;				
				}
			}
		}

		

		scanf("%d", &a2);

		for(i = 0; i < 4; i++){
			for(j = 0; j < 4; j++){
				scanf("%d", &grid2[i][j]);
				if(i + 1 == a2){
					r[grid2[i][j]]++;				
				}			
			}
		}

		for(i = 1; i < 17; i++){
			if(r[i] > 1){
				cont++;
				answer = i;			
			}
		}

		if(cont > 1)
			printf("Case #%d: Bad magician!\n", cases);
		else if(cont == 1)
			printf("Case #%d: %d\n", cases, answer);
		else
			printf("Case #%d: Volunteer cheated!\n", cases);
	}
}
