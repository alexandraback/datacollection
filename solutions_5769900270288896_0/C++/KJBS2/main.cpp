//
//  main.cpp
//  B. Noisy Neighbors
//
//  Created by KJBS2 on 2015. 5. 3..
//  Copyright (c) 2015년 KJBS2. All rights reserved.
//

#include <stdio.h>

int N, M, X, Ans;
int Map[20][20];

void Find(int n, int m, int x) {
    if(n == (N+1)) {
        if(x != X) return;
        
        int cnt = 0;
        for(int i=1; i<=N; i++)
            for(int j=1; j<=M; j++) {
                if(Map[i][j] == 0) continue;
                if(Map[i+1][j] == 1) cnt++;
                if(Map[i][j+1] == 1) cnt++;
            }
        if(Ans > cnt) Ans = cnt;
        return;
    }
    if(m == (M+1)) return Find(n+1, 1, x);
    
    Map[n][m] = 1;
    Find(n, m+1, x+1);
    Map[n][m] = 0;
    Find(n, m+1, x);
}

int main() {
    
    freopen("/Users/kjb/Desktop/Binput.txt", "r", stdin);
    freopen("/Users/kjb/Desktop/Bouptut.txt", "w", stdout);
    
    int T; scanf("%d", &T);
    for(int i=1; i<=T; i++) {
        scanf("%d%d%d", &N, &M, &X);
        Ans = 0x7fffffff;
        Find(1, 1, 0);
        
        printf("Case #%d: %d\n", i, Ans);
    }
    
    return 0;
}