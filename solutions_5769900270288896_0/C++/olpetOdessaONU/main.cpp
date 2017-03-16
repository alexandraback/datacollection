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
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int calc(int c, int doz)
{
    return max(0, 2 * doz - c - 1);
}

int calcIt(int r, int c, int n)
{
    int doz = n / r;
    int rest = n % r;
    int answ = 0;
    for(int i = 0; i < r; ++i)
        if(i < rest)
            answ += calc(c, doz + 1);
        else
            answ += calc(c, doz);
    return answ;
}

void test(int T)
{
    int r, c, n;
    scanf("%d%d%d",&r,&c,&n);
    if(r > c)
        swap(r,c);
    int answ = 0;
    answ += calcIt(r, c, n);
    answ += calcIt(c, r, n);
    printf("Case #%d: %d\n", T, answ);
}

int main(int argc, const char * argv[])
{
    
    freopen("/Users/olpet/Downloads/tmp_files/b.in", "r", stdin);
    freopen("/Users/olpet/Downloads/tmp_files/b.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; ++t)
        test(t+1);
    return 0;
}

