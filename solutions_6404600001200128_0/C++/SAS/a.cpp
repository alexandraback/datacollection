#include<stdio.h>
#include<stdlib.h>
int max(int a,int b){
    return a > b ? a : b;
}
int min(int a,int b){
    return a < b ? a : b;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int ca = 0; ca < T ; ca++){
        int N;
        int m[10021];
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            scanf("%d",&m[i]);
        }
        int x = 0;
        int maxE = 0;
        int c = 0;
        for(int i=1;i<N;i++){
            x += max(0, m[i - 1] - m[i]);
        }
        for(int i=1;i<N;i++){
            maxE = max(maxE, m[i - 1] - m[i]);
        }
        int y = 0;
        for(int i=1;i<N;i++){
            y += min(m[i-1], maxE);
        }
        printf("Case #%d: %d %d\n", ca + 1, x , y);
    }
    return 0;
}
