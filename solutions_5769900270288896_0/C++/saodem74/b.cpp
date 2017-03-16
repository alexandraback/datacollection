//
//  b.cpp
//  codejam1B
//
//  Created by Tran Hieu on 5/2/15.
//  Copyright (c) 2015 TranHieu. All rights reserved.
//

//
//  a.cpp
//  codejam1B
//
//  Created by Tran Hieu on 5/2/15.
//  Copyright (c) 2015 TranHieu. All rights reserved.
//

#if 1
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <stack>

#define for1(i,j,k) for (int i=j;i<=k;i++)
#define for2(i,n) for (int i=0;i<n;i++)
#define for1_(i,j,k) for (int i=j;i>=k;i--)
#define for2_(i,n) for (int i=n-1;i>=0;i--)
#define c_s cout.setf(ios::fixed)
#define c_p(x) cout.precision(x)
#define can(x,n) (int)pow(x,1.0/n)
#define mp(x,y) make_pair(x,y)
#define hvi(a,n) next_permutation(a,a+n)
#define Pi 2*asin(1.0)

#define maxN 1000007
#define oo 1000000000
#pragma comment(linker, "/STACK:36777216")

using namespace std;
int n, r, c;
int a[17][17];
int res;
int dr[2] = {0, 1};
int dc[2] = {1, 0};

void print(int test, int res)
{
    cout << "Case #" << test << ": "<<res << endl;
}
void try_(int x, int y, int cur)
{
    if (cur == 0)
    {
        int temp = 0;
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                if (a[i][j])
            {
                for (int k = 0; k < 2; k++)
                {
                    int newi = i + dr[k];
                    int newj = j + dc[k];
                    if (newi > r || newj > c) continue;
                    if (a[newi][newj])
                        temp++;
                }
            }
        res = min(res, temp);
        return;
    }
    if (x > r || cur < 0) return;
    
    for (int i = 1; i >= 0; i--)
    {
        a[x][y] = i;
        if (y == c)
            try_(x + 1, 1, cur - i);
        else
            try_(x, y + 1, cur - i);
    }
}

int main()
{
    //  FILE * f = fopen("", "r");
    //  FILE * fo = fopen("", "w");
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++)
    {
        cin >> r >> c >> n;
        res = oo;
        try_(1, 1, n);
        print(t, res);
    }
    
    
    return 0;
}
#endif