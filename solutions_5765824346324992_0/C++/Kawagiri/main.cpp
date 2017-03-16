//
//  main.cpp
//  GCJroundA-B
//
//  Created by 冥途雨中旅 on 15/4/18.
//  Copyright (c) 2015年 Gensokyou. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int B, N;
long long b[2000];


long long calc(long long P){
    long long ret = 0;
    for(int i = 0;i < B; ++i){
        ret += (P / b[i])+1;
    }
    return  ret;
}

int main(int argc, const char * argv[]) {
    freopen("../../../../GCJroundA-B/in","r",stdin);
    freopen("../../../../GCJroundA-B/out","w",stdout);

    int T;
    cin >> T;
    for(int bb = 1; bb <= T; ++bb){
        cin >> B >> N;
        
        int ans = 0;
        for(int i = 0;i < B; ++i)
            cin >> b[i];
        long long rb = 56110956,lb = 0, md;
        rb *= rb;
        md = (rb + lb) / 2;
        for(;lb < rb;md = (lb + rb + 1) / 2){
            long long here = calc(md);
            
            if(here < N)lb = md;
            else rb = md - 1;
        }
       
        if(calc(rb) < N){
            long long biu = calc(rb);
            for(;calc(rb) < N;)rb++;
            N -= biu;
        }
        //cout << rb << ' '  << N << endl;
        for(int i = 0;i < B; ++i)if(rb % b[i] == 0){
            N--;
            if(!N){
                ans = i + 1;
                break;
            }
        }
        cout << "Case #" << bb << ": " << ans << endl;
    }
    return 0;
}
