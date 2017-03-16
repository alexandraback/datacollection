//
//  main.cpp
//  2015R1B_B
//
//  Created by apple on 15/5/2.
//  Copyright (c) 2015年 apple. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <list>
#include <string>
#include <math.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef map<int, int> mii;
typedef map<ll, ll> mll;

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a > b ? b : a)

int RRR[100][100];

int main(int argc, const char * argv[]) {
    //    freopen("/Users/apple/Documents/coding/Xcode/Google Code Jam/2015R1B_B/2015R1B_B/", "r", stdin);
    freopen("/Users/apple/Documents/coding/Xcode/Google Code Jam/2015R1B_B/2015R1B_B/output1.txt", "w", stdout);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t){
        // each test case starts here
        int N, R, C; cin >> R >> C >> N;
        int temp = pow(2, R * C) - 1;
        int unhappy = INT32_MAX;
        for (int i = 0; i <= temp ; ++i){
            vector<int> room;
            int c = 0, j = i;
            while (j != 0){
                if (j % 2 == 1)room.push_back(c);
                j /= 2;
                c++;
            }
            if (room.size() != N)continue;
            for (int l = 0; l < 100; ++l){
                for (int m = 0; m < 100; ++m){
                    RRR[l][m] = 0;
                }
            }
            for (int i = 0; i < room.size(); ++i){
                int r = room[i];
                RRR[r / R + 1][r % R + 1] = 1;
            }
            int un = 0;
            for (int l = 1; l <= C; ++l){
                for (int m = 1; m <= R; ++m){
                    if (RRR[l][m] == 1 && RRR[l - 1][m] == 1){
                        un++;
                    }
                    if (RRR[l][m] == 1 && RRR[l][m - 1] == 1){
                        un++;
                    }
                }
            }
            unhappy = MIN(unhappy, un);
        }
        cout << "Case #" << t << ": " << unhappy << endl;
    }
    return 0;
}