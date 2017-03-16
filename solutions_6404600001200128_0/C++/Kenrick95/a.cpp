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


int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    // 
    int T, N, a[10010];
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &a[i]);
        }
        int ans1 = 0, ans2rate = 0, ans2 = 0;
        for (int i = 1; i < N; i++) {
            if (a[i-1] - a[i] > 0) {
                ans1 += a[i-1] - a[i];
                ans2rate = max(ans2rate, a[i-1] - a[i]);
            }
        }
        //printf("%d\n", ans2rate);
        for (int i = 1; i < N; i++) {
            if (a[i-1] < ans2rate) {
                    ans2 += a[i-1];
                } else {
                    ans2 += ans2rate;
                }
            // if (a[i] > a[i-1]) {
            //     if (a[i-1] < ans2rate) {
            //         ans2 += a[i-1];
            //     } else {
            //         ans2 += ans2rate;
            //     }
            // } else {
            //     if (a[i-1] < ans2rate) {
            //         ans2 += a[i-1];
            //     } else {
            //         ans2 += ans2rate;
            //     }
            //     ans2 += ans2rate;
            // }
        //printf("%d\n", ans2);
        }

        printf("Case #%d: %d %d\n", t, ans1, ans2);

    }
    return 0;
}
