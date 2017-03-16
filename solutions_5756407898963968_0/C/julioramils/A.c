#include <stdio.h>

int main(){
    freopen ("A-small-attempt0.in","r",stdin);
    freopen ("A_out","w",stdout);
    int T;
    int line[4];
    int cant;
    int user;
    int aux;
    int rows;
    int sol;
    int i;
    int caso=0;

    scanf("%d", &T);
    while(T--){
        caso++;
        cant=0;
        rows = 4;
        scanf("%d", &user);
        while(user>1){
            scanf("%d %d %d %d", &aux,&aux,&aux,&aux);
            user--;
            rows--;
        }
        scanf("%d %d %d %d", &line[0],&line[1],&line[2],&line[3]);
        rows--;
        while(rows>0){
            scanf("%d %d %d %d", &aux,&aux,&aux,&aux);
            rows--;
        }


        rows = 4;
        scanf("%d", &user);
        while(user>1){
            scanf("%d %d %d %d", &aux,&aux,&aux,&aux);
            user--;
            rows--;
        }
        user=4;
        while(user>0){
            scanf("%d", &aux);
            for(i=0;i<4;i++){
                if(line[i]==aux){
                    cant++;
                    sol=aux;
                    break;
                }
            }
            user--;
        }
        rows--;
        while(rows>0){
            scanf("%d %d %d %d", &aux,&aux,&aux,&aux);
            rows--;
        }

        switch(cant){
        case 0:
            printf("Case #%d: Volunteer cheated!\n", caso);
            break;
        case 1:
            printf("Case #%d: %d\n", caso, sol);
            break;
        default:
            printf("Case #%d: Bad magician!\n", caso);
            break;
        }
    }
}
