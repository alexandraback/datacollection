//
//  main.cpp
//  B. Noisy Neighbors(L)
//
//  Created by KJBS2 on 2015. 5. 3..
//  Copyright (c) 2015년 KJBS2. All rights reserved.
//

#include <stdio.h>

int N, M, X;
int Cnt[9];
int ChangeX[4] = {0, -1, 0, 1};
int ChangeY[4] = {-1, 0, 1, 0};

int min(int x, int y) {
    if(x<y) return x;
    return y;
}

int Check(int f) {
    
    for(int i=0; i<=4; i++) Cnt[i] = 0;
    
    int nowT = X;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            if( (i+j)%2 == f) {
                nowT --;
            }else{
                int nowcnt = 0;
                for(int k=0; k<4; k++) {
                    int nexti = ChangeX[k] + i;
                    int nextj = ChangeY[k] + j;
                    if(nexti >= 1 && nexti <= N && nextj >= 1 && nextj <= M)
                        nowcnt++;
                }
                Cnt[nowcnt]++;
            }
        }
    }
    
    if(nowT <= 0) return 0;
    
    int ans = 0;
    for(int i=0; i<=4; i++) {
        if(Cnt[i] < nowT) {
            ans += Cnt[i] * i;
            nowT -= Cnt[i];
        }else{
            ans += nowT * i;
            nowT = 0;
            return ans;
        }
    }
    
    return -1;
}
int main() {
    freopen("/Users/kjb/Desktop/Binput2.txt", "r", stdin);
    freopen("/Users/kjb/Desktop/Bouptut2.txt", "w", stdout);
    int T; scanf("%d", &T);
    for(int p=1; p<=T; p++) {
        scanf("%d%d%d", &N, &M, &X);
        
        int Ans = min(Check(0), Check(1));
        printf("Case #%d: %d\n", p, Ans);
    }
    return 0;
}