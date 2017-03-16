#include <stdio.h>

int main (){
	int i, j, n, test = 1;
	int square1[4][4], square2[4][4], qnt[17];
	int row1, row2;
	int appearTwice=0, chosen=0;

	scanf("%d ", &n);
	// printf("n %d \n",n);
	while(n--){

		for(i=0; i<17; i++){
			qnt[i]=0;
		}
		appearTwice=0;
		chosen=0;

		scanf("%d ", &row1);
		for(i=0; i<4; i++){ //i=row
			for(j=0; j<4; j++){ //j=col
				scanf("%d ",&square1[i][j]);
			}
		}

		// printf("row1 %d \n",row1);
		// for(i=0; i<4; i++){ //i=row
  //           for(j=0; j<4; j++){ //j=col
  //               printf("%d ",square1[i][j]);
  //           }
  //           printf("\n ");
  //       }


		scanf("%d", &row2);
		for(i=0; i<4; i++){
			for(j=0; j<4; j++){ 
				scanf("%d",&square2[i][j]);
			}
		}


		// printf("row2 %d \n",row2);
		// for(i=0; i<4; i++){ //i=row
  //           for(j=0; j<4; j++){ //j=col
  //               printf("%d ",square2[i][j]);
  //           }
  //           printf("\n ");
  //       }


		// printf("chosen \n");
		for(i=0; i<4; i++){
			qnt[square1[row1-1][i]]++;
			qnt[square2[row2-1][i]]++;
			// printf("%d %d\n",square1[row1-1][i], square2[row2-1][i]);
		}
		// printf("\n");

		for(i=0; i<17; i++){
			// printf("i %d -> %d\n", i, qnt[i]);
			if(qnt[i]==2){
				chosen=i;
				appearTwice++;
			}
		}
		// printf("\n");

		if (appearTwice == 0){
			printf("Case #%d: Volunteer cheated!\n", test++);
		}
		else if (appearTwice == 1) {
			printf("Case #%d: %d\n", test++, chosen);
		}
		else if (appearTwice >= 2){
			printf("Case #%d: Bad magician!\n", test++);
		}

	}

	return 1;
}