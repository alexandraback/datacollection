//
//  main.cpp
//  danteng
//
//  Created by dive5617 on 14-6-11.
//  Copyright (c) 2014年 dive5617. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

const int mx = 1005;
const int inf = 1e8;
#define pii pair<int, int>
#define mp make_pair

string a, b;
int dp[mx][mx];

int ret(char a, char b){
    if(a == b) return 0;
    return 2;
}

int main(){
    while(cin >> a >> b){
        int n = (int)a.size(), m = (int)b.size();
        for(int i = 0; i <= n; ++ i){
            dp[i][0] = i;
        }
        for(int i = 0; i <= m; ++ i){
            dp[0][i] = i;
        }
        for(int i = 1; i <= n; ++ i){
            for(int j = 1; j <= m; ++ j){
                dp[i][j] = dp[i - 1][j - 1] + ret(a[i - 1], b[j - 1]);
                dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j]);
                dp[i][j] = min(dp[i][j - 1] + 1, dp[i][j]);
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}