//
//  main.cpp
//  A
//
//  Created by Li Qiu on 4/10/15.
//  Copyright (c) 2015 Li Qiu. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <cmath>

using namespace std;
const int maxn = 1e5 + 10;
int n;
int m[maxn];

void solve(int tcase){
    int  x = 0, y = 0;
    int gap = 0;
    for(int i = 0; i + 1 < n; ++i ){
        if( m[i] > m[i + 1] ){
            
            x+= m[i] - m[i + 1];
            gap = max(gap, m[i] - m[i + 1]);
        }
    }
    for(int i = 0; i + 1 < n; ++i ){
        y += min(gap, m[i] );
    }
    printf("Case #%d: %d %d\n", tcase, x, y);
}

int main(int argc, const char * argv[]) {
    freopen("/Users/liqiu/Desktop/A/A.in", "r", stdin );
    freopen("/Users/liqiu/Desktop/A/A.out", "w", stdout );
    int T;
    cin >> T;
    int tcase = 0;
    while(T--){
        ++tcase;
        cin >> n;
        for(int i = 0; i < n; ++i ) cin >> m[i];
        solve(tcase);
    }
    return 0;
}
