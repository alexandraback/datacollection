//
//  main.cpp
//  p2
//
//  Created by 默默 on 15-4-2.
//  Copyright (c) 2015年 默默. All rights reserved.
//

#include <iostream>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
#define MA 1200005
int str[MA];
//int left[MA];
//int right[MA];
int r,c,n;
int martix[20][20];
int cou(int z, int tar){
    int t = 0;
    memset(martix, 0, sizeof(martix));
    
    //cout << z << endl;
    for (int i = 0; i < r*c; ++i){
        if ((1 << i) & z){
            t++;
            martix[i / c + 1][i % c + 1] = 1;
           // cout << i /r + 1 << " " << i % c + 1 << endl;
        }
    }
    if (t != tar)
        return -1;
    int total = 0;
    for (int i = 1; i <= r; ++i){
        for (int j = 1; j <= c; ++j){
            if (martix[i][j] == 1){
                //cout << i << " " << j << endl;
                if (martix[i - 1][j] == 1)
                    total++;
                if (martix[i + 1][j] == 1)
                    total++;

                if (martix[i][j + 1] == 1)
                    total++;

                if (martix[i][j - 1] == 1)
                    total++;
            }
        }
    }
    total /= 2;
    return total;
    
}
int main(int argc, const char * argv[]) {
    //freopen("/Users/momo/Desktop/xcode_data/in.txt", "r", stdin);
    freopen("/Users/momo/Desktop/xcode_data/B-small-attempt0.in", "r", stdin);
    freopen("/Users/momo/Desktop/xcode_data/out.txt", "w", stdout);
    
    //ifstream fin = ifstream("/Users/momo/Desktop/userProfile/user_profile1.txt");
    int cas;
    cin >> cas;
    int cc = 0;
    while (cc++ < cas){
        cin >> r >> c >> n;
        int zt = 1 << (r * c);
        int minn = 1000;
        
        for (int i = 0; i < zt; ++i){
            int ret = cou(i, n);
            if (ret == -1)
                continue;
            //cout << ret << endl;
            minn = min(minn, ret);
        }
        printf("Case #%d: %d\n", cc, minn);
    }
    return 0;
}








