//
//  main.cpp
//  poj3632
//
//  Created by dive5617 on 14-5-20.
//  Copyright (c) 2014年 dive5617. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int T, n;
    cin >> T;
    while(T --){
        int mmax = -1, mmin = 2100000000;
        cin >> n;
        for(int i = 0; i < n; ++ i) {
            int tmp;
            cin >> tmp;
            mmax = max(tmp,mmax);
            mmin = min(tmp,mmin);
        }
        cout << (mmax - mmin) * 2 << endl;
    }
    return 0;
}