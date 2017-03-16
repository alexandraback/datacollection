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

int solve() {
    //cout << "---------------\n";
    int B, N;
    int  i, min_idx = 0, t, j, mn, mx;
    int fact = 1;
    int *M, *CNT;
    //int *SOLUTIONS;
    std::map <int, int> SOLUTIONS;

    //scanf("%d", &l);
    cin >> B;
    cin >> N;

    //cout << B << " N:" << N << "\n";
    //cout << "LEN: " << l << endl;
    M = new int[B];
    CNT = new int[B];
    //SOLUTIONS = new int[10000000];

    // Read the first one
    for (i=0; i<B; i++) {
        cin >> M[i];
        //fact = lcm(fact, M[i]);
        CNT[i] = 0;
        //cout << M[i] << " ";
    }
    //cout << endl;
    //N = N % fact;


    for (i=0; i<N; i++) {
        min_idx = 0;
        mn = 1000000000;
        mx = -1;
        for (j=0; j<B; j++) {
            /*if (CNT[j] == 0) {
                min_idx = j;
                break;
            }*/

            if (CNT[j] < mn) {
                min_idx = j;
                mn = CNT[j];
            }

            if (CNT[j] > mx) mx = CNT[j];
        }

        SOLUTIONS[i] = min_idx;

        // The loop has completed
        if (mn == mx && mn > 0) {
            //cout << "LOOP " << i << endl;
            N = (N - 1) % i ;
            //cout << "ANSWER IDX " << N << endl;
            return SOLUTIONS[N] + 1;
        }

        //cout << "min_idx " << min_idx << " mn " << mn << " Addding " << M[min_idx] << " to " << CNT[min_idx] << endl;
        CNT[min_idx] += M[min_idx];

/*
        for (j=0; j<B; j++)
            cout << CNT[j] << " ";
        cout << endl;*/

    }


    delete M;
    //delete SOLUTIONS;
    return min_idx + 1;
}

int main()
{
    freopen("B-small-attempt2.in", "r", stdin);
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
