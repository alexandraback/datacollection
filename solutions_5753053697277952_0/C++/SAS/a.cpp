#include<stdio.h>
#include<stdlib.h>

int max(int a, int b){
    return a > b ? a : b;
}

int s[300];
int main(){
    int T;
    scanf("%d",&T);
    int N;
    for(int ca= 1;ca <=T;ca++){
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            scanf("%d", &s[i]);
        }

        printf("Case #%d:", ca);
        while(true){
            int max_s = 0;
            for(int i=0;i<N;i++){
                max_s = max(max_s, s[i]);
            }
            if(max_s == 0) break;

            int max_count = 0; 
            for(int i=0;i<N;i++){
                if(s[i] == max_s){
                    max_count++;
                }
            }


            
            if(max_count % 2 == 1){
                for(int i=0;i<N;i++){
                    if(s[i] == max_s){
                        printf(" %c", 'A' + i);
                        s[i]--;
                        break;
                    }
                }
            }
            int flag = 0;
            int ans[2];
            for(int i=0;i<N;i++){
                if(s[i] != max_s)continue;
                ans[flag++] = i;
                if(flag == 2){
                    printf(" %c%c", 'A' + ans[0], 'A' + ans[1]);
                    s[ans[0]]--;
                    s[ans[1]]--;
                    flag = 0;
                }
            } 
        }

        printf("\n");

    }
    return 0;
}
