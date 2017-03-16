//
//  main.cpp
//  A
//
//  Created by wangdongfang on 15/4/18.
//  Copyright (c) 2015年 _. All rights reserved.
//

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int N;
int M[100000];
void find(int round) {
    int ans1 = 0;
    int ans2 = 0;
    int max = -1;
    for (int i = 0, j = 1; i < N && j < N; i++, j++) {
        if (M[j] < M[i]) {
            ans1 = ans1 + M[i] - M[j];

        }
        if (max == -1 || (M[i] - M[j]) > max) {
            max = M[i] - M[j];
        }
        
    }

    for (int i = 0; i < N - 1; i++) {
        ans2 += M[i] <= max ? M[i] : max;
    }
    cout << "Case #" << round << ": " << ans1 << " " << ans2 << endl;
    
}

int main() {
    
 //   freopen("/Users/wangdongfang/Myprogram/codejam2015/round1/A/A/sampledata", "r",stdin);
    
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> N;
        for (int j = 0 ; j < N; j++) {
            cin >> M[j];
        }
        find(i+1);
    }
    return 0;
}
