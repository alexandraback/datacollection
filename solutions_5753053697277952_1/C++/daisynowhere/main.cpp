//
//  main.cpp
//  GCJ
//
//  Created by 陶源 on 4/9/16.
//  Copyright © 2016 daisynowhere. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <set>
#include <string>
using namespace std;
int main() {
    int T;
    int P[26];
    int N, sum, max, p;
    char n, all;
    freopen("/Users/daisy/Documents/GCJ/A-large.in","r",stdin);
    freopen("/Users/daisy/Documents/GCJ/GCJ/2.out","w",stdout);
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        for (int j = 0; j < 26; ++j) {
            P[j] = 0;
        }
        sum = 0;
        cin >> N;
        cout << "Case #" << i <<": ";
        for (int j = 0; j < N; ++j) {
            cin >> P[j];
            sum += P[j];
        }
        while (sum > 2) {
            max = 0;
            p = 0;
            all = 0;
            for (int j = 0; j < N; j ++) {
                if (P[j] >= P[max]) {
                    p = max;
                    max = j;
                }
                if (P[j]) {
                    all ++;
                }
            }
            if (all == 2) {
                n = p + 'A';
                cout << n ;
                n = max + 'A';
                cout << n << " ";
                P[p] --;
                P[max] --;
                sum -= 2;
            }
            else {
                P[max] --;
                sum --;
                n = max + 'A';
                cout << n << " " ;
            }
        }
        for (int j = 0; j < N; j ++) {
            if (P[j]) {
                n = j + 'A';
                cout << n;
            }
        }
        cout << endl;
    }
    return 0;
}
