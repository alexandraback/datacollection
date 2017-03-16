//
//  main.cpp
//  Noisy Neighbors
//
//  Created by 서승현 on 2015. 5. 3..
//  Copyright (c) 2015년 서승현. All rights reserved.
//

#include <iostream>

int R, C, N;
int map[20][20];
int ans;

void solve(int y, int x, int c, int d)
{
    if(c == N)
    {
        int t = 0;
        for(int i = 1;i <= R;++i)
            for(int j = 1;j <= C;++j)
                if(map[i][j])
                    t += map[i - 1][j] + map[i][j - 1];
        if(ans > t)
            ans = t;
        
        return;
    }
    
    else if(x == C + 1) solve(y + 1, 1, c, d);
    else if(y == R + 1) return;
    else
    {
        map[y][x] = 1;
        solve(y, x + 1, c + 1, d - 1);
        
        map[y][x] = 0;
        solve(y, x + 1, c, d - 1);
    }
}

int main(int argc, const char * argv[])
{
    FILE *input = freopen("B-small-attempt0.in", "r", stdin);
    FILE *output = freopen("output.txt", "w", stdout);
    
    int T; scanf("%d", &T);
    for(int i = 1;i <= T;++i)
    {
        scanf("%d %d %d", &R, &C, &N);
        
        ans = 16 * 4;
        solve(1, 1, 0, R * C);
        printf("Case #%d: %d\n", i, ans);
    }
    
    return 0;
}