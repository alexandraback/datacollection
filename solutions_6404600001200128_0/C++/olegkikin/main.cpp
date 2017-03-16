//#include "InfInt/InfInt.cpp"
#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#define MAX 10000 // for strings

using namespace std;

int gcd(int a, int b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int lcm(int a, int b)
{
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

string solve() {
    int  i, min_idx = 0, t, j, mn, mx;
    int N;
    int *CNT;
    int A=0, B=0;
    int MAXRATE = -1;
    int diff;
     char buffer [50];

    cin >> N;

    CNT = new int[N];

    for (i=0; i<N; i++) {
        cin >> CNT[i];
        //cout << CNT[i] << " ";

        if (i>0) {
            diff = CNT[i-1] - CNT[i];
            if (diff > 0) A += diff;
            if (diff > MAXRATE)
                MAXRATE = diff;
        }
    }
    //cout << endl;


    for (i=0; i<N-1; i++) {
        if (CNT[i] >= MAXRATE)
            B += MAXRATE; else
            B += CNT[i];
    }


    char numstr[50];

    sprintf(numstr, "%d %d", A, B);


    return (string)"" + numstr;
}

int main()
{
    freopen("A-small-attempt0 (2).in", "r", stdin);
    //freopen("B-small-attempt4.in", "r", stdin);
   	freopen("out.txt", "w", stdout);
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
