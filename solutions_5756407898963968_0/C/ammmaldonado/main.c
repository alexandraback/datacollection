#include <stdlib.h>
#include <stdio.h>

int num_coincidencias(int row1[4], int row2[4], int * num){

    int coinc = 0;

        int i,j;
        for(i=0; i<4; i++){
            for(j=0; j<4; j++){
                if(row1[i] == row2[j]){
                    coinc++;
                    *num = row1[i];
                    break;
                }
            }
        }
    return coinc;
}

int main(){

    int T; //Number of test cases (1-100)
    scanf("%d", &T);

    int F; //the row number of the selected card in the first arrangement (1-4)

    int S; //the row number of the selected card in the second arrangemens (1-4)

    int cards[4][4];

    int cards2[4][4];

    int t;
    for(t=1; t<=T; t++){

        scanf("%d", &F);

        int i,j;
        for(i=0; i<4; i++){
            for(j=0; j<4; j++){
                scanf("%d", &cards[i][j]);
            }
        }

        scanf("%d", &S);

        for(i=0; i<4; i++){
            for(j=0; j<4; j++){
                scanf("%d", &cards2[i][j]);
            }
        }

        int n;
        int num = num_coincidencias(cards[F-1], cards2[S-1], &n);
        if(num == 0){
            printf("Case #%d: Volunteer cheated!\n", t);
        }else if(num == 1){
            printf("Case #%d: %d\n", t, n);
        }else if(num > 1){
            printf("Case #%d: Bad magician!\n", t);
        }

    }

    return 0;
}
