#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    int i, j, k, T, a, b, r;

    int M[4][4];
    int C[16];

    cin >> T;

    for(k=0; k<T; k++){
        for(i=0; i<4; i++)  // RESETANDO
            for(j=0; j<4; j++)
                M[i][j] = 0;

        for(i=0; i<16; i++)
            C[i] = 0;

        cin >> r;
        r--;

        for(i=0; i<4; i++){ // LINHAS
            for(j=0; j<4; j++){
                cin >> M[i][j];
                M[i][j]--;
                //cout << M[i][j] << " ";
            }
            //cout << "\n";
        }

        for(i=0; i<4; i++){
            C[ M[r][i] ]++;
            //cout << M[r][i] << " ";
        }
            //cout << "\n";

        /*for(i=0; i<4; i++)  // RESETANDO
            for(j=0; j<4; j++)
                M[i][j] = 0;*/

        cin >> r;
        r--;

        for(i=0; i<4; i++){ // LINHAS
            for(j=0; j<4; j++){
                cin >> M[i][j];
                M[i][j]--;
                //cout << M[i][j] << " ";
            }
            //cout << "\n";
        }

        for(i=0; i<4; i++){
            C[ M[r][i] ]++;
            //cout << M[r][i] << " ";
        }
            //cout << "\n";

        int n = 16;
        int bad = 0;

        for(i=0; i<16; i++){
            if(C[i]==2){
                if(n==16)
                    n = i;
                else
                    bad = 1;
            }
           // printf("%d %d\n", i, C[i]);
        }

        if(bad)
            printf("Case #%d: Bad magician!\n", k+1);
        else if(n==16)
            printf("Case #%d: Volunteer cheated!\n", k+1);
        else
            printf("Case #%d: %d\n", k+1, n+1);
    }

    return 0;
}
