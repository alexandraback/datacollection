#include <stdio.h>

int main(){

    int z, t, n, i, j;
    int p[26];
    int sum, max1, max2;

    scanf("%d", &t);
    for(z=1; z<=t; z++){
        scanf("%d", &n);
        sum = 0;
        for(i=0; i<n; i++){
            scanf("%d", &(p[i]));
            sum += p[i];
        }
        printf("Case #%d: ", z);
        for(i=sum; i>0; ){
            if(i%2 == 0){
                max1 = 0;
                for(j=0; j<n; j++){
                    if(p[max1] < p[j]){
                        max1 = j;
                    }
                }
                max2 = (max1+1)%n;
                for(j=0; j<n; j++){
                    if(j == max1){
                        continue;
                    }
                    if(p[max2] < p[j]){
                        max2 = j;
                    }
                }
                printf("%c%c ", max1+'A', max2+'A');
                i-=2;
                p[max1]--;
                p[max2]--;
            }else{
                max1 = 0;
                for(j=0; j<n; j++){
                    if(p[max1] < p[j]){
                        max1 = j;
                    }
                }
                printf("%c ", max1+'A');
                i--;
                p[max1]--;
            }
        }
        printf("\n");
    }

    return 0;

}
