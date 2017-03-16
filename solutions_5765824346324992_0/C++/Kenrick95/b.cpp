#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
//#include <bits/stdc++.h>
#define INF 1000000007
#define INFLL 9223372036854775807LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/**
 * @problem 
 * @url    
 * @status  
 */

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    
    int T, N, a[100010], B, lc;
    bool b[100010];
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d %d", &B, &N);
        lc = 1;
        for (int i = 0; i < B; i++) {
            scanf("%d", &a[i]);
            lc = lcm(lc, a[i]);
            b[i] = false;
        }
        // printf("%d %d\n", lc, N);
        // N = N % lc;
        // if (N == 0)
        //     N += lc;
        int ax = 0;
        for (int i = 0; i < B; i++) {
            ax += lc / a[i];
        }
        N = N % ax;
        if (N == 0)
            N += ax;
        int ti = 0; int x = 0;
        while (1) {
            for (int i = 0; i < B; i++) {
                if (ti % a[i] == 0) {
                    x++;
                    // printf("%d %d\n", x, N);
                    if (x == N) {
                        printf("Case #%d: %d\n", t, i+1);
                        break;
                    }
                }
            }
            if (x == N)
                break;
            ti++;
        }
    }
    return 0;
}
