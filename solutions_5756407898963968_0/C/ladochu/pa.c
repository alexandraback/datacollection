#include <stdio.h>

#define WIDTH 4
#define HEIGHT 4

int main(){
    int T;
    int i, x, y;
    int case_n;
    scanf("%d", &T);
    for(case_n = 1;case_n <= T;++case_n){
        int impossible[HEIGHT * WIDTH + 1] = {};
        int possible_count = HEIGHT * WIDTH;
        for(i = 0;i < 2;++i){
            int answer_row;
            scanf("%d", &answer_row);
            for(x = 1;x <= HEIGHT;++x){
                for(y = 1;y <= WIDTH;++y){
                    int tmp;
                    scanf("%d", &tmp);
                    if(x != answer_row && impossible[tmp] == 0){
                        impossible[tmp] = 1;
                        --possible_count;
                    }
                }
            }
        }
        printf("Case #%d: ", case_n);
        if(possible_count == 0){
            printf("Volunteer cheated!");
        }else if(possible_count == 1){
            int answer;
            for(i = 1;i <= HEIGHT * WIDTH;++i){
                if(impossible[i] == 0){
                    answer = i;
                    break;
                }
            }
            printf("%d", answer);
        }else{
            printf("Bad magician!");
        }
        printf("\n");
    }
}
