//
//  main.cpp
//  GCJ-2014-a
//
//  Created by Andriy Medvid' on 12.04.14.
//  Copyright (c) 2014 Andriy Medvid'. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <memory.h>

using namespace std;

int main(int argc, const char * argv[])
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int T;
    cin >> T;
    int row1, row2;
    int cards1[4][4], cards2[4][4];
    for(int t = 0; t < T; t++) {
        cin >> row1;
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                cin >> cards1[i][j];
        
        cin >> row2;
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                cin >> cards2[i][j];
        
        int result = -1;
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++) {
                if(cards1[row1-1][i] == cards2[row2-1][j]) {
                    if(result == -1)
                        result = cards1[row1-1][i];
                    else result = -2;
                }
            }
        if(result == -1) {
            printf("Case #%d: Volunteer cheated!\n", t+1);
        } else if(result == -2) {
            printf("Case #%d: Bad magician!\n", t+1);
        } else {
            printf("Case #%d: %d\n", t+1, result);
        }
    }
    return 0;
}

