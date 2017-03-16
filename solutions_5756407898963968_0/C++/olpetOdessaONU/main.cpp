//
//  main.cpp
//  A
//
//  Created by Oleg Petrov on 12/04/2014.
//  Copyright (c) 2014 Oleg Petrov. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int m[2][4][4];
int r[2];

void test(int T)
{
    for(int t=0; t<2; ++t)
    {
        scanf("%d", r+t);
        --r[t];
        for(int i = 0; i < 4; ++i)
            for(int j = 0; j < 4; ++j)
                scanf("%d", &m[t][i][j]);
    }
    vector<int> answ;
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j)
            if(m[0][r[0]][i] == m[1][r[1]][j])
                answ.push_back(m[0][r[0]][i]);
    if(answ.size() == 0)
        printf("Case #%d: Volunteer cheated!\n", T);
    if(answ.size() >= 2)
        printf("Case #%d: Bad magician!\n", T);
    if(answ.size() == 1)
        printf("Case #%d: %d\n", T, answ[0]);
}

int main(int argc, const char * argv[])
{

    freopen("/Users/olpet/Downloads/a.in", "r", stdin);
    freopen("/Users/olpet/Downloads/a.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; ++t)
        test(t+1);
    return 0;
}

