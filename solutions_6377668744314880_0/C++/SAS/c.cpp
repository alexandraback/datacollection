#include<stdio.h>
#include<stdlib.h>
int x[3003],y[3003];
int N;
int max(int a, int b){
    return (a > b) ? a : b;
}
int min(int a,int b){
    return (a > b) ? b : a;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int ca =0 ;ca < T; ca++){
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            scanf("%d %d",&x[i],&y[i]);
        }
        printf("Case #%d:\n", ca + 1);
        if(N <= 3){
            for(int i=0;i<N;i++)
                printf("0\n");
            continue;
        }
        for(int i=0;i<N;i++){
            int ans = N / 2;
            for(int j=0;j<N;j++){
                if(i == j)continue;

                long long int dx = (x[i] - x[j]);
                long long int dy = (y[i] - y[j]);

                int largeCount = 0;
                int smallCount = 0;
                for(int k=0;k<N;k++){
                    if(k == i || k == j) continue;
                    long long int ddx = (x[i] - x[k]);
                    long long int ddy = (y[i] - y[k]);
                    long long int tmp = ddx * dy - ddy * dx;
                    if(tmp > 0){
                        largeCount ++;
                    }else if(tmp < 0){
                        smallCount ++;
                    }
                }
                ans = min(ans, largeCount);
                ans = min(ans, smallCount);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
