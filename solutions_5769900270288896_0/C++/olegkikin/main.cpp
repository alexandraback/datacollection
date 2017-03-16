//#include "InfInt/InfInt.cpp"
#include <bits/stdc++.h>
/*#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>*/
#define MAX 10000 // for strings

using namespace std;
//std::map <int, long> cache;

char mp[16][16];

int r, c;

int calc() {
    int ret = 0, i, j;
    for (i=0; i<r ; i++)
        for (j=0; j<c ; j++) {
            if (i<r-1 && mp[i][j] == 1 && mp[i + 1][j] == 1) ret++;
            if (j<c-1 && mp[i][j] == 1 && mp[i][j + 1] == 1) ret++;
        }

    return ret;
}

void outp() {
    int ret = 0, i, j;
    cout << "-------------" << endl;
    for (j=0; j<c ; j++) {
        for (i=0; i<r ; i++)
                cout << (char)(mp[i][j] + '0') << " ";
            cout << endl;
    }
    cout << "Score: " << calc() << endl;
}

int minm(int x, int y, int n) {
    //cout << "\t"<< x << " " << y << " " << n << endl;
    //if (n == 0) outp();
    if (n == 0) return calc();
    if (x == r - 1 && y == c - 1 && n > 1) return 999999;

    if (n == 1 && x == r - 1 && y == c - 1) {
        mp[x][y] = 1;
        int ret = calc();
        mp[x][y] = 0;
        return ret;
    }


    int nx, ny;

    nx = x + 1;
    ny = y;
    if (nx >= r) {
        nx = 0;
        ny++;
    }

    // case 1 (put the tenant here)
    mp[x][y] = 1;
    int sc1 = minm(nx, ny, n - 1);

    // case 2 (no tenant)
    mp[x][y] = 0;
    int sc2 = minm(nx, ny, n);

    return min(sc1, sc2);
}


long solve() {
    long n, i, j, cnt = 0, tmp;
    cin >> r >> c >> n;
    //cout << r << c << " " << n << endl;

    if (n < 2) return 0;

    for (i=0; i<16; i++)
        for (j=0; j<16; j++)
            mp[i][j] = 0;

    return minm(0, 0 , n);

}

int main()
{
    //precalc();
    //cout << rev(99989);
    //return 0;
    freopen("B-small-attempt0.in", "r", stdin);
    //freopen("A.in", "r", stdin);
    //freopen("B-small-attempt4.in", "r", stdin);
   	freopen("out8.txt", "w", stdout);
    int cases = 123;
    //scanf("%d", &cases);
    cin >> cases;
    //cout << "CASES " << cases << endl;
    for (int c=0; c < cases; c++) {
         cout << "Case #" << (c + 1) << ": " << solve() << endl;
//         return 0;
    }

    return 0;
}
