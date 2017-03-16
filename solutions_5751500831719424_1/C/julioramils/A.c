#include <stdio.h>

#define MAX_N 101


int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(){
    freopen("A-large.in", "r", stdin);
    freopen("A-large.txt", "w", stdout);
    int T;
    char s[MAX_N];
    int val[MAX_N][MAX_N];
    int caso=1;
    int possible;
    int N;
    int i,j,k;
    int tam;
    char c;
    int flag;
    int sol=0;
    int arr[MAX_N];
    int aux;

    scanf("%d", &T);
    while (T--){
        aux=0;
        sol=0;
        possible=1;

        scanf("%d", &N);
        getchar();

        i=j=0;
        flag=1;

        scanf("%c", &c);
        s[i]=c;
        val[j][i]=1;
        while(scanf("%c", &c)!=EOF&&c!='\n'){
            if(c==s[i]){
                val[j][i]++;
            }else{
                i++;
                s[i]=c;
                val[j][i]=1;
            }
        }
        tam=i;
        j++;

        for(j=1; j<N; j++){
            for(k=0;k<MAX_N;k++){
                val[j][k]=0;
            }
            i=0;
            while(scanf("%c", &c)!=EOF&&c!='\n'){
                if(c==s[i]){
                    val[j][i]++;
                }else if(val[j][i]==0){
                    possible=0;
                }else{
                    i++;
                    if(c==s[i]){
                        val[j][i]++;
                    }else{
                        possible=0;
                    }
                }
            }
            if(i<tam||val[j][i]==0){
                possible=0;
            }
        }
/*
        for(i=0; i<N; i++){
            for(j=0; j<=tam; j++){
                printf("%d ", val[i][j]);
            }printf("\n");
        }

*/
        if(possible){
            for(j=0; j<=tam;j++){
                for(i=0; i<N; i++){
                    arr[i]=val[i][j];
                }
                qsort(arr, N, sizeof(int), compare );
                /*for(i=0; i<N; i++){
                    printf("%d ", arr[i]);
                }*/
                aux=arr[N/2];
                for(i=0;i<N/2; i++){
                    sol+=aux-arr[i];
                }
                for(i=(N/2)+1;i<N; i++){
                    sol+=arr[i]-aux;
                }
                //printf("%d\n", sol);
            }
            printf("Case #%d: %d\n", caso, sol);
        }else{
            printf("Case #%d: Fegla Won\n", caso);
        }
        caso++;

    }
    return 0;
}
