//
//  main.cpp
//  A
//
//  Created by fLOyd on 5/3/14.
//  Copyright (c) 2014 fLOyd. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

const int MAXN = 105;
const int MAXL = 105;

int T, N, ans;
std::string w[MAXN];
int cs0[MAXN];
char cs[MAXN][MAXL];
int cs_count[MAXN][MAXL];



void solve() {
    int now = 0;

    memset(cs0, 0, sizeof(cs0));
    memset(cs_count, 0, sizeof(cs_count));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < w[i].length(); ++j) {
            if (j == 0 || w[i][j] != w[i][j - 1]) {
                cs0[i]++;
                cs[i][cs0[i] - 1] = w[i][j];
                cs_count[i][cs0[i] - 1] = 1;
            } else {
                cs_count[i][cs0[i] - 1]++;
            }
        }
        if ((i != 0) && (cs0[i] != cs0[i - 1])) return;
    }
    for (int i = 1; i < N; ++i) {
        for (int k = 0; k < cs0[i]; ++k) {
            if (cs[i][k] != cs[i - 1][k]) {
                return;
            }
        }
    }

    now = 0;
    for (int j = 0; j < cs0[0]; ++j) {
        for (int t1 = 0; t1 < N - 1; ++t1) {
            for (int t2 = t1 + 1; t2 < N; ++t2) {
                if (cs_count[t1][j] > cs_count[t2][j]) {
                    int tmp = cs_count[t1][j];
                    cs_count[t1][j] = cs_count[t2][j];
                    cs_count[t2][j] = tmp;
                }
            }
        }
        for (int i = 0; i < N / 2; ++i) {
            now += cs_count[N - 1 - i][j] - cs_count[i][j];
        }
    }
    if (ans == -1 || now < ans) {
        ans = now;
    }
}

int main(int argc, const char * argv[]) {
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        std::cin >> N;
        for (int i = 0; i < N; ++i) { std::cin >> w[i]; }
        ans = -1;
        solve();
        std::cout << "Case #" << t + 1 << ": ";
        if (ans == -1) {
            std::cout << "Fegla Won";
        } else {
            std::cout << ans;
        }
        std::cout << std::endl;
    }
    return 0;
}
